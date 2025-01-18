;SDL
{"road"
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
		(include "killzones.inc")
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
		else stuff "grapple_fx"								; grapple hook
			{if rain
				{spawn "ex_ap_size2"}
			else season "winter"
				{spawn "ex_ap_size2"}
			else
				{spawn "ex_ap_size2_dust"}
			}
			{spawn "ap_shellhole" scale 0.4}

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

		else stuff "mortar big ic"							; 120mm Mortar incendiary
			{spawn "ex_ic_120_rock"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" scale 1.4 random_orientation}
			{fire radius 4 time 20 heating 0.25}

		else stuff "mortar big bomb size1"					; 200 Mortar shells
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar big bomb size2"					; 170 Mortar shell
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg_rock"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "mortar big"								; 120mm Mortar shells
			{spawn "ex_he_size3_rock"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar small"							; 50-60mm Mortar shells
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
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
			{spawn "ap_shellhole" scale 0.8 terrain_texmod}

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
		else stuff "mortar"
			{spawn "add_land_explosion_small"}
			{spawn "add_fx_stone"}
			{spawn "ex_grenade_big"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else stuff "fx_40" 
			{spawn "ex_fx_25_40"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else stuff "shell_fire"
			{spawn "ex_shell_fire"}
			{spawn "shellhole_dead_car2" terrain_texmod random_orientation}
		else stuff "no_hit" 
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
		else stuff "laser_bullet"
			{spawn "ex_bul_laser"}
		else stuff "laser_bullet_red"
			{spawn "ex_bul_laser_red"}
		else stuff "laser_bullet_blue"
			{spawn "ex_bul_laser_blue"}
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
		else stuff "size3 ptrk"
			{spawn "ex_fg_small"}
			{spawn "crater_small" terrain_texmod random_orientation}
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
			{spawn "shockwave"}
			{spawn "ex_anti_big"}
			{spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb no_crater"
			{spawn "ex_bomb_big"}
			{spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb"
			{spawn "add_land_explosion"}
			{spawn "add_fx_stone"}
			{spawn "ex_bomb_big"}
			{spawn "crater_norm_road" terrain_texmod random_orientation}
		else stuff "shell fg_art big bomb"
			{spawn "add_land_explosion"}
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
		 else stuff "shell big shell_big pierce"
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_ap_big"}
			{spawn "shellhole_big_sand" terrain_texmod random_orientation}
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
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_fg_medium_art"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell fg rocket"
			{spawn "add_land_explosion"}
			{spawn "ex_fg_small"}
			{if rand 0.15
			{spawn "crater_small" terrain_texmod random_orientation}
			else
			{spawn "shellhole4d3" terrain_texmod random_orientation}
			}
		else stuff "shell fg"
			{spawn "add_land_explosion"}
			{spawn "ex_fg_small"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell ap rocketlauncher"
			{spawn "add_land_explosion_small"}
			{spawn "ex_grenade_sm"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		else stuff "c4_explosive"
			{spawn "add_land_explosion_small"}
			{spawn "add_fx_stone"}
			{spawn "fx_sled_fire"}
			{spawn "broken_prop"}
			{spawn "ex_fragment_cl"}
			{spawn "ex_fg_medium"}
			{spawn "shellhole_big" terrain_texmod random_orientation}
		else stuff "shell ap atgm"
			{spawn "add_land_explosion_small"}
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
			{spawn "add_land_explosion_small"}
			{spawn "fx_sled_fire"}
			{spawn "add_fx_stone"}
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium" random_orientation}
		else stuff "small_fg"
			{spawn "add_land_explosion_small"}
			{spawn "ex_air_norm3"}
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}
		else stuff "small_fg2"
			{spawn "add_land_explosion_small"}
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

	   else stuff "mine-cluster-mini"
		  {spawn "ex_grenade_sm"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "mine-cluster"
			{spawn "ex_grenade_big"}
			{spawn "grenade_at_shellhole" terrain_texmod}
		else stuff "dynamite"
			{spawn "add_land_explosion_small"}
			{spawn "fx_sled_fire"}
			{spawn "ex_bomb_big"}
			{spawn "shellhole_big_road" random_orientation}
		else stuff "grenade flashbang"
			{spawn "ex_grenade_flash"}
			{spawn "fire_shellhole_flash" random_orientation}
		else stuff "grenade big"
			{if tagged "expl_emitters_int"
				{spawn "rex_frag_int"}
			}
			{if tagged "expl_emitters_ext"
				{spawn "rex_frag_ext"}
			}
			{if tagged "expl_emitters_mtl"
				{spawn "rex_frag_mtl"}
			}
			{spawn "fx_sled_fire"}
			{spawn "ex_grenade_big"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else stuff "grenade mine"
			{spawn "m47_mine_proj" dir_velocity}			
			{spawn "ex_bul_big3"}
		else stuff "mine antitank"							; Anti-Tank Mines
			{spawn "ex_at_mine_rock"}
			{spawn "crater_tiny" terrain_texmod}
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
		else stuff "grenade"
			{if tagged "expl_emitters_int"
				{spawn "rex_frag_int"}
			}
			{if tagged "expl_emitters_ext"
				{spawn "rex_frag_ext"}
			}
			{if tagged "expl_emitters_mtl"
				{spawn "rex_frag_mtl"}
			}
			{spawn "fx_sled_fire"}
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		else stuff "bullet small"
			{spawn "ex_bul_sm"}
			{spawn "bullet_shellhole_small_ground"  random_orientation}
			{if rand 0.01 {spawn "piece_small_hit"}}			
 		else stuff "bullet normal"
			{spawn "bullet_shellhole_med_ground"  random_orientation}
			{spawn "ex_bul_big"}
			{if rand 0.02 {spawn "piece_small_hit"}}			
		else stuff "bullet meds"
			{spawn "bullet_shellhole_med_ground"  random_orientation}
			{spawn "ex_bul_big4"}
			{if rand 0.02 {spawn "piece_small_hit"}}			
		else stuff "bullet big"
			{if rand 0.05 {spawn "piece_small_hit"}}			
			{spawn "ex_bul_big_50"}
			{spawn "bullet_shellhole_big_ground"  random_orientation}
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
		else stuff "bullet"
		}
	}
}

{"country_road" ;village road
	(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on hit
		(include "generic.inc")
		{if effector "shell_s1"
			{start_sound "hit/casing/s1/soft/dirt/" use_position}

		else effector "shell_s2"
			{start_sound "hit/casing/s2/soft/dirt/" use_position}

		else effector "shell_s3"
			{start_sound "hit/casing/s3/soft/dirt/" use_position}

		else effector "shell_cannon"
			{spawn "spheredust_shell"}
		else effector "s5_rocket"
			{spawn "fx_sled_fire"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else effector "fx_dust"
			{if rand 0.1
				{spawn "rock_pile_00" terrain_texmod random_orientation}		
			else rand 0.1
				{spawn "rock_pile_01" terrain_texmod random_orientation}		
			else rand 0.1
				{spawn "rock_pile_02" terrain_texmod random_orientation}		
			else
				{spawn "rock_pile_03" terrain_texmod random_orientation}		
			}
			{spawn "spheredust_small"}
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
		{if min_speed 10
			{if effector "helicopter"
				{spawn "fire_shellhole_flash" random_orientation}
			}
		}		
		{if min_mass 100
			{if effector "tree"
				{spawn "tree_crush"}
			else effector "smsteel"
				{spawn "spheredust_small_short_smsteel"}
			else effector "plastic"
				{spawn "spheredust_small_short_plastic"}
			else effector "armor"
				{spawn "spheredust_small_short_arm"}
			else effector "wood"
				{spawn "spheredust_small_short_wood"}
			else
				{spawn "wound_steel_ground"}
				{spawn "spheredust_small"}
			}
		else min_mass 10
			{if effector "tree"
				{spawn "spheredust_small_short"}
			else effector "smsteel"
				{spawn "spheredust_small_short_smsteel"}
			else effector "plastic"
				{spawn "spheredust_small_short_plastic"}
			else effector "armor"
				{spawn "spheredust_small_short_arm"}
			else effector "wood"
				{spawn "spheredust_small_short_wood"}
			else 
				{if not effector "blood_part"
					{spawn "wound_steel_ground"}
					{spawn "spheredust_small_short_plastic"}
				}
			}
		}
	}
	{on detonate
		(include "killzones.inc")
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
		else stuff "grapple_fx"								; grapple hook
			{if rain
				{spawn "ex_ap_size2"}
			else season "winter"
				{spawn "ex_ap_size2"}
			else
				{spawn "ex_ap_size2_dust"}
			}
			{spawn "ap_shellhole" scale 0.4}

		else stuff "bullet_fx size1"						; Pistol Caliber
			{if rain
				{spawn "ex_bul_sm_mud"}
			else season "winter"
				{spawn "ex_bul_sm"}
			else
				{spawn "ex_bul_sm_dust"}
			}

		else stuff "bullet_fx size2 intermediate"			; Rifle Caliber
			("sonic_crack_s1")
			{if rain
				{spawn "ex_bul_big_mud"}
			else season "winter"
				{spawn "ex_bul_big"}
			else
				{spawn "ex_bul_big_dust"}
			}

		else stuff "bullet_fx size2"						; Rifle Caliber
			("sonic_crack_s2")
			{if rain
				{spawn "ex_bul_big_mud"}
			else season "winter"
				{spawn "ex_bul_big"}
			else
				{spawn "ex_bul_big_dust"}
			}

		else stuff "bullet_fx size3 api"					; Large Rifle Caliber API
			("sonic_crack_s3")
			{spawn "ex_bul_heavy_ex"}
			{if rain
				{spawn "ex_bul_heavy_mud"}
			else season "winter"
				{spawn "ex_bul_heavy"}
			else
				{spawn "ex_bul_heavy_dust"}
			}

		else stuff "bullet_fx size3"						; Large Rifle Caliber
			("sonic_crack_s3")
			{if rain
				{spawn "ex_bul_heavy_mud"}
			else season "winter"
				{spawn "ex_bul_heavy"}
			else
				{spawn "ex_bul_heavy_dust"}
			}

		else stuff "rifle_grenade_at"						; HEAT rifle Grenades
			{spawn "ex_heat"}
			{if rain
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			else
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}

		else stuff "grenade size1"							; Anti-Personnel Grenades Size 1
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

		else stuff "mortar big ic"							; 120mm Mortar incendiary
			{spawn "ex_ic_120_ground"}
			{spawn "burn_piece" dir_velocity}
			{spawn "burned_spot_round2" scale 1.4 random_orientation}
			{fire radius 4 time 20 heating 0.25}

		else stuff "mortar big bomb size1"					; 200 Mortar shells
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_50kg"}
			{spawn "crater_small" terrain_texmod}

		else stuff "mortar big bomb size2"					; 170 Mortar shell
			{spawn "shockwave_sphere"}
			{spawn "ex_bomb_100kg"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "mortar big"								; 120mm Mortar shells
			{if rain
				{spawn "ex_he_size3_mud"}
				{spawn "crater_small" texmod "mud"}
			else season "winter"
				{spawn "ex_mort_big"}
				{spawn "crater_small" terrain_texmod}
			else
				{spawn "ex_mort_big"}
				{spawn "crater_small" terrain_texmod}
			}

		else stuff "mortar small"							; 50-60mm Mortar shells
			{if rain
				{spawn "ex_grenade_size1_mud"}
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod }
			else
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}
		else stuff "mortar"
			{spawn "add_land_explosion_small"}
			{spawn "add_fx_stone"}
			{spawn "ex_grenade_big"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else stuff "fx_40" 
			{spawn "ex_fx_25_40"}
			{spawn "grenade_at_shellhole" terrain_texmod random_orientation}
		else stuff "shell_fire"
			{spawn "ex_shell_fire"}
			{spawn "shellhole_dead_car2" terrain_texmod random_orientation}
		else stuff "no_hit" 
		else stuff "laser_bullet"
			{spawn "ex_bul_laser"}
		else stuff "laser_bullet_red"
			{spawn "ex_bul_laser_red"}
		else stuff "laser_bullet_blue"
			{spawn "ex_bul_laser_blue"}
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
		else stuff "fx_ap_20_35"
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}
		else stuff "fx_fg_20_35"
			{spawn "ex_fg_minimum"}
			{spawn "shellhole_small" random_orientation}
		else stuff "fx_hg_20_35"
			{spawn "ex_air_norm3" offset 0 0 4}
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}	  
		else stuff "size3 ptrk"
			{spawn "ex_fg_small"}
			{spawn "crater_small" terrain_texmod random_orientation}
		else stuff "shell fg small bomb no_crater"
			{spawn "shockwave"}
			{spawn "ex_anti_big"}
			{spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb no_crater"
			{spawn "ex_bomb_big"}
			{spawn "shellhole7" random_orientation}
		else stuff "shell fg big bomb"
			{spawn "add_land_explosion"}
			{spawn "add_fx_stone"}
			{spawn "ex_bomb_big"}
			{spawn "crater_norm_road" terrain_texmod random_orientation}
		else stuff "shell big fg max"
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_fg_maximum"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell fg_art big bomb"
			{spawn "add_land_explosion"}
			{spawn "ex_fg_medium_art"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		 else stuff "shell big shell_big pierce"
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_ap_big"}
			{spawn "shellhole_big_sand" terrain_texmod random_orientation}
			{if rand 0.5
				{spawn "decal_spotfire_sheet_0" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_1" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_2" terrain_texmod random_orientation}
			else rand 0.3
				{spawn "decal_spotfire_sheet_3" terrain_texmod random_orientation}
			}
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
 		else stuff "shell big fg heat"
			{spawn "add_land_explosion_small"}
			{spawn "cannon_add_mark_big"}
			{spawn "metal_hit_atgm"}
			{spawn "ex_fg_medium_art"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell fg rocket"
			{spawn "add_land_explosion"}
			{spawn "ex_fg_small"}
			{if rand 0.15
			{spawn "crater_small" terrain_texmod random_orientation}
			else
			{spawn "shellhole4d3" terrain_texmod random_orientation}
			}
		else stuff "shell fg"
			{spawn "add_land_explosion"}
			{spawn "ex_fg_small"}
			{spawn "crater_norm" terrain_texmod random_orientation}
		else stuff "shell ap rocketlauncher"
			{spawn "add_land_explosion_small"}
			{spawn "ex_grenade_sm"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		else stuff "c4_explosive"
			{spawn "add_land_explosion_small"}
			{spawn "add_fx_stone"}
			{spawn "fx_sled_fire"}
			{spawn "broken_prop"}
			{spawn "ex_fragment_cl"}
			{spawn "ex_fg_medium"}
			{spawn "shellhole_big" terrain_texmod random_orientation}
		else stuff "shell ap atgm"
			{spawn "add_land_explosion_small"}
			{spawn "ex_fg_medium"}
			{spawn "shellhole_big" terrain_texmod random_orientation}
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
		else stuff "shell size2_heat_shell"					; 75-104mm cannon HEAT shells
			{if rain
				{spawn "ex_heat_size2_mud"}
				{spawn "grenade_shellhole" texmod "mud"}
			else season "winter"
				{spawn "ex_heat_size2"}
				{spawn "grenade_shellhole" terrain_texmod}
			else
				{spawn "ex_heat_size2"}
				{spawn "grenade_shellhole" terrain_texmod}
			}

		else stuff "shell size3_heat_shell"					; 105-149mm cannon HEAT shells
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "ex_heat_size3_mud"}
				{spawn "crater_tiny" texmod "mud"}
			else season "winter"
				{spawn "ex_heat_size3"}
				{spawn "crater_tiny" terrain_texmod}
			else
				{spawn "ex_heat_size3"}
				{spawn "crater_tiny" terrain_texmod}
			}

		else stuff "shell size4_heat_shell"					; 150mm cannon HEAT shells
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "ex_heat_size3_mud"}
				{spawn "crater_small" texmod "mud"}
			else season "winter"
				{spawn "ex_heat_size3"}
				{spawn "crater_small" terrain_texmod}
			else
				{spawn "ex_heat_size3"}
				{spawn "crater_small" terrain_texmod}
			}

		else stuff "rocketlauncher heat_shell size1"		; 60mm AT Rockets
			{spawn "shockwave"}
			{spawn "ex_heat"}
			{if rain
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			else
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}
			{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

		else stuff "rocketlauncher heat_shell size2"		; AT Rockets
			{spawn "shockwave"}
			{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce
			{if rain
				{spawn "ex_heat_size2_mud"}
				{spawn "grenade_shellhole" texmod "mud"}
			else season "winter"
				{spawn "ex_heat_size2"}
				{spawn "grenade_shellhole" terrain_texmod}
			else
				{spawn "ex_heat_size2"}
				{spawn "grenade_shellhole" terrain_texmod}
			}

		else stuff "heat_shell"								; All Other HEAT Shells
			{spawn "shockwave"}
			{spawn "ex_heat"}
			{if rain
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			else
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}

		else stuff "auto 15mm he"							; 15mm Autocannon HE shells
			{if rain
				{spawn "ex_he_autocannon_mud"}
			else season "winter"
				{spawn "ex_he_15mm"}
			else
				{spawn "ex_he_15mm"}
			}

		else stuff "auto size1 he"							; 20-25mm Autocannon HE shells
			{if rain
				{spawn "ex_he_autocannon_mud"}
			else season "winter"
				{spawn "ex_he_autocannon"}
			else
				{spawn "ex_he_autocannon"}
			}

		else stuff "auto size1 aphe"						; 20-25mm Autocannon APHE shells
			{if rain
				{spawn "ex_he_autocannon_mud"}
			else season "winter"
				{spawn "ex_he_autocannon"}
			else
				{spawn "ex_he_autocannon"}
			}

		else stuff "auto size1"								; 20-25mm Autocannon AP shells
			{if rain
				{spawn "ex_ap_autocannon_mud"}
			else season "winter"
				{spawn "ex_ap_autocannon"}
			else
				{spawn "ex_ap_autocannon_dust"}
			}

		else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
			{if rain
				{spawn "ex_grenade_size1_mud"}
				{spawn "grenade_shellhole" scale 0.4 texmod "mud"}
			else season "winter"
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.4 terrain_texmod}
			else
				{spawn "ex_grenade_size1"}
				{spawn "grenade_shellhole" scale 0.4 terrain_texmod}
			}

		else stuff "auto size2"								; 37-40mm Autocannon AP shells
			{if rain
				{spawn "ex_ap_size1_mud"}
			else season "winter"
				{spawn "ex_ap_size1"}
			else
				{spawn "ex_ap_size1"}
			}

		else stuff "shell size1 all_he"							; 37-74mm cannon HE shells
			{if rain
				{spawn "ex_he_size1_mud"}
				{spawn "grenade_shellhole" scale 0.6 texmod "mud"}
			else season "winter"
				{spawn "ex_he_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			else
				{spawn "ex_he_size1"}
				{spawn "grenade_shellhole" scale 0.6 terrain_texmod}
			}

		else stuff "shell size1"							; 37-74mm cannon AP shells
			{spawn "ap_shellhole" scale 0.2}
			{if rain
				{spawn "ex_ap_size1_mud"}
			else season "winter"
				{spawn "ex_ap_size1"}
			else
				{spawn "ex_ap_size1_dust"}
			}

		else stuff "shell size2 all_he"							; 75-104mm cannon HE shells
			{if rain
				{spawn "ex_he_size2_mud"}
				{spawn "crater_tiny" texmod "mud"}
			else season "winter"
				{spawn "ex_he_size2"}
				{spawn "crater_tiny" terrain_texmod}
			else
				{spawn "ex_he_size2"}
				{spawn "crater_tiny" terrain_texmod}
			}

		else stuff "shell size2"							; 75-104mm cannon AP shells
			{spawn "ap_shellhole" scale 0.4}
			{if rain
				{spawn "ex_ap_size2_mud"}
			else season "winter"
				{spawn "ex_ap_size2"}
			else
				{spawn "ex_ap_size2_dust"}
			}

		else stuff "shell size3 all_he"							; 105-149mm cannon HE shells
			{if rain
				{spawn "ex_he_size3_mud"}
				{spawn "crater_small" texmod "mud"}
			else season "winter"
				{spawn "ex_he_size3"}
				{spawn "crater_small" terrain_texmod}
			else
				{spawn "ex_he_size3"}
				{spawn "crater_small" terrain_texmod}
			}

		else stuff "shell size3"							; 105-149mm cannon AP shells
			{spawn "ap_shellhole" scale 0.6}
			{if rain
				{spawn "ex_ap_size3_mud"}
			else season "winter"
				{spawn "ex_ap_size3"}
			else
				{spawn "ex_ap_size3_dust"}
			}

		else stuff "shell size4 all_he"							; 150-169mm cannon HE shells
			{if rain
				{spawn "ex_he_size4_mud"}
				{spawn "crater_medium" texmod "mud"}
			else season "winter"
				{spawn "ex_he_size4"}
				{spawn "crater_medium" terrain_texmod}
			else
				{spawn "ex_he_size4"}
				{spawn "crater_medium" terrain_texmod}
			}

		else stuff "shell size4"							; 150-169mm cannon AP shells
			{if rain
				{spawn "ex_ap_size4_mud"}
				{spawn "crater_tiny" texmod "mud"}
			else season "winter"
				{spawn "ex_ap_size4"}
				{spawn "crater_tiny" terrain_texmod}
			else
				{spawn "ex_ap_size4_dust"}
				{spawn "crater_tiny" terrain_texmod}
			}

		else stuff "shell size5"							; 170mm+ cannon HE shells
			{spawn "ex_he_size5"}
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "crater_big" texmod "mud"}
			else
				{spawn "crater_big" terrain_texmod}
			}

		else stuff "shell size6"							; 240mm+ cannon HE shells
			{spawn "ex_he_size6"}
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "crater_massive" texmod "mud"}
			else
				{spawn "crater_massive" terrain_texmod}
			}

		else stuff "shell size7"							; 600mm cannon HE shells
			{spawn "ex_he_size7"}
			{spawn "shockwave_sphere"}
			{if rain
				{spawn "crater_massive" texmod "mud"}
			else
				{spawn "crater_massive" terrain_texmod}
			}

		else stuff "shell wp_size1"							; 50mm WP shells
			{spawn "ex_wp_size1"}								; initial explosion fx
			{spawn "shell_smoke_wp_size1"}						; actual smoke and vision volumes

		else stuff "shell wp_size2"							; 75-95mm WP shells
			{spawn "ex_wp_size2"}								; initial explosion fx
			{spawn "shell_smoke_wp_size2"}						; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell wp_size3"							; 100-149mm WP shells
			{spawn "ex_wp_size3"}								; initial explosion fx
			{spawn "shell_smoke_wp_size3"}						; actual smoke and vision volumes
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell wp_size4"							; 150+mm WP shells
			{spawn "ex_wp_size4"}								; initial explosion fx
			{spawn "shell_smoke_wp_size4"}						; actual smoke and vision volumes
			{spawn "grenade_at_shellhole" scale 0.8 terrain_texmod}

		else stuff "shell smoke_size1"						; 50mm Smoke shells
			{spawn "mortar_smoke"}								; initial explosion fx
			{spawn "shell_smoke"}								; actual smoke and vision volumes

		else stuff "shell smoke_size2"						; 75-95mm Smoke shells
			{spawn "ex_sm_size2"}								; initial explosion fx
			{spawn "shell_smoke_size2"}							; actual smoke and vision volumes
			{spawn "ap_shellhole"}

		else stuff "shell smoke_size3"						; 100-149mm Smoke shells
			{spawn "ex_sm_size3"}								; initial explosion fx
			{spawn "shell_smoke_size3"}							; actual smoke and vision volumes
			{spawn "grenade_shellhole" terrain_texmod}

		else stuff "shell smoke_size4"						; 150+mm Smoke shells
			{spawn "ex_sm_size4"}								; initial explosion fx
			{spawn "shell_smoke_size4"}							; actual smoke and vision volumes
			{spawn "grenade_at_shellhole" scale 0.8 terrain_texmod}

		else stuff "bomb size1"								; 50-60kg bombs / explosives
			{spawn "ex_bomb_50kg"}
			{spawn "crater_medium" terrain_texmod}

		else stuff "bomb size2"								; 100-200kg bombs / explosives
			{spawn "ex_bomb_100kg"}
			{spawn "crater_big" terrain_texmod}

		else stuff "bomb size3"								; 250kg+ bomb
			{spawn "ex_bomb_250kg"}
			{spawn "crater_massive" terrain_texmod}
		else stuff "mine antipersonnel"
			{spawn "add_land_explosion_small"}
			{spawn "fx_sled_fire"}
			{spawn "add_fx_stone"}
			{spawn "ex_grenade_big"}
			{spawn "shellhole_medium" random_orientation}
		else stuff "mine antitank"							; Anti-Tank Mines
			{if rain
				{spawn "ex_at_mine"}
				{spawn "crater_tiny" texmod "mud"}
			else season "winter"
				{spawn "ex_he_size3"}
				{spawn "crater_tiny" terrain_texmod}
			else
				{spawn "ex_he_size3"}
				{spawn "crater_tiny" terrain_texmod}
			}
		else stuff "small_fg"
			{spawn "add_land_explosion_small"}
			{spawn "ex_air_norm3"}
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small" random_orientation}
		else stuff "small_fg2"
			{spawn "add_land_explosion_small"}
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
		else stuff "mine-cluster-mini"
		  {spawn "ex_grenade_sm"}
		  {spawn "grenade_shellhole" terrain_texmod}
		else stuff "mine-cluster"
		  {spawn "ex_grenade_big"}
		  {spawn "grenade_at_shellhole" terrain_texmod}
		else stuff "dynamite"
			{spawn "add_land_explosion_small"}
			{spawn "fx_sled_fire"}
		  {spawn "ex_bomb_big"}
		  {spawn "shellhole_big_road" random_orientation}
		else stuff "grenade flashbang"
		  {spawn "ex_grenade_flash"}
		  {spawn "fire_shellhole_flash" random_orientation}
		else stuff "grenade big"
			{if tagged "expl_emitters_int"
				{spawn "rex_frag_int"}
			}
			{if tagged "expl_emitters_ext"
				{spawn "rex_frag_ext"}
			}
			{if tagged "expl_emitters_mtl"
				{spawn "rex_frag_mtl"}
			}
			{spawn "fx_sled_fire"}
		  {spawn "ex_grenade_big"}
		  {spawn "grenade_at_shellhole" terrain_texmod random_orientation}
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
		else stuff "grenade mine"
			{spawn "m47_mine_ground_proj" dir_velocity}			
			{spawn "ex_bul_big"}
		else stuff "grenade"
			{if tagged "expl_emitters_int"
				{spawn "rex_frag_int"}
			}
			{if tagged "expl_emitters_ext"
				{spawn "rex_frag_ext"}
			}
			{if tagged "expl_emitters_mtl"
				{spawn "rex_frag_mtl"}
			}
			{spawn "fx_sled_fire"}
			{spawn "ex_grenade_size1_rock"}
			{spawn "grenade_shellhole" terrain_texmod random_orientation}
		else stuff "bullet small"
			{spawn "ex_bul_sm"}
			{spawn "bullet_shellhole_small_ground"  random_orientation}
			{if rand 0.01 {spawn "piece_small_hit"}}			
		else stuff "bullet normal"
			{spawn "bullet_shellhole_med_ground"  random_orientation}
			{spawn "ex_bul_big"}
			{if rand 0.02 {spawn "piece_small_hit"}}			
		else stuff "bullet meds"
			{spawn "bullet_shellhole_med_ground"  random_orientation}
			{spawn "ex_bul_big4"}
			{if rand 0.02 {spawn "piece_small_hit"}}			
		else stuff "bullet big"
			{if rand 0.05 {spawn "piece_small_hit"}}			
			{spawn "ex_bul_big_50"}
			{spawn "bullet_shellhole_big_ground"  random_orientation}
		else stuff "bullet"
		}
	}
}
