// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class SLAYER_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	// 体力関連のAttribute
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Abilities", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Health);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Abilities", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MaxHealth);
	
	// スタミナ関連のAttribute
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Abilities", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, Stamina);
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Abilities", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UBasicAttributeSet, MaxStamina);
	
public:
	UBasicAttributeSet();
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const;
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldValue) const;
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldValue) const;

	/**
	 * サーバーの同期リストに設定する
	 * @param OutLifetimeProps 
	 */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
