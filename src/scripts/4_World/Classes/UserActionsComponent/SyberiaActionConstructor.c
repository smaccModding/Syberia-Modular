modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
	{		
		super.RegisterActions(actions);
		actions.Insert(ActionInjectSyringeSelf);
		actions.Insert(ActionInjectSyringeTarget);
		actions.Insert(ActionEmptySyringe);
		actions.Insert(ActionInjectInjectorTarget);
		actions.Insert(ActionInjectInjectorSelf);
		actions.Insert(ActionSurgeryTarget);
		actions.Insert(ActionSurgerySelf);
		actions.Insert(ActionUseSalveTarget);
		actions.Insert(ActionUseSalveSelf);
		actions.Insert(ActionOpenPDA);
		actions.Insert(ActionCheckName);
		actions.Insert(ActionSayName);
		actions.Insert(ActionSleep);
        actions.Insert(ActionCutBookPage);
		actions.Insert(ActionPlugStethoscope);
		actions.Insert(ActionStethoscopeInspect);
		actions.Insert(ActionDebugBuildingToolNext);
		actions.Insert(ActionDebugBuildingToolLink);
		actions.Insert(ActionDebugBuildingToolUpgrade);
		actions.Insert(ActionDebugBuildingToolObjPos);
		actions.Insert(ActionDebugBuildingToolObjRot);
		actions.Insert(ActionDebugBuildingToolDoorID);
		actions.Insert(ActionDebugBuildingToolElementID);
		actions.Insert(ActionDebugBuildingToolMarker);
		actions.Insert(ActionDebugBuildingToolSizer);
		actions.Insert(ActionSearchTargetInventory);
		actions.Insert(ActionTraderInteract);
        actions.Insert(ActionWashFruitsWell);
		actions.Insert(ActionWashFruitsWater);
        actions.Insert(ActionHomebookClaimOwnership);
        actions.Insert(ActionOpenHomebook);
	}
};