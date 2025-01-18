{"tree"
	{inflammation_time 35}
	{on spawn
		{link_sound "amb_emitters" "amb_emitters/tree"}
		{link_sound "burn_crown" "fire/crown"}
		{link_sound "burn_tree" "fire/tree"}
		{mtl_enable_skin 0}
		;{use_local_light 1}
		{view hide "shadow_fall"}
		{call "update_texmod"}
		{call "amb_emitters"}
	}
	(define "stir"
		{if not "bare"
			{if not "started"
				{mtl_enable_skin 1}
				{ani_play "stir" 1.0 %params}
				{set "started" 1}
			}
			{if not burned
				{start_sound "push/tree_crown"}
			}
		}
	)
	{on "amb_emitters"
		{if not fallen
			{delay 120 40
				{if rand 0.7
					{if not burned
						{if not fallen
							{play_sound "amb_emitters" }
							{call "amb_emitters"}
						}
					}
				}
			}
		}
	}
	{on "stir"
		{call "snow_fall"}
		("stir" params(loop callback))
	}
	(define "stir_slow"
		{if not "bare"
			{if not "started"
				{mtl_enable_skin 1}
				{ani_play "stir" 0.2 %params}
				{set "started" 1}
			}
		}
	)
	{on overlap begin sync
		{if not effector "obstacle"
			{if effector "fx_obstacles"
				{if not tagged "overlap"
					("stir_slow" params(loop callback))
					{tags add "overlap" }
					;{set "overlap" 1}
				}
				{with_effector
					{delete}
				}
			else effector "grenade"
				{volumes disable overlap}
				{delay 0.5
					{volumes enable overlap}
				}
				{spawn "bush_hit_small"}
				{mtl_enable_skin 1}
				{ani_play "stir" 1.7}
	;		else effector "shoots_heavy"
	;			{if rand 0.7
	;				{burn fx "smoke_aero_small" time 0.5 fake}				
	;			}
	;			{start_sound "hit/small/bush/big"}
	;			{mtl_enable_skin 1}
	;			{ani_play "stir" 3}
			else effector "animal"
				{if not fallen
					{tags add "overlap" }
					;{set "overlap" 1}
					{start_sound "animal/donkey/bush/"}	
					{call "stir"}
				}
			else effector "fx_obstacles_fast"
				{mtl_enable_skin 1}
				{ani_play "stir" 1.7}
				{with_effector
					{delete}
				}
			else 
				{if not fallen
					{tags add "overlap" }
					;{set "overlap" 1}
					{call "stir"}
				}
			}
		}
	}
	{on overlap end
		{delay 2 0.5
			{tags remove "overlap" }
			;{set "overlap" 0}
			{ani_stop "stir"}
		}
	}
	{on animation_end "stir"
		{if not tagged "overlap"
			{if "started"
				{set "started" 0}
				{ani_stop "stir"}
				{mtl_enable_skin 0}
			}
		}
	}
	{on bullet_hit overload
		{if volume "crown"
			{volumes disable bullet}
			{delay 0.5
				{volumes enable bullet}
			}
			{if stuff "zenite th"
				{spawn "bush_hit_zenite"}
				{kill_delay "stir"}
				{burn volume fx "rex_emitters_bush" time 2 fake even_law}
				{mtl_enable_skin 1}
				{ani_play "stir" 1}
				{delay 0.3 "stir"
					{ani_play "stir" 0.5 loop callback}	
					{delay 3 "stir"
						{ani_stop "stir"}	
					}
				}
			else stuff "rocketlauncher"
				{if rand 0.3
					{burn fx "smoke_barrel_small4" time 2 fake}
					{fire radius 0.1 time 0.5 heating 1}				
				}
				{spawn "bush_hit_zenite"}
				{kill_delay "stir"}
				{burn volume fx "rex_emitters_bush" time 2 fake even_law}
				{mtl_enable_skin 1}
				{ani_play "stir" 1}
				{delay 0.3 "stir"
					{ani_play "stir" 0.5 loop callback}	
					{delay 3 "stir"
						{ani_stop "stir"}	
					}
				}
			else stuff "shell"
				{if rand 0.01
					{burn fx "smoke_barrel_small4" time 2 fake}
					{fire radius 0.1 time 0.5 heating 1}				
				}
				{spawn "bush_hit_big"}
				{ani_play "stir" 3}
				{kill_delay "stir"}
				{if rand 0.7
					{burn volume fx "rex_emitters_bush" time 1 fake even_law}
				}
				{if rand 0.1
					{fire radius 0.1 time 0.5 heating 0.2}				
				}
				{mtl_enable_skin 1}
				{delay 0.3 "stir"
					{ani_play "stir" 1 loop callback}	
					{delay 3 "stir"
						{ani_stop "stir"}	
					}
				}
			else stuff "zenite"
				{spawn "bush_hit_zenite"}
				{kill_delay "stir"}
				{if rand 0.3
					{burn volume fx "rex_emitters_bush" time 1 fake even_law}
				}
				{mtl_enable_skin 1}
				{ani_play "stir" 1}
				{delay 0.3 "stir"
					{ani_play "stir" 0.5 loop callback}	
					{delay 3 "stir"
						{ani_stop "stir"}	
					}
				}
			else stuff "grenade"
				{spawn "bush_hit_zenite"}
				{kill_delay "stir"}
				{if rand 0.3
					{burn volume fx "rex_emitters_bush" time 1 fake even_law}
				}
				{mtl_enable_skin 1}
				{ani_play "stir" 1}
				{delay 0.3 "stir"
					{ani_play "stir" 0.5 loop callback}	
					{delay 3 "stir"
						{ani_stop "stir"}	
					}
				}
			else stuff "bullet"
				{spawn "bush_hit_small"}
				{kill_delay "stir"}
				{if rand 0.3
					{burn volume fx "rex_emitters_bush" time 1 fake even_law}
				}
				{mtl_enable_skin 1}
				{ani_play "stir" 0.4}
				{mtl_enable_skin 1}
			}
		 else volume "bole"
			{if stuff "zenite fg"
				{call "stir"}
				{spawn "wood_hit_small"}
				{spawn "ex_air_norm7"}					
			else stuff "zenite th"
				{call "stir"}
				{spawn "wood_hit_small"}
				{fire radius 0.2 time 7 heating 1}
				{start_sound "detonation/phosphorus_start/"}
				{bullet_detonate}
				{burn fx "thermite_hit" time 10 fake}
				{spawn "ex_air_norm7"}					
			else stuff "zenite sp"
				{call "stir"}
				{spawn "wood_hit_small"}
				{spawn "ex_air_norm7"}					
			 else stuff "bullet"
				{spawn "wood_hit_bul"}
			 else stuff "shell"
				{spawn "tree_crush"}
				{call "stir"}
			}
		}
	}
	{on blast
		{if volume "crown"
			{call "stir"}
		else min_energy 4
			{call "start_fall"}
		}
	}
	{on contact
		{if not effector "obstacle"
			{call "stir"}
			{if effector "tank"
				{call "start_fall"}
			else effector "armored_car"
				{call "start_fall"}
			else effector "baze_machinery"
				{with_effector
					{if min_mass 1000
						{with_effector
							{call "start_fall"}
						}
					}
				}
			else effector "car"
				{if min_speed 25
					{burn volume "crown" fx "rex_emitters_bush" time 0.1 fake even_law}			
					{if rand 0.2
						{call "start_fall"}
					}
				else min_speed 5
					{spawn "hay_hit_small2"}
				else min_speed 1
				}
			else effector "airborne"
				{call "start_fall"}
			else effector "helicopter"
				{call "start_fall"}
			}
		}
	}
	{on "snow_fall"
		{if "snow"
			{if not "snow_fall"
				{set "snow_fall" 1}
				{burn volume "crown" fx "snow_fir" time 0.5 fake even_law}
				{tex_morph "_win0" 2}
			}
		}
	}
	{on "start_fall"
		{burn volume "crown" fx "tree_fall" time 2 fake even_law}			
		{start_sound "crush/medium/tree"}
		{volumes "bole" disable contact obstacle blast}
		{tags add "falling"}
		{pillar_fall}
		{call "regenerate"}
	}
	{on "tree_fall"
		{if tagged "falling"
			{start_sound "crush/medium/tree"}
			{volumes "bole" disable contact obstacle blast}
			{spawn "tree_crush"}
			{if rand 0.5
				{spawn "wood_trunk_01"	random_position 2 random_orientation}
			else
				{spawn "wood_trunk_02"	random_position 2 random_orientation}
			}
			{spawn "crushed_bush_02"	random_position 15 random_orientation}
			{spawn "crushed_bush_03"	random_position 15 random_orientation}
			{spawn "crushed_bush_04"	random_position 15 random_orientation}
			{spawn "crushed_bush_02"	random_position 15 random_orientation}
			{spawn "crushed_bush_03"	random_position 15 random_orientation}
			{spawn "crushed_bush_04"	random_position 15 random_orientation}
			{spawn "crushed_bush_01"	random_position 15 random_orientation}
			{spawn "crushed_bush_02"	random_position 15 random_orientation}
			{spawn "crushed_bush_03"	random_position 15 random_orientation}
			{spawn "crushed_bush_04"	random_position 15 random_orientation}
			{delete}
		else
			{tags add "falling"}
			{burn volume "crown" fx "tree_fall" time 3 fake even_law}			
			{start_sound "crush/medium/tree"}
			{volumes "bole" disable contact obstacle blast}
			{pillar_fall}
			{spawn "crushed_bush_01"	random_position 15 random_orientation}
			{spawn "crushed_bush_02"	random_position 15 random_orientation}
			{spawn "crushed_bush_03"	random_position 15 random_orientation}
			{spawn "crushed_bush_04"	random_position 15 random_orientation}
		}
	}
	{on ground_hit
		{if min_speed 5
			{if rand 0.5
				{spawn "crushed_bush_01" }
				{spawn "crushed_bush_02" }
				{spawn "crushed_bush_03" }
			else rand 0.2
				{spawn "crushed_bush_02" }
				{spawn "crushed_bush_03" }
				{spawn "crushed_bush_05" }
				{spawn "crushed_bush_05" }
			}
			{start_sound "hit/small/bush/big"}
			{burn volume "crown" fx "circledust_norm2" time 0.2 fake even_law}
		}
	}
	{on "fallen"
		{tags add "fallen"}
		{volumes "crown" enable overlap visible}
		{call "update_wind"}
	}
	{on "burn_volume"
		(define "burn_volume"
			{if volume %0
				{if not burned
					{if not tagged %1
						{tags add %1}
						{tags add "burned"}
						{call "update_crown_visibility"}
						{set "burned" 1}
						{delay 0.1
							{if tagged "burn_bole"
								{play_sound "burn_tree" 1}
								{burn volume %0 fx "smoke_tree_bole" time 45}
								{fire volume %0 time 40}
							else
								{play_sound "burn_crown" 1}
								{burn volume %0 fx "smoke_tree_crown" time 25}
								{fire volume %0 time 22}
								{delay 20
									{burn volume "crown" fx "fair_tree_end" time 8 4}								
								}
							}
						}
						{delay 10 5
							{if "bare"
								{play_sound "amb_emitters" }
								{tex_morph "_burned1" 3 "_burned3" 5 "_burned4" 8 "_burned5" 10 "_burned6" 12 "_burned7" 14 "_burned8" 16 "_burned9" 18 "_burned10" 21 "_burned11" 23}
							else
								{play_sound "amb_emitters" }
								{tex_morph "_burned0" 0.2 "_burned1" 3 "_burned3" 5 "_burned4" 8 "_burned5" 10 "_burned6" 12 "_burned7" 14 "_burned8" 16 "_burned9" 18 "_burned10" 21 "_burned11" 23}
							}
							{if tagged "burn_bole"
								{play_sound "burn_crown" 1}
								{burn volume "crown" fx "smoke_tree_crown" time 35 6}
								{fire volume "crown" time 25}										
							}
						}
					}
				}
				{delay 25
					{stop_sound "burn_tree" }
					{stop_sound "burn_crown" }
				}
			}
		)
		("burn_volume" args "crown" "burn_crown")
		("burn_volume" args "bole" "burn_bole")
		{call "regenerate"}
	}
	(define "set_crown_visible"
		{volumes "crown" %0 visible}
		{update_visibility_patch}
	)
	{on "update_crown_visibility"
		{if burned
			("set_crown_visible" args disable)
		else "bare"
			("set_crown_visible" args disable)
		else fallen
			("set_crown_visible" args enable)
		}
	}
	{on "update_wind"
		{if "bare"
			{depend_on_wind 1}
		else fallen
			{depend_on_wind 1}
		else
			{depend_on_wind 1}
		}
	}
	{on "update_texmod"
; uncommenting this will cause OOS in client-server mode because flags are synced but server has no render
;		{set "bare" 0}
;		{set "snow" 0}
;		{set "autlate" 0}
;		{if tex_mod "bare" "bare1" "broken" "_burned1" "_burned3" "win3"
;			{set "bare" 1}
;		else tex_mod "win" "win1" "win2"
;			{set "snow" 1}
;		else tex_mod "aut" "aut1" "aut2" "aut3" "autlate" "autlate1" "autlate2" "autlate3"
;			{set "autlate" 1}
;		}
;		{if tex_mod "_crushed"
;			{set "crushed" 1}
;		}
;		{call "update_crown_visibility"}
;		{call "update_wind"}
	}
	{on "texmod_changed"
		{call "update_texmod"}
	}
	{on "regenerate"
		{if flora_regenerate
			{delay 140
				{tags remove "crown_fall" }
				{burn stop_retry}
				{volumes "bole" enable contact blast}
				{tex_mod reset}
				{pillar_up}
				{scale from 0.1 to 1 time 10}
				{call "update_visibility_10_sec"}
			}
		}
	}
	{on "plant"
		{scale from 0.1 to 1 time 10}
		{call "update_visibility_10_sec"}
	}
	{on "update_visibility_10_sec"
		{delay 4	{update_visibility_patch}}
		{delay 7	{update_visibility_patch}}
		{delay 10	{update_visibility_patch}}
	}
}
{"ambient"
	{on spawn overload
		{link_sound "amb_emitters" "amb_emitters/tree"}
		{link_sound "burn_crown" "fire/crown"}
		{link_sound "burn_tree" "fire/tree"}
		{mtl_enable_skin 1}
		;{use_local_light 1}
		{view hide "shadow_fall"}
		{call "update_texmod"}
		{delay 15	{call "amb_emitters"}}	
	}
}



