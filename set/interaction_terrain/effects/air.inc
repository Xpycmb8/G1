;SDL

{"air"
	{on detonate
		{if stuff "molotov_coctail"
		else stuff "mine-cluster"
			{spawn "ex_air_big"}
		 else stuff "rocketlauncher 40mm_fg" ;og7v
			{spawn "ex_air_big"}
		 else stuff "rocketlauncher 75mm"
			{spawn "ex_air_big"}
		 else stuff "rocketlauncher 85mm"
			{spawn "ex_air_big"}
		 else stuff "rocketlauncher 105_th" ; thermite
			{spawn "ex_air_big"}
			{spawn "fraction_thermite" }
		else stuff "mine-cluster-fier"
			{spawn "ex_air_big"}
		else stuff "mine-cluster-mini"
			{spawn "ex_air_norm"}
		else stuff "c4_explosive"
			{spawn "ex_air_big"}
		else stuff "fx_40" 
			{spawn "ex_air_norm8"}
		 else stuff "rocketlauncher 40mm_fg" ;og7v
			{spawn "fx_sled_fire"}
			{spawn "fraction_spawn"}		
		else stuff "rocketlauncher 75mm"
			{spawn "fx_sled_fire"}
			{spawn "fraction_spawn"}		
		 else stuff "rocketlauncher 85mm"
			{spawn "fx_sled_fire"}
			{spawn "fraction_spawn"}		
		 else stuff "rocketlauncher 105_th" ; thermite
			{spawn "fx_sled_fire"}
		else stuff "dynamite"
			("distant_big") 
			{spawn "ex_air_big"}
		else stuff "big shell fg bomb"
			("distant_big") 
			{spawn "ex_bomb_big"}
		else stuff "mortar"
			("distant_small") 
			{spawn "ex_air_big"}
		else stuff "shell_fire"		
			{spawn "ex_bomb_big"}
		else stuff "zenite"
			{spawn "ex_air_norm"}
		else stuff "shell_minimum"
			{spawn "ex_air_big"}
		else stuff "big sm"		
			{spawn "smoke_shell"}
			{spawn "smoke_cover-up_big"}	
		else stuff "sm"		
			{spawn "smoke_shell"}
		else stuff "ex_fx_25_40"
			{spawn "ex_air_norm"}
		else stuff "big shell fg bomb fl" 
			{spawn "fuel_die"}
			{spawn "train_die"}
			{spawn "shellhole_big_dead"}	  
		else stuff "semtex"
			{spawn "ex_air_big"}
		else stuff "shell ap big"
			{spawn "ex_air_big"}
		else stuff "grenade"
			("distant_small") 
			{spawn "ex_air_big"}
		}
	}
}
