{"generic"
	(include "\set\interaction_terrain\effects\effects-defines.inc")
	{on ground_hit
		{if contact_velocity 5
			{if prop "metal_auto"
				{if material "steel"
					{start_sound "hit/cars/crumple"}
				}
			}
		}
		(define "ground_fx_generic"
			{if prop "%prop"
				{if contact_velocity %speed_max
					; {if min_mass %mass_max
						; {spawn "spheredust_small_short"}
					; else min_mass %mass_min
						; {spawn "spheredust_small_short2"}
					; }
					{start_sound "hit/generic/%sound/15"}
					;{burn volume fx "rex_emitters_pipes" time 3 fake even_law}
				else contact_velocity %speed_min
					; {if min_mass %mass_max
						; {spawn "spheredust_small_short"}
					; else min_mass %mass_min
						; {spawn "spheredust_small_short2"}
					; }
					{start_sound "hit/generic/%sound/5"}
				}
			}
		)
		;                       ;props%0       			;sound%1	      	 ;speed%2-3  	             mass_min%4  	mass_max%5 		wound(6)
		("ground_fx_generic" 	prop(tank) 				sound(metal_auto)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel))
		("ground_fx_generic" 	prop(metal_auto) 		sound(none)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel))
		("ground_fx_generic" 	prop(rubberball) 		sound(rubberball)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(barrel_small) 		sound(barrel)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel))
		("ground_fx_generic" 	prop(body) 				sound(body)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(none))
		("ground_fx_generic" 	prop(box_cardboard) 	sound(box)     		  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(ceramic) 			sound(ceramic)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(bottle) 			sound(glass_bottle)   speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(none))
		("ground_fx_generic" 	prop(metal_bucket) 		sound(bucket)    	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel_small))
		("ground_fx_generic" 	prop(metal_weight) 		sound(metal_weight)   speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel))
		("ground_fx_generic" 	prop(metal_small) 		sound(metal_small)    speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel_small))
		("ground_fx_generic" 	prop(plastic) 			sound(plastic)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(tire) 				sound(rubber_tire)    speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(none))
		("ground_fx_generic" 	prop(small_tire) 		sound(rubber_tire)    speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(none))
		("ground_fx_generic" 	prop(steel_props) 		sound(steel)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel_small))
		("ground_fx_generic" 	prop(wood_props) 		sound(wood)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(tree) 				sound(wood)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(misc))
		("ground_fx_generic" 	prop(armor) 			sound(metal_weight)   speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel))
		("ground_fx_generic" 	prop(hit_small) 		sound(hit_small)   	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel_small))
		("ground_fx_generic" 	prop(hit_medium) 		sound(hit_medium)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(steel_small))
		("ground_fx_generic" 	prop(hit_small_wood) 	sound(wood)     	  speed_max(15) speed_min(2) mass_min(10) mass_max(100) wound(none))
	}
	{on contact
		{if not under_water
			{if material "steel"
				{if stuff "mortar"
					{play_sound "reverb"}

				else stuff "size4"
					{play_sound "reverb"}

				else stuff "shell small he"
					{play_sound "reverb"}

				else stuff "shell small"
					{play_sound "reverb"}

				else stuff "shell hv_ap"
					{play_sound "reverb"}

				else stuff "shell all_he"
					{play_sound "reverb"}

				else stuff "shell"

				}

			else material "wood"
				{if stuff "mortar"
					{play_sound "reverb"}

				else stuff "shell hv_ap"
					{play_sound "reverb"}

				else stuff "shell all_he"
					{play_sound "reverb"}
				}

			else material "concrete"
				{if stuff "big shell all_he"

				else stuff "shell hv_ap"
					{play_sound "reverb3"}

				else stuff "shell all_he"
					{play_sound "reverb3"}
				}
			}
		}
		{if effector "ex_molot_fire" ;class_d flame
			{burn fx "pyro_fire_fuel_contact_burn" time 6 }
			;{burn fx "ex_molot_fire_burning_particle" time 13 fake}
			;{spawn "ex_molot_fire_impact_small" }
			;{fire radius 0.7 time 2 heating 8 effector}
		}
		{if effector "ex_molot_fire_burning" ;flame class d
			{burn fx "pyro_fire_fuel_contact_burn_small" time 5 }
			;{spawn "" }
			{fire radius 0.2 time 2 heating 2 effector}
		}


		{if effector "molotov_coctail"
			{with_effector 
				{if tagged "activate"
					{volumes disable contact}
					{start_sound "hit/small/bottle"}
					{fire radius 1 time 6 heating 15}
					{spawn "ex_molot_contact" }		
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact"}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{spawn "ex_molot_fire_impact_inv" {impulse up 1 0.5 forward 2 1 rnd_dir 3 com  }}
					{delete}	
				}
			}
		}
		{if effector "40x46_ammo_armed"
			{if material "steel"
				{spawn "metal_hit_br_small" }
			else material "wood"
				{burn fx "thermite_hit" time 1 }
				{spawn "wood_hit_br_small"}
			else material "concrete"
				{spawn "stone_hit_br_small" }
			}	
		}	
		{if effector "40x46_ammo_thermite"
			{if not prop "human"
				{with_effector
					{if not tagged "burned"
						{blastwave c4 1 r0 0.5 r1 0.5}	
						{burn fx "thermite_hit3" time 12 }
						{tags add "burned"}
						{link_sound "loop"	 "detonation/thermite/loop/"				}
						{start_sound "detonation/thermite/flash/"}	
						{spawn "ex_th2" }
						{fire radius 0.3 time 12 heating 10 effector}
						{spawn "fraction_thermite" }
						{spawn "fraction_thermite" offset 0 4 0}
						{spawn "fraction_thermite" offset 0 4 0}
						{spawn "fraction_thermite" offset 0 4 0}
						{delay 1.5
							{play_sound "loop" 1}
							{delay 20
								{stop_sound "loop" }
								{start_sound "detonation/thermite/end/"}	
								{view stop	"fx_fire"}
								{view hide	"fx_fire"}	
							}
						}
					}
				}
			}
		}	
		{if effector "fraction_small"
			{if material "steel"
				{if not effector "fraction_small"
					{spawn "metal_hit_sl" }
				}
			else material "wood"
				{spawn "hay_hit_small3"}
			else material "kevlar"
				{spawn "plastic_hit_bul" }
			else material "misc"
				{spawn "plastic_hit_bul" }
			else material "steelball"
				{spawn "metal_hit_sl" }
			else material "armor"
				{spawn "metal_hit_sl" }
				{if rand 0.5
					{spawn "metal_hit_bul" }
				}
			else material "concrete"
				{spawn "stone_hit_sl" }
			else material "gypsum"
				{spawn "stone_hit_sl" }
			else material "flesh"
				{start_sound "human/hit_fraction/"}
				{spawn "bloodsparks_small" }	
			else material "kevlar_human"
				{start_sound "human/hit_fraction/"}
				{spawn "bloodsparks_small" }	
			else material "wound_glass"
				{spawn "glass_hit_sm_bullet" }
			else material "wound_glass_small"
				{spawn "glass_hit_sm_bullet" }
			else material "wound_lamp"
				{spawn "glass_hit_sm_bullet" }
			}	
		}	
		{if effector "wound_shotgun"
			{if material "steel"
				{if not effector "fraction_small"
					{spawn "metal_hit_sl" }
				}
			else material "wood"
				{spawn "hay_hit_small3"}
			else material "gypsum"
				{spawn "stone_hit_sl" }
			else material "concrete"
				{spawn "stone_hit_sl" }
				;{burn fx "wound_shotgun_r" time 8 }
			else material "wound_glass"
				{spawn "glass_hit_sm_bullet" }	
			}	
		}	
		{if effector "air_bombing_drone"
			{blastwave c4 20 r0 8 r1 8}	
			{blastwave c4 5 r0 25 r1 25}	
			{if material "steel"
				{burn fx "smoke_hit03" time 1 fake even_law}	
				{spawn "wood_hit_fg" }
			else material "flesh"
				{spawn "metal_hit_fg" }	
			else material "wood"
				{burn fx "smoke_hit03" time 4 fake even_law}	
				{spawn "wood_hit_fg_small"}
			else material "gypsum"
				{spawn "metal_hit_fg" }
			else material "concrete"
				{burn fx "smoke_hit03" time 3 fake even_law}	
				{spawn "metal_hit_fg" }
				{spawn "gypsum_crush_big" }				
			else material "wound_glass"
				{spawn "metal_hit_fg" }	
			}	
		}	
		{if effector "dragon_fire"
			{if material "steel"
				{if not effector "fraction_small"
					{burn fx "dragonfire_hit" time 2 fake even_law}	
					{spawn "metal_hit_sl" }
				}
			else material "flesh"
				{burn fx "dragonfire_hit" time 4 fake even_law}	
				{start_sound "human/hit_fraction/"}
				{spawn "bloodsparks_small" }	
			else material "wood"
				{burn fx "dragonfire_hit" time 4 fake even_law}	
				{spawn "hay_hit_small3"}
			else material "gypsum"
				{burn fx "dragonfire_hit" time 0.6 fake even_law}	
				{spawn "stone_hit_sl" }
			else material "concrete"
				{burn fx "dragonfire_hit" time 1 fake even_law}	
				{spawn "stone_hit_sl" }
				;{burn fx "wound_shotgun_r" time 8 }
			else material "wound_glass"
				{spawn "glass_hit_sm_bullet" }	
			}	
		}	
		{if prop "big_build_60t"
			{if effector "wound_blood"
				{spawn "decal_blood_fx_t60" }
			}
		}
		{if prop "big_build"
			{if effector "wound_blood"
				{spawn "decal_blood_fx" }
			else effector "fx_obstacles"
				{if rand 0.5
					{spawn "wound_engine" }
				}
			else effector "distant_small_set_expl"
				{spawn "distant_small_set_expl_invert" }
			else effector "distant_big_set_expl"
				{spawn "distant_big_set_expl_invert" }
			else effector "wound_fire"
				{spawn "wound_fire" }
			else effector "helicopter"
				{spawn "wound_steel" }
			else effector "vehicle"
				{if min_speed 5	
					{spawn "wound_steel" }
				}
			}
		}
		{if effector "thermite"
			{if not prop "human"
				{with_effector
					{if not tagged "burned"
						{blastwave c4 1 r0 0.5 r1 0.5}	
						{burn fx "thermite_hit3" time 8 }
						{tags add "burned"}
						{link_sound "loop"	 "detonation/thermite/loop/"				}
						{start_sound "detonation/thermite/flash/"}	
						{spawn "ex_th2" }
						{fire radius 0.3 time 8 heating 10 effector}
						{spawn "fraction_thermite" }
						{spawn "fraction_thermite" offset 0 4 0}
						{spawn "fraction_thermite" offset 0 4 0}
						{spawn "fraction_thermite" offset 0 4 0}
						{delay 1.5
							{play_sound "loop" 1}
							{delay 20
								{stop_sound "loop" }
								{start_sound "detonation/thermite/end/"}	
								{view stop	"fx_fire"}
								{view hide	"fx_fire"}	
							}
						}
					}
				}
			}
		}
		{if effector "cluster_mine"
			(define "contact_fx_grenade"
				{if material %0 
					{spawn "%5"}
					{if min_speed %2
						{if rand 0.3 
							{spawn "spheredust_small_short2" }
						else rand 0.1 
							{spawn "spheredust_small_short" }
						}
						{start_sound "hit/small/grenade/%1/hard/"}	
					else min_speed %3
						{start_sound "hit/small/grenade/%1/med/"}	
					else
						{start_sound "hit/small/grenade/%1/soft/"}	
					}
				}
			)
			("contact_fx_grenade" args "armor" 					armor 		15 5 2 metal_hit_bul_big_ap)
			("contact_fx_grenade" args "glass" 					glass 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "wound_glass" 			glass 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "wound_glass_small" 		glass 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "wound_lamp" 			glass 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "concrete" 				concrete 	15 5 2 stone_hit_bul_big)
			("contact_fx_grenade" args "gypsum" 				concrete 	15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "steel" 					metal 		15 5 2 metal_hit_bul_big_ap)
			("contact_fx_grenade" args "steelball" 				steelbal 	15 5 2 metal_hit_bul_big_ap)
			("contact_fx_grenade" args "wood" 					wood 		15 5 2 wood_hit_bul)
			("contact_fx_grenade" args "flesh" 					carpet 		15 5 2 hit_bul_non_lethal)
			("contact_fx_grenade" args "kevlar_human" 			carpet 		15 5 2 hit_bul_non_lethal)
			("contact_fx_grenade" args "straw" 					carpet 		15 5 2 hit_bul_non_lethal)
			("contact_fx_grenade" args "kevlar" 				carpet 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "misc" 					carpet 		15 5 2 ex_air_norm9)
			("contact_fx_grenade" args "rock" 					concrete 	15 5 2 stone_hit_bul_big)
			{with_effector 
				{stuff_detonate}
			}
		}
		{if effector "throwing"
			(define "contact_fx_grenade"
				{if material %0 
					{if min_speed %2
						{if rand 0.3 
							{spawn "spheredust_small_short2" }
						else rand 0.1 
							{spawn "spheredust_small_short" }
						}
						{start_sound "hit/small/grenade/%1/hard/"}	
					else min_speed %3
						{start_sound "hit/small/grenade/%1/med/"}	
					else min_speed %4
						{start_sound "hit/small/grenade/%1/soft/"}	
					}
				}			
			)
			("contact_fx_grenade" args "armor" 					armor 		15 5 2)
			("contact_fx_grenade" args "glass" 					glass 		15 5 2)
			("contact_fx_grenade" args "wound_glass" 			glass 		15 5 2)
			("contact_fx_grenade" args "wound_glass_small" 		glass 		15 5 2)
			("contact_fx_grenade" args "wound_lamp" 			glass 		15 5 2)
			("contact_fx_grenade" args "concrete" 				concrete 	15 5 2)
			("contact_fx_grenade" args "gypsum" 				concrete 	15 5 2)
			("contact_fx_grenade" args "steel" 					metal 		15 5 2)
			("contact_fx_grenade" args "steelball" 				steelbal 	15 5 2)
			("contact_fx_grenade" args "wood" 					wood 		15 5 2)
			("contact_fx_grenade" args "flesh" 					carpet 		15 5 2)
			("contact_fx_grenade" args "kevlar_human" 			carpet 		15 5 2)
			("contact_fx_grenade" args "straw" 					carpet 		15 5 2)
			("contact_fx_grenade" args "kevlar" 				carpet 		15 5 2)
			("contact_fx_grenade" args "misc" 					carpet 		15 5 2)
			("contact_fx_grenade" args "rock" 					concrete 	15 5 2)
		}
	}
	{on pierce
		{if material "concrete" ;on pierce
			{if stuff "bullet big"
				{spawn "stone_hit_bul_big_pierce" }				
			else stuff "bullet normal"
				{if rand 0.1
					{burn fx "pierce_bullet_smoke" time 0.7 fake}				
				}
				;{spawn "" }				
			else stuff "bullet small"
				;{spawn "" }				
			else stuff "zenite ap"
				{spawn "stone_hit_bul_big_pierce" }				
				{if rand 0.4
					{burn fx "pierce_zenite_smoke" time 2 fake}
				}
				;{spawn "" }				
			else stuff "zenite fg"
				{spawn "stone_hit_bul_big_pierce" }				
				;{spawn "" }				
				{if rand 0.8
					{burn fx "pierce_zenite_smoke" time 2 fake}
				}
			}
		}
		{if material "steel" ;on pierce
			{if stuff "bullet big"
				{if rand 0.25
					{burn fx "pierce_bullet_burn" time 1.2 fake}				
				}
				{spawn "metal_pierce_bul_big" }				
			else stuff "zenite ap"
				{if rand 0.4
					{burn fx "pierce_zenite_burn" time 2 fake}
				}
				{spawn "metal_pierce_zenite" }				
			else stuff "zenite fg"
				{spawn "metal_pierce_zenite" }				
				{if rand 0.8
					{burn fx "pierce_zenite_burn" time 2 fake}
				}
			else stuff "rocketlauncher shell ap"
				{if rand 0.4
					{burn fx "pierce_shell_burn" time 2 1 fake}				
				}
				{spawn "fraction_thermite_fast" }				
			else stuff "bullet normal ap"
				{spawn "metal_pierce_bul" }				
			else stuff "bullet normal"
				{if rand 0.1
					{burn fx "pierce_bullet_burn" time 0.7 fake}				
				}
				{spawn "metal_pierce_bul" }				
			else stuff "bullet small ap"
				{spawn "metal_pierce_bul_small_ap" }				
			else stuff "bullet small"
				{spawn "metal_pierce_bul_small" }				
			}
		}
	}
	{on bullet_hit
		{if not under_water		
			{if material "flesh"
				{if stuff "zenite sp"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_zenite"}					
				else stuff "zenite ap"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_zenite_ap"}					
				else stuff "bullet big"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_zenite_ap"}					
				else stuff "zenite fg"
					{spawn "bloodsparks_zenite"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite th"
					{fire radius 0.2 time 8 heating 25 effector}
					{spawn "bloodsparks_zenite"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fraction_thermite_fast" }
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
				else stuff "shell_minimum"
					{spawn "bloodsparks_big"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
				else stuff "mine_cluster"
					{spawn "m47_mine_proj" dir_velocity}			
					{spawn "spheredust_small_short"}
				else stuff "mortar"
					{spawn "ex_air_big"}
					{spawn "bloodsparks_big"}
				else stuff "fx_40"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_norm"}
					{spawn "bloodsparks_big"}
				else stuff "shell fg"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_big"}					
					{spawn "bloodsparks_big"}
				else stuff "shell ap atgm_launcher"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_big"}
				else stuff "shell"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "bazooka"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_big"}
					{spawn "bloodsparks_big"}
				else stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "blood_small"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s1")

				else stuff "bullet_fx size2"					;	Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s2")

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s3")

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto size2 he"
					{spawn "object_hit_fg_auto_size2"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "auto pierce"
					("sonic_crack_s4")
					{spawn "blood_small"}
					{spawn "blood_big"}	

				else stuff "auto"
					("sonic_crack_s4")
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "rifle_grenade_at"
					{spawn "ex_air_small_heat"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood"}

				else stuff "rifle_grenade"
					{spawn "ex_air_small"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood"}

				else stuff "bomb size3"
					{spawn "ex_air_he_size5"}
					{spawn "hit_he_fragments_size3"}
					{spawn "blood_big"}

				else stuff "big mortar"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "blood"}
					{spawn "ex_air_norm"}
					{spawn "hit_he_fragments_size1"}
				else stuff "rocketlauncher heat_shell size1"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size1 all_he"
					{spawn "blood"}
					{spawn "ex_air_he_size1"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "blood"}
					{spawn "ex_air_he_size2"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "size4 std_ap"
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "size4"
					("explosion_HE_s4")
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size2_heat_shell"
					{spawn "ex_air_big_heat"}
					{spawn "blood_big"}

				else stuff "shell size3_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "shell size4_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "heat_shell"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "shell all_he"
					{spawn "blood"}
					{spawn "ex_air_big"}
					{spawn "hit_he_fragments_size2"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet os"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_big"}
				else stuff "bullet sm_ic"
					{spawn "bloodsparks_small2"}
					;{spawn "ex_inc_small"}
				else stuff "laser_bullet_red"
					{spawn "bloodsparks_small2"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "bloodsparks_small2"}
					{spawn "metal_hit_laser_blue"}					
				else stuff "bullet stackable"
					{spawn "fx_piece_blood_fx" }	
					{spawn "bloodsparks_small"}
				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm VT airburst
					{spawn "flare_artillery_240"}
					{bullet_detonate}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}		
			else material "kevlar_human"
				{if stuff "zenite sp"
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "kevlar_bloodsparks_zenite"}					
				else stuff "zenite ap"
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "kevlar_bloodsparks_zenite_ap"}					
				else stuff "zenite fg"
					{spawn "kevlar_bloodsparks_zenite"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite th"
					{fire radius 0.3 time 8 heating 10 effector}
					{spawn "kevlar_bloodsparks_zenite"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fraction_thermite_fast" }
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
				else stuff "shell_minimum"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
				else stuff "mortar"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "ex_air_big"}
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "fx_40"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_norm"}
				else stuff "shell fg"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_big"}					
				else stuff "shell ap atgm_launcher"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "shell"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "bazooka"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "ex_air_big"}
				else stuff "bullet big"
					{spawn "kevlar_bloodsparks_big"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "bullet os"
					{spawn "kevlar_bloodsparks"}					
					{spawn "fx_piece_blood_fx_fast" }	
					{spawn "fx_piece_blood_fx" }	
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet sm_ic"
					{spawn "kevlar_bloodsparks_small"}					
				else stuff "laser_bullet_red"
					{spawn "bloodsparks_small2"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "bloodsparks_small2"}
					{spawn "metal_hit_laser_blue"}					
				else stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "blood_small"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s1")

				else stuff "bullet_fx size2"					;	Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s2")

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					{spawn "blood_small"}
					("sonic_crack_s3")

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto size2 he"
					{spawn "object_hit_fg_auto_size2"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "auto pierce"
					("sonic_crack_s4")
					{spawn "blood_small"}
					{spawn "blood_big"}	

				else stuff "auto"
					("sonic_crack_s4")
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "rifle_grenade_at"
					{spawn "ex_air_small_heat"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood"}

				else stuff "rifle_grenade"
					{spawn "ex_air_small"}
					{spawn "hit_he_fragments_size1"}
					{spawn "blood"}

				else stuff "bomb size3"
					{spawn "ex_air_he_size5"}
					{spawn "hit_he_fragments_size3"}
					{spawn "blood_big"}

				else stuff "big mortar"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "blood"}
					{spawn "ex_air_norm"}
					{spawn "hit_he_fragments_size1"}
				else stuff "rocketlauncher heat_shell size1"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size1 all_he"
					{spawn "blood"}
					{spawn "ex_air_he_size1"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "blood"}
					{spawn "ex_air_he_size2"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size3"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "size4 std_ap"
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "size4"
					("explosion_HE_s4")
					{spawn "blood_big"}
					{spawn "ex_air_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size2_heat_shell"
					{spawn "ex_air_big_heat"}
					{spawn "blood_big"}

				else stuff "shell size3_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "shell size4_heat_shell"
					{spawn "ex_air_heat_size3"}
					{spawn "blood_big"}	

				else stuff "heat_shell"
					{spawn "ex_heat"}
					{spawn "blood_small"}
					{spawn "blood_big"}

				else stuff "shell all_he"
					{spawn "blood"}
					{spawn "ex_air_big"}
					{spawn "hit_he_fragments_size2"}
				else stuff "bullet stackable"
					{spawn "fx_piece_blood_fx" }	
					{spawn "kevlar_bloodsparks_small"}					
				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm VT airburst
					{spawn "flare_artillery_240"}
					{bullet_detonate}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}		
			else material "ground"
				(include "killzones.inc")
				{if stuff "grenade fire"							; Molotov Grenades
					{spawn "ex_molot_ground"}

				else stuff "grapple_fx"								; grapple hook
					{if rain
						{spawn "ex_ap_size2"}
					else season "winter"
						{spawn "ex_ap_size2"}
					else
						{spawn "ex_ap_size2_dust"}
					}

				else stuff "bullet_fx size1"						; Pistol/SMG Ammo
					{if rain
						{spawn "ex_bul_sm"}
					else season "winter"
						{spawn "ex_bul_sm"}
					else
						{spawn "ex_bul_sm_dust"}
					}

				else stuff "bullet_fx size2 intermediate"
					{if rain
						{spawn "ex_bul_big"}
					else season "winter"
						{spawn "ex_bul_big"}
					else
						{spawn "ex_bul_big_dust"}
					}
					("sonic_crack_s1")

				else stuff "bullet_fx size2"						; Rifle/MG ammo
					{if rain
						{spawn "ex_bul_big"}
					else season "winter"
						{spawn "ex_bul_big"}
					else
						{spawn "ex_bul_big_dust"}
					}
					("sonic_crack_s2")

				else stuff "bullet_fx size3 api"					; AT Rifle/HMG ammo
					{if rain
						{spawn "ex_bul_heavy"}
					else season "winter"
						{spawn "ex_bul_heavy"}
					else
						{spawn "ex_bul_heavy_dust"}
					}
					{spawn "ex_bul_heavy_ex"}
					("sonic_crack_s3")

				else stuff "bullet_fx size3"						; AT Rifle/HMG ammo
					{if rain
						{spawn "ex_bul_heavy"}
					else season "winter"
						{spawn "ex_bul_heavy"}
					else
						{spawn "ex_bul_heavy_dust"}
					}
					("sonic_crack_s3")

				else stuff "rifle_grenade_at"
					{spawn "ex_heat"}
					{spawn "hit_he_fragments_size1"}
					
				else stuff "rifle_grenade"
					{if rain
						{spawn "ex_he_size1_mud"}
					else
						{spawn "ex_grenade_size1"}
					}

				else stuff "mortar big ic"							; 120mm Mortar incendiary
					{spawn "ex_ic_120_ground"}
					{spawn "burn_piece" dir_velocity}
					{spawn "burned_spot_round2" scale 1.4 random_orientation}
					{fire radius 4 time 20 heating 0.25}

				else stuff "mortar big bomb size1"					; 200 Mortar shells
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_50kg"}

				else stuff "mortar big bomb size2"					; 170 Mortar shell
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_100kg"}

				else stuff "big mortar"
					{if rain
							{spawn "ex_he_size3_mud"}
					else
							{spawn "ex_he_size3"}
					}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{if rain
							{spawn "ex_he_size1_mud"}
					else
							{spawn "ex_he_size1"}
					{spawn "hit_he_fragments_size1"}
					}

				else stuff "mortar"
					{if rain
							{spawn "ex_he_size2_mud"}
					else
							{spawn "ex_he_size2"}
					}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2_heat_shell"					; 75-104mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size2_mud"}
					else
						{spawn "ex_heat_size2"}
					}

				else stuff "shell size3_heat_shell"					; 105-149mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size3_mud"}
					else
						{spawn "ex_heat_size3"}
					}
					{spawn "shockwave_sphere"}

				else stuff "shell size4_heat_shell"					; 150mm cannon HEAT shells
					{if rain
						{spawn "ex_heat_size3_mud"}
					else
						{spawn "ex_heat_size3"}
					}
					{spawn "shockwave_sphere"}

				else stuff "rocketlauncher heat_shell size1"		; 60mm AT Rockets
					{spawn "shockwave"}
					{spawn "ex_heat"}
					{spawn "grenade_at_shellhole" terrain_texmod}

				else stuff "rocketlauncher heat_shell size2"		; AT Rockets
					{spawn "shockwave"}
					{if rain
						{spawn "ex_heat_size2_mud"}
						{spawn "grenade_at_shellhole" texmod "mud"}
					else
						{spawn "ex_heat_size2"}
						{spawn "grenade_at_shellhole" terrain_texmod}
					}

				else stuff "heat_shell"								; All HEAT Shells / AT Rockets
					{spawn "ex_heat"}
					{spawn "hit_he_fragments_size1"}

				else stuff "auto 15mm he"							; 15mm Autocannon HE shells
					{spawn "ex_he_autocannon_15mm"}

				else stuff "auto size1 he"							; 20-25mm Autocannon HE shells
					{if rain
						{spawn "ex_he_autocannon_mud"}
					else
						{spawn "ex_he_autocannon"}
					}

				else stuff "auto size1"								; 20-25mm Autocannon AP shells
					{if rain	
						{spawn "ex_ap_autocannon_mud"}
					else
						{spawn "ex_ap_autocannon"}
					}

				else stuff "auto size2 he"							; 37-40mm Autocannon HE shells
					{if rain
						{spawn "ex_grenade_size1_mud"}
					else
						{spawn "ex_grenade_size1"}
					}

				else stuff "auto size2"								; 37-40mm Autocannon AP shells
					{if rain
						{spawn "ex_ap_size1_mud"}
					else
						{spawn "ex_ap_size1"}
					}

				else stuff "shell size1 all_he"							; 37-74mm cannon HE shells
					{if rain
							{spawn "ex_he_size1_mud"}
					else
							{spawn "ex_he_size1"}
					}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size1"							; 37-74mm cannon AP shells
					{if rain
						{spawn "ex_ap_size1_mud"}
					else
						{spawn "ex_ap_size1"}
					}

				else stuff "shell size2 all_he"							; 75-104mm cannon HE shells
					{if rain
							{spawn "ex_he_size2_mud"}
					else
							{spawn "ex_he_size2"}
					}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2"							; 75-104mm cannon AP shells
					{if rain
						{spawn "ex_ap_size2_mud"}
					else
						{spawn "ex_ap_size2"}
					}

				else stuff "shell size3 all_he"							; 105-149mm cannon HE shells
					{if rain
							{spawn "ex_he_size3_mud"}
					else
							{spawn "ex_he_size3"}
					}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size3"							; 105-149mm cannon AP shells
					{if rain
						{spawn "ex_ap_size3_mud"}
					else
						{spawn "ex_ap_size3"}
					}

				else stuff "shell size4 all_he"							; 150-169mm cannon HE shells
					{spawn "ex_he_size4"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size4"							; 150-169mm cannon AP shells
					{if rain
						{spawn "ex_ap_size4_mud"}
					else
						{spawn "ex_ap_size4"}
					}

				else stuff "shell size5"							; 170mm+ cannon HE shells
					{spawn "ex_he_size5"}
					
				else stuff "shell size6"							; 240mm+ cannon HE shells
					{spawn "ex_he_size6"}

				else stuff "shell wp_size1"							; 50mm WP shells
					{spawn "ex_wp_size1"}									; initial explosion fx
					{spawn "shell_smoke_wp_size1"}							; actual smoke and vision volumes

				else stuff "shell wp_size2"							; 75-95mm WP shells
					{spawn "ex_wp_size2"}									; initial explosion fx
					{spawn "shell_smoke_wp_size2"}							; actual smoke and vision volumes

				else stuff "shell wp_size3"							; Large WP shells
					{spawn "ex_wp_size3"}									; initial explosion fx
					{spawn "shell_smoke_wp_size3"}							; actual smoke and vision volumes
					
				else stuff "shell wp_size4"							; 100-149mm WP shells
					{spawn "ex_wp_size4"}									; initial explosion fx
					{spawn "shell_smoke_wp_size4"}							; actual smoke and vision volumes

				else stuff "shell smoke_size1"						; 50mm Smoke shells
					{spawn "ex_sm_size2"}									; initial explosion fx
					{spawn "shell_smoke_size2"}								; actual smoke and vision volumes
					
				else stuff "shell smoke_size2"						; 75-95mm Smoke shells
					{spawn "ex_sm_size2"}									; initial explosion fx
					{spawn "shell_smoke_size2"}								; actual smoke and vision volumes

				else stuff "shell smoke_size3"						; 100-149mm Smoke shells
					{spawn "ex_sm_size3"}									; initial explosion fx
					{spawn "shell_smoke_size3"}								; actual smoke and vision volumes
					
				else stuff "shell smoke_size4"						; 150+mm Smoke shells
					{spawn "ex_sm_size4"}									; initial explosion fx
					{spawn "shell_smoke_size4"}								; actual smoke and vision volumes

				else stuff "bomb size1"								; 50-60kg bombs / explosives
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_50kg"}

				else stuff "bomb size2"								; 100-200kg bombs / explosives
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_100kg"}

				else stuff "bomb size3"								; 250kg+ bomb
					{spawn "shockwave_sphere"}
					{spawn "ex_bomb_250kg"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts
					{spawn "flare_marker"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "spheredust_small"}
					{bullet_detonate}

				else stuff "glass ic"								; Ampulomet glass ball
					{spawn "ex_glass_ic_ground"}
					{spawn "burn_piece" dir_velocity}
					{spawn "burned_spot_round2" random_orientation}
					{fire radius 2 time 20 heating 0.25}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "steel" ;on bullet_hit
				(include "killzones.inc")
				{if stuff "os"
					{if "car"
						{spawn "ex_air_norm6"}
						{spawn "metal_hit_bul_ap"}
					else "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else "armor"
						{spawn "ex_air_norm6"}
						{spawn "metal_hit_bul_arm_ap"}
					else			
						{spawn "ex_air_norm6"}
						{spawn "metal_hit_bul_ap"}
					}	
				else stuff "sm_ic"
					{if "car"
						{spawn "ex_inc_small"}
						{spawn "metal_hit_bul_car"}
						{if rand 0.02
							{spawn "metal_hit_bul_rand00"}
						else rand 0.02
							{spawn "metal_hit_bul_rand01"}
						else rand 0.01
							{spawn "metal_hit_bul_rand02"}
						}
					else "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else "armor"
						{spawn "ex_inc_small"}					
						{spawn "metal_hit_bul_arm"}
						{if rand 0.2
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.03
							{spawn "metal_hit_bul_rand02"}
						}
					else	
						{spawn "ex_inc_small"}					
						{spawn "metal_hit_bul"}
					}	
				else stuff "zenite sp" ;on bullet_hit
					{if rand 0.35
						{spawn "damage_shock_micro"}
					}
					{spawn "metal_hit_bul_zenite"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite cs"
					{if rand 0.5
						{spawn "damage_shock_micro"}
					}
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "metal_hit_zenite_cs"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite fg"
					{if rand 0.6
						{spawn "damage_shock_micro_fg"}
					}
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "ex_air_norm7"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite th"
					{fire radius 0.3 time 8 heating 25 effector}
					{start_sound "detonation/phosphorus_start/"}
					{spawn "fraction_thermite_fast" }
					{bullet_detonate}
					{burn fx "thermite_hit" time 10 fake}
					{spawn "ex_air_norm7"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				 else stuff "40mm_fg" ;og7v
					{spawn "fraction_spawn"}		
					{spawn "metal_hit_fg"}			
				 else stuff "75mm"
					{spawn "metal_hit_br"}			
				 else stuff "85mm"
					{spawn "metal_hit_br"}			
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "metal_hit_zenite_cs"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "105_th" ; thermite
					{spawn "metal_hit_br"}			
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_spawn"}		
					{fire radius 2 time 9 heating 20 follow}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}
					{burn fx "thermite_hit3" time 8 }
					{spawn "ex_air_norm7"}					
				else stuff "fx_40"
					{spawn "ex_air_norm"}
				else stuff "laser_bullet_red"
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "metal_hit_laser_blue"}					
				else stuff "mine_cluster"
					{spawn "m47_mine_proj" dir_velocity}			
					{spawn "spheredust_small_short"}
				else stuff "grenade fg"
					{spawn "metal_hit_fg"}
				else stuff "mortar"
					{spawn "metal_hit_br"}
				else stuff "zenite"
					{if rand 0.2
						{spawn "damage_shock_micro"}
					}
					{spawn "metal_hit_bul_ap"}
					{spawn "ex_air_sm"}
				else stuff "shell_minimum"
					{spawn "metal_hit_fg_small"}					
				else stuff "shell fg small"
					{spawn "metal_hit_fg"}
				else stuff "shell small"
					{spawn "metal_hit_br_small"}
				else stuff "shell fg"
					{spawn "metal_hit_fg"}
				else stuff "shell ap atgm_launcher"				
					{if volume "blocked_volume"
						{spawn "noview"}
					else
						{spawn "cannon_add_mark_big"}
						{spawn "metal_hit_atgm"}
					}
				else stuff "shell"
					{spawn "metal_hit_br"}
				else stuff "rocketlauncher shell ap"
					{spawn "metal_hit_br"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet big"		
					{if rand 0.01
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.1
						{spawn "damage_shock_micro"}
					}
					{if rand 0.03
						{spawn "metal_hit_loud"}
					}
					{if rand 0.006
						{spawn "metal_hit_loud_dust"}
					}
					{if volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else "armor"
						{spawn "metal_hit_bul_arm"}
						{if rand 0.3
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
							{spawn "metal_hit_bul_add"}
						else rand 0.03
							{spawn "metal_hit_bul_rand02"}
						}
					else 	 
						{spawn "metal_hit_bul_big"}
					}					
				else stuff "bullet big ap"		
					{if rand 0.01
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.1
						{spawn "damage_shock_micro"}
					}
					{if rand 0.03
						{spawn "metal_hit_loud"}
					}
					{if rand 0.06
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.006
						{spawn "metal_hit_loud_dust"}
					}
					{if volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else "armor"
						{spawn "metal_hit_bul_arm"}
						{if rand 0.3
							{spawn "metal_hit_bul_rand00"}
						else rand 0.2
							{spawn "metal_hit_bul_rand01"}
							{spawn "metal_hit_bul_add"}
						else rand 0.03
							{spawn "metal_hit_bul_rand02"}
						}
					else 	 
						{spawn "metal_hit_bul_big_ap"}
					}					
				else stuff "bullet normal"
					
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
					{if volume "set_glass"
						{spawn "glass_hit_sm_bullet"}						
					else volume "glass"
						{spawn "glass_hit_sm_bullet"}	
					else volume "sheet"
						{spawn "metal_hit_bul_car"}
					else volume "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else volume "cartoon"
						{spawn "plastic_hit_bul"}
					else volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "plastic"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "concrete"			
						{spawn "stone_hit_bul"}
						{spawn "ex_air_sm"}						
						{if rand 0.4
							{spawn "wound_small_stone00"}
							{if rand 0.2
								{spawn "wound_fx_stone00"}
							}
						else
							{spawn "wound_small_stone01"}
							{if rand 0.2
								{spawn "wound_fx_stone01"}
							}
						}
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else prop "fraction"
					else "armor"
						{spawn "metal_hit_bul_arm"}
						{if rand 0.2
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
							{spawn "metal_hit_bul_add"}
						else rand 0.03
							{spawn "metal_hit_bul_rand02"}
						}
					else 	 
						{spawn "metal_hit_bul_nm"}
					}					
				else stuff "bullet normal ap"		
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
					{if volume "set_glass"
						{spawn "glass_hit_sm_bullet"}						
					else volume "glass"
						{spawn "glass_hit_sm_bullet"}	
					else volume "sheet"
						{spawn "metal_hit_bul_car"}
					else volume "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else volume "cartoon"
						{spawn "plastic_hit_bul"}
					else volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "plastic"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "concrete"			
						{spawn "stone_hit_bul"}
						{spawn "ex_air_sm"}						
						{if rand 0.4
							{spawn "wound_small_stone00"}
							{if rand 0.2
								{spawn "wound_fx_stone00"}
							}
						else
							{spawn "wound_small_stone01"}
							{if rand 0.2
								{spawn "wound_fx_stone01"}
							}
						}
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else prop "fraction"
					else "armor"
						{spawn "metal_hit_bul_arm"}
						{if rand 0.2
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
							{spawn "metal_hit_bul_add"}
						else rand 0.03
							{spawn "metal_hit_bul_rand02"}
						}
					else 	 
						{spawn "metal_hit_bul_nm_ap"}
					}					
				else stuff "bullet small ap"		
					{if volume "set_glass"
						{spawn "glass_hit_sm_bullet"}						
					else volume "glass"
						{spawn "glass_hit_sm_bullet"}	
					else volume "sheet"
						{spawn "metal_hit_bul_car"}
					else volume "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else volume "cartoon"
						{spawn "plastic_hit_bul"}
					else volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "plastic"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "concrete"			
						{spawn "stone_hit_bul"}
						{spawn "ex_air_sm"}						
						{if rand 0.2
							{spawn "wound_small_stone00"}
							{if rand 0.1
								{spawn "wound_fx_stone00"}
							}
						else
							{spawn "wound_small_stone01"}
							{if rand 0.1
								{spawn "wound_fx_stone01"}
							}
						}
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else prop "fraction"
					else 	 
						{spawn "metal_hit_bul_sm_ap"}
					}					
				else stuff "bullet small"		
					{if volume "set_glass"
						{spawn "glass_hit_sm_bullet"}						
					else volume "glass"
						{spawn "glass_hit_sm_bullet"}	
					else volume "sheet"
						{spawn "metal_hit_bul_car"}
					else volume "smsteel"
						{spawn "metal_hit_bul_smsteel"}
					else volume "cartoon"
						{spawn "plastic_hit_bul"}
					else volume "wheel"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "plastic"
						{spawn "plastic_hit_bul"}
						{burn fx "smoke_heat_barrel" time 6 fake}						
					else volume "concrete"			
						{spawn "stone_hit_bul"}
						{spawn "ex_air_sm"}						
						{if rand 0.2
							{spawn "wound_small_stone00"}
							{if rand 0.1
								{spawn "wound_fx_stone00"}
							}
						else
							{spawn "wound_small_stone01"}
							{if rand 0.1
								{spawn "wound_fx_stone01"}
							}
						}
					}
					{if "car"
						{if rand 0.1
							{spawn "metal_hit_bul_rand00"}
						else rand 0.1
							{spawn "metal_hit_bul_rand01"}
						else rand 0.1
							{spawn "metal_hit_bul_rand02"}
						}
						{spawn "metal_hit_bul_car"}
					else prop "fraction"
					else 	 
						{spawn "metal_hit_bul_sm"}
					}					
				else stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size2 api"				;	Rifle Caliber - API
					("sonic_crack_s2")
					{spawn "metal_hit_bul_api"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "metal_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber - API
					("sonic_crack_s3")
					{spawn "metal_hit_bul_at"}

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "metal_hit_bul_heavy"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"	
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "metal_hit_br_small"}

				else stuff "bomb size3"
				 	{spawn "metal_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar_smoke"
					{spawn "metal_hit_br"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_heat_riflegrenade"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "metal_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "metal_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "metal_hit_fg_auto"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "auto"
					{spawn "metal_hit_bul_zenite"}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size1 hv_ap"
					{spawn "metal_hit_br_small_apcr"}

				else stuff "size2 hv_ap"
					{spawn "metal_hit_br_apcr"}

				else stuff "size3 hv_ap"
					{spawn "metal_hit_br_big_apcr"}

				else stuff "size4 hv_ap"
					{spawn "metal_hit_br_big_apcr"}

				else stuff "shell size1 all_he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "metal_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size1 hasfiller"
					{spawn "metal_hit_br_small"}

				else stuff "shell size2 hasfiller"
					{spawn "metal_hit_br"}

				else stuff "shell size3 hasfiller"
					{spawn "metal_hit_br_big"}

				else stuff "shell size4 hasfiller"
					{spawn "metal_hit_br_big"}

				else stuff "shell size1"
					{spawn "metal_hit_br_small"}

				else stuff "shell size2"
					{spawn "metal_hit_br"}

				else stuff "shell size3"
					{spawn "metal_hit_br_big"}

				else stuff "shell size4"
					{spawn "metal_hit_br_big"}

				else stuff "shell small"
					{spawn "metal_hit_br_small"}

				else stuff "shell zenite"
					{spawn "metal_hit_bul_zenite"}

				else material "steelball"
					{spawn "metal_hit_bul"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "metal_hit_bul"}
					{bullet_detonate}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "armor"
				{if stuff "os"
					{spawn "ex_air_norm6"}
					{spawn "metal_hit_bul_arm_ap"}
					{if rand 0.2
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}	
				else stuff "sm_ic"
					{spawn "ex_inc_small"}					
					{spawn "metal_hit_bul_arm"}
					{if rand 0.2
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}	
				else stuff "zenite sp"
					{if rand 0.35
						{spawn "damage_shock_micro"}
					}
					{spawn "metal_hit_bul_zenite"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite cs"
					{if rand 0.5
						{spawn "damage_shock_micro"}
					}
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "metal_hit_zenite_cs"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite fg"
					{if rand 0.6
						{spawn "damage_shock_micro_fg"}
					}
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "ex_air_norm7"}					
					{blastwave c4 1 r0 0.5 r1 0.5}	
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "zenite th"
					{blastwave c4 1 r0 0.5 r1 0.5}	
					{fire radius 0.3 time 8 heating 25 effector}
					{start_sound "detonation/phosphorus_start/"}
					{spawn "fraction_thermite_fast" }
					{bullet_detonate}
					{burn fx "thermite_hit" time 10 fake}
					{spawn "ex_air_norm7"}					
					{if rand 0.2
						{spawn "metal_hit_loud"}
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				 else stuff "40mm_fg" ;og7v
					{spawn "fraction_spawn"}		
					{spawn "metal_hit_fg"}			
				 else stuff "75mm"
					{spawn "metal_hit_br"}			
				 else stuff "85mm"
					{spawn "metal_hit_br"}			
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "metal_hit_zenite_cs"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "105_th" ; thermite armor
					{spawn "metal_hit_br"}			
					{spawn "ex_air_norm7"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_spawn"}		
					{fire radius 1 time 8 heating 10 follow}
					{start_sound "detonation/phosphorus_start/"}
					;{bullet_detonate}
					{burn fx "thermite_hit3" time 8 }
				else stuff "fx_40"
					{spawn "ex_air_norm"}
				else stuff "laser_bullet_red"
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "metal_hit_laser_blue"}					
				else stuff "grenade fg"
					{spawn "metal_hit_fg"}
				else stuff "mortar"
					{spawn "metal_hit_br"}
				else stuff "shell_minimum"
					{spawn "metal_hit_fg_small"}					
				else stuff "shell fg small"
					{spawn "metal_hit_fg"}
				else stuff "shell small"
					{spawn "metal_hit_br_small"}
				else stuff "shell fg"
					{spawn "metal_hit_fg"}
				else stuff "shell ap atgm_launcher"
					{spawn "metal_hit_atgm"}
				else stuff "shell"
					{spawn "metal_hit_br"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet small ap"		
					{spawn "metal_hit_bul_sm_ap"}
					{if rand 0.03
						{spawn "damage_shock_micro"}
					}
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
				else stuff "bullet small"		
					{spawn "metal_hit_bul_sm"}
					{if rand 0.03
						{spawn "damage_shock_micro"}
					}
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
				else stuff "bullet big ap"		
					{if rand 0.3
						{spawn "metal_hit_bul_rand00"}
					else rand 0.2
						{spawn "metal_hit_bul_rand01"}
						{spawn "metal_hit_bul_add"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
					{if rand 0.01
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.1
						{spawn "damage_shock_micro"}
					}
					{if rand 0.03
						{spawn "metal_hit_loud"}
					}
					{if rand 0.06
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.006
						{spawn "metal_hit_loud_dust"}
					}
					{spawn "metal_hit_bul_big_ap"}
				else stuff "bullet big"		
					{if rand 0.3
						{spawn "metal_hit_bul_rand00"}
					else rand 0.2
						{spawn "metal_hit_bul_rand01"}
						{spawn "metal_hit_bul_add"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
					{if rand 0.01
						{spawn "metal_hit_trace_burn"}
					}
					{if rand 0.1
						{spawn "damage_shock_micro"}
					}
					{if rand 0.03
						{spawn "metal_hit_loud"}
					}
					{if rand 0.006
						{spawn "metal_hit_loud_dust"}
					}
					{spawn "metal_hit_bul_big"}
				else stuff "meds"		
					{if rand 0.09
						{spawn "metal_hit_loud"}
					}
					{spawn "metal_hit_bul_arm"}
					{if rand 0.2
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
						{spawn "metal_hit_bul_add"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
				else stuff "bullet normal ap"		
					{if rand 0.2
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
						{spawn "metal_hit_bul_add"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
					{spawn "metal_hit_bul_nm_ap"}
				else stuff "bullet normal"		
					{if rand 0.2
						{spawn "metal_hit_bul_rand00"}
					else rand 0.1
						{spawn "metal_hit_bul_rand01"}
						{spawn "metal_hit_bul_add"}
					else rand 0.03
						{spawn "metal_hit_bul_rand02"}
					}
					{if rand 0.01
						{spawn "metal_hit_loud"}
					}
					{if rand 0.001
						{spawn "metal_hit_loud_dust"}
					}
					{spawn "metal_hit_bul_nm"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "steelball"
				{if not stuff "no_hit"		
					{spawn "metal_hit_bul"}
				}
			else material "wood"
				(include "killzones.inc")
				{if stuff  "mortar"
					{spawn "wood_hit_fg"}
				else stuff "zenite fg"
					{spawn "wood_hit_fg_small"}
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite cs"
					{spawn "wood_hit_small"}
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite th"
					{spawn "fraction_thermite_fast" }
					{spawn "wood_hit_small"}
					{fire radius 0.3 time 8 heating 30 effector}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}
					{burn fx "thermite_hit" time 10 fake}
					{spawn "ex_air_norm7"}					
				else stuff "zenite"
					{spawn "wood_hit_small"}
					{spawn "ex_air_norm7"}	
				 else stuff "40mm_grenade" ;og7v
					{spawn "wood_hit_fg_small"}			
					{spawn "fraction_spawn"}		
					{bullet_detonate}			
				 else stuff "rocketlauncher 40mm_fg" ;og7v
					{spawn "wood_hit_fg_small"}			
					{spawn "fraction_spawn"}		
					{bullet_detonate}			
				 else stuff "rocketlauncher 75mm"
					{spawn "wood_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 85mm"
					{spawn "wood_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "wood_hit_fg_small"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "rocketlauncher 105_th" ; thermite
					{bullet_detonate}			
					{if volume "window"
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fx_piece_fire" }
					else
						{burn fx "thermite_hit3" time 8 }
					}
					{spawn "wood_hit_fg"}			
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 0.5 time 7 heating 10 follow}
					{start_sound "detonation/phosphorus_start/"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet os"
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}
				else stuff "laser_bullet_red"
					{spawn "wood_hit_bul"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "wood_hit_bul"}
					{spawn "metal_hit_laser_blue"}
				else stuff "shell big ap"
					{spawn "wood_hit_br"}
				else stuff "shell big fg"
					{spawn "wood_hit_fg_big"}
				else stuff "shell fg"
					{spawn "wood_hit_fg"}
				else stuff "shell ap atgm_launcher"
					{spawn "wood_hit_fg_big"}
				else stuff "shell small"
					{spawn "wood_hit_fg_small"}
				else stuff "shell"
					{spawn "wood_hit_br"}
				else stuff "bullet big"		
					{burn fx "smoke_hit01" time 1 }
					{spawn "wood_hit_bul"}
				else stuff "bullet sm_ic"
					{spawn "ex_inc_small"}
				else stuff "bullet stackable"
					{spawn "wood_hit_bul"}
				else stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "wood_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "wood_hit_br"}

				else stuff "bomb size3"
					{spawn "wood_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_heat"}
					;{spawn "wood_hit_fg"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "metal_hit_heat_riflegrenade"}
					;{spawn "wood_hit_fg_small"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "metal_hit_heat"}
					;{spawn "wood_hit_fg"}

				else stuff "shell size3_heat_shell"
					{spawn "metal_hit_heat_big"}
					;{spawn "wood_hit_fg_big"}

				else stuff "shell size4_heat_shell"
					{spawn "metal_hit_heat_big"}
					;{spawn "wood_hit_fg_big"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto he size1"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto he size2"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto"
					{spawn "wood_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "wood_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size5"}

				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size6"}

				else stuff "shell small"
					{spawn "ex_air_sm"}
					{spawn "wood_hit_br"}

				else stuff "shell all_he"
					{spawn "ex_mort_big_wood"}

				else stuff "shell"
					{spawn "wood_hit_br"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "plastic"
				{if stuff "bullet os"
					{spawn "ex_air_sm"}
					{spawn "plastic_hit_bul"}
				else stuff "zenite sp"
					{spawn "ex_air_norm7"}					
				 else stuff "rocketlauncher 40mm_fg" ;og7v
					{spawn "wood_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 75mm"
					{spawn "wood_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 85mm"
					{spawn "wood_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "wood_hit_br_small"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "rocketlauncher 105_th" ; thermite
					{if volume "window"
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fx_piece_fire" }
					else
						{burn fx "thermite_hit3" time 7 }
					}
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "wood_hit_br_small"}			
					{fire radius 0.2 time 7 heating 8 follow}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}			
					{spawn "ex_air_norm7"}					
				else stuff "zenite fg"
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
					{spawn "fx_piece_fire" }
				else stuff "laser_bullet_red"
					{spawn "plastic_hit_bul"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "plastic_hit_bul"}
					{spawn "metal_hit_laser_blue"}					
				else stuff "mortar"
					{spawn "plastic_hit_bul"}
				else stuff "zenite"
					{spawn "plastic_hit_bul"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet big"		
					{burn fx "smoke_hit01" time 1 }
					{spawn "plastic_hit_bul"}
				else stuff "bullet stackable"
					{spawn "plastic_hit_bul"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "gypsum"
				{if stuff "bullet os"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "zenite sp"
					{spawn "stone_hit_zenite"}
				else stuff "zenite cs"
					{spawn "stone_hit_zenite"}
					{spawn "fraction_set" }
				else stuff "zenite fg"
					{spawn "stone_hit_zenite"}
					{spawn "ex_air_norm7"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
				else stuff "zenite th"
					{if not volume "window"
						{fire radius 0.2 time 7 heating 5 follow}
						{start_sound "detonation/phosphorus_start/"}
						{bullet_detonate}
						{spawn "fraction_thermite_fast" }
						{spawn "stone_hit_zenite"}
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{burn fx "thermite_hit" time 10 fake}
						{if rand 0.3
							{burn fx "wound_fx_stone00" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone02" time 3 }
						}
					else
						{spawn "ex_air_norm7"}					
						{fire radius 0.2 time 7 heating 1}
						{burn fx "thermite_hit" time 0.3 fake}				
					}
					{if "not_destroy"
						{fire radius 0.2 time 7 heating 3 follow}
						{start_sound "detonation/phosphorus_start/"}
						{bullet_detonate}
						{burn fx "thermite_hit" time 10 fake}
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
				else stuff "fx_40"
					{spawn "wound_stone_shell40"}
					{spawn "stone_hit_br_small"}
					{spawn "ex_add_fx40"}
				 else stuff "rocketlauncher 40mm_fg" ;og7v
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 75mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 85mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "stone_hit_br_small"}					
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
				 else stuff "rocketlauncher 105_th" ; thermite
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "stone_hit_br_small"}			
					{fire radius 0.2 time 7 heating 6 follow}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}			
					{spawn "ex_air_norm7"}					
				else stuff "bullet sm_ic"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
					{spawn "ex_inc_small"}
				else stuff "grenade flashbang"
					{spawn "ex_grenade_flash"}
				else stuff "grenade fg"
					{spawn "stone_hit_br_small"}
				else stuff "laser_bullet_red"
					{spawn "stone_hit_bul"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "stone_hit_bul"}
					{spawn "metal_hit_laser_blue"}					
				else stuff "zenite"
					{spawn "stone_hit_zenite"}
				else stuff "big shell fg"
				 	{spawn	"stone_hit_br_big"}
				else stuff "shell ap atgm_launcher"
					{spawn "stone_hit_br_big"}
				else stuff "shell ap"
					{spawn "stone_hit_br_small"}
					{spawn "piece_crush_big"}
					{spawn "ex_add_fx40"}
				else stuff "shell small"
				 	{spawn	"stone_hit_br_small"}
				else stuff "bullet big "
					{spawn "stone_hit_bul_big"}
				else stuff "bullet small"
					{spawn	"stone_hit_bul_small"}
				else stuff "bullet stackable"
					{spawn	"stone_hit_bul"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "concrete"
				(include "killzones.inc")
				{if stuff "bullet os"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
					{if rand 0.2
						{start_sound "detonation/crack_bullet/med/"}
					}
				else stuff "zenite sp"
					{if not volume "window"
						{if rand 0.2
							{spawn "damage_shock_micro"}
						}
						{if rand 0.3
							{burn fx "wound_fx_stone00" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone02" time 3 }
						}
					}
					{if "not_destroy"
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
					{spawn "stone_hit_zenite"}
					{if rand 0.2
						{spawn "pierce_zenite_smoke"}
						{start_sound "detonation/crack_bullet/med/"}
					}
				else stuff "zenite cs"
					{if rand 0.3
						{spawn "damage_shock_micro"}
					}
					{if "not_destroy"
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
					{spawn "stone_hit_zenite"}
					{spawn "fraction_set" }
					{if rand 0.1
						{spawn "pierce_zenite_smoke"}
						{start_sound "detonation/crack_bullet/med/"}
					}
				else stuff "zenite fg"
					{if not volume "window"
						{if rand 0.5
							{spawn "damage_shock_micro"}
						}
						{if rand 0.3
							{burn fx "wound_fx_stone00" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone02" time 3 }
						}
					}
					{if "not_destroy"
						{burn fx "thermite_hit" time 0.5 fake}
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
					{if rand 0.4
						{spawn "pierce_zenite_smoke"}
						{start_sound "detonation/crack_bullet/med/"}
					}
					{spawn "stone_hit_zenite"}
					{spawn "ex_air_norm7"}					
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fraction_set" }
					{spawn "fx_piece_fire" }
				else stuff "zenite th"
					{if not volume "window"
						{fire radius 0.2 time 7 heating 1}
						{start_sound "detonation/phosphorus_start/"}
						{bullet_detonate}
						{spawn "fraction_thermite_fast" }
						{spawn "stone_hit_zenite"}
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{burn fx "thermite_hit" time 10 fake}
						{if rand 0.3
							{burn fx "wound_fx_stone00" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone02" time 3 }
						}
					else
						{spawn "ex_air_norm7"}					
						{fire radius 0.2 time 7 heating 1}
						{burn fx "thermite_hit" time 0.3 fake}				
					}
					{if "not_destroy"
						{fire radius 0.2 time 7 heating 1}
						{start_sound "detonation/phosphorus_start/"}
						{bullet_detonate}
						{burn fx "thermite_hit" time 10 fake}
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
				else stuff "fx_40"
					{if "not_destroy"
						{if rand 0.4
							{spawn "wound_fx_stone01"}
						else
							{spawn "wound_fx_stone00"}
						}
					}
					{spawn "wound_stone_shell40"}
					{spawn "stone_hit_br_small"}
					{spawn "ex_add_fx40"}
				else stuff "mortar"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 40mm_fg" ;og7v
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 75mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 85mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "rocketlauncher 105_th" ; thermite
					{if volume "window"
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fx_piece_fire" }
					else
						{burn fx "thermite_hit3" time 8 }
					}
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "stone_hit_br_small"}			
					{fire radius 0.2 time 7 heating 1}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}			
					{spawn "ex_air_norm7"}					
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "bullet sm_ic"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
					{spawn "ex_inc_small"}
				else stuff "grenade flashbang"
					{spawn "ex_grenade_flash"}
				else stuff "grenade fg"
					{spawn "stone_hit_br_small"}
				else stuff "laser_bullet_red"
					{spawn "stone_hit_bul"}
					{spawn "metal_hit_laser_red"}
				else stuff "laser_bullet_blue"
					{spawn "stone_hit_bul"}
					{spawn "metal_hit_laser_blue"}					
				else stuff "zenite"
					{spawn "stone_hit_zenite"}
				else stuff "big shell fg"
				 	{spawn	"stone_hit_br_big"}
				else stuff "shell ap atgm_launcher"
					{spawn "stone_hit_br_big"}
				else stuff "shell ap"
					{spawn "stone_hit_br_small"}
					{spawn "piece_crush_big"}
					{spawn "ex_add_fx40"}
				else stuff "shell small"
				 	{spawn	"stone_hit_br_small"}
				else stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "stone_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "stone_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "stone_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "stone_hit_br_small"}

				else stuff "bomb size3"
					{spawn "stone_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "stone_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "stone_hit_heat"}
					{spawn "hit_he_fragments_size2"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "stone_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "stone_hit_heat"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3_heat_shell"
					{spawn "stone_hit_heat_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4_heat_shell"	
					{spawn "stone_hit_heat_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "auto"
					("sonic_crack_s4")	
					{spawn "stone_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "stone_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "stone_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "stone_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "stone_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "shell hv_ap"
					{spawn "stone_hit_br"}

				else stuff "shell small"
					{spawn "stone_hit_br_small"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "stone_hit_bul"}
					{bullet_detonate}
				else stuff "bullet big "
					{if not volume "window"
						{if rand 0.3
							{spawn "damage_shock_micro"}
							{spawn "pierce_bullet_smoke"}
							{start_sound "detonation/crack_bullet/med/"}
							{burn fx "wound_fx_stone00" time 3 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 3 }
						else rand 0.1
							{spawn "damage_shock_micro"}
							{start_sound "detonation/crack_bullet/med/"}
							{burn fx "wound_fx_stone02" time 3 }
						}
						{spawn "stone_hit_bul_big"}
					else
						{spawn	"glass_hit_sm_bullet"}
					}
				else stuff "bullet small"
					{if not volume "window"
						{if rand 0.1
							{spawn "pierce_bullet_smoke"}
							{start_sound "detonation/crack_bullet/small/"}
							{burn fx "wound_fx_stone00" time 0.5 }
						else rand 0.1
							{start_sound "detonation/crack_bullet/small/"}
							{burn fx "wound_fx_stone01" time 0.5 }
						else rand 0.1
							{start_sound "detonation/crack_bullet/small/"}
							{burn fx "wound_fx_stone02" time 0.5 }
						}
						{spawn	"stone_hit_bul_small"}
					else
						{spawn	"glass_hit_sm_bullet"}
					}
				else stuff "bullet stackable"
					{if not volume "window"
						{if rand 0.2
							{burn fx "wound_fx_stone00" time 1.5 }
						else rand 0.1
							{burn fx "wound_fx_stone01" time 1.5 }
						else rand 0.1
							{burn fx "wound_fx_stone02" time 1.5 }
						}
						{if rand 0.1
							{spawn "pierce_bullet_smoke"}
							{start_sound "detonation/crack_bullet/small/"}
						}
						{spawn	"stone_hit_bul"}
					else
						{spawn	"glass_hit_sm_bullet"}
					}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				else stuff "glass ic"
					{spawn "empty_fx"}
				}
			else material "straw"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3 api"				;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "bullet_fx size3"
					("sonic_crack_s3")
					{spawn "wood_hit_bul"}

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "grapple_fx"							; grapple hook
					{spawn "wood_hit_br"}

				else stuff "bomb size3"
					{spawn "wood_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "mortar_smoke"
					{spawn "mortar_smoke"}
					{spawn "ex_air_sm"}
					{spawn "wood_hit_bul"}

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_heat"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell"
					{spawn "metal_hit_heat_riflegrenade"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "shell size2_heat_shell"
					{spawn "metal_hit_heat"}

				else stuff "shell size3_heat_shell"
					{spawn "metal_hit_heat_big"}

				else stuff "shell size4_heat_shell"
					{spawn "metal_hit_heat_big"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto he size1"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto he size2"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto"
					{spawn "wood_hit_br_auto"}

				else stuff "shell size1 all_he"
					{spawn "wood_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "wood_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "wood_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "wood_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size5"}

				else stuff "shell size6"
					{spawn "shockwave_sphere"}
					{spawn "ex_he_size6"}

				else stuff "shell small"
					{spawn "ex_air_sm"}
					{spawn "wood_hit_br"}

				else stuff "shell all_he"
					{spawn "ex_mort_big_wood"}

				else stuff "shell"
					{spawn "wood_hit_br"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "wood_hit_bul"}
					{bullet_detonate}

				else stuff "no_hit"		
					{spawn "empty_fx"}
				else
					{spawn "wood_hit_br"}
				}
;sand
			else material "sand"
				(include "killzones.inc")
				{if stuff "bullet_fx size1"						;	Pistol Caliber
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size2 intermediate"		;	Intermediate Rifle Caliber
					("sonic_crack_s1")
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size2"					;	Rifle Caliber
					("sonic_crack_s2")
					{spawn "sand_hit_bul_sm"}

				else stuff "bullet_fx size3"					;	Large Rifle Caliber
					("sonic_crack_s3")
					{spawn "ex_bul_heavy"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "sand_hit_heat_small"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "sand_hit_heat"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rifle_grenade_at"
					{spawn "sand_hit_heat_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "size2 heat_shell"
					{spawn "sand_hit_heat"}
					{spawn "hit_he_fragments_size2"}

				else stuff "size3 heat_shell"
					{spawn "sand_hit_heat_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "size4 heat_shell"
					{spawn "sand_hit_heat_big"}
					{spawn "hit_he_fragments_size2"}

				else stuff "big mortar"
					{spawn "sand_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "mortar"
					{spawn "sand_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "15mm he"
					{spawn "object_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "shell auto size1 he"
					{spawn "object_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "shell auto size1"
					{spawn "sand_hit_zenite"}

				else stuff "shell auto size2 he"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "shell auto size2"
					{spawn "sand_hit_zenite_big"}

				else stuff "shell size1 all_he"
					{spawn "sand_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size1"
					{spawn "sand_hit_shell_37_57"}

				else stuff "shell size2 all_he"
					{spawn "sand_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size2"
					{spawn "sand_hit_shell_75_100"}

				else stuff "shell size3 all_he"
					{spawn "sand_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size3"
					{spawn "sand_hit_shell_105_128"}

				else stuff "shell size4 all_he"
					{spawn "sand_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size4"
					{spawn "sand_hit_shell_152"}

				else stuff "shell size5"
					{spawn "ex_he_size5 he"}

				else stuff "shell size6"
					{spawn "ex_he_size6"}

				else stuff "flare marker"							; Special Flare ammo for mission scripts 
					;{spawn "flare_marker"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "sand_hit_bul_sm"}
					{bullet_detonate}

				else stuff "zenite"
					{spawn "ex_air_sm"}
					{spawn "sandbags_hit_big_50"}
				else stuff "small bullet"
					{if rand 0.5
						{spawn "sandbags_hit_small1"}
					else
						{spawn "sandbags_hit_small2"}
					}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "big bullet"
					{spawn "sandbags_hit_big_50"}
				else stuff "bullet"
					{if rand 0.5
						{spawn "sandbags_hit_big1"}
					else
						{spawn "sandbags_hit_big1"}
					}
				else stuff "grenade fg"
					{spawn "ex_mort_sm"}
				else stuff "mortar"
					{spawn "ex_mort_sm"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "shell ap atgm_launcher"
					{spawn "metal_hit_atgm"}
				else stuff "bazooka"
					{spawn "ex_air_big"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				else
					{spawn "sandbags_crush"}
				}
			else material "gas"
				{spawn "ex_air_sm"}
			else material "wound_glass"
				{if stuff "zenite"
					{if not volume "window"
						{spawn "glass_sm_hit"}	
					else
						{spawn "glass_hit3"}		
					}
				 else stuff "rocketlauncher 40mm_fg" ;og7v
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 75mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "rocketlauncher 85mm"
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_spawn"}		
				 else stuff "45_th" ; thermite
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "stone_hit_br_small"}			
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
				 else stuff "rocketlauncher 105_th" ; thermite
					{if volume "window"
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fx_piece_fire" }
					else
						{burn fx "thermite_hit3" time 8 }
					}
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "stone_hit_br_small"}			
					{fire radius 0.2 time 7 heating 1}
					{start_sound "detonation/phosphorus_start/"}
					{bullet_detonate}			
					{spawn "ex_air_norm7"}					
				else stuff "rifle_grenade_at"
					("explosion_HEAT_s1")
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "bomb size3"
				 	{spawn "metal_hit_fg_massive"}

				else stuff "big mortar"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "small mortar"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}
				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "metal_hit_fg_15mm"}
					{spawn "hit_he_fragments_15mm"}

				else stuff "auto size1 he"
					{spawn "metal_hit_fg_auto"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto size2 he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_auto"}

				else stuff "auto aphe"			;// plane autocannon
					{spawn "metal_hit_fg_auto"}
					{blastwave c4 0.504 r0 0.2 r1 0.5 position}		; needs blast because ammo is pierce
					{blastwave c4 0.36 r0 0.75 r1 3.06 position}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "shell size1 all_he"
					{spawn "metal_hit_fg_small"}
					{spawn "hit_he_fragments_size1"}

				else stuff "shell size2 all_he"
					{spawn "metal_hit_fg"}
					{spawn "hit_he_fragments_size2"}

				else stuff "shell size3 all_he"
					{spawn "metal_hit_fg_big"}
					{spawn "hit_he_fragments_size3"}

				else stuff "shell size4 all_he"
					{spawn "metal_hit_fg_massive"}
					{spawn "hit_he_fragments_size4"}

				else stuff "shell size5"
					{spawn "object_hit_fg_massive"}

				else stuff "shell size6"
					{spawn "object_hit_fg_massive"}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "glass_hit"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "glass_hit"}
					{bullet_detonate}
				else stuff "bullet"
					{if not volume "window"
						{spawn "glass_sm_hit"}	
					else
						{spawn "glass_hit_sm_bullet"}		
					}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				else
					{spawn "glass_sm_hit"}	
				}
			else material "wound_glass_small"
				{spawn "glass_hit_shrap_small"}	
			else material "ice"
				{if stuff "shell all_he"
					("explosion_HE_s4")
					("explosion_s2_dirt")
					{spawn "ex_mort_sm_snow"}

				else stuff "shell hv_ap"
					{spawn "snow_hit_small"}

				else stuff "flame"

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{spawn "ex_bul_sm_snow"}
					{bullet_detonate}

				else stuff "no_hit"		
					{spawn "empty_fx"}
				else
					{spawn "snow_hit_small"}
				}

			else material "fabric"
				{if stuff "flame"

				else stuff "rifle_grenade_at"
					{spawn "metal_hit_heat_riflegrenade"}
					{spawn "hit_he_fragments_size1"}

				else stuff "rifle_grenade"
					{spawn "fabric_hit_bul"}

				else stuff "big mortar"
					{spawn "fabric_hit_bul"}

				else stuff "small mortar"
					{spawn "fabric_hit_bul"}

				else stuff "mortar"
					{spawn "fabric_hit_bul"}

				else stuff "rocketlauncher heat_shell size1"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "rocketlauncher heat_shell size2"
					{spawn "metal_hit_br_small_bazooka"}
					{blastwave c4 2.5 r0 2 r1 3.5 position}		; needs blast because ammo is pierce

				else stuff "15mm he"
					{spawn "fabric_hit_bul"}

				else stuff "auto size1 he"
					{spawn "fabric_hit_bul"}

				else stuff "auto size2 he"
					{spawn "fabric_hit_bul"}

				else stuff "auto aphe"
					{spawn "fabric_hit_bul"}

				else stuff "auto"
					{spawn "fabric_hit_bul"}

				else stuff "size1 heat_shell"
					{spawn "metal_hit_br_small_heat"}

				else stuff "size2 heat_shell"
					{spawn "metal_hit_br_heat"}

				else stuff "size3 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "size4 heat_shell"
					{spawn "metal_hit_br_big_heat"}

				else stuff "shell size1"
					{spawn "fabric_hit_bul"}

				else stuff "shell size2"
					{spawn "fabric_hit_bul"}

				else stuff "shell size3"
					{spawn "fabric_hit_bul"}

				else stuff "shell size4"
					{spawn "fabric_hit_bul"}

				else stuff "shell size5"
					{spawn "fabric_hit_bul"}

				else stuff "shell size6"
					{spawn "fabric_hit_bul"}

				else stuff "flare artillery"						; Flare for off-map Artillery
					{spawn "flare_artillery"}
					{bullet_detonate}

				else stuff "flare_usa mortar_60"					; Flare for off-map 60mm mortar
					{spawn "flare_mortar_60"}
					{bullet_detonate}

				else stuff "flare_usa mortar_81"					; Flare for off-map 81mm mortar
					{spawn "flare_mortar_81"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105"				; Flare for off-map 105mm
					{spawn "flare_artillery_105"}
					{bullet_detonate}

				else stuff "flare_usa artillery_105_vt"				; Flare for off-map 105mm VT airburst
					{spawn "flare_artillery_105_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155"				; Flare for off-map 155mm
					{spawn "flare_artillery_155"}
					{bullet_detonate}

				else stuff "flare_usa artillery_155_vt"				; Flare for off-map 155mm VT airburst
					{spawn "flare_artillery_155_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203"				; Flare for off-map 203mm
					{spawn "flare_artillery_203"}
					{bullet_detonate}

				else stuff "flare_usa artillery_203_vt"				; Flare for off-map 203mm VT airburst
					{spawn "flare_artillery_203_vt"}
					{bullet_detonate}

				else stuff "flare_usa artillery_240"				; Flare for off-map 240mm airburst
					{spawn "flare_artillery_240"}
					{bullet_detonate}

				else stuff "no_hit"		
					{spawn "empty_fx"}
				else
					{spawn "fabric_hit_bul"}
				}
;misc			
			else material "misc"
				{if stuff "zenite sp"
					{spawn "spheredust_small" }	
				else stuff "zenite ap"
					{spawn "spheredust_small" }	
				else stuff "zenite cs"
					{spawn "plastic_hit_bul" }	
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite fg"
					{spawn "plastic_hit_bul" }	
					{spawn "ex_add_fx40"}					
					{spawn "fraction_set" }
					{spawn "ex_air_norm7"}					
				else stuff "zenite th"
					{spawn "plastic_hit_bul" }	
					{spawn "fraction_thermite_fast" }
					{spawn "ex_add_fx40"}					
					{spawn "ex_air_norm7"}					
					{fire radius 0.4 time 7 heating 8}
				 else stuff "45_th" ; thermite
					{spawn "ex_air_norm7"}					
					{spawn "fraction_thermite_fast" }
					{spawn "fx_piece_fire" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 1 time 9 heating 20 follow}
					{bullet_detonate}
					{burn fx "thermite_hit" time 3 }
				 else stuff "rocketlauncher 105_th" ; thermite
					{spawn "ex_air_norm7"}					
					{bullet_detonate}			
					{if volume "window"
						{spawn "ex_air_norm7"}					
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fraction_set" }
						{spawn "fx_piece_fire" }
					else
						{burn fx "thermite_hit3" time 8 }
					}
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" }
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{spawn "fraction_thermite" offset 0 8 0}
					{fire radius 0.5 time 7 heating 10 follow}
					{start_sound "detonation/phosphorus_start/"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "mortar"
					{spawn "spheredust_small"}
				else stuff "shell big fg"
					{spawn "metal_hit_fg"}
				else stuff "shell fg"
					{spawn "spheredust_norm"}
				else stuff "shell ap atgm_launcher"
					{spawn "metal_hit_atgm"}
				else stuff "bullet stackable"
					{spawn "plastic_hit_bul"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				}
			else material "wound_lamp"
				{if stuff "bullet"
					{spawn "glass_hit_sm_bullet"}
				else stuff "no_hit"		
				}
			else material "dummy"
				{if stuff "shell ap atgm_launcher"
					{spawn "none"}
				}
			else material "kevlar"
				{if stuff "bullet"
					{spawn "plastic_hit_bul"}
				else stuff "bullet non_lethal"
					{spawn "hit_bul_non_lethal"}
				else stuff "mortar"
					{spawn "spheredust_small"}
				else stuff "zenite"
					{spawn "spheredust_small"}
				else stuff "shell fg"
					{spawn "spheredust_norm"}
				else stuff "no_hit"		
					{spawn "empty_fx"}
				else stuff "shell ap atgm_launcher"
					{spawn "spheredust_norm"}
				}
			}
		}
	}
}