{"crushed_tree"
	{inflammation_time 40}
	{on spawn
		{link_sound "amb_emitters" "amb_emitters/tree"}
		{link_sound "burn_crown" "fire/crown"}
		{link_sound "burn_tree" "fire/tree"}
	}
	{on "amb_emitters"
		{if not fallen
			{delay 120 40
				{if rand 0.7
					{if not burned
						{if not fallen
							{play_sound "amb_emitters" }
							{call "amb_emitters"}
						}
					}
				}
			}
		}
	}
	{on "burn_volume" overload
		{if volume "bole_crushed_upper"
			{if not tagged "bole_upper" 
				{tags add "bole_upper"} 
				{burn volume "bole_upper" fx "smoke_black" time 3} ;мелкий дым bole
				{delay 8
					{play_sound "burn_tree" 1}
					{burn volume "bole_upper" fx "smoke_tree_bole" time 90};горит bole
					{fire volume "bole_upper" time 90} ; bole
					{delay 20 10
						{if not tagged "broken_upper"
							{start_sound "break/tree/crush/"} ;сломанно
							{tags add "broken_upper"}
							{delay 0.4
								{burn volume "bole_upper" fx "smoke_tree_bole_break" time 1.5};быстрый спавн искр при сломе
								{start_sound "break/tree/break_tree_final"} ;отрыв от дерева
								{tear "piece_big_tree_crush_upper" bone "bole_upper"
									;{volumes "%vol_crown" disable all}
									{impulse forward 0.1 com}						
								}						
							}
						}						
					}						
					{delay 90
						{stop_sound "burn_tree" }						
					}
				}
			}
		}		
		(define "burn_volume_crown"
			{if volume %0 ; crown
				{if not tagged %1
					{tags add %1} 
					{delay 10
						{burn volume %0 fx "smoke_black" time 3 fake even_law} ;мелкий дым crown
						{delay 4
							{play_sound "burn_crown" 1}
							{burn volume %0 fx "smoke_tree_crown" time 60 fake even_law};горит crown
							{fire volume %0 radius 4 heating 15 time 60 follow} ; crown
							{delay 60
								{stop_sound "burn_crown" }						
							}
						}
					}
				}
			}
		)
		("burn_volume_crown" args "crown" 	"burn_crown" )
		("burn_volume_crown" args "crown1" 	"burn_crown1" 	)
		("burn_volume_crown" args "crown2" 	"burn_crown2" 	)
		("burn_volume_crown" args "crown3" 	"burn_crown3" 	)
		("burn_volume_crown" args "crown4" 	"burn_crown4" 	)
		("burn_volume_crown" args "crown5" 	"burn_crown5" 	)
		("burn_volume_crown" args "crown6" 	"burn_crown6" 	)
		("burn_volume_crown" args "crown7" 	"burn_crown7" 	)
		("burn_volume_crown" args "crown8" 	"burn_crown8" 	)
		("burn_volume_crown" args "crown9" 	"burn_crown9" 	)
		("burn_volume_crown" args "crown10" "burn_crown10" 	)
		("burn_volume_crown" args "crown11" "burn_crown11" 	)
		(define "burn_volume_main"
			{if volume "%vol" ; bole
				{if not tagged "%tags"
					{tags add "%tags"} 
					{delay 10
						{burn volume "%vol" fx "smoke_black" time 12 fake even_law} ;мелкий дым bole
						;{fire volume "%vol" time 90}
						;{fire radius 2 time 85}
						{delay 8
							{fire volume "%vol" radius 2 heating 20 time 90 follow}
							{play_sound "burn_tree" 1}
							{burn volume "%vol" fx "smoke_tree_bole" time 90 fake even_law};горит bole
							;{fire volume "%vol" time 60} ; bole
							{delay 90
								{stop_sound "burn_tree" }						
							}
						}
					}
				}
			}
		)
		("burn_volume_main" 	vol(bole_main) 			tags(bole_main))
		("burn_volume_main" 	vol(bole_main1) 		tags(bole_main1))
		("burn_volume_main" 	vol(bole_main2) 		tags(bole_main2))
		("burn_volume_main" 	vol(bole_main3) 		tags(bole_main3))
		("burn_volume_main" 	vol(bole_main4) 		tags(bole_main4))
		("burn_volume_main" 	vol(bole_main5) 		tags(bole_main5))
		("burn_volume_main" 	vol(bole_main6) 		tags(bole_main6))
		(define "burn_volume_crush"
			{if volume "bole_crushed"
				{if volume "%vol" ; bole
					{if not tagged "%tags" ; burn_bole
						{tags add "%tags"} ; burn_bole2
						{tags add "burned_bole"} ; transfer burn to tear link sound
						{delay 10
							;{call "update_crown_visibility"}
							{burn volume "%vol" fx "smoke_black" time 3} ;мелкий дым bole
							{delay 8
								{play_sound "burn_tree" 1}
								{burn volume "%vol" fx "smoke_tree_bole" time 45};горит bole
								{fire volume "%vol" radius 3 heating 15  time 30 follow}
								;{fire volume "%vol" time 40} ; bole
								{delay 25
									{start_sound "break/tree/crush/"} ;сломанно
									{ani_play "%vol" 0.1 callback} ;anim crush
									{burn volume "%vol" fx "listya_fall_burned" time 3 2 fake even_law} ;женные листья
									{delay 6
										{stop_sound "burn_tree" }						
									}
								}
							}
						}
					}				
				}							
			}
		)
		("burn_volume_crush" 	vol(bole) 			tags(burn_bole))
		("burn_volume_crush" 	vol(bole1) 			tags(burn_bole1))
		("burn_volume_crush" 	vol(bole2) 			tags(burn_bole2))
		("burn_volume_crush" 	vol(bole3) 			tags(burn_bole3))
		("burn_volume_crush" 	vol(bole4) 			tags(burn_bole4))
		("burn_volume_crush" 	vol(bole5) 			tags(burn_bole5))
		("burn_volume_crush" 	vol(bole6) 			tags(burn_bole6))
		("burn_volume_crush" 	vol(bole7) 			tags(burn_bole7))
		("burn_volume_crush" 	vol(bole8) 			tags(burn_bole8))
		("burn_volume_crush" 	vol(bole9) 			tags(burn_bole9))
		("burn_volume_crush" 	vol(bole10) 		tags(burn_bole10))
		("burn_volume_crush" 	vol(bole11) 		tags(burn_bole11))
		;{call "regenerate"}
	}
	{on bullet_hit
		(define "volume_tree"
			(define "hit_tree"
				{if volume "%vol_crown"
					{if stuff %0
						{ani_play "%vol_crown" +%1 resume}	;скорость дрожанте листвы
						{start_sound "break/tree/hit/"} ;крона дерева
					}
				}
			)
			("hit_tree" args "bullet stackable small"  		0.1 )
			("hit_tree" args "bullet big ap"  	  		 	0.7 )
			("hit_tree" args "bullet big sp"  	  			0.6 )
			("hit_tree" args "zenite fg"  	  			 	0.9 )
			("hit_tree" args "zenite ap"  	  			 	0.9 )
			("hit_tree" args "zenite"  	  				 	0.7 )
			("hit_tree" args "shell"  	  				 	1   )
		)
		("volume_tree" 	vol(bole1) vol_bone(bole1_bone) vol_crown(crown1) )
		("volume_tree" 	vol(bole2) vol_bone(bole2_bone) vol_crown(crown2) )
		("volume_tree" 	vol(bole3) vol_bone(bole3_bone) vol_crown(crown3) )
		("volume_tree" 	vol(bole4) vol_bone(bole4_bone) vol_crown(crown4) )
		("volume_tree" 	vol(bole5) vol_bone(bole5_bone) vol_crown(crown5) )
		("volume_tree" 	vol(bole6) vol_bone(bole6_bone) vol_crown(crown6) )
		("volume_tree" 	vol(bole7) vol_bone(bole7_bone) vol_crown(crown7) )
		("volume_tree" 	vol(bole8) vol_bone(bole8_bone) vol_crown(crown8) )
		("volume_tree" 	vol(bole9) vol_bone(bole9_bone) vol_crown(crown9) )
	}	
	{on contact overload
		{if not effector "obstacle"
			{if effector "tank"
				{burn volume "crown" fx "rex_emitters_bush" time 2 fake even_law}			
			else effector "armored_car"
				{burn volume "crown" fx "rex_emitters_bush" time 0.1 fake even_law}			
			else effector "car"
				{if min_speed 25
					{burn volume "crown" fx "rex_emitters_bush" time 0.1 fake even_law}			
					{if rand 0.2
						{call "start_fall"}
					}
				else min_speed 5
					{spawn "hay_hit_small2"}
				else min_speed 1
				}
			else effector "airborne"
				{burn volume "crown" fx "rex_emitters_bush" time 1 fake even_law}			
			else effector "helicopter"
				{burn volume "crown" fx "rex_emitters_bush" time 1 fake even_law}			
			}
			{if contact_velocity 20
				(define "volume_tree"
					(define "hit_tree"
						{if volume "%vol"
							{tags add "%vol"}
							{burn volume "%vol_crown" fx "listya_fall" time 10 fake even_law}
							{start_sound "break/tree/break_tree_final"} ;отрыв от дерева
							{tear "piece_big_tree_crush" bone "%vol_bone"
								{volumes "%vol_crown" disable all}
								{impulse forward 0.1 com}						
							}						
						}
					)
				)
				("volume_tree" 	vol(bole1) vol_bone(bole1_bone) vol_crown(crown1) )
				("volume_tree" 	vol(bole2) vol_bone(bole2_bone) vol_crown(crown2) )
				("volume_tree" 	vol(bole3) vol_bone(bole3_bone) vol_crown(crown3) )
				("volume_tree" 	vol(bole4) vol_bone(bole4_bone) vol_crown(crown4) )
				("volume_tree" 	vol(bole5) vol_bone(bole5_bone) vol_crown(crown5) )
				("volume_tree" 	vol(bole6) vol_bone(bole6_bone) vol_crown(crown6) )
				{if volume "bole_upper"				
					{tags add "broken_upper"}
					{start_sound "break/tree/crush/"} ;сломанно
					{burn volume "crown8" fx "listya_fall" time 6 fake even_law}
					{burn volume "crown9" fx "listya_fall" time 6 fake even_law}
					{burn volume "crown10" fx "listya_fall" time 6 fake even_law}
					{delay 0.1
						{start_sound "break/tree/break_tree_final"} ;отрыв от дерева
						{tear "piece_big_tree_crush_upper" bone "bole_upper"
							{volumes "%vol_crown" disable all}
							{impulse forward 0.1 com}						
						}						
					}
				}
			}
		}
	}
	{on pierce 
		(define "volume_tree"
			(define "hit_tree"
				{if volume "%vol"
					{if stuff %0
						{ani_play "%vol_crown" +%1 resume}	;скорость дрожанте листвы
						{if rand %1
							{start_sound "break/tree/crush/"} ;сломанно
							{ani_play "%vol" %1 callback} ;anim crush
							{tags add "%vol"}
							{burn volume "%vol" fx "listya_fall" time 10 fake even_law}
						}
					}
				}
			)
			("hit_tree" args "bullet stackable small"  		0.1 )
			("hit_tree" args "bullet big ap"  	  		 	0.7 )
			("hit_tree" args "bullet big sp"  	  			0.6 )
			("hit_tree" args "zenite fg"  	  			 	0.9 )
			("hit_tree" args "zenite ap"  	  			 	0.9 )
			("hit_tree" args "zenite"  	  				 	0.7 )
			("hit_tree" args "shell"  	  				 	1   )
		)
		("volume_tree" 	vol(bole1) vol_bone(bole1_bone) vol_crown(crown1) )
		("volume_tree" 	vol(bole2) vol_bone(bole2_bone) vol_crown(crown2) )
		("volume_tree" 	vol(bole3) vol_bone(bole3_bone) vol_crown(crown3) )
		("volume_tree" 	vol(bole4) vol_bone(bole4_bone) vol_crown(crown4) )
		("volume_tree" 	vol(bole5) vol_bone(bole5_bone) vol_crown(crown5) )
		("volume_tree" 	vol(bole6) vol_bone(bole6_bone) vol_crown(crown6) )
		("volume_tree" 	vol(bole7) vol_bone(bole7_bone) vol_crown(crown7) )
		("volume_tree" 	vol(bole8) vol_bone(bole8_bone) vol_crown(crown8) )
		("volume_tree" 	vol(bole9) vol_bone(bole9_bone) vol_crown(crown9) )
	}
	(define "volume_tree"
		{on animation_end "%vol" 
			{spawn "tree_hit_small" "%vol_bone" }				
			{start_sound "break/tree/break_tree_final"} ;отрыв от дерева
			{delay 0.1 0.1
				{if tagged "burned_bole"
					{tear "piece_big_tree_crush_burned" bone "%vol_bone"
						{volumes "%vol_crown" disable all}
						{impulse forward 0.6 com}						
					}						
				else
					{tear "piece_big_tree_crush" bone "%vol_bone"
						{volumes "%vol_crown" disable all}
						{impulse forward 0.6 com}						
					}						
				}						
			}
		}						
	)
	("volume_tree" 	vol(bole1) vol_bone(bole1_bone) vol_crown(crown1) )
	("volume_tree" 	vol(bole2) vol_bone(bole2_bone) vol_crown(crown2) )
	("volume_tree" 	vol(bole3) vol_bone(bole3_bone) vol_crown(crown3) )
	("volume_tree" 	vol(bole4) vol_bone(bole4_bone) vol_crown(crown4) )
	("volume_tree" 	vol(bole5) vol_bone(bole5_bone) vol_crown(crown5) )
	("volume_tree" 	vol(bole6) vol_bone(bole6_bone) vol_crown(crown6) )
	("volume_tree" 	vol(bole7) vol_bone(bole7_bone) vol_crown(crown7) )
	("volume_tree" 	vol(bole8) vol_bone(bole8_bone) vol_crown(crown8) )
	("volume_tree" 	vol(bole9) vol_bone(bole9_bone) vol_crown(crown9) )
}


