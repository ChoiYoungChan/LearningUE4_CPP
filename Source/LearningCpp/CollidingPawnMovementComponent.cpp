#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) { return; }

	FVector m_DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
	if (!m_DesiredMovementThisFrame.IsNearlyZero()) {
		FHitResult _hit;

		SafeMoveUpdatedComponent(m_DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, _hit);

		if (_hit.IsValidBlockingHit()) {
			SlideAlongSurface(m_DesiredMovementThisFrame, 1.0f - _hit.Time, _hit.Normal, _hit);
		}
	}
}