// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "RemakeAttributeSet.generated.h"

UCLASS()
class REMAKE_API URemakeAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	URemakeAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_Health)
    FGameplayAttributeData Health = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, Health)    
    
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, MaxHealth)    
    
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_Rage)
    FGameplayAttributeData Rage = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, Rage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_MaxRage)
    FGameplayAttributeData MaxRage = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, MaxRage)    
    
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_Poise)
    FGameplayAttributeData Poise = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, Poise)    
    
    UPROPERTY(BlueprintReadOnly, Category = "RemakeAttributeSet", ReplicatedUsing = OnRep_MaxPoise)
    FGameplayAttributeData MaxPoise = 0.0;
    ATTRIBUTE_ACCESSORS(URemakeAttributeSet, MaxPoise)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

    UFUNCTION()
    virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

    UFUNCTION()
    virtual void OnRep_Rage(const FGameplayAttributeData& OldRage);

    UFUNCTION()
    virtual void OnRep_MaxRage(const FGameplayAttributeData& OldMaxRage);

    UFUNCTION()
    virtual void OnRep_Poise(const FGameplayAttributeData& OldPoise);

    UFUNCTION()
    virtual void OnRep_MaxPoise(const FGameplayAttributeData& OldMaxPoise);
	
	
};
