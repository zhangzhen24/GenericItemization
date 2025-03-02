// Copyright Fissure Entertainment, Pty Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericItemizationTypes.h"
#include "GenericItemizationInstanceTypes.h"
#include "ItemDrop.generated.h"

/**
 * An Actor that is representing an actual FItemInstance that has been dropped and can be claimed by a UItemInventoryComponent.
 */
UCLASS(ClassGroup = "Generic Itemization", Blueprintable)
class GENERICITEMIZATION_API AItemDrop : public AActor
{
	GENERATED_BODY()
	
public:	

	friend class UItemDropperComponent;
	friend class UItemInventoryComponent;
	
	AItemDrop();

	/* Returns the ItemInstance this ItemDrop is representing. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Generic Itemization")
	void GetItemInstance(TInstancedStruct<FItemInstance>& OutItemInstance) const;

	/* Returns the ItemInstance as the underlying Struct value. Make note, that this will slice any overridden data if you are not using FItemInstance. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Generic Itemization")
	void GetItemInstanceStruct(FItemInstance& OutItemInstanceStruct) const;

	/* Returns the ItemInstances ItemDefinition as the underlying Struct value. Make note, that this will slice any overridden data if you are not using FItemDefinition. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Generic Itemization")
	void GetItemDefinitionStruct(FItemDefinition& OutItemDefinitionStruct) const;

	/* Returns true if this ItemDrop is representing a valid ItemInstance. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Generic Itemization")
	bool HasValidItemInstance() const;

	/* Decides if the passed in Inventory can attempt to take this ItemDrop. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Generic Itemization")
	bool CanTakeItem(UItemInventoryComponent* InventoryComponent) const;

protected:

	/* The ItemInstance this ItemDrop is representing. */
	UPROPERTY(Replicated)
	TInstancedStruct<FItemInstance> ItemInstance;

};
