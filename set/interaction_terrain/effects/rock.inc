;SDL
{"rock"
	(include "\set\interaction_terrain\effects\effects-defines.inc")
   {on hit
		(include "generic.inc")
		{if effector "shell_s1"
			{start_sound "hit/casing/s1/hard/concrete/" use_position}

		else effector "shell_s2"
			{start_sound "hit/casing/s2/hard/concrete/" use_position}

		else effector "shell_s3"
			{start_sound "hit/casing/s3/hard/concrete/" use_position}

		else effector "shell_cannon"
			{spawn "spheredust_shell"}
		else effector "s5_rocket"
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
		else stuff "no_hit" 
		else stuff "grapple_fx"								; grapple hook
			{if rain
				{spawn "ex_ap_size2"}
			else season "winter"
				{spawn "ex_ap_size2"}
			else
				{spawn "ex_ap_size2_dust"}
			}
			{spawn "ap_shellhole" scale 0.4}
		else stuff "fx_40" 
			{spawn "ex_fx_25_40"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
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
		else stuff "shell_fire"
		{spawn "ex_shell_fire"}
      {spawn "shellhole_dead_car2" terrain_texmod random_orientation}
		else stuff "laser_bullet"
			{spawn "ex_bul_laser"}
		else stuff "laser_bullet_red"
			{spawn "ex_bul_laser_red"}
		else stuff "laser_bullet_blue"
			{spawn "ex_bul_laser_blue"}
		else stuff "fx_hg_20_35"
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}	  
		else stuff "bullet meds"
		{spawn "ex_bul_big4"}
		else stuff "size3 ptrk"
	  {spawn "ex_fg_small"}
	{spawn "crater_small" terrain_texmod random_orientation}
		else stuff "dynamite"
     {spawn "ex_bomb_big"}
      {spawn "shellhole_medium" random_orientation}
		else stuff "grenade flashbang"
      {spawn "ex_grenade_flash"}
      {spawn "fire_shellhole_flash" random_orientation}
		else stuff "bullet_fx size1"						; Pistol Caliber
			{spawn "ex_bul_puff"}

		else stuff "bullet_fx size2 intermediate"			; Rifle Caliber
			("sonic_crack_s1")
			{spawn "ex_bul_puff"}

		else stuff "bullet_fx size2"						; Rifle Caliber
			("sonic_crack_s2")
			{spawn "ex_bul_puff"}

		else stuff "bullet_fx size3 api"					; Large Rifle Caliber API
			("sonic_crack_s3")
			{spawn "ex_bul_puff"}
			{spawn "ex_bul_heavy_ex"}

		else stuff "bullet_fx size3"						; Large Rifle Caliber
			("sonic_crack_s3")
			{spawn "ex_bul_puff"}

		else stuff "rifle_grenade_at"						; HEAT rifle Grenades
			{spawn "ex_heat_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}

		else stuff "grenade size1"							; Anti-Personnel Grenades Size 1
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}

		else stuff "grenade size2"							; Anti-Personnel Grenades Size 2
			{spawn "ex_grenade_size2_rock"}
			{spawn "grenade_shellhole" scale 0.8 terrain_texmod}

		else stuff "grenade size3"							; Anti-Tank Grenades
			{spawn "ex_grenade_size3_rock"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "grenade size4"							; Dynamite/Satchel Charges
			{spawn "shockwave_sphere"}
			{spawn "ex_mort_big_rock"}
			{spawn "crater_tiny" terrain_texmod}
		else stuff "grenade big"
			{spawn "ex_grenade_size2_rock"}
			{spawn "grenade_shellhole" scale 0.8 terrain_texmod}
		else stuff "grenade mine"
			{spawn "m47_mine_ground_proj" dir_velocity}			
			{spawn "ex_bul_big3"}
		else stuff "grenade"
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
		else stuff "bullet small"
			{if rand 0.5
				{spawn "ex_bul_sm"}
			else
				{spawn "ex_bul_sm2"}
			}
		else stuff "bullet big"
			{spawn "ex_bul_big_50"}
		else stuff "bullet"
			{if rand 0.5
				{spawn "ex_bul_big"}
			else
				{spawn "ex_bul_big2"}
			}   
		else stuff "c4_explosive"
			{spawn "ex_fg_medium"}
			{spawn "shellhole_big" texmod "ground" random_orientation}
		else stuff "rocketlauncher 40mm_fg" ;og7v
			{spawn "ex_grenade_size2_rock"}
			{spawn "grenade_shellhole" scale 0.8 terrain_texmod}
		else stuff "rocketlauncher 75mm"
			{spawn "fx_sled_fire"}
			{spawn "ex_fg_small_rpg"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		 else stuff "rocketlauncher 85mm"
			{spawn "fx_sled_fire"}
			{spawn "ex_fg_small_rpg"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		 else stuff "rocketlauncher 105_th" ; thermite
			{spawn "fx_sled_fire"}
			{spawn "ex_therm_rpg"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		else stuff "shell fg_art big bomb"
      {spawn "ex_fg_medium_art"}
      {spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell shell_big heat"
		{spawn "crater_norm" terrain_texmod random_orientation}
		{spawn "ex_heat_medium"}
		{if rand 0.5
			{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
		else rand 0.3
			{spawn "decal_spotfire_sheet_1" terrain_texmod random_orientation}
		else rand 0.3
			{spawn "decal_spotfire_sheet_2" terrain_texmod random_orientation}
		else rand 0.3
			{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
		}
		else stuff "small_fg"
      {spawn "ex_air_norm3" offset 0 0 4}
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small" random_orientation}
		else stuff "small_fg2"
      {spawn "ex_fg_minimum"}
      {spawn "shellhole_small" random_orientation}		
		else stuff "zenite ap"
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
			{spawn "fraction_thermite" }
			{spawn "ex_bul_zenit_th"}
			{if rand 0.5
				{spawn "shelllhole_scorch_00" terrain_texmod random_orientation}
			else 
				{spawn "shelllhole_scorch_01" terrain_texmod random_orientation}
			}
		else stuff "zenite fg"
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
		else stuff "mortar big ic"							; 120mm Mortar incendiary
			{spawn "ex_ic_120_rock"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" scale 1.4 random_orientation}
			{fire radius 4 time 20 heating 0.25}

		else stuff "mortar big bomb size1"					; 200mm Mortar shells
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar big bomb size2"					; 170mm Mortar shells
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg_rock"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "mortar big"								; 120mm Mortar shells
			{spawn "ex_he_size3_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar small"							; 50-60mm Mortar shells
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" terrain_texmod}
		else stuff "mortar"
			{spawn "ex_grenade_big"}
			{spawn "grenade_at_shellhole" texmod "ground" random_orientation}
		else stuff "shell size2_heat_shell"					; 75-104mm cannon HEAT shells
			{spawn "ex_heat_size2_rock"}
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell size3_heat_shell"					; 105-149mm cannon HEAT shells
			{spawn "shockwave_sphere"}
			{spawn "ex_heat_size3_rock"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size4_heat_shell"					; 150mm cannon HEAT shells
			{spawn "shockwave_sphere"}
			{spawn "ex_heat_size3_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "rocketlauncher heat_shell size1"		; 60mm AT Rockets
			{spawn "shockwave"}
			{spawn "ex_heat_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

		else stuff "rocketlauncher heat_shell size2"		; AT Rockets
			{spawn "shockwave"}
			{spawn "ex_heat_size2_rock"}
			{spawn "grenade_shellhole" texmod "mud"}
			{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

		else stuff "heat_shell"								; All Other HEAT Shells
			{spawn "shockwave"}
			{spawn "ex_heat_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
		else stuff "shell_minimum fg"		 
			{spawn "ap_shellhole" terrain_texmod random_orientation}
			{spawn "ex_fg_minimum"}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
		else stuff "auto 15mm he"							; 15mm Autocannon HE shells
			{spawn "ex_he_15mm"}

		else stuff "auto size1 he"							; 20-25mm Autocannon HE shells
			{spawn "ex_he_autocannon"}

		else stuff "auto size1 aphe"						; 20-25mm Autocannon APHE shells
			{spawn "ex_he_autocannon"}

		else stuff "auto size1"								; 20-25mm Autocannon AP shells
			{spawn "ex_ap_autocannon"}

		else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" scale 0.4 terrain_texmod}

		else stuff "auto size2"								; 37-40mm Autocannon AP shells
			{spawn "ex_ap_size1_rock"}

		else stuff "shell size1 all_he"							; 37-74mm cannon HE shells
			{spawn "ex_he_size1_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}

		else stuff "shell size1"							; 37-74mm cannon AP shells
			{spawn "ex_ap_size1_rock"}
			{spawn "ap_shellhole" scale 0.2}

		else stuff "shell size2 all_he"							; 75-104mm cannon HE shells
			{spawn "ex_he_size2_rock"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "shell size2"							; 75-104mm cannon AP shells
			{spawn "ex_ap_size2_rock"}
			{spawn "ap_shellhole" scale 0.4}

		else stuff "shell size3 all_he"							; 105-149mm cannon HE shells
			{spawn "ex_he_size3_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "shell size3"							; 105-149mm cannon AP shells
			{spawn "ex_ap_size3_rock"}
			{spawn "ap_shellhole" scale 0.6}

		else stuff "shell size4 all_he"							; 150-169mm cannon HE shells
			{spawn "ex_he_size4"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "shell size4"							; 150-169mm cannon AP shells
			{spawn "ex_ap_size4_rock"}
			{spawn "ap_shellhole" scale 0.8}

		else stuff "shell size5"							; 170mm+ cannon HE shells
			{spawn "ex_he_size5_rock"}
			{spawn "shockwave_sphere"}
			{spawn "crater_big" terrain_texmod}

		else stuff "shell size6"							; 240mm+ cannon HE shells
			{spawn "ex_he_size6_rock"}
			{spawn "shockwave_sphere"}
			{spawn "crater_massive" terrain_texmod}

		else stuff "shell size7"							; 600mm cannon HE shells
			{spawn "ex_he_size7_rock"}
			{spawn "shockwave_sphere"}
			{spawn "crater_massive" terrain_texmod}

		else stuff "shell wp_size1"							; 50mm WP shells
			{spawn "ex_wp_size1_rock"}							; initial explosion fx
			{spawn "shell_smoke_wp_size1"}						; actual smoke and vision volumes

		else stuff "shell wp_size2"							; 75-95mm WP shells
			{spawn "ex_wp_size2_rock"}							; initial explosion fx
			{spawn "shell_smoke_wp_size2"}						; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell wp_size3"							; 100-149mm WP shells
			{spawn "ex_wp_size3_rock"}							; initial explosion fx
			{spawn "shell_smoke_wp_size3"}						; actual smoke and vision volumes
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell wp_size4"							; 150+mm WP shells
			{spawn "ex_wp_size4_rock"}							; initial explosion fx
			{spawn "shell_smoke_wp_size4"}						; actual smoke and vision volumes
			{spawn "grenade_at_shellhole" scale 0.8 terrain_texmod}

		else stuff "shell smoke_size1"						; 50mm Smoke shells
			{spawn "mortar_smoke"}								; initial explosion fx
			{spawn "shell_smoke"}								; actual smoke and vision volumes

		else stuff "shell smoke_size2"						; 75-95mm Smoke shells
			{spawn "ex_sm_size2_rock"}							; initial explosion fx
			{spawn "shell_smoke_size2"}							; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell smoke_size3"						; 100-149mm Smoke shells
			{spawn "ex_sm_size3_rock"}							; initial explosion fx
			{spawn "shell_smoke_size3"}							; actual smoke and vision volumes
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell smoke_size4"						; 150+mm Smoke shells
			{spawn "ex_sm_size4_rock"}							; initial explosion fx
			{spawn "shell_smoke_size4"}							; actual smoke and vision volumes
			{spawn "grenade_at_shellhole" scale 0.8 terrain_texmod}

		else stuff "bomb size1"								; 50-60kg bombs / explosives
			{spawn "ex_bomb_50kg_rock"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "bomb size2"								; 100-200kg bombs / explosives
			{spawn "ex_bomb_100kg_rock"}
			{spawn "crater_big" terrain_texmod}

		else stuff "bomb size3"								; 250kg+ bomb
			{spawn "ex_bomb_250kg_rock"}
			{spawn "crater_massive" terrain_texmod}
		else stuff "shell_minimum"
		 
		{spawn "ap_shellhole" terrain_texmod random_orientation}
		{spawn "ex_ap_minimum"}
		{if rand 0.5
			{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
		else rand 0.3
			{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
		}
		else stuff "shell fg small bomb no_crater"
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb no_crater"
      {spawn "ex_bomb_big"}
      {spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb"
      {spawn "ex_bomb_big"}
      {spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell big shell_big pierce"
        {spawn "add_land_explosion_small"}
		{spawn "cannon_add_mark_big"}
		{spawn "metal_hit_atgm"}
		{spawn "ex_ap_big"}
		{if rand 0.5
			{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
 		else rand 0.3
			{spawn "decal_spotfire_sheet_1" terrain_texmod random_orientation}
 		else rand 0.3
			{spawn "decal_spotfire_sheet_2" terrain_texmod random_orientation}
 		else rand 0.3
			{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
		}
 		else stuff "shell big fg max"
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_fg_maximum"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell big fg heat"
		{spawn "metal_hit_atgm"}
		{spawn "ex_fg_medium_art"}
		{spawn "shellhole_medium" terrain_texmod random_orientation}
		else stuff "shell fg rocket"
	  {spawn "ex_fg_small"}
	  {if rand 0.15
		{spawn "crater_small" terrain_texmod random_orientation}
		else
	    {spawn "shellhole4d3" random_orientation}
	  }
		else stuff "shell fg"
      {spawn "ex_fg_small"}
      {spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell ap rocketlauncher"
      {spawn "ex_grenade_sm"}
      {spawn "grenade_shellhole" texmod "ground" random_orientation}
		else stuff "shell ap atgm"
      {spawn "ex_fg_medium"}
      {spawn "shellhole_big" texmod "ground" random_orientation}
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
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium" random_orientation}
		else stuff "big sm"		
			{spawn "ex_arm_big"}
			{spawn "smoke_shell"}
			{spawn "smoke_cover-up_big"}
		else stuff "sm"	
			{spawn "smoke_shell"}
		else stuff "mine antitank"							; Anti-Tank Mines
			{spawn "ex_at_mine_rock"}
			{spawn "crater_tiny" terrain_texmod}

		else stuff "flare marker"							; Special Flare ammo for mission scripts
			{spawn "flare_marker"}
			{spawn "ex_bul_puff"}

		else stuff "flare artillery"						; Flare for off-map Artillery
			{spawn "flare_artillery"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
			{spawn "flare_mortar_60"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
			{spawn "flare_mortar_81"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
			{spawn "flare_artillery_105"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
			{spawn "flare_artillery_105_vt"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
			{spawn "flare_artillery_155"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
			{spawn "flare_artillery_155_vt"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
			{spawn "flare_artillery_203"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
			{spawn "flare_artillery_203_vt"}
			{spawn "ex_bul_puff"}

		else stuff "flare_usa artillery_240"				; Flare for off-map 240mm VT airburst
			{spawn "flare_artillery_240"}
			{spawn "ex_bul_puff"}

		else stuff "glass ic"								; Ampulomet glass ball
			{spawn "ex_glass_ic_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" random_orientation}
			{fire radius 2 time 20 heating 0.25}
		}
	}
}
