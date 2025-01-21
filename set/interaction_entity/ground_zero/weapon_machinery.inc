{"rocket_skirmisher" ;weapon_attach_skir
	{on spawn	
		{add_view 	"rpg_shot_small" 						"fx_muzzle_rpg" "fx_shoot"}
		{add_view 	"rpg_shot_small" 						"fx_muzzle_rpg" "fx_shoot"}
		{add_view 	"laser_sight_add_guided_rocket" 		"laser_point" "fx_laser_point"}
		{add_view 	"laser_sight_guided_rocket" 			"laser_point" "fx_laser_point"}
		{view hide	"laser_point"}
		{view pause	"laser_point"}		
		{if stuff_filled "ap_proj" 
			{tags add "ap_proj" }
		else stuff_filled "fg_proj" 
			{tags add "fg_proj" }
		else stuff_filled "th_proj" 
			{tags add "th_proj" }
		}		
	}
	{on "fire"
		{bone hide "laser_point"}
		{view hide	"laser_point"}
		{view pause	"laser_point"}		
		{start_sound "weapon/shoot_loud/far/rpg"}	
		{start_sound "weapon/shoot_loud/close/rpg"}	
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_shoot" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_shoot" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_shoot" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_shoot" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight" }
		{spawn "boltclear" "foresight" }			
		{view start "fx_muzzle_rpg"}
		{view show "fx_muzzle_rpg"}
		{delay 3 
			;{view hide	"fx_muzzle_rpg"}
			{view pause	"fx_muzzle_rpg"}
		}
		{if stuff_filled "ap_proj" 
			{tags add "ap_proj" }
			;{spawn "shell_5m_ap_loader_auto" "foresight" x {call "check_side"}}
		else stuff_filled "fg_proj" 
			{tags add "fg_proj" }
			;{spawn "shell_5m_fg_loader_auto" "foresight" x {call "check_side"}}
		else stuff_filled "th_proj" 
			{tags add "th_proj" }
			;{spawn "shell_5m_th_loader_auto" "foresight" x {call "check_side"}}
		}		
	}
	{on "reload"
		{tags remove "ap_proj"}
		{tags remove "fg_proj"}
		{tags remove "th_proj"}
		{delay 2
			{if stuff_filled "ap_proj" 
				{tags add "ap_proj"}
			else stuff_filled "fg_proj" 
				{tags add "fg_proj"}
			else stuff_filled "th_proj" 
				{tags add "th_proj"}
			}		
		}		
	}
}

{"shotgun127x55_skirmisher" ;weapon_attach_skir
	{on spawn
		;shotgun
		{add_view 	"muzzle_front_shotgun" 		"fx_muzzle_buck" 	"foresight"}
		{add_view 	"muzzle_front_hmgun" 		"fx_muzzle_slug" 	"foresight"}
		{add_view 	"muzzle_gun30_auto" 		"fx_muzzle_dragon" 	"foresight"}
		{add_view 	"smoke_sil_small" 			"fire_hot" 			"foresight"}
		;----------
	}
	{on "reload"
		{tags remove "slug"}
		{tags remove "buck"}
		{tags remove "dragon"}
	}
	{on "fire"
		{view start	"fire_hot"}
		{view show	"fire_hot"}
		{if stuff_filled "slug" 
			{tags add "slug"}
			{tags remove "buck"}
			{tags remove "dragon"}
			{view start "fx_muzzle_slug"}
			{view show "fx_muzzle_slug"}
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		else stuff_filled "dragon" 
			{start_sound "hit/small/bullet_fire/"}	
			{view start "fx_muzzle_dragon"}
			{view show "fx_muzzle_dragon"}
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "trace_linear" "foresight" x }
			{spawn "trace_linear" "foresight" x }
			{spawn "trace_linear" "foresight" x }
			{spawn "trace_linear" "foresight" x }
			{spawn "trace_linear" "foresight" x }
			{spawn "trace_linear" "foresight" x }
			{tags add "dragon"}
			{tags remove "buck"}
			{tags remove "slug"}
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
			{spawn "dragon_fire" "foresight" x {impulse dir 100 rnd_dir 2} {gravity 0.8} }
		else 
			{view start "fx_muzzle_buck"}
			{view show "fx_muzzle_buck"}
			{tags add "buck"}
			{tags remove "slug"}
			{tags remove "dragon"}
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
			{spawn "fraction" "foresight" x {impulse dir 80 rnd_dir 1} {gravity 0.5} }
		}		
		{delay 0.1 "fire"
			{view pause "fx_muzzle_dragon"}
			{view pause "fx_muzzle_buck"}
			{view pause "fx_muzzle_slug"}
		}
		{delay 2 1 "fire"
			{view hide	"fire_hot"}
			{view pause	"fire_hot"}
		}
	}
}
(define "bullet_filling_10_load"
	("bullet_filling" args 11)	("bullet_filling" args 10)
	("bullet_filling" args 09)	("bullet_filling" args 08)
	("bullet_filling" args 07)	("bullet_filling" args 06)
	("bullet_filling" args 05)	("bullet_filling" args 04)
	("bullet_filling" args 03)	("bullet_filling" args 02)
	("bullet_filling" args 01)	
)



