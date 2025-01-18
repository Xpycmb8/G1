;SDL
{"shoot_emit_int"
   {on hit
		(include "generic.inc")
		{if effector "s5_rocket"
			{spawn "fx_sled_fire"}
			{spawn "rex_rocket_int"}		
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else effector "piece_big_steel_rocket"
			{if rand 0.5
				{spawn "impact_burnmark_02_blend" random_orientation}		
			else
				{spawn "impact_burnmark_01_blend" random_orientation}		
			}
			{spawn "spheredust_small_short_steel"}
		else effector "s5_rocket_failed"
			{if rand 0.5
				{spawn "impact_burnmark_02_blend" random_orientation}		
			else
				{spawn "impact_burnmark_01_blend" random_orientation}		
			}
			{spawn "spheredust_small_short_steel"}
		}
		{if effector "helicopter"
			{if min_speed 10
				{spawn "fire_shellhole_flash" random_orientation}
			}
		}		
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			}
		else min_mass 10
			{if effector "tree"
				{spawn "spheredust_small_short"}
			}
		}
	}
	{on detonate
	(include "generic_blast.inc")
	{if stuff "molotov_coctail"
		else stuff "grenade_cluster"
			("fraction_round_5m") 
			{spawn "ex_he_15mm"}
			{if rand 0.5
				{spawn "shelllhole_scorch_00" terrain_texmod random_orientation}
			else 
				{spawn "shelllhole_scorch_01" terrain_texmod random_orientation}
			}
    else stuff "mortar"
		{spawn "rex_rocket_int"}
		{spawn "add_fx_dirt"}
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod random_orientation}
      else stuff "rocketlauncher 40mm_fg" ;og7v
		("radius_he_5m") ;5 10
		("fraction_round_15m") ; 5 15 30
		("distant_small") 
 		{spawn "rex_rocket_int"}
  		{spawn "fx_sled_fire"}
		{spawn "ex_grenade_size3"}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
    else stuff "rocketlauncher 75mm"
		{spawn "rex_rocket_int"}
		("radius_he_5m") ;5 10
		("fraction_round_5m") ; 5 15 30
		("distant_small") 
		{spawn "fx_sled_fire"}
		{spawn "ex_heat_size2"}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
     else stuff "rocketlauncher 85mm"
		{spawn "rex_rocket_int"}
		("radius_he_5m") ;5 10
		("fraction_round_5m") ; 5 15 30
		("distant_small") 
		{spawn "fx_sled_fire"}
		{spawn "ex_heat_size2"}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
     else stuff "rocketlauncher 105_th" ; thermite
		("radius_he_5m") ;5 10
		("distant_small") 
 		{spawn "rex_rocket_int"}
 		{spawn "fx_sled_fire"}
		{spawn "ex_therm_rpg"}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
    else stuff "c4_explosive"
		("radius_he_10m") ;5 10
		("fraction_round_30m") ; 5 15 30
		("distant_small") 
		{spawn "rex_frag_int"}
		{spawn "fx_sled_fire"}
		{spawn "ex_he_size3"}
		{spawn "shellhole_big" terrain_texmod random_orientation}
	else stuff "noview" 
		else stuff "laser_bullet"
			{spawn "ex_bul_laser"}
		else stuff "laser_bullet_red"
			{spawn "ex_bul_laser_red"}
		else stuff "laser_bullet_blue"
			{spawn "ex_bul_laser_blue"}
	else stuff "fx_40" 
		{spawn "rex_frag_int"}
		{spawn "add_fx_dirt"}
		{spawn "fx_sled_fire"}
		{spawn "ex_fx_25_40"}
		{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
	else stuff "shell_fire"
		{spawn "ex_shell_fire"}
      {spawn "shellhole_dead_car2" terrain_texmod random_orientation}
		else stuff "fx_ap_20_35"
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}
		else stuff "fx_hg_20_35"
			{spawn "ex_air_norm3" offset 0 0 4}
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}
		else stuff "fx_fg_20_35"
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}	  
	else stuff "shell fg small bomb no_crater"
		{spawn "rex_rocket_int"}
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "shellhole4d3" random_orientation}
    else stuff "shell fg big bomb no_crater"
      {spawn "ex_bomb_big"}
      {spawn "shellhole4d2" random_orientation}
    else stuff "shell fg big bomb"
 		{spawn "add_fx_dirt"}
     {spawn "ex_bomb_big"}
      {spawn "crater_norm" terrain_texmod random_orientation}
    else stuff "small_fg"
		{spawn "rex_rocket_int"}
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "fx_hg_20_35"
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "small_fg2"
      {spawn "ex_fg_minimum"}
      {spawn "shellhole_small" random_orientation}
    else stuff "shell big fg heat"
		{spawn "rex_rocket_int"}
		{spawn "cannon_add_mark_big"}
		{spawn "metal_hit_atgm"}
		{spawn "ex_fg_medium_art"}
		{spawn "crater_norm_road" terrain_texmod random_orientation}
	else stuff "shell fg rocket"
		{spawn "rex_rocket_int"}
	  {spawn "ex_fg_small"}
	  {if rand 0.15
		{spawn "crater_small" terrain_texmod random_orientation}
	  else
	    {spawn "shellhole4d3" random_orientation}
	  }
	else stuff "size3 ptrk"	
	  {spawn "ex_fg_small"}
		{spawn "crater_norm_road" terrain_texmod random_orientation}
		else stuff "shell size2 cm"		   
		{spawn "ex_fx_45_89_cm"}		     
		;{spawn "ex_anti_size1"}		     
		{spawn "crater_gun_m3" terrain_texmod}	
	else stuff "shell fg"
			{spawn "rex_frag_int"}
		{spawn "add_fx_dirt"}
	  {spawn "ex_fg_small"}
	  {spawn "crater_norm" terrain_texmod random_orientation}
	else stuff "shell ap rocketlauncher"
		{spawn "rex_rocket_int"}
	  {spawn "ex_grenade_sm_ground"}
	  {spawn "grenade_shellhole" terrain_texmod random_orientation}
	else stuff "shell ap atgm"
		{spawn "cannon_add_mark_big"}
		{spawn "metal_hit_atgm"}
		{spawn "fx_sled_fire"}
		{spawn "rex_rocket_int"}
		{spawn "ex_fg_medium"}
		{spawn "shellhole_big" terrain_texmod random_orientation}
		else stuff "shell big ap"
			 
			{spawn "ap_shellhole" terrain_texmod random_orientation}
			{spawn "ex_ap_medium"}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
		else stuff "shell ap"
			 
			{spawn "ap_shellhole" terrain_texmod random_orientation}
			{spawn "ex_ap_minimum"}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
    else stuff "mine antipersonnel"
			{spawn "rex_frag_int"}
   		{spawn "add_fx_dirt"}
		{spawn "ex_grenade_big"}
		{spawn "shellhole_medium" random_orientation}
    else stuff "dynamite"
			{spawn "rex_frag_int"}
 		{spawn "add_fx_dirt"}
     {spawn "ex_bomb_big"}
      {spawn "shellhole_big" random_orientation}
    else stuff "grenade flashbang"
      {spawn "ex_grenade_flash"}
      {spawn "fire_shellhole_flash" random_orientation}
		else stuff "grenade size1"							; Anti-Personnel Grenades Size 1
			("radius_he_5m") ;5 10
			("fraction_round_15m") ; 5 15 30
			("distant_small") 
			{if rain
				{spawn "ex_grenade_size1_mud"}
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			else
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}
			
		else stuff "grenade size2"							; Anti-Personnel Grenades Size 2
			("radius_he_5m") ;5 10
			("fraction_round_15m") ; 5 15 30
			("distant_small") 
			{if rain
				{spawn "ex_grenade_size2_mud"}
				{spawn "grenade_shellhole" scale 0.8 texmod "mud"}
			else season "winter"
				{spawn "ex_grenade_size2"}
				{spawn "grenade_shellhole" scale 0.8 terrain_texmod}
			else
				{spawn "ex_grenade_size2"}
				{spawn "grenade_shellhole" scale 0.8 terrain_texmod}
			}
			
		else stuff "grenade size3"							; Anti-Tank Grenades
			{if rain
				{spawn "ex_grenade_size3_mud"}
				{spawn "grenade_shellhole" texmod "mud"}
			else season "winter"
				{spawn "ex_grenade_size3"}
				{spawn "grenade_shellhole" terrain_texmod}
			else
				{spawn "ex_grenade_size3"}
				{spawn "grenade_shellhole" terrain_texmod}
			}
			
		else stuff "grenade size4"							; Dynamite/Satchel Charges
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "ex_at_mine"}
				{spawn "crater_tiny" texmod "mud"}
			else season "winter"
				{spawn "ex_mort_big"}
				{spawn "crater_tiny" terrain_texmod}
			else
				{spawn "ex_mort_big"}
				{spawn "crater_tiny" terrain_texmod}
			}
    else stuff "grenade big"
			{spawn "rex_frag_int"}
		{spawn "fx_sled_fire"}
		{spawn "ex_grenade_size2"}
		{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
    else stuff "grenade"
		("radius_he_5m") ;5 10
		("fraction_round_15m") ; 5 15 30
		("distant_small") 
		{spawn "rex_frag_int"}
		{spawn "fx_sled_fire"}
		{if rain
			{spawn "ex_grenade_size1_mud"}
			{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
		else season "winter"
			{spawn "ex_grenade_size1"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
		else
			{spawn "ex_grenade_size1"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
		}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
    else stuff "bullet small"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else rand 0.3
			{spawn "bullet_shellhole_2" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else rand 0.3
			{spawn "bullet_shellhole_3" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else 
			{spawn "bullet_shellhole_4" terrain_texmod random_orientation}
			{spawn "ex_bul_sm2"}
		}
   else stuff "bullet meds"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else rand 0.3
			{spawn "bullet_shellhole_2x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else rand 0.3
			{spawn "bullet_shellhole_3x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else 
			{spawn "bullet_shellhole_4x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		}
    else stuff "bullet big os"
		{spawn "rex_bullet_int"}
      {spawn "ex_bul_big_50"}
      {spawn "ex_air_norm6"}
	else stuff "bullet big"
		{spawn "rex_bullet_int"}
		{spawn "ex_bul_big_50"}
   else stuff "bullet"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big"}
		else rand 0.3
			{spawn "bullet_shellhole_2x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big"}
		else rand 0.3
			{spawn "bullet_shellhole_3x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big2"}
		else 
			{spawn "bullet_shellhole_4x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big2"}
		}
		else stuff "zenite ap"
			{spawn "rex_bullet_int"}
			{spawn "ex_bul_zenit_ap"}
			{if rand 0.3
				{spawn "bullet_shellhole_1x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_2x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_3x75" terrain_texmod random_orientation}
			else 
				{spawn "bullet_shellhole_4x75" terrain_texmod random_orientation}
			}
		else stuff "zenite cs"
			{spawn "ex_bul_zenit_cs"}
			{if rand 0.3
				{spawn "bullet_shellhole_1x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_2x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_3x75" terrain_texmod random_orientation}
			else 
				{spawn "bullet_shellhole_4x75" terrain_texmod random_orientation}
			}
		else stuff "zenite th"
			{spawn "rex_bullet_int"}
			{spawn "fraction_thermite" }
			{spawn "ex_bul_zenit_th"}
			{if rand 0.5
				{spawn "shelllhole_scorch_00" terrain_texmod random_orientation}
			else 
				{spawn "shelllhole_scorch_01" terrain_texmod random_orientation}
			}
		else stuff "zenite fg"
			{spawn "rex_bullet_int"}
			{if rand 0.3
				{spawn "bullet_shellhole_1x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_2x75" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "bullet_shellhole_3x75" terrain_texmod random_orientation}
			else 
				{spawn "bullet_shellhole_4x75" terrain_texmod random_orientation}
			}
			{spawn "ex_bul_zenit_fg"}
    else stuff "mine-cluster"
 			{spawn "rex_frag_int"}
     {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}
    else stuff "mine-cluster-mini"
      {spawn "ex_grenade_sm_ground"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "mine-cluster-fier"
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}

	}
  }
}
{"shoot_emit_int_wood"
  {on hit
		(include "generic.inc")
		{if effector "s5_rocket"
			{spawn "fx_sled_fire"}
			{spawn "rex_rocket_int"}		
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else effector "piece_big_steel_rocket"
			{if rand 0.5
				{spawn "impact_burnmark_02_blend" random_orientation}		
			else
				{spawn "impact_burnmark_01_blend" random_orientation}		
			}
			{spawn "spheredust_small_short_steel"}
		else effector "s5_rocket_failed"
			{if rand 0.5
				{spawn "impact_burnmark_02_blend" random_orientation}		
			else
				{spawn "impact_burnmark_01_blend" random_orientation}		
			}
			{spawn "spheredust_small_short_steel"}
		}
	{if effector "helicopter"
		{if min_speed 10
			{spawn "fire_shellhole_flash" random_orientation}
		}
	}		
	{if min_mass 100
      {if effector "tree"
        {spawn "tree_crush"}
     else effector "armor"
        {spawn "spheredust_small_short_arm"}
      else
        {spawn "spheredust_small"}
      }
    else min_mass 10
      {if effector "tree"
        {spawn "spheredust_small_short"}
      else effector "armor"
        {spawn "spheredust_small_short_arm"}
      else 
        {spawn "spheredust_small_short_plastic"}
      }
    }
  }
  {on detonate
    {if stuff "mortar"
		{spawn "rex_rocket_int"}
		{spawn "add_fx_dirt"}
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod random_orientation}
     else stuff "c4_explosive"
		{spawn "rex_frag_int"}
		{spawn "add_fx_dirt"}
		{spawn "fx_sled_fire"}
		{spawn "broken_prop"}
		{spawn "ex_fragment_cl"}
		{spawn "ex_fg_medium"}
		{spawn "shellhole_big" terrain_texmod random_orientation}
	else stuff "noview" 
		else stuff "laser_bullet"
			{spawn "ex_bul_laser"}
		else stuff "laser_bullet_red"
			{spawn "ex_bul_laser_red"}
		else stuff "laser_bullet_blue"
			{spawn "ex_bul_laser_blue"}
	else stuff "fx_40" 
		{spawn "rex_frag_int"}
		{spawn "add_fx_dirt"}
		{spawn "fx_sled_fire"}
		{spawn "ex_fx_25_40"}
		{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
	else stuff "shell_fire"
		{spawn "ex_shell_fire"}
      {spawn "shellhole_dead_car2" terrain_texmod random_orientation}
    else stuff "fx_ap_20_35"
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "fx_fg_20_35"
      {spawn "ex_fg_minimum"}
      {spawn "shellhole_small" random_orientation}
		else stuff "shell_minimum fg"
			 
			{spawn "ap_shellhole" terrain_texmod random_orientation}
			{spawn "ex_fg_minimum"}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
		else stuff "shell_minimum"
			 
			{spawn "ap_shellhole" terrain_texmod random_orientation}
			{spawn "ex_ap_minimum"}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
	else stuff "shell fg small bomb no_crater"
		{spawn "rex_rocket_int"}
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "shellhole4d3" random_orientation}
    else stuff "shell fg big bomb no_crater"
      {spawn "ex_bomb_big"}
      {spawn "shellhole4d2" random_orientation}
    else stuff "shell fg big bomb"
 		{spawn "add_fx_dirt"}
     {spawn "ex_bomb_big"}
      {spawn "crater_norm" terrain_texmod random_orientation}
    else stuff "small_fg"
		{spawn "rex_rocket_int"}
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "fx_hg_20_35"
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "small_fg2"
      {spawn "ex_fg_minimum"}
      {spawn "shellhole_small" random_orientation}
    else stuff "shell big fg heat"
		{spawn "rex_rocket_int"}
		{spawn "cannon_add_mark_big"}
		{spawn "metal_hit_atgm"}
		{spawn "ex_fg_medium_art"}
		{spawn "crater_norm_road" terrain_texmod random_orientation}
	else stuff "shell fg rocket"
		{spawn "rex_rocket_int"}
	  {spawn "ex_fg_small"}
	  {if rand 0.15
		{spawn "crater_small" terrain_texmod random_orientation}
	  else
	    {spawn "shellhole4d3" random_orientation}
	  }
	else stuff "size3 ptrk"	
	  {spawn "ex_fg_small"}
		{spawn "crater_norm_road" terrain_texmod random_orientation}
		else stuff "shell size2 cm"		   
		{spawn "ex_fx_45_89_cm"}		     
		;{spawn "ex_anti_size1"}		     
		{spawn "crater_gun_m3" terrain_texmod}	
	else stuff "shell fg"
			{spawn "rex_frag_int"}
		{spawn "add_fx_dirt"}
	  {spawn "ex_fg_small"}
	  {spawn "crater_norm" terrain_texmod random_orientation}
	else stuff "shell ap rocketlauncher"
		{spawn "rex_rocket_int"}
	  {spawn "ex_grenade_sm_ground"}
	  {spawn "grenade_shellhole" terrain_texmod random_orientation}
	else stuff "shell ap atgm"
		{spawn "cannon_add_mark_big"}
		{spawn "metal_hit_atgm"}
		{spawn "fx_sled_fire"}
		{spawn "rex_rocket_int"}
		{spawn "ex_fg_medium"}
		{spawn "shellhole_big" terrain_texmod random_orientation}
	else stuff "shell ap"
	  {spawn "ex_ap_small"}
    else stuff "mine antipersonnel"
			{spawn "rex_frag_int"}
   		{spawn "add_fx_dirt"}
		{spawn "ex_grenade_big"}
		{spawn "shellhole_medium" random_orientation}
    else stuff "dynamite"
			{spawn "rex_frag_int"}
 		{spawn "add_fx_dirt"}
     {spawn "ex_bomb_big"}
      {spawn "shellhole_big" random_orientation}
    else stuff "grenade flashbang"
      {spawn "ex_grenade_flash"}
      {spawn "fire_shellhole_flash" random_orientation}
    else stuff "grenade big"
			{spawn "rex_frag_int"}
		{spawn "fx_sled_fire"}
		{spawn "ex_grenade_big"}
		{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
    else stuff "grenade"
			{spawn "rex_frag_int"}
		{spawn "fx_sled_fire"}
		{spawn "ex_grenade_sm_ground"}
		{spawn "grenade_shellhole" terrain_texmod random_orientation}
    else stuff "bullet small"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else rand 0.3
			{spawn "bullet_shellhole_2" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else rand 0.3
			{spawn "bullet_shellhole_3" terrain_texmod random_orientation}
			{spawn "ex_bul_sm"}
		else 
			{spawn "bullet_shellhole_4" terrain_texmod random_orientation}
			{spawn "ex_bul_sm2"}
		}
   else stuff "bullet meds"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else rand 0.3
			{spawn "bullet_shellhole_2x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else rand 0.3
			{spawn "bullet_shellhole_3x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		else 
			{spawn "bullet_shellhole_4x75" terrain_texmod random_orientation}
			{spawn "ex_bul_big4"}
		}
    else stuff "bullet big os"
		{spawn "rex_bullet_int"}
      {spawn "ex_bul_big_50"}
      {spawn "ex_air_norm6"}
	else stuff "bullet big"
		{spawn "rex_bullet_int"}
		{spawn "ex_bul_big_50"}
   else stuff "bullet"
		{spawn "rex_bullet_int"}
		{if rand 0.3
			{spawn "bullet_shellhole_1x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big"}
		else rand 0.3
			{spawn "bullet_shellhole_2x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big"}
		else rand 0.3
			{spawn "bullet_shellhole_3x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big2"}
		else 
			{spawn "bullet_shellhole_4x50" terrain_texmod random_orientation}
			{spawn "ex_bul_big2"}
		}
	else stuff "zenite"
 		{spawn "rex_bullet_int"}
     {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
    else stuff "mine-cluster"
 			{spawn "rex_frag_int"}
     {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}
    else stuff "mine-cluster-mini"
      {spawn "ex_grenade_sm_ground"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "mine-cluster-fier"
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}

	}
  }
}