{"crown_crush"
	{on spawn
		{ani_play "crown1" 0.4 loop}		
		{ani_play "crown2" 0.4 loop}		
		{ani_play "crown3" 0.4 loop}		
		{ani_play "crown4" 0.4 loop}		
		{ani_play "crown5" 0.4 loop}		
		{ani_play "crown6" 0.4 loop}		
		{delay 1.5
			{ani_stop "crown1" }		
			{ani_stop "crown2" }		
			{ani_stop "crown3" }		
			{ani_stop "crown4" }		
			{ani_stop "crown5" }		
			{ani_stop "crown6" }			
		}
	}
	{on ground_hit
		{burn volume fx "tree_hit_big" time 0.1 fake even_law}
		{start_sound "break/tree/hit/"} ;; удар
		{ani_play "crown1" }		
		{ani_play "crown2" }		
		{ani_play "crown3" }		
		{ani_play "crown4" }		
		{ani_play "crown5" }		
		{ani_play "crown6" }		
		;{volumes disable contact_ground}
		{burn volume fx "listya_fall" time 3 fake even_law}
		{delay 1
			{tex_morph "_crushed" 0.1 }
			{ani_stop "crown1" }		
			{ani_stop "crown2" }		
			{ani_stop "crown3" }		
			{ani_stop "crown4" }		
			{ani_stop "crown5" }		
			{ani_stop "crown6" }			
		}
	}
}