{"weapon cluster_launcher" ;weapon_attach
	{on spawn
;		{add_view 	"smoke_heat_barrel" 		"smoke" 			"brass_alt"}
;		{add_view 	"smoke_heat_barrel2" 		"smoke_recoil" 		"brass_alt"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 			"foresight3"}
		{add_view 	"muzzle_front_shorted" 		"fx_muzzle" 		"foresight3"}
		{view hide	"fx_muzzle"}
		{view pause	"fx_muzzle"}
	}
	; {on animation_event "clear_casing_12x55" overload
		; {start_sound "weapon/shell_eject/shell12"}	
		; {tear "shell_drop_12_55" bone "shell_drop_masterkey" copy ;slicer_tail
			; {impulse forward 0.6 cx -0.1 0.1 com  }
		; }
		; {delay 0
			; {view hide "shell_drop_masterkey"}	
		; }
	; }
	{on "link"
	}
	{on "reload"
		{delay 2
			{ani_play "reload" 0.8}
			{start_sound "generation_zero/weapon/load/tank_wpn_prepare_missiles"}	
			
		}
		{delay 9
			{ani_play "load" resume}
			{start_sound "weapon/click/LauncherMissile_click"}	
		}
	}	
	{on "fire"
		{if stuff_filled "gas" 
			{tags add "gas"}
			{spawn "m43_gas_bullet" 	"foresight3" x {impulse dir 75 rnd_dir 0.3} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		else
			{tags remove "gas"}			
		}
		(define "bullet_filling"
			{if bone "bullet%0" visible
				{tags add "bullet%0"}
			else
				{ani_play "shot_small%0" resume}
				{tags remove "bullet%0"}
			}
		)
		("bullet_filling_10_load")
		{view show	"fx_muzzle"}
		{view start	"fx_muzzle"}
		{view show "shell_drop"}	
		{delay 0.2
			{start_sound "weapon/shell_eject/shell12"}	
			{tear "shell_drop_25_59" bone "shell_drop" copy 
				{impulse forward 2 com  }
			}
			{delay 0
				{view hide "shell_drop"}	
			}
			;{burn volume fx "smoke_heat" time 5 fake even_law}
			{view hide "fx_muzzle"}
			{view pause "fx_muzzle"}
		}			
		; ;{kill_delay "fire"}
		; {delay 0. ""
			; {view pause	""}
		; }
		{kill_delay "heater"}
		{if not tagged "heater"				
			{ani_play "stage1" +1.5 resume callback}
			{ani_play "stage2" +0.8 resume callback}
			{tags add "heater"}
		}
		{delay 3 "heater"
			{ani_play "stage1" -0.1 resume }
			{ani_play "stage2" -0.1 resume }
			{tags remove "heater"}
		}
	}
	{on animation_end "stage1"
		{ani_play "cooler" +0.3 resume loop}
		{burn volume "heat" fx "smoke_heat_barrel" time 3 fake even_law}
	}
	{on animation_end "stage2"
		{ani_play "cooler" +0.8 resume loop}
		; {delay 5 
			; {tags remove "heat_full"}		
		; }
		; {if tagged "fire_hold"				
			; {start_sound "weapon/heat/"}
		; }
		{burn volume "heat_cooler" fx "smoke_heat_barrel" time 3 fake even_law}
		{burn volume "heat"		 fx "smoke_heat_barrel" time 8 fake even_law}
	}	
}
{"drone_c4"
	{on spawn
		{add_view 	"diod_red"			"diod_red"		"led"}
		{view show	"diod_red"}
		{view start	"diod_red"}
		
		{add_view 	"diod_red"			"diod_red_drop"		"turret_link_c4"}
		{view hide	"diod_red_drop"}
		{view pause	"diod_red_drop"}
		{link_sound "fly"			"vehicle/quad/quadcopter" 	}
		{ani_play "engine_work" loop}
		{chassis_work 0}
		{delay 2
			{ani_play "fly" 0.4}
			{delay 1
				{chassis_work 1}
			}
		}
		{play_sound "fly" 1}
		{link_sound "engine_start"	"vehicle/quad/quadcopter" 	}
		{link_sound "engine_work"	"vehicle/quad/quadcopter" 	}
		{link_sound "engine_stop"	"vehicle/quad/quadcopter" 	}
		{link_sound "rotate_body" 	"weapon/turret/Beep_Fire_01"}
		{link_sound "rotate_turret" "vehicle/turret/small"}
	}
	{on fire "gun"
		{view show	"diod_red_drop"}
		{view start	"diod_red_drop"}
		{delay 0.2
			{start_sound "weapon/armed/с4/detpack_button"}			
			{call "drop"}
		}
	}		
	{on animation_event "move_update" ;scout. drone c4
		{if not able "exploded"
			{call "velocity_update"}	
		}
	}
	{on animation_event "slope_left_start" 
		{tags add "slope"}
		{tags add "slope_left"}
		{ani_stop "hover" }
		;{chassis_work 0}
	}
	{on animation_event "slope_left_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_left"}
		}
	}
	{on animation_event "slope_right_start" 
		{tags add "slope"}
		{tags add "slope_right"}
		{ani_stop "hover" }
		;{chassis_work 0}
	}
	{on animation_event "slope_right_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_right"}
		}
	}
	{on animation_event "slope_right_reward_start" 
		{tags add "slope"}
		{tags add "slope_left"}
		{ani_stop "hover" }
		;{chassis_work 0}
	}
	{on animation_event "slope_right_reward_end" 
		{tags remove "slope"}
		{if not tagged "break_jetengine"
			{ani_play "hover" loop }
		}
		;{chassis_work 1}
		{delay 0.5 
			{tags remove "slope_left"}
		}
	}
	{on "slope_weapon_warning"
		{if not able "exploded"		
			{call "stop_idle"}
			{if tagged "flying"
				{if not tagged "slope"
					{if rand 0.5
						{if not tagged "slope_left"
							{ani_play "slope_left" 1}
							{ani_stop "slope_right" }
						}
					else
						{if not tagged "slope_right"
							{ani_play "slope_right" 1}
							{ani_stop "slope_left" }
						}
					}
				}		
			}
		}		
	}
	{on "drop"
		{if not tagged "slope"
			{if rand 0.5
				{if not tagged "slope_left"
					{ani_play "slope_left" 1}
					{ani_stop "slope_right" }
				}
			else
				{if not tagged "slope_right"
					{ani_play "slope_right" 1}
					{ani_stop "slope_left" }
				}
			}
		}		
		(define "drop"
			{if tagged %0
				{tear "c4_ground" bone "c4"
					{volumes disable contact}
					{impulse forward %1}
				}		
				{tear "piece_medium_steel" bone "cap"
					{impulse forward 0.7}
				}
			else
				{tear "c4_ground" bone "c4"
					{volumes disable contact}
					{impulse forward 0.1}
				}		
				{tear "piece_medium_steel" bone "cap"
					{impulse forward 0.1}
				}
			}
		)
		("drop" args "17_speed" 8.5)
		("drop" args "16_speed" 8)
		("drop" args "15_speed" 7.5)
		("drop" args "14_speed" 7)
		("drop" args "13_speed" 6.5)
		("drop" args "12_speed"	6)
		("drop" args "11_speed" 5.5)
		("drop" args "10_speed" 5)
		("drop" args "9_speed" 	4.5)
		("drop" args "8_speed" 	4)
		("drop" args "7_speed" 	3.5)
		("drop" args "6_speed" 	3)
		("drop" args "5_speed" 	2.5)
		("drop" args "4_speed"  2)
		("drop" args "3_speed" 	1.5)
		("drop" args "2_speed" 	1)
		("drop" args "1_speed"  0.5)
		("drop" args "0_speed"  0.1)
	}

	{on "velocity_update"
		{if velocity 17
			{if not tagged "17_speed"
				{tags add "17_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	+1)
				("speed" args "16_speed" 	+1)
				("speed" args "15_speed" 	+1)
				("speed" args "14_speed" 	+1)
				("speed" args "13_speed" 	+1)
				("speed" args "12_speed" 	+1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 16
			{if not tagged "16_speed"
				{tags add "16_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				;("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	+1)
				("speed" args "14_speed" 	+1)
				("speed" args "13_speed" 	+1)
				("speed" args "12_speed" 	+1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 15
			{if not tagged "15_speed"
				{tags add "15_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				;("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	+1)
				("speed" args "13_speed" 	+1)
				("speed" args "12_speed" 	+1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 14
			{if not tagged "14_speed"
				{tags add "14_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				;("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	+1)
				("speed" args "12_speed" 	+1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 13
			{if not tagged "13_speed"
				{tags add "13_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				;("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	+1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 12
			{if not tagged "12_speed"
				{tags add "12_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				;("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	+1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 11
			{if not tagged "11_speed"
				{tags add "11_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				;("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	+1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 10
			{if not tagged "10_speed"
				{tags add "10_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				;("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	+1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 9
			{if not tagged "9_speed"
				{tags add "9_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "8_speed" 	+1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 8
			{if not tagged "8_speed"
				{tags add "8_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 7
			{if not tagged "7_speed"
				{tags add "7_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				;("speed" args "7_speed" 	+1)
				("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 6
			{if not tagged "6_speed"
				{tags add "6_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				;("speed" args "6_speed" 	+1)
				("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 5
			{if not tagged "5_speed"
				{tags add "5_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				;("speed" args "5_speed" 	+1)
				("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 4
			{if not tagged "4_speed"
				{tags add "4_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				;("speed" args "4_speed" 	+1)
				("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 3
			{if not tagged "3_speed"
				{tags add "3_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				;("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 3
			{if not tagged "3_speed"
				{tags add "3_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				;("speed" args "3_speed" 	+1)
				("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 2
			{if not tagged "2_speed"
				{tags add "2_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				;("speed" args "2_speed" 	+1)
				("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 1
			{if not tagged "1_speed"
				{tags add "1_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				("speed" args "2_speed" 	-1)
				;("speed" args "1_speed" 	+1)
				("speed" args "0_speed" 	+1)
			}
		else velocity 0
			{if not tagged "0_speed"
				{tags add "0_speed"}
				(define "speed"
					{if tagged %0
						{ani_play "speed_full" %1 resume}
						{tags remove %0}
					}
				)
				("speed" args "17_speed" 	-1)
				("speed" args "16_speed" 	-1)
				("speed" args "15_speed" 	-1)
				("speed" args "14_speed" 	-1)
				("speed" args "13_speed" 	-1)
				("speed" args "12_speed" 	-1)
				("speed" args "11_speed" 	-1)
				("speed" args "10_speed" 	-1)
				("speed" args "9_speed" 	-1)
				("speed" args "8_speed" 	-1)
				("speed" args "7_speed" 	-1)
				("speed" args "6_speed" 	-1)
				("speed" args "5_speed" 	-1)
				("speed" args "4_speed" 	-1)
				("speed" args "3_speed" 	-1)
				("speed" args "2_speed" 	-1)
				("speed" args "1_speed" 	-1)
				;("speed" args "0_speed" 	+1)
			}
		}
	}
	{on "engine_started"
		{if not "engine_started"
			{set "engine_started" 1}
		}
	}
	{on "engine_stopped"
		{if "engine_started"
			{set "engine_started" 0}
		}
	}
	{on engine on overload
		{call "engine_on"}
	}
	
	{on "engine_on" overload
	}
	
	{on engine off overload
	}
	
	{on "engine_stop"
	}
	(define "cut_part"
		{tear "piece_medium_steel" bone from_volume
			{spawn "spheredust_small_short_arm" }
			{impulse up 3 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
		}	
	)
	{on break_armor
		{if name "pierce"
			{if stuff "shell"
				{impulse up 1 0.5 dir 0.3 0.2}
				{call "_explosion"}
			else stuff "zenite"
				{if rand 0.3
					{impulse up 1 0.5 dir 0.3 0.2}
					{call "_explosion"}
				}
			}
		else name "blast"
			{if volume "main_body"
				{impulse up 1 0.5 dir 0.3 0.2}
				{call "_explosion"}
			}
		}
	}
	
	{on pierce sync
		{if volume "part"
			{spawn "spheredust_small_short_arm" }
			{tear "piece_medium_steel" bone from_volume
				{impulse up 2 1 dir 7 3 cx 2 1 cy 2 1  no_position}
			}	
			{call "break"}
		}
		{if stuff "bullet"
			{if rand 0.7
				{call "break"}
			}
		}
		{if stuff "atgm_launcher"
			{call "break"}
		}
		{if stuff "shell_big"
			{call "break"}
		}
		{if stuff "rocketlauncher"
			{call "break"}
		}
	}	
	{on ground_hit
		{if volume "part"
			{if min_speed 10
				{call "cut_part"}
				{components "main_body" destroy}
				{spawn "spheredust_small_short_arm" }
				{tear "piece_medium_steel" bone from_volume
					{impulse up 2 1 dir 7 3 cx 2 1 cy 2 1  no_position}
				}	
			}	
		}
		{if tagged "die" 
			{if rand 0.6
				{call "break"}
			}
		}
		{if min_speed 10
			{if rand 0.5
				{call "break"}
			}
		}
	}	
	{on contact overload
		{if not effector "obstacle"
			{if not impregnable
				{if volume "main_body"
					{if min_speed 2
						{call "break"}
					}
				}
				{if volume "part"
					{call "cut_part"}
				}
			}
		}
	}
	{on blast
		{if min_energy 1
			{call "die"}
		}
	}
	{on "die"
		{spawn "break_small_body_robot" "body"}
		{tags add "die"}
		{impulse up 0.2 com}
		{stop_sound "fly" }
		{ani_stop "fly"}
		{delay 2
			{ani_stop "engine_work"}
		}
		{ani_stop "move"}
	}
	{on "break" 
		{if not able "exploded"
			{able "exploded" 1}
			(define "blast"
				{spawn "spheredust_small_short_arm" }
				{tear "piece_medium_steel" bone %0
					{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
				}
			)
			("blast" args "cap"		 )
			("blast" args "part"		 )
			("blast" args "part1"		 )
			("blast" args "part2"		 )
			("blast" args "part3"		 )
			("blast" args "part4"		 )
			("blast" args "propeller"		 )
			("blast" args "propeller1"		 )
			("blast" args "propeller2"		 )
			("blast" args "propeller3"		 )
			{ani_stop "fly"}
			{ani_stop "move"}
			{ani_stop "engine_work"}
			{burn stop}
			{stop_sound "fly" }
			{kill_crew}
			{auto_operatable 0}
			{drop_orders}
			{delay 0.5
				{components destroy}
			}
			{able select 0}
			{clear_inventory}
			{tags add "destroyed"}
			{tags remove "air"}
			{impulse up 0.2 com}
		}
	}
}
