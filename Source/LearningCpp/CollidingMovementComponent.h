#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "CollidingMovementComponent.generated.h"


UCLASS()
class LEARNINGCPP_API UCollidingMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
