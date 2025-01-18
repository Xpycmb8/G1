{if stuff "rocketlauncher 75mm"
	("distant_small") 
	("radius_he_5m") 
 else stuff "rocketlauncher 85mm"
	("distant_small") 
	("radius_he_5m") 
else stuff "rocketlauncher 105_th" ; thermite
	("distant_small") 
else stuff "rocketlauncher 40mm_fg" ;og7v
	("radius_he_5m") ;5 10
	("fraction_round_15m") ; 5 15 30
	("distant_small") 
else stuff "shell_fire"
else stuff "fx_40" 
	("distant_small") 
	("radius_he_10m") ;5 10 25
	("fraction_round_5m") ;5 15 30
else stuff "size3 ptrk"
	("distant_big") 
	("radius_he_25m") ;5 10 25
	("fraction_round_15m") ;5 15 30
else stuff "shell fg small bomb no_crater"
	("distant_big") 
	("radius_he_25m") ;5 10 25
	("fraction_round_30m") ;5 15 30
else stuff "shell fg big bomb no_crater"
	("radius_he_25m") ;5 10 25
else stuff "shell shell_big heat"
	("radius_he_5m") ;5 10
	("fraction_round_5m") ; 5 15 30
	("distant_big") 
else stuff "shell big fg"
	("radius_he_10m") ;5 10 25
	("fraction_round_30m") ;5 15 30
else stuff "shell fg_art big bomb"
	("distant_big") 
	("radius_he_25m") ;5 10 25
	("fraction_round_30m") ;5 15 30
else stuff "shell fg big bomb"
	("distant_big") 
	("radius_he_25m") ;5 10 25
	("fraction_round_30m") ;5 15 30
else stuff "shell fg rocket"
	("radius_he_10m") ;5 10 25
	("fraction_round_15m") ;5 15 30
	("distant_big") 
else stuff "shell_minimum fg"
	("radius_he_5m") ;5 10 25
	("fraction_round_5m") ;5 15 30
	("distant_small") 
else stuff "shell_minimum"
	("distant_small") 
else stuff "shell fg"
	("radius_he_10m") ;5 10 25
	("fraction_round_5m") ;5 15 30
	("distant_small") 
else stuff "shell ap rocketlauncher"
else stuff "c4_explosive"
	("radius_he_25m") ;5 10 25
	("fraction_round_30m") ;5 15 30
	("distant_big") 
else stuff "shell ap atgm"
else stuff "shell big ap"
	("distant_small") 
else stuff "shell ap"
	("distant_small") 
else stuff "shell size1 fg"		     
else stuff "shell size1"		    
else stuff "shell size2 fg"		    
else stuff "shell size3 fg"		   
else stuff "shell size3"		     
else stuff "shell size4"	
else stuff "shell size5"		     
else stuff "shell size5 fg"		     
else stuff "dynamite"
	("radius_he_10m") ;5 10 25
	("fraction_round_15m") ;5 15 30
	("distant_big") 
	{if tagged "expl_emitters_int"
		{spawn "rex_frag_int"}
	}
	{if tagged "expl_emitters_ext"
		{spawn "rex_frag_ext"}
	}
	{if tagged "expl_emitters_mtl"
		{spawn "rex_frag_mtl"}
	}
else stuff "grenade flashbang"
else stuff "grenade big"
	("radius_he_10m") ;5 10 25
	("fraction_round_15m") ;5 15 30
	("distant_small") 
	{if tagged "expl_emitters_int"
		{spawn "rex_frag_int"}
	}
	{if tagged "expl_emitters_ext"
		{spawn "rex_frag_ext"}
	}
	{if tagged "expl_emitters_mtl"
		{spawn "rex_frag_mtl"}
	}
else stuff "grenade fg"
	("radius_he_5m") ;5 10 25
	("fraction_round_15m") ;5 15 30
	("distant_small") 
	{if tagged "expl_emitters_int"
		{spawn "rex_frag_int"}
	}
	{if tagged "expl_emitters_ext"
		{spawn "rex_frag_ext"}
	}
	{if tagged "expl_emitters_mtl"
		{spawn "rex_frag_mtl"}
	}
else stuff "mortar"
	("radius_he_10m") ;5 10 25
	("fraction_round_30m") ;5 15 30
	("distant_small") 
else stuff "zenite fg"
else stuff "fx_hg_20_35"
else stuff "fx_fg_20_35"
else stuff "small_fg"
	("distant_small") 
else stuff "small_fg2"
else stuff "mine-cluster-mini"
else stuff "mine-cluster"
else stuff "fx_ap_20_35"
	("radius_he_2m") ;5 10
	("fraction_round_5m") ; 5 15 30
	("distant_small") 
else stuff "rifle_grenade_at"						; HEAT rifle Grenades
else stuff "mine antipersonnel"
	("radius_he_10m") ;5 10 25
	("fraction_round_15m") ;5 15 30
	("distant_small") 
else stuff "mine antitank"							; Anti-Tank Mines
	("radius_he_10m") ;5 10
	("fraction_round_15m") ; 5 15 30
	("distant_big") 
else stuff "grenade size1"							; Anti-Personnel Grenades Size 1
	("radius_he_5m") ;5 10
	("fraction_round_15m") ; 5 15 30
	("distant_small") 
else stuff "grenade size2"							; Anti-Personnel Grenades Size 2
	("radius_he_5m") ;5 10
	("fraction_round_15m") ; 5 15 30
	("distant_small") 
else stuff "grenade size3"							; Anti-Tank Grenades
else stuff "grenade size4"							; Dynamite/Satchel Charges
else stuff "mortar big bomb size1"					; 200 Mortar shells
else stuff "mortar big bomb size2"					; 170 Mortar shell
else stuff "mortar big"								; 120mm Mortar shells
else stuff "mortar small"							; 50-60mm Mortar shells
else stuff "rocketlauncher heat_shell size1"		; 60mm AT Rockets
else stuff "rocketlauncher heat_shell size2"		; AT Rockets
		else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
		else stuff "shell size2 all_he"							; 75-104mm cannon HE shells
		else stuff "shell size3 all_he"							; 105-149mm cannon HE shells
		else stuff "shell size4 all_he"							; 150-169mm cannon HE shells
		else stuff "bomb size1"								; 50-60kg bombs / explosives
		else stuff "shell big fg max"
			("radius_he_10m") ;5 10
			("fraction_round_30m") ; 5 15 30
			("distant_big") 
		else stuff "shell fg small bomb no_crater"
			("radius_he_10m") ;5 10
			("fraction_round_30m") ; 5 15 30
			("distant_big") 
}
