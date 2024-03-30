// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "BossrushAttributeSet.generated.h"

UCLASS()
class REMAKE_API UBossrushAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UBossrushAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "BossrushAttributeSet", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health = 0.0;
    ATTRIBUTE_ACCESSORS(UBossrushAttributeSet, Health)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	
	
};
