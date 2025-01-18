{"bullet"
	{on spawn
		{if bone "trace762" visible
			{add_view "trace_bullet_762" 			"trace" 	"trace762"}
			{tags add "trace_762"}
		}
		{if bone "trace127" visible
			{add_view "trace_bullet_127" 			"trace" 	"trace127"}
			{tags add "trace_127"}
		}
		{if bone "starter" visible
			{call "start_starter"}				
		}
		{link_sound "start_small_rpg" "generation_zero/weapon/micro_missile/loop/mach_wpn_micro_missile_trail_loop_01"}
		{link_sound "fly_atgw" "weapon/fly_guided/"}
		{link_sound "mortar_incoming" "detonation/mortar_incoming"}
		{link_sound "start_small" "weapon/whiz"}
		{link_sound "start_small_trace" "weapon/whiz_heavy"}
		{link_sound "fly_tow" "weapon/reactive/tow/rocket_loop"}
		{link_sound "fly_rpg" "weapon/reactive/move/rpg7/move_rpapa7_proj_flame_cls"}
		{link_sound "start_fly_rpg" "weapon/reactive/move/rocket_oneshot/"}
		{link_sound "start_rpg" "weapon/shot/small_arms/rpg7/"}
		{link_sound "fly" "weapon/reactive/move/rpg7/move_rpapa7_proj_flame_cls"}
		{link_sound "start_9m39" "weapon/reactive/9k38/start/"} ;выстрел
		{link_sound "open_9m39" "weapon/reactive/9k38/open/"} ;раскрытие
		{link_sound "move_9m39" "weapon/reactive/9k38/move/"} ;move

		{link_sound "mortar_whistle" "projectile/mortar/whistle/"}

		{link_sound "at_rocket"			"projectile/shell/rocket/"}
		{link_sound "shell_small"		"projectile/shell/small/"}
		{link_sound "shell_low"			"projectile/shell/standard_low/"}
		{link_sound "shell"				"projectile/shell/standard/"}
		{link_sound "artillery"			"projectile/shell/artillery/"}
		{link_sound "shell_thor"		"projectile/shell/karl_gerat"}
		{view stop "start_9m39"}
		{view hide "start_9m39"}
		{view stop "fly_type90"}
		{view hide "fly_type90"}
		{view stop "fly_type90_end"}
		{view hide "fly_type90_end"}
		{delay 0 
			{if bone "sound_rocket"			;// rocket artillery
				{play_sound "rocket"}
			}
			{if bone "sound_at_rocket"		;// anti-tank rockets
				{play_sound "at_rocket"}
			}
			{if bone "sound_shell_small"	;// small cannon shells
				{play_sound "shell_small"}
			}
			{if bone "sound_shell_low"		;// low velocity cannon shells
				{play_sound "shell_low"}
			}
			{if bone "sound_shell"			;// standard cannon shells
				{play_sound "shell"}
			}
			{if bone "sound_artillery"		;// artillery cannon shells
				{play_sound "artillery"}
			}
			{if bone "600mm_ger_he"			;// karl thor shells
				{play_sound "shell_thor"}
			}
		}
	}
	{on "start_small"	
		{play_sound 		"start_small" }
		{if not "blocked"
			{set "blocked" 1}
			{ani_play "start" }	
			{view start "trace"}
			{view show "trace"}
		}
	}
	{on "start_small_trace"	
		{play_sound 		"start_small_trace" }
		{if not "blocked"
			{ani_stop "trace"}
			{set "blocked" 1}
			{ani_play "start" }	
			{view start "trace"}
			{view show "trace"}
			{if rand 0.3
				{tags add "trace_fire"}
				{bone hide "trace"}
				{bone show "trace_fire"}				
				{view start "start_slug"}
				{view show "start_slug"}
				{delay 0.7 0.2 
					{view stop "start_slug"}
					{view hide "start_slug"}
				}
			else
				{bone hide "trace_fire"}
				{bone show "trace"}						
			}		
		}
	}
	{on "blast_small"
		{blastwave c4 0.7 r0 1.5 r1 1.5}		
		{spawn "blast_cluster" "basis" x}
		{start_sound "detonation/missile/"}				
		{spawn "fx_shoot_hit_sparks" "basis" x {impulse forward -2 rnd_dir 0.5} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "basis" x {impulse forward -2 rnd_dir 0.5} {gravity 0} }
		{spawn "grenade_cluster_proj" "basis" x {impulse forward -2 rnd_dir 10 5}}
		{delete}
	}	
	{on animation_event "start_type90_cluster"	
		{call "start_type90_cluster"}	
	}
	{on animation_event "start_type90"	
		{call "start_type90"}	
	}
	{on "start_type90"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 				"start_type90" 		"tail"}
			{add_view "rpg7_tail2_fx" 					"fly_type90" 		"tail"}
			{add_view "guided_tail_fx_heavy_start" 		"fly_type90_start" 	"tail"}			
			{add_view "fx_fire_hot_type" 				"fly_type90_end" 	"tail"}
			{view start "start_type90"}
			{view show "start_type90"}
			{view pause "fly_type90"}
			{view pause "fly_type90_end"}
			{delay 0.2 
				{ani_play "open" 1}	
			}
			{delay 0.5
				{view stop "start_type90"}
				{view hide "start_type90"}
				{spawn "rpg_shot_small" "tail" x }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{start_sound "weapon/reactive/9k38/open/"}				
				{play_sound "start_small_rpg" 1}
				{view start "fly_type90_start"}
				{view show "fly_type90_start"}
			}
			{delay 3 2.5
				{view start "fly_type90"}
				{view show "fly_type90"}
				{view stop "fly_type90_start"}
				{view hide "fly_type90_start"}
			}
			{delay 6 5.5
				{start_sound "detonation/flare/start/"}				
				{spawn "rpg_shot_small" "tail" x }
				{stop_sound "start_small_rpg" }
				{view start "fly_type90_end"}
				{view show "fly_type90_end"}
				{view stop "fly_type90"}
				{view hide "fly_type90"}
			}
		}		
	}	
	{on "start_type90_cluster"		
		{if tagged "open"
			{if altitude 90
			else altitude 80
				{volumes disable all}
				{burn volume fx "tail_grenade" time 1 fake even_law}	
			else altitude 70			
				{view stop "add_guided"}
				{view hide "add_guided"}				
				{start_sound "detonation/missile/"}				
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{spawn "grenade_cluster_proj" "flash" x {impulse rnd_dir 50 25}}
				{bone cut "tail"}
				{bone hide "body"}
			}	
		}
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 				"start_type90" 		"tail"}
			{add_view "rpg7_tail2_fx" 					"fly_type90" 		"tail"}
			{add_view "guided_tail_fx_heavy_start" 		"fly_type90_start" 	"tail"}			
			{add_view "fx_fire_hot_type" 				"fly_type90_end" 	"tail"}
			{view start "start_type90"}
			{view show "start_type90"}
			{view pause "fly_type90"}
			{view pause "fly_type90_end"}
			{delay 0.2 
				{ani_play "open" 1}	
			}
			{delay 0.5
				{view stop "start_type90"}
				{view hide "start_type90"}
				{spawn "rpg_shot_small" "tail" x }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "tail" x {impulse forward 2 rnd_dir 0.5} {gravity 0} }
				{start_sound "weapon/reactive/9k38/open/"}				
				{play_sound "start_small_rpg" 1}
				{view start "fly_type90_start"}
				{view show "fly_type90_start"}
			}
			{delay 3 2.5
				{view start "fly_type90"}
				{view show "fly_type90"}
				{view stop "fly_type90_start"}
				{view hide "fly_type90_start"}
			}
			{delay 6 5.5
				{start_sound "detonation/flare/start/"}				
				{spawn "rpg_shot_small" "tail" x }
				{stop_sound "start_small_rpg" }
				{view start "fly_type90_end"}
				{view show "fly_type90_end"}
				{view stop "fly_type90"}
				{view hide "fly_type90"}
			}
		}		
	}	
	{on "start_cluster"
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_23mm" "tail"}
			{view start "start_23mm"}
			{view show "start_23mm"}
			{delay 0.3 0.1
				{play_sound 		"start_small" }
				{view stop "start_23mm"}
				{view hide "start_23mm"}
			}
		}
		{if tagged "open"
			{if altitude 10
			else altitude 9
				{add_view "laser_sight_add_guided" 		"add_guided" "basis"}
				{view start "add_guided"}
				{view show "add_guided"}		
				{burn volume fx "tail_grenade" time 1 fake even_law}	
				{burn volume fx "fx_trace_bullet_round" time 1 fake even_law}	
			else altitude 6	
				{ani_stop "tail"}
				{view stop "add_guided"}
				{view hide "add_guided"}
				{spawn "blast_cluster" "proj" x}
				{start_sound "detonation/missile/"}				
				{spawn "fx_shoot_hit_sparks" "proj" x {impulse forward -3 rnd_dir 0.5} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "proj" x {impulse forward -7 rnd_dir 0.5} {gravity 0} }
				{spawn "grenade_cluster_proj" "proj" x {impulse forward -25 rnd_dir 10 5}}
				{spawn "grenade_cluster_proj" "proj" x {impulse forward -25 rnd_dir 10 5}}
				{spawn "grenade_cluster_proj" "proj" x {impulse forward -25 rnd_dir 10 5}}
				{spawn "grenade_cluster_proj" "proj" x {impulse forward -25 rnd_dir 10 5}}
				{bone cut "proj"}
			else altitude 5	
				{bone cut "proj"}
			}	
		}
	}	
	{on "start_panzerschreck"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "guided_tail_fx_start" 		"start_panzerschreck" "fx_tail"}
			{view start "start_panzerschreck"}
			{view show "start_panzerschreck"}
			{play_sound "start_rpg" }
			{view pause "fly_panzerschreck"}
			{delay 0.2 
				{add_view "guided_tail_fx_fly" 			"fly_panzerschreck" "fx_tail"}
				{add_view "start_stage2" 				"start_fly_panzerschreck" "fx_tail"}
				{view start "start_fly_panzerschreck"}
				{view show "start_fly_panzerschreck"}
				{view start "fly_panzerschreck"}
				{view show "fly_panzerschreck"}
				{play_sound "fly_rpg" 1}
				{view stop "start_cg"}
				{view hide "start_panzerschreck"}
			}
			{delay 0.5
				{view stop "start_fly_panzerschreck"}
				{view hide "start_fly_panzerschreck"}
			}
			{delay 1
				{view stop "fly_panzerschreck"}
				{view hide "fly_panzerschreck"}
				{stop_sound "fly_rpg" }
			}		
		}		
	}	
	{on "start_82mm_mortar"
		{if tagged "open"
			;{if rand 0.01 ; сделать осечку просто отрыв с детонацией и отменить волюмы(невозможно)
			;}
			{if altitude 60
				;{spawn "" "tail"}
			else altitude 50			
				{play_sound "mortar_incoming" }
				;{tear "piece_delete" bone "tail"
				;}	
			}	
		}
	}	
	{on "start_small_slug"		
		;{delay 0.05 ;  Assertion failed : !Raw() (eEntity.cpp:665) @ [quant] ?
		;}
		{if rand 0.6
			{start_sound "weapon/whiz/"}
			{spawn "spark_fly_bullet" "tail" x}
		}
		{if not "blocked"
			{set "blocked" 1}
			{add_view "slug_tail" 			"start_slug" "tail"}
			{add_view "start_slug_tail" 		"start_slug" "tail"}
			{view start "start_slug"}
			{view show "start_slug"}
			{delay 0.25 0.2 
				{view stop "start_slug"}
				{view hide "start_slug"}
			}
		}		
	}	
	{on "fly_tow"	
		{if rand 0.3
			{add_view "fly_tow_turn" 		"fly_tow_l" "fx_tail01"}
			{view start "fly_tow_l"}
			{view show "fly_tow_l"}
			{delay 0.2 0.1
				{view stop "fly_tow_l"}
				{view hide "fly_tow_l"}
			}
		}
		{if rand 0.3
			{add_view "fly_tow_turn" 		"fly_tow_r" "fx_tail00"}
			{view start "fly_tow_r"}
			{view show "fly_tow_r"}
			{delay 0.2 0.1
				{view stop "fly_tow_r"}
				{view hide "fly_tow_r"}
			}
		}
	}
	{on "start_tow"		
		{if not "blocked"
			{add_view "laser_sight_add_guided" 		"guided" "basis"}
			{view stop 			"start_fly_tow"}
			{view hide 			"start_fly_tow"}
			{view stop 			"fly_tow_l"}
			{view hide 			"fly_tow_l"}
			{view stop 			"fly_tow_r"}
			{view hide 			"fly_tow_r"}
			{view stop 			"guided"}
			{view hide 			"guided"}
			{ani_play "open" 1}	
			{add_view "open_tow" 			"start_tow" "tail"}
			{view start "start_tow"}
			{view show "start_tow"}
			{set "blocked" 1}
			{delay 0.2
				{view start 							"guided"}
				{view show 								"guided"}
				{start_sound 		"weapon/reactive/tow/start/"}				
				{add_view "start_fly_tow" 		"start_fly_tow" "fx_tail00"}
				{add_view "start_fly_tow" 		"start_fly_tow" "fx_tail01"}
				{view start 		"start_fly_tow"}
				{view show 			"start_fly_tow"}
				{play_sound 		"fly_tow" 1}
				{view stop 			"start_tow"}
				{view hide 			"start_tow"}
			}
			{delay 0.35
				{ani_play "fly" 0.2 loop}	
			}
			;{delay 3
			;}		
		}		
	}	
	; {on "start_atgw_skir"		
		; {if not "blocked"
			; {set "blocked" 1}
			; {add_view "guided_tail_fx_heavy_start" 		"start_9m39" "tail"}
			; {burn volume fx "smoke_heat" time 2 fake even_law}
			; {spawn "bazooka_shot" "tail" x}
			; {ani_play "open" 0.7}	
			; {delay 0.2
				; {view start "start_9m39"}
				; {view show "start_9m39"}
				; {play_sound "open_9m39" }
				; {ani_play "fly" loop}
				; {play_sound "move_9m39" 1}
			; }
			; {delay 1
				; {stop_sound "move_9m39" }
				; {view stop "start_9m39"}
				; {view hide "start_9m39"}
			; }		
		; }		
	; }	
	
	{on "start_rpg29"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "rocket_smoke_s5" 		"tail_fast" "tail"}
			{add_view "start_fly_tow" 			"tail_start" "tail"}
			{view start "tail_start"}
			{start_sound 		"weapon/reactive/tow/start/"}				
			{delay 0.2
				{play_sound "fly_rpg" 1}
				{view start "tail_fast"}
			}
			{delay 0.5
				{view stop "tail_start"}
			}
		}
	}	
	
	
	{on "start_starter"	
		;{start_sound "expl_emitters///"}	
		{spawn "bazooka_shot" "tail" x}
		{tear "piece_small_steel" bone "starter"
			{impulse forward 10 5 com  fx 0.5}
		}		
	}	
	{on "start_9m39"		
		{if not "blocked"
			{set "blocked" 1}
			{ani_play "fly" loop}
			{add_view "guided_tail_fx_heavy_start" 		"start_9m39" "tail"}
			{view start "start_9m39"}
			{view show "start_9m39"}
			{play_sound "open_9m39" }
			{delay 0.5
				{play_sound "move_9m39" 1}
			}
			{delay 6
				{view stop "start_9m39"}
				{view hide "start_9m39"}
				{delay 2.92 1.3;  
					{stop_sound "move_9m39" }
					{blastwave c4 15 r0 8 r1 8}	
					{volumes disable all }	
					;{bone hide "basis"}
					{spawn "distant_big_expl"}
					{spawn "fraction_spawn"}
					{spawn "ex_air_big"}
				}
			}		
		}		
	}	
	{on "start_s8"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "rocket_smoke_s5" 		"tail_fast" "tail"}
			{add_view "rocket_smoke_s5_start" 	"tail_start" "tail"}
			{view start "tail_start"}
			{start_sound "weapon/reactive/wrist_rocket"}	
			{delay 0.1
				{play_sound "fly_rpg" 1}
				{view start "tail_fast"}
				{view stop "tail_start"}
			}
			; {delay 0.92 0.3;  0,55-0,92 сек.
				; {blastwave c4 15 r0 8 r1 8}	
				; {volumes disable all }	
				; ;{bone hide "basis"}
				; {stuff_detonate}
				; {spawn "distant_big_expl"}
				; {spawn "fraction_spawn"}
				; {spawn "ex_air_big"}
			; }
		}
	}	
	{on "start_23mm"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_23mm" "tail"}
			{view start "start_23mm"}
			{view show "start_23mm"}
			{delay 0.2 0.1
				{view stop "start_23mm"}
				{view hide "start_23mm"}
			}
			{delay 1 0.6
				{blastwave c4 2 r0 2 r1 2}	
				{volumes disable all }	
				{bone hide "basis"}
				{spawn "ex_air_smoke"}
			}		
		}		
	}	
	{on "start_57mm"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_57mm" "tail"}
			{view start "start_57mm"}
			{view show "start_57mm"}
			{delay 0.2 0.1
				{view stop "start_57mm"}
				{view hide "start_57mm"}
			}
		}		
	}	
	{on "start_5r"		
		{if not "blocked"
			{ani_play "open" 1}	
			{set "blocked" 1}
			{play_sound "fly_rpg" 1}
			{add_view "rpg7_tail_fx" 		"start_tail" "fx"}
			{view start "start_tail"}
			{view show "start_tail"}
			{delay 0.2 0.1
				{view stop "start_tail"}
				{view hide "start_tail"}
			}
		}		
	}	
	{on "start_5r_ap"		
		{if not "blocked"
			{if rand 0.3
				{play_sound "mortar_whistle" }
			}
			{ani_play "open" 1}	
			{set "blocked" 1}
			{play_sound "fly_rpg" 1}
			{add_view "guided_tail_fx_start" 		"start_tail" "fx"}
			{view start "start_tail"}
			{view show "start_tail"}
			{delay 0.4 0.2
				{view stop "start_tail"}
				{view hide "start_tail"}
			}
		}		
	}	
	{on "start_5r_fg"		
		{if not "blocked"
			{ani_play "open" 1}	
			{set "blocked" 1}
			{play_sound "fly_rpg" 1}
			{add_view "40mm_start" 		"start_tail" "fx1"}
			{add_view "40mm_start" 		"start_tail" "fx2"}
			{add_view "40mm_start" 		"start_tail" "fx3"}
			{view start "start_tail"}
			{view show "start_tail"}
			{delay 0.4 0.2
				{view stop "start_tail"}
				{view hide "start_tail"}
			}
		}		
	}	
	{on "start_5m_fg"		
		{if not "blocked"
			{play_sound "start_small_rpg" 1}
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_xm109" "tail"}
			{add_view "rpg7_tail_fx" 			"fly_pg7v" "tail"}
			{add_view "rpg7_end" 				"end_pg7v" "tail"}
			{view pause "fly_pg7v"}
			{view pause "end_pg7v"}
			{view start "start_xm109"}
			{view show "start_xm109"}
			{delay 0.1 
				{view start "fly_pg7v"}
				{view show "fly_pg7v"}
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 0.5
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 2
				{view stop "fly_pg7v"}
				{view hide "fly_pg7v"}
				{view start "end_pg7v"}
				{view show "end_pg7v"}
			}
		}		
	}	
	{on "start_5m"		
		{if not "blocked"
			{play_sound "start_small_rpg" 1}
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_xm109" "tail"}
			{add_view "rpg7_tail_fx" 			"fly_pg7v" "tail"}
			{add_view "rpg7_end" 				"end_pg7v" "tail"}
			{view pause "fly_pg7v"}
			{view pause "end_pg7v"}
			{view start "start_xm109"}
			{view show "start_xm109"}
			{delay 0.1 
				{view start "fly_pg7v"}
				{view show "fly_pg7v"}
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 0.15
				{if rand 0.1
					{play_sound "mortar_whistle" }
				}
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 2
				{view stop "fly_pg7v"}
				{view hide "fly_pg7v"}
				{view start "end_pg7v"}
				{view show "end_pg7v"}
			}
		}		
	}	
	{on "start_xm109"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "start_xm109_tail" 		"start_xm109" "tail"}
			{view start "start_xm109"}
			{view show "start_xm109"}
			{view pause "fly_cg"}
			{delay 0.1 
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 0.5
				{view stop "start_xm109"}
				{view hide "start_xm109"}
			}
			{delay 1 0.3
				{blastwave c4 3 r0 3 r1 3}	
				{volumes disable all }	
				{bone hide "basis"}
				{spawn "distant_small_expl" offset 0 0 5}
				{spawn "tinnitus_small_expl" offset 0 0 3}
				{spawn "fraction_spawn"}
				{spawn "ex_air_big"}
			}		
		}		
	}	
	{on "start_cg"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "guided_tail_fx_start" 		"start_cg" "tail"}
			{view start "start_cg"}
			{view show "start_cg"}
			{play_sound "start_rpg" }
			{view pause "fly_cg"}
			{delay 0.2 
				{add_view "guided_tail_fx_fly" 			"fly_cg" "tail"}
				{add_view "start_stage2" 				"start_fly_cg" "tail"}
				{view start "start_fly_cg"}
				{view show "start_fly_cg"}
				{view start "fly_cg"}
				{view show "fly_cg"}
				{play_sound "fly_rpg" 1}
				{view stop "start_cg"}
				{view hide "start_cg"}
			}
			{delay 0.5
				{view stop "start_fly_cg"}
				{view hide "start_fly_cg"}
			}
			{delay 1
				{view stop "fly_cg"}
				{view hide "fly_cg"}
				{stop_sound "fly_rpg" }
				;{view start "end_pg7v"}
				;{view show "end_pg7v"}
			}		
		}		
	}	
	{on "start_cg_heat"		
		{if not "blocked"
			{set "blocked" 1}
			{add_view "laser_sight_add_guided" 		"guided" "basis"}
			{add_view "guided_tail_fx_start" 		"start_cg" "tail"}
			{view start "guided"}
			{view show "guided"}
			{view start "start_cg"}
			{view show "start_cg"}
			{play_sound "start_rpg" }
			{view pause "fly_cg"}
			{delay 0.3 
				{add_view "guided_tail_fx_fly" 			"fly_cg" "tail"}
				{add_view "start_stage2" 				"start_fly_cg" "tail"}
				{view start "start_fly_cg"}
				{view show "start_fly_cg"}
				{view start "fly_cg"}
				{view show "fly_cg"}
				{play_sound "fly_rpg" 1}
				{view stop "start_cg"}
				{view hide "start_cg"}
			}
			{delay 0.5
				{view stop "start_fly_cg"}
				{view hide "start_fly_cg"}
			}
			{delay 3
				{view stop "fly_cg"}
				{view hide "fly_cg"}
				{stop_sound "fly_rpg" }
				;{view start "end_pg7v"}
				;{view show "end_pg7v"}
			}		
			{delay 4
				{volumes disable all }	
				{blastwave c4 3 r0 3 r1 3}	
				{bone hide "basis"}
				{spawn "distant_big_expl"}
				{spawn "fraction_spawn"}
				{spawn "ex_air_big"}
			}		
		}		
	}	
	{on "start_atgw"	
		{if not "blocked"
			{set "blocked" 1}
			{ani_play "fly" loop}	
			{add_view "atgw_tail_fx" 				"fly_atgw" "tail"}
			{play_sound "fly_atgw" 1}
			{view start "fly_atgw"}
			{view show "fly_atgw"}
		}	
	}	
	{on "start_thermite_small"	
		{if not "blocked"
			{set "blocked" 1}
			{start_sound "detonation/phosphorus_start/"}
			{spawn "fraction_thermite_fast" }
			{spawn "ex_air_norm7"}					
			{burn volume "body" fx "thermite_hit" time 8 fake even_law}
			{fire volume "body" radius 0.2 heating 6  time 8 follow}		
		}	
	}	
	{on contact
		{if volume "detonate"	
			{spawn "distant_big_expl"}
			{spawn "fraction_spawn"}
			{spawn "ex_air_big"}
			{stuff_detonate}		
		}
	}
	{on "start_pg7v"		
		{if not "blocked"
			{ani_play "open" 1}	
			{ani_play "fly" loop}	
			{add_view "rpg7_start" 				"start_pg7v" "tail"}
			{add_view "rpg7_tail_fx" 			"fly_pg7v" "tail"}
			{add_view "rpg7_end" 				"end_pg7v" "tail"}
			{view start "start_pg7v"}
			{view show "start_pg7v"}
			;{start_sound 		"weapon/reactive/move/rpg7/rocket_oneshot"}				
			{play_sound "start_fly_rpg" }
			{set "blocked" 1}
			{view pause "fly_pg7v"}
			{view pause "end_pg7v"}
			{delay 0.05
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail00"}
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail01"}
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail02"}
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail03"}
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail04"}
				{add_view "start_stage2" 		"start_fly_pg7v" "fx_tail05"}
				{view start "start_fly_pg7v"}
				{view show "start_fly_pg7v"}
				{view stop "start_pg7v"}
				{view hide "start_pg7v"}
			}
			{delay 0.1
				{play_sound "fly_rpg" 1}
				{view stop "start_fly_pg7v"}
				{view hide "start_fly_pg7v"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail00"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail01"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail02"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail03"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail04"}
				{add_view "rpg7_tail_small_fx" 		"fly_pg7v" "fx_tail05"}
				{view start "fly_pg7v"}
				{view show "fly_pg7v"}
			}
			{delay 1.7
				{view stop "fly_pg7v"}
				{view hide "fly_pg7v"}
				{stop_sound "fly_rpg" }
				{view start "end_pg7v"}
				{view show "end_pg7v"}
			}		
		}		
	}	
	{on "start_og7v"		
		{if not "blocked"
			{ani_play "open" 1}	
			{add_view "rpg7_start" 				"start_og7v" "tail"}
			{add_view "rpg7_tail_fx" 			"fly_og7v" "tail"}
			{add_view "rpg7_end" 				"end_og7v" "tail"}					
			{set "blocked" 1}
			;{start_sound 		"weapon/reactive/move/rocket_oneshot"}				
			{play_sound "start_fly_rpg" }
			{view start "start_og7v"}
			{view show "start_og7v"}
			{view hide "fly_og7v"}
			{view hide "end_og7v"}
			{delay 0.15 
				{view stop "start_og7v"}
				{view hide "start_og7v"}
				{play_sound "fly_rpg" 1}
				{view start "fly_og7v"}
				{view show "fly_og7v"}
			}
			{delay 1
				{view stop "fly_og7v"}
				{view hide "fly_og7v"}
				{view start "end_og7v"}
				{view show "end_og7v"}
			}		
			{delay 2.5
				{stop_sound "fly_rpg" }
				{view stop "end_og7v"}
				{view hide "end_og7v"}
			}		
			{delay 3
				{spawn "distant_big_expl"}
				{spawn "fraction_spawn"}
				{spawn "ex_air_big"}
				{spawn "block_detonate"}
			}		
		}		
	}
	{on animation_event "start_panzerschreck"	
		{call "start_panzerschreck"}	
	}
	{on animation_event "start_atgw_skir"	
		{call "start_atgw_skir"}	
	}
	{on animation_event "start_small_slug"	
		{call "start_small_slug"}	
	}
	{on animation_event "start_small_trace"	
		{call "start_small_trace"}	
	}
	{on animation_event "start_thermite_small"	
		{call "start_thermite_small"}	
	}
	{on animation_event "start_rpg29"	
		{call "start_rpg29"}	
	}
	{on animation_event "start_9m39"	
		{call "start_9m39"}	
	}
	{on animation_event "start_s8"	
		{call "start_s8"}	
	}
	{on animation_event "start_tbg7v"	
		{call "start_pg7v"}	
	}
	{on animation_event "start_pg7vl"	
		{call "start_pg7v"}	
	}
	{on animation_event "start_pg7vs"	
		{call "start_pg7v"}	
	}
	{on animation_event "start_pg7vr"	
		{call "start_pg7v"}	
	}
	{on animation_event "start_og7v"	
		{call "start_og7v"}	
	}
	{on animation_event "start_pg7v"	
		{call "start_pg7v"}	
	}
	{on animation_event "start_cg"	
		{call "start_cg"}	
	}
	{on animation_event "start_cg_heat"	
		{call "start_cg_heat"}	
	}
	{on animation_event "start_xm109"	
		{call "start_xm109"}	
	}
	{on animation_event "start_5m_fg"	
		{call "start_5m_fg"}	
	}
	{on animation_event "start_5m"	
		{call "start_5m"}	
	}
	{on animation_event "start_5r"	
		{call "start_5r"}	
	}
	{on animation_event "start_5r_fg"	
		{call "start_5r_fg"}	
	}
	{on animation_event "start_5r_ap"	
		{call "start_5r_ap"}	
	}
	{on animation_event "start_23mm"	
		{call "start_23mm"}	
	}
	{on animation_event "start_57mm"	
		{call "start_57mm"}	
	}
	{on animation_event "start_tow"	
		{call "start_tow"}
		{if rand 0.1
			{call "fly_tow"}			
		}			
	}
	{on animation_event "start_atgw"	
		{call "start_atgw"}
	}
	{on animation_event "start_small"	
		{call "start_small"}	
	}
	{on animation_event "open_bullet"
		{delay 1
			{tags add "open"}
		}
	}
	{on animation_event "atgm_aa"	
		;{spawn "atgm_warning" "atgm_aa" x} ; not work on bullet
	}
	{on animation_event "start_tail_82mm"	
		{call "start_82mm_mortar"}	
	}
	{on animation_event "start_tail_cluster"	
		{call "start_cluster"}	
	}
	{on animation_event "blast_small"	
		{call "blast_small"}	
	}
}