{"crown_crush_burned"
	{on spawn
		{ani_play "crown1" 0.4 loop}		
		{ani_play "crown2" 0.4 loop}		
		{ani_play "crown3" 0.4 loop}		
		{ani_play "crown4" 0.4 loop}		
		{ani_play "crown5" 0.4 loop}		
		{ani_play "crown6" 0.4 loop}		
		{delay 1.5
			{ani_stop "crown1" }		
			{ani_stop "crown2" }		
			{ani_stop "crown3" }		
			{ani_stop "crown4" }		
			{ani_stop "crown5" }		
			{ani_stop "crown6" }			
		}
	}
	{on ground_hit
		{burn volume fx "tree_hit_big" time 0.1 fake even_law}
		{start_sound "break/tree/hit/"} ;; удар
		{ani_play "crown1" }		
		{ani_play "crown2" }		
		{ani_play "crown3" }		
		{ani_play "crown4" }		
		{ani_play "crown5" }		
		{ani_play "crown6" }		
		;{volumes disable contact_ground}
		{burn volume fx "listya_fall" time 3 fake even_law}
		{delay 1
			{tex_morph "_crushed" 0.1 }
			{ani_stop "crown1" }		
			{ani_stop "crown2" }		
			{ani_stop "crown3" }		
			{ani_stop "crown4" }		
			{ani_stop "crown5" }		
			{ani_stop "crown6" }			
		}
	}
}




