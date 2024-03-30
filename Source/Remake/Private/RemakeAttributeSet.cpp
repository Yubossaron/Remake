// Fill out your copyright notice in the Description page of Project Settings.


#include "RemakeAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
URemakeAttributeSet::URemakeAttributeSet()
{
	// Default constructor
}

void URemakeAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max attributes we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    // Set adjust code here
    //
    // Example:
    //
    // If a Max value changes, adjust current to keep Current % of Current to Max
    //
    // if (Attribute == GetMaxHealthAttribute())
    // {
    //     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    // }
}

void URemakeAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    FGSCAttributeSetExecutionData ExecutionData;
    GetExecutionDataFromMod(Data, ExecutionData);

    // Set clamping or handling or "meta" attributes here (like damages)

    // Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     HandleHealthAttribute(ExecutionData);
    // }

    // Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

    // if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    // {
    //     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    // }
}

void URemakeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
        
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, Health, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, Rage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, MaxRage, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, Poise, COND_None, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(URemakeAttributeSet, MaxPoise, COND_None, REPNOTIFY_Always);
}

void URemakeAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, Health, OldHealth);
}

void URemakeAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, MaxHealth, OldMaxHealth);
}

void URemakeAttributeSet::OnRep_Rage(const FGameplayAttributeData& OldRage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, Rage, OldRage);
}

void URemakeAttributeSet::OnRep_MaxRage(const FGameplayAttributeData& OldMaxRage)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, MaxRage, OldMaxRage);
}

void URemakeAttributeSet::OnRep_Poise(const FGameplayAttributeData& OldPoise)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, Poise, OldPoise);
}

void URemakeAttributeSet::OnRep_MaxPoise(const FGameplayAttributeData& OldMaxPoise)
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(URemakeAttributeSet, MaxPoise, OldMaxPoise);
}