{"ambient_big"
	{on spawn overload
		{link_sound "amb_emitters" "amb_emitters/tree"}
		{link_sound "burn_crown" "fire/crown"}
		{link_sound "burn_tree" "fire/tree"}
		{mtl_enable_skin 1}
		;{use_local_light 1}
		{view hide "shadow_fall"}
		{call "update_texmod"}
		{delay 15	{call "amb_emitters"}}	
		{use_local_light 0}
		{depend_on_wind 0}
		;{wind_detail_bending}
	}
}

{"bush"
	{inflammation_time 3}
	{on overlap begin
		{if effector "tank"
			{call "crush"}
		else effector "armored_car"
			{call "crush"}
		else effector "car"
			{call "crush"}
		else effector "airborne"
			{call "crush"}
		}
	}
	{on "crush" overload
		{if not "crushed"
			{volumes disable bullet contact blast touch overlap}
			{pillar_fall}
			{if "bare"
				{tex_morph "_burned1" 1 "_burned3" 1}
			else "snow"
				{tex_morph "_burned1" 1 "_burned3" 1}
			else
				{tex_morph "_burned0" 1 "_burned1" 1 "_burned3" 1}
			}
			{if rand 0.5
				{spawn "crushed_bush_01" }
			else rand 0.5
				{spawn "crushed_bush_02" }
			else rand 0.5
				{spawn "crushed_bush_03" }
			else rand 0.5
				{spawn "crushed_bush_04" }
			else rand 0.5
				{spawn "crushed_bush_05" }
			}
			{spawn "tree_hit_big" "root"}
			{delay 0.3
				{delete}
			}
		}
	}
	{on "burn" overload
		{if not burned
			{fire volume "crown" time 10 heating 0.3}
			{burn volume "crown" fx "smoke_dead_tree1" time 12 2}
			{tags add "burned"}
			{if prop "corn"
				{spawn "fire_mark_2" random_orientation}
			}
			{if "bare"
				{tex_morph "_burned1" 5 "_burned3" 5}
			else "snow"
				{tex_morph "_burned1" 5 "_burned3" 5}
			else
				{tex_morph "_burned0" 3 "_burned1" 3 "_burned3" 3}
			}
			{delay 10
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
			{call "regenerate"}
		}
	}
	{on "stir" overload
		{call "snow_fall"}
		{if fogged
			("stir" params(loop fake callback))
		else
			("stir" params(loop callback))
		}
	}
	{on blast
		{if min_energy 0.75
			{if not tagged "crown_fall"
				{if not burned
					{tags add "crown_fall" }
					{if "bare"
						{tex_morph "_burned1" 0.3 "_burned3" 0.3}
					else "snow"
						{tex_morph "_win0" 2}
					else
						{tex_morph "_burned0" 0.2 "_burned1" 0.2 "_burned3" 0.2}
					}
					{if "snow"
						{spawn "snow_hit_small" no_position}
					else "autlate"
						{spawn "tree_hit_big_out"}
					else not "bare"
						{spawn "tree_hit_big"}
					}
					{call "regenerate"}
				}
			else
				{pillar_fall}
				{delay 0.1
					{delete}
				}
				{if rand 0.5
					{spawn "crushed_bush_05" }
					{spawn "crushed_bush_02" }
				else rand 0.4
					{spawn "crushed_bush_05" }
					{spawn "crushed_bush_02" }
				else rand 0.4
					{spawn "crushed_bush_01" }
					{spawn "crushed_bush_02" }
				}
				{spawn "tree_hit_big" "root"}
			
			}
		}
	}
}




{"bush_tiny"
	{on spawn
		{use_local_light 0}
		{depend_on_wind 1}
		{wind_detail_bending}
	}
	{inflammation_time 25}
	{on overlap begin
		{if effector "tank"
			{call "crush"}
		else effector "armored_car"
			{ani_play "stir" 0.4}	
			{if rand 0.5
				{call "crush"}
			}
		else effector "car"
			{ani_play "stir" 0.3}	
			{if rand 0.3
				{call "crush"}
			}
		else effector "airborne"
			{if rand 0.5
				{call "crush"}
			}
		else effector "human"
			{ani_play "stir" 0.2 }		
		else effector "pest_base"
			{ani_play "stir" 0.2 }		
			{start_sound "generation_zero/characters/pest/move/twigs/"}	
		else effector "distant_big_grass"
			{if rand 0.7
				{spawn "dust_bodyfals" "basis"}
			}
			{ani_play "stir" 1.2}				
			{delay 0.2 "stir"
				{ani_play "stir" 0.7 loop}	
				{delay 1 0.5 "stir"
					{ani_stop "stir"}	
				}
			}
		else effector "distant_small_grass"
			{ani_play "stir" 0.7 }
			{volumes disable overlap}
			{delay 0.4
				{volumes enable overlap}
			}
		else effector "fx_blood"
			(define "tex_mod"
				{if tex_mod "%tex_mod"
					{if not tagged "blood"
						{tags add "blood"}
						{tags add "%tex_mod"}
						{tex_mod "%tex_mod_set"}
					}
				}
			)
			("tex_mod" tex_mod(1) 				tex_mod_set(1_blood)	 	 )
			("tex_mod" tex_mod(2) 				tex_mod_set(2_blood)	 	 )
			("tex_mod" tex_mod(3) 				tex_mod_set(3_blood)	 	 )
			("tex_mod" tex_mod(4) 				tex_mod_set(4_blood)	 	 )
			("tex_mod" tex_mod(5) 				tex_mod_set(5_blood)		 )
			("tex_mod" tex_mod(6) 				tex_mod_set(6_blood)	 	 )
			("tex_mod" tex_mod(7) 				tex_mod_set(7_blood)	 	 )
			("tex_mod" tex_mod(8) 				tex_mod_set(8_blood)	 	 )
			("tex_mod" tex_mod(9) 				tex_mod_set(9_blood)	 	 )
			("tex_mod" tex_mod(10)			 	tex_mod_set(10_blood)		 )
			("tex_mod" tex_mod(11) 				tex_mod_set(11_blood)	 	 )
			("tex_mod" tex_mod(12) 				tex_mod_set(12_blood)	 	 )
			("tex_mod" tex_mod(_winter) 		tex_mod_set(_winter_blood)	 )
			("tex_mod" tex_mod(_winter1) 		tex_mod_set(_winter1_blood)	 )
			("tex_mod" tex_mod(_winter2) 		tex_mod_set(_winter2_blood)	 )
			("tex_mod" tex_mod(_winter3) 		tex_mod_set(_winter3_blood)	 )
			("tex_mod" tex_mod(_winter4) 		tex_mod_set(_winter4_blood)	 )
			("tex_mod" tex_mod(_winter5) 		tex_mod_set(_winter5_blood)	 )
			("tex_mod" tex_mod(_winter6) 		tex_mod_set(_winter6_blood)	 )
		else effector "stuff"
			{ani_play "stir" 0.6}	
		}
	}
	{on "crush" overload
		{spawn "tree_hit_small" "basis"}
		{delete}			
	}
	{on "burn" overload
		{if not burned
			{link_sound 	"small"			"fire/small_stuff/fire_small"}
			{play_sound "small" 1}					
			{fire volume "body" radius 0.2 heating 0.4  time 15 follow}		
			{burn volume "body" fx "smoke_bush" time 9}
			{tags add "burned"}
			{if "bare"
				{tex_morph "_burned1" 5 "_burned3" 5}
			else "snow"
				{tex_morph "_burned1" 5 "_burned3" 5}
			else
				{tex_morph "_burned0" 3 "_burned1" 3 "_burned3" 3}
			}
			{delay 15
				{stop_sound "small" }
				{call "crush"}
				{if rand 0.5
					{spawn "impact_burnmark_02_blend" }
				}
			}
		}
	}
	{on blast
		{if min_energy 1.5
			{call "crush"}
		else
			{ani_play "stir" 0.4 loop}	
			{delay 1 0.5 "stir"
				{ani_stop "stir"}	
			}
		}
	}
}

{"bush crushable"
	{on overlap begin
		{if effector "vehicle"
			{if not "crushed"
				{set "crushed" 1}
				{tex_morph "_crushed" 0.2}
			}
		}
	}
}

{"wheat"
	{inflammation_time 2}
	{on "burn" overload
		{if not burned
			{fire radius 2 time 3 heating 0.3}
			{burn volume "crown" fx "smoke_dead_tree1" time 3 1}
			{tags add "burned"}
			{if "bare"
				{tex_morph "_burned1" 3 "_burned3" 3}
			else
				{tex_morph "_burned0" 2 "_burned1" 2 "_burned3" 2}
			}
			{delay 4
				{call "burn_end"}
			}
			{call "update_crown_visibility"}
		}
		{call "regenerate"}
	}
}

{"cornfield"
	{on overlap begin
		{if effector "tank"
			{call "crush"}
		else effector "armored_car"
			{call "crush"}
		else effector "car"
			{call "crush"}
		else effector "airborne"
			{call "crush"}
		}
	}
	{on "crush" overload
		{if not "crushed"
			{set_skeleton "_x"}
			{tags add "crushed"}
			{spawn "tree_hit_big" "root"}
			{start_sound "push/tree_crown"}
			;{tex_mod "dead"}
			{volumes disable visible bullet contact blast touch overlap}
		}
	}
}


;{"delete_after_burn"
;	{on "burn_end"
;		{hide 2}
;	}
;}

{"delete_after_burn stamp"
	{on "burn_end"
		{spawn "burn_grass1"}
	}
}

{"delete_after_blast"
	{on blast
		{if min_energy 0.8
			{hide 0.6}
		}
	}
}

{"no_wind"
	{on "update_wind" overload
		{depend_on_wind 0}
	}
}

{"invisible_crown"
	{on "update_crown_visibility" overload
		("set_crown_visible" args disable)
	}
}

{"cabbage"
	{inflammation_time 10000}
	{on bullet_hit overload
		{if rand 0.2
			{call "crush"}
		else
			{if rand 0.3
				{spawn "tree_hit_small"}
			}
		}
	}
	{on blast_hit
		{if min_energy 1
			{call "crush"}
		else
			{impulse up 2 1 dir 2 1}
		}
	}
	{on contact
		{if effector "human"
			{volumes "crown" disable contact}
			{if rand 0.3
				{call "crush"}
			}
			{delay 0.5
				{volumes "crown" enable contact}
			}
		else
			{call "crush"}
		}
	}
	{on "crush"
		{spawn "tree_hit_small"}
		{delay 0.2
			{spawn "cabbage_destroy1" no_position no_normal}
		}
		{hide 0.3}
	}
}

{"tree normal_light"
	{on spawn
		{use_local_light 0}
	}
}

{"stack_bush"
	{on spawn
		{use_local_light 0}
	}
}

{"wind_has_foliage"
	{on spawn
		{depend_on_wind 1}
		{wind_detail_bending}
	}
}

{"tree foliage"
	(define "foliage"
		{add_view "foliage" "foliage" "foliage%0"}
	)
	{on spawn
		("foliage" args 00) ("foliage" args 01) ("foliage" args 02) ("foliage" args 03) ("foliage" args 04)
		("foliage" args 05) ("foliage" args 06) ("foliage" args 07) ("foliage" args 08) ("foliage" args 09)
		("foliage" args 10) ("foliage" args 11) ("foliage" args 12) ("foliage" args 13) ("foliage" args 14)
		("foliage" args 15) ("foliage" args 16) ("foliage" args 17) ("foliage" args 18) ("foliage" args 19)
		("foliage" args 20) ("foliage" args 21) ("foliage" args 22) ("foliage" args 23) ("foliage" args 24)
		("foliage" args 25) ("foliage" args 26) ("foliage" args 27) ("foliage" args 28) ("foliage" args 29)
		("foliage" args 30) ("foliage" args 31) ("foliage" args 32) ("foliage" args 33) ("foliage" args 34)
		("foliage" args 35) ("foliage" args 36) ("foliage" args 37) ("foliage" args 38) ("foliage" args 39)
		("foliage" args 40) ("foliage" args 41) ("foliage" args 42) ("foliage" args 43) ("foliage" args 44)
		("foliage" args 45) ("foliage" args 46) ("foliage" args 47) ("foliage" args 48) ("foliage" args 49)
	}
}
{"tree large"
	{on blast overload
		{if volume "crown"
			{call "stir"}
		else min_energy 13
			{call "start_fall"}
		else min_energy 2
			{call "snow_fall"}
		}
	}
	{on contact overload
		{if not effector "obstacle"
			{call "stir"}
			{call "snow_fall"}
		}
	}
}
