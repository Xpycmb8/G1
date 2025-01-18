(define "shoot_cloud"
	{"stuff weapon %stuff"
		{on "reload"
			{if tagged "fire_move"		
				{start_sound "weapon/clear/%sound/"}
			}
		}
	}
)		
("shoot_cloud" stuff(mgun)					sound(mgun)		)
("shoot_cloud" stuff(assaultrifle)			sound(ar)		)
("shoot_cloud" stuff(pistol)				sound(pistol)	)		
("shoot_cloud" stuff(shotgun) 				sound(ar)		)
("shoot_cloud" stuff(smg)					sound(smg)		)


(define "add_tags_spawn"
	{"stuff weapon %tag"
		{on spawn
			{tags add "%tag"}
		}		
	}
)
("add_tags_spawn" 	tag(100_bullet) )
("add_tags_spawn" 	tag(96_bullet) )
("add_tags_spawn" 	tag(75_bullet) )
("add_tags_spawn" 	tag(70_bullet) )
("add_tags_spawn" 	tag(53_bullet) )
("add_tags_spawn" 	tag(50_bullet) )
("add_tags_spawn" 	tag(45_bullet) )
("add_tags_spawn" 	tag(40_bullet) )
("add_tags_spawn" 	tag(35_bullet) )
("add_tags_spawn" 	tag(32_bullet) )
("add_tags_spawn" 	tag(30_bullet) )
("add_tags_spawn" 	tag(25_bullet) )
("add_tags_spawn" 	tag(20_bullet) )
("add_tags_spawn" 	tag(18_bullet) )
("add_tags_spawn" 	tag(16_bullet) )
("add_tags_spawn" 	tag(15_bullet) )
("add_tags_spawn" 	tag(12_bullet) )
("add_tags_spawn" 	tag(10_bullet) )
("add_tags_spawn" 	tag(8_bullet) )
("add_tags_spawn" 	tag(7_bullet) )
("add_tags_spawn" 	tag(5_bullet) )
("add_tags_spawn" 	tag(6_bullet) )
("add_tags_spawn" 	tag(1_bullet) )

(define "shell_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%shell" "shell" "FXshell"}
			{add_view "%shell" "shell" "FXshell01"}
		}
	}
)

("shell_fx" tag(shell5)				shell(shell5))
("shell_fx" tag(shell6)				shell(shell6))
("shell_fx" tag(shell5_inv)			shell(shell5_inv))
("shell_fx" tag(shell308)			shell(shell308))
;("shell_fx" tag(shell7_free)		shell(shell7_free))
("shell_fx" tag(shell7)				shell(shell7))
("shell_fx" tag(shell7x51)			shell(shell7x51))
("shell_fx" tag(shell9)				shell(shell9))
("shell_fx" tag(shell939)			shell(shell939))
("shell_fx" tag(shell9s1)			shell(shell9s1))
("shell_fx" tag(shell11)			shell(shell11))
("shell_fx" tag(shell12)			shell(shell12))
("shell_fx" tag(shell12_ash)		shell(shell12_ash))
("shell_fx" tag(shell127x99_inv)	shell(shell127x99_inv))
("shell_fx" tag(shell12_inv)		shell(shell12_inv))

(define "shell_fx_ph"
	{"stuff weapon %tag"
		{on "fire"
			{spawn "%shell" "FXshell" x
				{impulse up 0.2 cx 0.7 com  }
			}
		}
	}
)
("shell_fx_ph" tag(shell7_free)				shell(#762_gauge))
("shell_fx_ph" tag(shell5_free)				shell(#556_gauge))


(define "loud_fx"
	{"stuff weapon %stuff"
		{on "fire"
			{if altitude 1;stand
			else altitude 0.3;seat
			else altitude 0.1;lie
				{spawn "dust_lie_weapon" "foresight3" x}
			}
			{spawn "distant_small_grass_set" "foresight3" x}
			{start_sound "weapon/shoot_loud/far/%sound"}	
			;{start_sound "weapon/shoot_loud/close/%sound"}	
			{if not prop "silenced"
				{if not prop "silenced_small"
					{spawn "distant_small" "foresight3" }
				}
			}
		}	
	}
)		
("loud_fx" stuff(DP27_set) 							sound(DP27_distant) 					)
("loud_fx" stuff(DS39_set) 							sound(DS39_distant) 					)
("loud_fx" stuff(G41_set) 							sound(G41_distant) 					)
("loud_fx" stuff(G43_set) 							sound(G43_distant) 					)
("loud_fx" stuff(K98k_set) 							sound(K98k_distant) 					)
("loud_fx" stuff(M9130_set) 						sound(M9130_distant) 					)
("loud_fx" stuff(MG13_set) 							sound(MG13_distant) 					)
("loud_fx" stuff(MG34_set) 							sound(MG34_distant) 					)
("loud_fx" stuff(MG42_set) 							sound(MG42_distant) 					)
("loud_fx" stuff(SG43_set) 							sound(SG43_distant) 					)
("loud_fx" stuff(SVT40_set) 						sound(SVT40_distant) 					)
("loud_fx" stuff(heavy_shoot) 						sound(heavy) 					)
("loud_fx" stuff(rocketlauncher) 					sound(rpg)			)
("loud_fx" stuff(assaultrifle_silenced_set) 		sound(ar_sup)	)
("loud_fx" stuff(assaultrifle_set) 					sound(ar)				)		
("loud_fx" stuff(pistol_silenced_set) 				sound(pistol_sup)			)
("loud_fx" stuff(pistol_set) 						sound(pistol)					)
("loud_fx" stuff(shotgun_silenced_set) 				sound(shotgun_sup)			)
("loud_fx" stuff(shotgun_set) 						sound(shotgun)					)
("loud_fx" stuff(shortsmg_silenced_set) 			sound(ar_sup)			)
("loud_fx" stuff(shortsmg_set) 						sound(ar)					)		
("loud_fx" stuff(sniper_silenced_set) 				sound(sniper_sup)			)	
("loud_fx" stuff(sniper_set) 						sound(sniper)					)	
("loud_fx" stuff(rifle_silenced_set) 				sound(ar_sup)			)
("loud_fx" stuff(rifle_set) 						sound(ar)					)
("loud_fx" stuff(at_rifle_silenced_set) 			sound(sniper_sup)			)	
("loud_fx" stuff(at_rifle_set) 						sound(heavy)					)			
("loud_fx" stuff(mgun_silenced_set) 				sound(mgun_silenced)			)	
("loud_fx" stuff(mgun_set) 							sound(lmg)						)		
("loud_fx" stuff(smg_silenced_set) 					sound(pistol_sup)			)	
("loud_fx" stuff(smg_set) 							sound(pistol)					)	

;-goh_ww
(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight%foresight"}
			else
				{add_view "flash_gun_silencer" "flashbarrel" "foresight%foresight"}
			}
		}
	}
)

("flash_fx" tag(pistol)			flash(flash_gun_small)	foresight(3))
("flash_fx" tag(smg)			flash(flash_gun_small)	foresight(11))
("flash_fx" tag(rifle)			flash(flash_gun_rifle)	foresight(12))
("flash_fx" tag(mgun)			flash(flash_gun_big)	foresight(14))
("flash_fx" tag(at_rifle)		flash(flash_gun_atrifle)foresight(18))
("flash_fx" tag(shotgun)		flash(flash_shotgun)	foresight(3))



{"heat_small"
	{on spawn
		{add_view 	"heat_stage1" 					"stage1" "fx_main"}
		{add_view 	"heat_stage2_small" 			"stage2" "fx_main"}
		{add_view 	"muzzle_single" 				"fx_muzzle_heat" "fx_main"}
		{add_view 	"muzzle_single_heavy" 			"fx_muzzle_heat_full" "fx_main"}
	}
	{on "reload"
		{tags remove "heat50"}
		{if tagged "fire_hold"					
			{ani_play "stage1" -0.1 resume }
			{ani_play "stage2" -0.1 resume }
		}
	}
	{on "fire"
		{kill_delay "heat50"}
		{if not tagged "heat50"				
			{tex_morph "_heat1" 7}
			{tags add "heat50"}
			{ani_play "stage1" +0.7 resume callback}
			{ani_play "stage2" +0.3 resume callback}
		}
		{delay 2 "heat50"
			{ani_play "stage1" -0.5 resume }
			{ani_play "stage2" -0.2 resume }
			{tex_morph "_heat0" 6}
			{tags remove "heat50"}
		}
		{if tagged "stage1"
			{if rand 0.7
				{view start "fx_muzzle_heat"}
			}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
			{if rand 0.06
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{if tagged "stage2"
			{if rand 0.7
				{view start "fx_muzzle_heat_full"}
			}
			{delay 0.04 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
			{if rand 0.1
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
	}
	{on animation_end "stage1"
		{view start "stage1"}
		{delay 2 1 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "recoil" fx "smoke_heat_barrel" time 3 fake even_law}
		{burn volume "barrel" fx "smoke_heat_barrel" time 7 fake even_law}
		{burn volume "handguard" fx "smoke_heat_barrel" time 7 fake even_law}
		{tags add "stage1"}
	}
	{on animation_end "stage2"
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 5 
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "handguard" fx "smoke_heat_barrel" time 5 fake even_law}
		{burn volume "muzzle" 	 fx "smoke_heat_barrel" time 8 fake even_law}
		{burn volume "recoil"	 fx "smoke_heat_barrel" time 12 fake even_law}
		{burn volume "barrel"	 fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
}


{"heat50"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle_heat" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point05"}

		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point00"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point01"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point02"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point03"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point04"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point05"}

		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point00"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point01"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point02"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point03"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point04"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point05"}


		{add_view 	"heat_stage1" 		"stage1" "fx_main"}
		{add_view 	"heat_stage2" 		"stage2" "fx_main"}
	}
	{on "reload"
		{if tagged "fire_hold"					
			{ani_play "stage1" -0.1 resume }
			{ani_play "stage2" -0.1 resume }
		}
	}
	{on "fire"
		{if tagged "stage1"
			{if rand 0.7
				{view start "fx_muzzle_heat"}
			}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{if tagged "stage2"
			{if rand 0.7
				{view start "fx_muzzle_heat_full"}
			}
			{delay 0.04 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{kill_delay "heat50"}
		{if not tagged "heat50"				
			{ani_play "stage1" +1.0 resume callback}
			{ani_play "stage2" +0.5 resume callback}
			{tags add "heat50"}
		}
		{delay 3 "heat50"
			{ani_play "stage1" -0.5 resume }
			{ani_play "stage2" -0.2 resume }
			{tags remove "heat50"}
		}
	}
	{on animation_end "stage1"
		{view start "stage1"}
		{delay 4 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "heat" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
	}
	{on animation_end "stage2"
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 8 
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "heat" fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
}


{"heat100"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle_heat" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point05"}

		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point00"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point01"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point02"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point03"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point04"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point05"}

		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point00"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point01"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point02"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point03"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point04"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point05"}


		{add_view 	"heat_stage1_fire" 	"stage1_fire" "fx_main"}
		{add_view 	"heat_stage1" 		"stage1" "fx_main"}
		{add_view 	"heat_stage2" 		"stage2" "fx_main"}
	}
	{on "reload"
		{if tagged "fire_hold"					
			{ani_play "stage1" -0.05 resume }
			{ani_play "stage2" -0.05 resume }
		}
	}
	{on "fire"
		{if tagged "stage1"
			{if rand 0.7
				{view start "fx_muzzle_heat"}
			}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{if tagged "stage2"
			{view start "stage2"}
			{delay 5 "heat100"
				{view hide	"stage2"}
				{view pause	"stage2"}
			}
			{if rand 0.7
				{view start "fx_muzzle_heat_full"}
			}
			{delay 0.04 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{kill_delay "heat100"}
		{if not tagged "heat100"				
			{ani_play "stage1" +1.0 resume callback}
			{ani_play "stage2" +0.5 resume callback}
			{tags add "heat100"}
		}
		{delay 5 "heat100"
			{ani_play "stage1" -0.2 resume }
			{ani_play "stage2" -0.1 resume }
			{tags remove "heat100"}
		}
	}
	{on animation_end "stage1"
		{view start "stage1_fire"}
		{view start "stage1"}
		{burn volume "barrel" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
		{delay 1 0.5
			{view hide	"stage1_fire"}
			{view pause	"stage1_fire"}
		}
		{delay 4 
			{tags remove "stage1"}
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
	}
	{on animation_end "stage2"
		{play_sound "heat" 1}
		{start_sound "weapon/heat/overheat"}	
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 8 
			{tags remove "stage2"}
			{stop_sound "heat"}
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "barrel" fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
}

{"heat100_slowfire"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle_heat" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle_heat" "fx_point05"}

		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point00"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point01"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point02"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point03"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point04"}
		{add_view 	"muzzle_single_heavy" 	"fx_muzzle_heat_full" "fx_point05"}

		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point00"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point01"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point02"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point03"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point04"}
		{add_view 	"muzzle_single_heavy2" 	"fx_muzzle_heat_full2" "fx_point05"}


		{add_view 	"heat_stage1_fire" 	"stage1_fire" "fx_main"}
		{add_view 	"heat_stage1" 		"stage1" "fx_main"}
		{add_view 	"heat_stage2" 		"stage2" "fx_main"}
	}
	{on "reload"
		{if tagged "fire_hold"					
			{ani_play "stage1" -0.1 resume }
			{ani_play "stage2" -0.1 resume }
		}
	}
	{on "fire"
		{if tagged "stage1"
			{if rand 0.7
				{view start "fx_muzzle_heat"}
			}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle_heat"}
				{view pause	"fx_muzzle_heat"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{if tagged "stage2"
			{if rand 0.7
				{view start "fx_muzzle_heat_full"}
			}
			{delay 0.04 "fire"
				{view hide	"fx_muzzle_heat_full"}
				{view pause	"fx_muzzle_heat_full"}
			}
			{if rand 0.01
				{spawn "spark_small_gun_heat" "foresight3" x}
			}
		}
		{kill_delay "heat100"}
		{if not tagged "heat100"				
			{ani_play "stage1" +1.0 resume callback}
			{ani_play "stage2" +0.5 resume callback}
			{tags add "heat100"}
		}
		{delay 5 "heat100"
			{ani_play "stage1" -0.2 resume }
			{ani_play "stage2" -0.1 resume }
			{tags remove "heat100"}
		}
	}
	{on animation_end "stage1"
		{view start "stage1_fire"}
		{view start "stage1"}
		{delay 1 0.5
			{view hide	"stage1_fire"}
			{view pause	"stage1_fire"}
		}
		{delay 4 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "barrel" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
	}
	{on animation_end "stage2"
		{play_sound "heat" 1}
		{start_sound "weapon/heat/overheat"}	
		{tags add "heat_full"}		
		{view start "stage2"}
		{delay 8 
			{stop_sound "heat"}
			{tags remove "heat_full"}		
			{view hide	"stage2"}
			{view pause	"stage2"}
		}
		{if tagged "fire_hold"				
			{start_sound "weapon/heat/"}
		}
		{burn volume "barrel" fx "smoke_heat_barrel" time 8 fake even_law}
		{tags add "stage2"}
	}
}




{"stuff weapon sniper silenced quiet_sniper"
	{on spawn
		{add_view 	"flash_gun_silencer" 		"fx_main" "foresight3"}
		{add_view 	"smoke_sil" 				"fx_fire_hot" "foresight3"}
		{view hide	"fx_fire_hot"}
		{view pause	"fx_fire_hot"}
	}
	{on animation_event "clear_casing"
		{start_sound "weapon/shell_eject/shell12"}	
		{if tagged "transform"
			{tear "shell_drop" bone "shell" copy ;slicer_tail
				{burn volume "shell" fx "smoke_mist_run" time 2 fake even_law}
				{impulse forward 2 com  }
			}
		else
			{tear "shell_drop" bone "shell" copy ;slicer_tail
				{impulse forward 2 com  }
			}
		}		
	}		
	{on "fire" 
		{if rand 0.1
			{spawn "sparks01s" "foresight3" x}
		else rand 0.1
			{spawn "sparks02s" "foresight3" x}
		else rand 0.1
			{spawn "sparks03s" "foresight3" x}
		}	
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1.4 0.7 "fire_hot"
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
	}
}


{"stuff weapon sniper silenced"
	{on spawn
		{add_view 	"flash_gun_silencer" 		"fx_muzzle" "foresight3"}
		{add_view 	"smoke_sil" 				"fx_tail" "foresight3"}
		{view hide	"fx_muzzle"}
		{view pause	"fx_muzzle"}
	}
	{on "fire"
		{if not tagged "shoot_m203"
			{if rand 0.05
				{spawn "sparks01s" "foresight3" x}
			else rand 0.05
				{spawn "sparks02s" "foresight3" x}
			else rand 0.05
				{spawn "sparks03s" "foresight3" x}
			}	
			{view start "fx_muzzle"}
			{delay 0.03 "fire"
				{view hide	"fx_muzzle"}
				{view pause	"fx_muzzle"}
				{view start "fx_tail"}
				{delay 1.5 "tail"
					{view hide	"fx_tail"}
					{view pause	"fx_tail"}
				}
			}
		}
	}
}


{"stuff weapon silenced_small"
	{on spawn
		{add_view 	"flash_gun_silencer_small" 		"fx_main" "foresight3"}
		{add_view 	"smoke_sil_small" 				"fx_fire_hot" "foresight3"}
		{view hide	"fx_main"}
		{view pause	"fx_main"}
		{view hide	"fx_fire_hot"}
		{view pause	"fx_fire_hot"}
	}
	{on "fire"
		{if rand 0.1
			{spawn "sparks01s" "foresight3" x}
		else rand 0.1
			{spawn "sparks02s" "foresight3" x}
		else rand 0.1
			{spawn "sparks03s" "foresight3" x}
		}	
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1.4 0.7 "fire_hot"
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
	}
}
{"stuff weapon silenced"
	{on spawn
		{add_view 	"flash_gun_silencer" 		"fx_main" "foresight3"}
		{add_view 	"smoke_sil" 				"fx_fire_hot" "foresight3"}
		{view hide	"fx_main"}
		{view pause	"fx_main"}
		{view hide	"fx_fire_hot"}
		{view pause	"fx_fire_hot"}
	}
	{on "fire"
		{if rand 0.1
			{spawn "sparks01s" "foresight3" x}
		else rand 0.1
			{spawn "sparks02s" "foresight3" x}
		else rand 0.1
			{spawn "sparks03s" "foresight3" x}
		}	
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1.4 0.7 "fire_hot"
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
		}
	}
}
{"stuff weapon bullet"
	{on spawn
		{add_view "smoke_heat_barrel"			"jammed"	"fxshell"}
		{add_view "smoke_heat_gun"				"jammed"	"foresight3" }
		{add_view "belt_crashed" 				"shell" "fxbelt"}
		{view hide	"led_fire"}
		{view pause	"led_fire"}
		{view hide	"led_hold"}
		{view pause	"led_hold"}
		{tex_mod "hold"}
	}
	{on "link"
		{call "weapon_warning"}
	}
	{on "unlink"
		{kill_delay "weapon_warning"}
	}
	{on "weapon_warning"
		{if active
			{spawn "weapon_warning" "foresight3" x}
		}
		{delay_effect 1
			"weapon_warning"
		}
	}
	{on "reload"
		{tags add "reload"}
		{delay 3
			{tags remove "reload"}	
		}
	}
	{on "fire"		
		;{kill_delay "fire"}
		{ani_play "hit_charm" }
;		{if not prop "silenced"
;			{if rand 0.1
;				{spawn "sparks01" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks02" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks03" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks04" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks05" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks06" "foresight3" x}
;			else rand 0.1
;				{spawn "sparks07" "foresight3" x}
;			}	
;		}	
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "trace_linear" "foresight3" x }
		{spawn "ex_w_small" "fx_fireopen" }
		;{call "check"}
		;{call "check_damage"}
	}
	{on animation_event "open_bolt_ithaca"
		{start_sound "weapon/bolt_move/ithaca/forward"}	
	}		
	{on animation_event "clear_casing_127_55hmg"
		{start_sound "weapon/shell_eject/shell127hmg"}	
	}
	{on animation_event "clear_casing_12x55"
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop_12_55" bone "shell_drop" copy ;slicer_tail
			{impulse forward 0.6 cx -0.1 0.1 com  }
		}
		{delay 0
			{view hide "shell_drop"}	
		}
	}
	{on animation_event "clear_casing_12x55_fast"
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop_12_55" bone "shell_drop" copy ;slicer_tail
			{impulse forward 3 1 cx -0.2 0.2 com  }
		}
		{delay 0
			{view hide "shell_drop"}	
		}
	}
	{on animation_event "close_bolt_ithaca"
		{start_sound "weapon/bolt_move/ithaca/back"}	
	}
	{on animation_event "open_bolt_auto"
		{spawn "fx_eject_smoke2" "shell_drop" }		
		{start_sound "weapon/bolt_move/med/mike14_raise_open"}	
	}		
	{on animation_event "close_bolt_auto"
		{start_sound "weapon/bolt_move/med/mike14_raise_close"}	
	}		
	{on animation_event "open_bolt_med"
		{spawn "fx_eject_smoke2" "shell_drop" }		
		{start_sound "weapon/bolt_move/med/mike14_raise_open"}	
	}		
	{on animation_event "open_bolt_heavy"
		{spawn "fx_eject_smoke2" "shell_drop" }		
		{start_sound "weapon/bolt_move/heavy/"}	
	}		
	{on animation_event "close_bolt_med"
		{start_sound "weapon/bolt_move/med/close_bolt_med"}	
	}		
	{on animation_event "open_bolt_lmg"
		{start_sound "weapon/bolt_move/med/lmg"}	
	}		
	{on animation_event "bullet_drop_hide"
		{view hide "shell_drop"}	
		{view hide "shell"}	
	}
	{on animation_event "bullet_drop_view"
		{view show "shell"}	
		{view show "shell_drop"}	
		{view show "shell_drop_masterkey"}	
	}
	{on animation_event "bullet_view_charge"
		{view show "bullet_view"}	
	}
	{on animation_event "bullet_hide_charge"
		{view hide "bullet_view"}	
	}
	{on animation_event "bullet_hide_empty"
		{view show "shell_drop"}	
		{view hide "bullet_view"}	
		{view hide "bullet"}	
	}
	{on animation_event "bullet_view_close"
		{view show "bullet_view"}	
		{view show "bullet"}	
	}
	{on animation_event "belt_drop"
		{view show "belt_drop"}	
		{tear "belt_drop" bone "belt_drop" copy 
			{impulse forward 4 2 cx -0.5 0.5 com}
		}
	}
	(define "clear_casing"
		{on animation_event "clear_casing_%tags"
			{start_sound "weapon/shell_eject/%shell_eject"}	
			{tear "shell_drop_%drop" bone "shell_drop" copy 
				{impulse forward 6 3 cx -1.5 1.5 com}
			}
			{delay 0
				{view hide "shell_drop"}	
			}
		}
	)
	("clear_casing" 	tags(25_59) 		drop(25_59)					shell_eject(shell25) 	impulse({impulse forward 6 3 cx -1.5 1.5 com}) )
	("clear_casing" 	tags(556_45) 		drop(556_45)				shell_eject(shell5) 	impulse({impulse forward 4 2 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(9_19) 			drop(9_19)					shell_eject(shell9) 	impulse({impulse forward 2 3 cx -0.2 0.2 com}) )
	("clear_casing" 	tags(9_19_fast) 	drop(9_19)					shell_eject(shell9) 	impulse({impulse forward 2 1 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(762_57) 		drop(762_57)				shell_eject(shell7) 	impulse({impulse forward 4 2 cx -0.5 0.5 com}) )
	("clear_casing" 	tags(12_77) 		drop(12_77)					shell_eject(shell12) 	impulse({impulse forward 0.2 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(127_55) 		drop(127_55)				shell_eject(shell12) 	impulse({impulse forward 4 2 cx -0.5 0.5 com}) )
	("clear_casing" 	tags(762_51) 		drop(762_39)				shell_eject(shell7) 	impulse({impulse forward 2 1 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(762_39) 		drop(762_39)				shell_eject(shell7) 	impulse({impulse forward 0.1 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(762_39_fast) 	drop(762_39)				shell_eject(shell7) 	impulse({impulse forward 4 2 cx -0.1 0.1 com}) )
	("clear_casing" 	tags(792_33) 		drop(792_33)				shell_eject(shell7) 	impulse({impulse forward 4 2 cx -0.5 0.5 com}) )
	("clear_casing" 	tags(545_39) 		drop(545_39)				shell_eject(shell5) 	impulse({impulse forward 2 1 cx -0.1 0.1 com}) )

	{on "check_damage"
		{if rand 0.4 
			{spawn "ex_w_small2" "fxshell" }
		}	
	}
	;{on "move_weapon"
	;	{ani_play "recoil" 1 loop}
	;}
}

; {"stuff weapon riflehand_mc"
	; {on spawn
		; {add_view 	"flash_gun_silencer" 		"fx_muzzle" "foresight3"}
		; {set "riflehand" 1}
	; }
	; {on "fire"
		; {view start "fx_muzzle"}
		; {delay 0.5 "fire2"
			; ;{play_sound "boltopen" 1}
			; {if not "reload"
				; {ani_play "recoil" 0.5}
				; {set "fire_stand" 0}
				; {delay 0.2 "shell"
					; {view start "shell"}
					; {delay 0.1 "shell2"
						; {view pause "shell"}
					; }
				; }
			; }
		; }
		; {delay 0.4 "fire"
			; {if not "reload"
				; {spawn "boltopen" }
			; }
			; {view hide	"fx_muzzle"}
			; {view pause	"fx_muzzle"}
		; }
	; }
; }


{"stuff weapon gewerh"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"fx_smoke" "foresight3"}
		{tags add "riflehand" }
	}
	{on "fire"
		{view start "fx_smoke"}
		{if rand 0.1
			{spawn "sparks01" "foresight3" x}
		else rand 0.1
			{spawn "sparks02" "foresight3" x}
		else rand 0.1
			{spawn "sparks03" "foresight3" x}
		else rand 0.1
			{spawn "sparks04" "foresight3" x}
		else rand 0.1
			{spawn "sparks05" "foresight3" x}
		else rand 0.1
			{spawn "sparks06" "foresight3" x}
		else rand 0.1
			{spawn "sparks07" "foresight3" x}
		}	
		{view start "fx_muzzle"}
		{if not tagged "reload"
			{ani_play "recoil" }
			{delay 0.5 "fire2"
				;{set "fire_stand" 0}
				{delay 0.2 "shell"
					{ani_play "armed" }
					{start_sound "weapon/shell_eject/shell308"}	
					{view start "shell"}
					{delay 0.1 "shell2"
						{view pause "shell"}
					}
				}
			}
		}
		{delay 0.4 "fire"
			{if not tagged "reload"
				{spawn "boltopen" }
			}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 1.2 
			{view pause	"fx_smoke"}
		}
	}
}


{"stuff weapon riflehand_hamr_single"
	{on spawn
		{add_view 	"muzzle_front_small2" 		"fx_muzzle_shot" "fx_main"}
		{add_view 	"sparks01" 		"sparks01" "fx_main"}
		{add_view 	"sparks02" 		"sparks02" "fx_main"}
		{add_view 	"sparks03" 		"sparks03" "fx_main"}
		{add_view 	"sparks04" 		"sparks04" "fx_main"}
		{add_view 	"sparks05" 		"sparks05" "fx_main"}
		{add_view 	"sparks06" 		"sparks06" "fx_main"}
		{add_view 	"sparks07" 		"sparks07" "fx_main"}
		{tags add "riflehand" }
	}
	{on "fire"
		{view start "fx_muzzle"}
		{delay 0.5 "fire2"
			;{play_sound "boltopen" 1}
;			{if not "reload"
			{ani_play "recoil" 0.5}
			;{set "fire_stand" 0}
			{delay 0.2 "shell"
				{view start "shell"}
				{delay 0.1 "shell2"
					{view pause "shell"}
				}
			}
;			}
		}
		{delay 0.2 "fire"
;			{if not "reload"
				{spawn "boltopen" }
;			}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}

{"stuff weapon pistol"
	{on "fire"
	}
}

(define "fire_sound"
	{"stuff weapon %stuff"
		{on spawn
			{link_sound "mid"		"weapon/shot/small_arms/%mid/"}		
			{link_sound "close"		"weapon/shot/small_arms/%close/"}		
			{link_sound "reload"	"weapon/reload/%reload/"}		
		}
	}
)		

;----------------ar
("fire_sound" stuff(acr_v1)			mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(ak-12_v1)		mid(silenced_ak74)			close(silenced_ak74_close)		reload(ak47))
("fire_sound" stuff(ak-15_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-15_v1b)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-15_v2)		mid(silenced_ak74)			close(silenced_ak74_close)		reload(ak47))
("fire_sound" stuff(ak-74m_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-74m_v2)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-74m_v3)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-103m_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-104m_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(ak-105m_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(akm_v1)			mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(akm_v1s)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(akm_v2)			mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(akm_v2s)		mid(silenced_ak74)			close(silenced_ak74_close)		reload(ak47))
("fire_sound" stuff(aks74_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(aks74_v1b)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(aks74_v2)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(aks74_v2b)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(aks74_v3)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(aks74_v4)		mid(m203)					close(m203_close)				reload(ak47))
("fire_sound" stuff(aks74u_v1)		mid(aks74u)					close(aks74u_close)				reload(ak47))
("fire_sound" stuff(aks74u_v2)		mid(aks74u)					close(aks74u_close)				reload(ak47))
("fire_sound" stuff(aks74u_v3)		mid(aks74u)					close(aks74u_close)				reload(ak47))
("fire_sound" stuff(an-94_v1)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(an-94_v2)		mid(ak74)					close(ak74_close)				reload(ak47))
("fire_sound" stuff(an-94_v3)		mid(silenced_ak74)			close(silenced_ak74_close)		reload(ak47))
("fire_sound" stuff(ar57_v1)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(ar57_v2)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(ar70_v1)		mid(ar70)					close(ar70_close)				reload(m16))
("fire_sound" stuff(ar70_v2)		mid(ar70)					close(ar70_close)				reload(m16))
("fire_sound" stuff(arx160_v1)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(arx160_v2)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(arx160_v3)		mid(silenced_arx160)		close(silenced_arx160_close)	reload(m16))
("fire_sound" stuff(as_val_v1)		mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(bos14_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(bos14_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(f2000_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(famas_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(famas_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(famas_v3)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(famas_v4)		mid(acr_sup)				close(acr_sup_close)			reload(m16))
("fire_sound" stuff(fg42_v1)		mid(sa80)					close(sa80_close)				reload(mgun_clip))
("fire_sound" stuff(fn_fal_v1)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_fal_v1s)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_fal_v2)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_fal_v3)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_fal_v4)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_fal_v5)		mid(fal)					close(fal_close)				reload(m16))
("fire_sound" stuff(fn_scar_v1)		mid(scar)					close(scar_close)				reload(m16))
("fire_sound" stuff(fn_scar_v3)		mid(scar)					close(scar_close)				reload(m16))
("fire_sound" stuff(fn_scar_v2)		mid(scar)					close(scar_close)				reload(m16))
("fire_sound" stuff(g3a3_v1)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a4_v1)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a4_v1b)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a4_v2b)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a7_v1)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a7_v1b)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g3a7_v2b)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g27_v1)			mid(scar)					close(scar_close)				reload(m16))
("fire_sound" stuff(g27_v2)			mid(silenced_scar)			close(silenced_scar_close)		reload(m16))
("fire_sound" stuff(g36a2_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36a2_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36a3_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36a3_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36a3_v3)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v3)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v4)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v5)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36c_v6)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36a3_v4)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(g36ka4_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36ka4_v2)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(g36ka4_v3)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(galil_v1)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(galil_v2)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(hk416_v1)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(hk416_v2)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(hk433_v1)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(hk433_v2)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(hk433_v3)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(m16))
("fire_sound" stuff(hk433_v4)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(honey_badger_v1) mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(lr300_v1)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1_v1)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1_v1b)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1_v2)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1_v2b)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1_v3)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(m4a1_v4)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(m4a1_v5)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(m4a1cqbr_v1)	mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1cqbr_v2)	mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(m4a1cqbr_v3)	mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(m16a2_v1)		mid(m16)					close(m16_close)				reload(m16))
("fire_sound" stuff(m16a2_v2)		mid(m16)					close(m16_close)				reload(m16))
("fire_sound" stuff(m16a4_v1)		mid(m16)					close(m16_close)				reload(m16))
("fire_sound" stuff(m16a4_v2)		mid(m16)					close(m16_close)				reload(m16))
("fire_sound" stuff(m21bs_v1)		mid(silenced_m21bs)			close(silenced_m21bs_close)		reload(m16))
("fire_sound" stuff(m24sws_v1)		mid(m24)					close(m24_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(msbs_grot_v1)	mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(remington_r11)	mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(remington_r11_v2)	mid(arx160)				close(arx160_close)				reload(m16))
("fire_sound" stuff(remington_r11_v3)	mid(acr_sup)			close(acr_sup_close)			reload(m16))
("fire_sound" stuff(sg552_v1)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sg552_v2)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sg552_v3)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sg552_v4)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sg552_v5)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sg552_v6)		mid(sg552)					close(sg552_close)				reload(m16))
("fire_sound" stuff(sig_mcx_v1_sight) mid(m4)					close(m4_close)					reload(m16))
("fire_sound" stuff(sig_mcx_v1_stock) mid(m4)					close(m4_close)					reload(m16))
("fire_sound" stuff(sig_mcx_v2)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(sig_mcx_v3)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(sig_mcx_v4)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(sr556_v1)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(sr556_v2)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(sr556_v3)		mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(steyraug_a3_lmg_v1) mid(aug)				close(aug_close)				reload(startreload))
("fire_sound" stuff(steyraug_a3_xs_v1)  mid(aug_9mm)			close(aug_9mm_close)			reload(startreload))
("fire_sound" stuff(steyraug_a3_xs_v2)  mid(aug_9mm)			close(aug_9mm_close)			reload(startreload))
("fire_sound" stuff(steyraug_a3_xs_v3)  mid(aug_9mm)			close(aug_9mm_close)			reload(startreload))
("fire_sound" stuff(steyraug_a3_xs_v4) mid(silenced_mp5)		close(silenced_mp5_close)		reload(startreload))
("fire_sound" stuff(steyraug_a3_xs_v5) mid(aug)					close(aug_close)				reload(startreload))
("fire_sound" stuff(xm4_v1)			mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(xmlar_v1)		mid(m77)					close(m77_close)				reload(m16))
;------------------------mg
("fire_sound" stuff(browning_m2_v1) mid(50cal)					close(50cal_close)				reload(mgun_heavy))
("fire_sound" stuff(dshk_v1)		mid(nsvt)					close(nsvt_close)				reload(mgun_heavy))
("fire_sound" stuff(fn_mag_v1)		mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(fn_mk48_v1)		mid(sa80)					close(sa80_close)				reload(mgun))
("fire_sound" stuff(fn_mk48_v2)		mid(sa80)					close(sa80_close)				reload(mgun))
("fire_sound" stuff(g8a1_v1)		mid(g3)						close(g3_close)					reload(m16))
("fire_sound" stuff(g8a1_v2)		mid(acr_sup)				close(acr_sup_close)			reload(m16))
("fire_sound" stuff(kord_v1)		mid(nsvt)					close(nsvt_close)				reload(mgun_heavy))
("fire_sound" stuff(l86_v1)			mid(sa80)					close(sa80_close)				reload(mgun_clip))
("fire_sound" stuff(l86_v2)			mid(sa80)					close(sa80_close)				reload(mgun_clip))
("fire_sound" stuff(m2hb_v1)		mid(50cal)					close(50cal_close)				reload(mgun_heavy))
("fire_sound" stuff(m2hb_v2)		mid(50cal)					close(50cal_close)				reload(mgun_heavy))
("fire_sound" stuff(m27_mg)			mid(g36mg)					close(g36mg_close)				reload(mgun))
("fire_sound" stuff(m60_hg_v1)		mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(m60_hg_v2)		mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(m60_hg_v3)		mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(m60_v1)			mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(m60b_v1)		mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(m85_v1)			mid(50cal)					close(50cal_close)				reload(mgun_heavy))
("fire_sound" stuff(m134_heavy)		mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(m134d_v1)		mid(m240)					close(m240_close)				reload(mgun_tank))
("fire_sound" stuff(m240_v1)		mid(m240)					close(m240_close)				reload(mgun_tank))
("fire_sound" stuff(m240b_v1)		mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(m240l_v1)		mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(m249_v1)		mid(m249)					close(m249_close)				reload(mgun))
("fire_sound" stuff(mg3_v1)			mid(mg3)					close(mg3_close)				reload(mgun))
("fire_sound" stuff(mg3_v1b)		mid(mg3)					close(mg3_close)				reload(mgun))
("fire_sound" stuff(mg4_v1)			mid(mg4)					close(mg4_close)				reload(mgun))
("fire_sound" stuff(mg5_v1)			mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(mg34_tank)		mid(mg34)					close(mg34_close)				reload(mgun))
("fire_sound" stuff(mg34_v1)		mid(mg34)					close(mg34_close)				reload(mgun))
("fire_sound" stuff(mg34_v2)		mid(mg34)					close(mg34_close)				reload(mgun))
("fire_sound" stuff(mg36_v1)		mid(g36)					close(g36_close)				reload(m16))
("fire_sound" stuff(mg42_v1)		mid(mg42)					close(mg42_close)				reload(mgun/mg42))
("fire_sound" stuff(mg42_v2)		mid(mg42)					close(mg42_close)				reload(mgun/mg42))
("fire_sound" stuff(mk48_ext_v1) 	mid(m240)					close(m240_close)				reload(mgun))
("fire_sound" stuff(modern_browning_m2_v1) mid(50cal)			close(50cal_close)				reload(mgun_heavy))
("fire_sound" stuff(nsvt_v1)		mid(nsvt)					close(nsvt_close)				reload(mgun_heavy))
("fire_sound" stuff(pkm_v1)			mid(pkm)					close(pkm_close)				reload(mgun))
("fire_sound" stuff(pkmt_v1)		mid(pkm)					close(pkm_close)				reload(mgun_tank))
("fire_sound" stuff(pkp_v1)			mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(pkt_v1)			mid(pkm)					close(pkm_close)				reload(mgun_tank))
("fire_sound" stuff(rpd_v1)			mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(rpd_v2)			mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(rpk_v1)			mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(rpk16_v1)		mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(rpk74m_v1)		mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(rpk74m_v1b)		mid(rpk)					close(rpk_close)				reload(mgun_clip))
("fire_sound" stuff(stoner_lmg_a1_v1) mid(sa80)					close(sa80_close)				reload(mgun))
("fire_sound" stuff(stoner_lmg_a1_v2) mid(sa80)					close(sa80_close)				reload(mgun))
;------------------------rifle
("fire_sound" stuff(ash127_v1)		mid(ash)					close(ash_close)				reload(test))
("fire_sound" stuff(ash127_v2)		mid(ash)					close(ash_close)				reload(test))
("fire_sound" stuff(ash127_v3)		mid(origin12sil)			close(origin12sil_close)		reload(test))
("fire_sound" stuff(asvk-m_v1)		mid(m107)					close(m107_close)				reload(svt40))
("fire_sound" stuff(b725)			mid(gewer)					close(gewer_close)				reload(rifle_bolt_single))
("fire_sound" stuff(b725_v2)		mid(gewer)					close(gewer_close)				reload(rifle_bolt_single))
("fire_sound" stuff(cheytac_v1)		mid(hdr)					close(hdr_close)				reload(rifle_at))
("fire_sound" stuff(cheytac_v2)		mid(hdr)					close(hdr_close)				reload(rifle_at))
("fire_sound" stuff(cobalt_kinetic_v1) mid(m39)					close(m39_close)				reload(m16))
("fire_sound" stuff(cobalt_kinetic_v2) mid(acr_sup)				close(acr_sup_close)			reload(m16))
("fire_sound" stuff(enfield_v1) 	mid(enfield)				close(enfield_close)			reload(enfield_reload))
("fire_sound" stuff(fnscar_ssr_v1)  mid(m39)					close(m39_close)				reload(m16))
("fire_sound" stuff(fnscar_ssr_v2)	mid(m39)					close(m39_close)				reload(m16))
("fire_sound" stuff(g22_v1)			mid(m24)					close(m24_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(g28_v1)			mid(m39)					close(m39_close)				reload(m16))
("fire_sound" stuff(g43)			mid(g41_shot)				close(g41_shot/3p)				reload(G43_reload))
("fire_sound" stuff(gewerh_v1)		mid(gewer)					close(gewer_close)				reload(lever_reload))
("fire_sound" stuff(gm6_lynx_v1) 	mid(lynx)					close(lynx_close)				reload(small_arms/StartReload))
("fire_sound" stuff(gm6_lynx_v2)	mid(lynx)					close(lynx_close)				reload(small_arms/StartReload))
("fire_sound" stuff(hdr_quiet)		mid(hdr_sup)				close(hdr_sup_close)			reload(small_arms/StartReload))
("fire_sound" stuff(hdr_v2)			mid(hdr)					close(hdr_close)				reload(small_arms/StartReload))
("fire_sound" stuff(hdr_v3)			mid(hdr)					close(hdr_close)				reload(small_arms/StartReload))
("fire_sound" stuff(l96a1_v1)		mid(m24)					close(m24_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(l96a1_v1s)		mid(silenced_val)			close(mc5_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(l96a1_v2)		mid(m24)					close(m24_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(l96a1_v2s)		mid(silenced_val)			close(mc5_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(l96a1_v2)		mid(m24)					close(m24_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(l96a1_v3s)		mid(silenced_val)			close(mc5_close)				reload(small_arms/rifle_5))
("fire_sound" stuff(m14_v1)			mid(m24)					close(m24_close)				reload(small_arms/StartReload))
("fire_sound" stuff(m14_v2)			mid(m24)					close(m24_close)				reload(small_arms/StartReload))
("fire_sound" stuff(m14_v3)			mid(silenced_val)			close(silenced_val_close)		reload(small_arms/StartReload))
("fire_sound" stuff(m27iar_v1)		mid(m27)					close(m27_close)				reload(m16))
("fire_sound" stuff(m39emr_v1)		mid(m39)					close(m39_close)				reload(m16))
("fire_sound" stuff(m77_v1)			mid(m77)					close(m77_close)				reload(ak47))
("fire_sound" stuff(m77_v1b)		mid(m77)					close(m77_close)				reload(ak47))
("fire_sound" stuff(m77_v2)			mid(m77)					close(m77_close)				reload(ak47))
("fire_sound" stuff(m82_rsd)		mid(m107)					close(m107_close)				reload(mgun_clip))
("fire_sound" stuff(m82a1)			mid(m107)					close(m107_close)				reload(small_arms/StartReload))
("fire_sound" stuff(m107a1_v1)		mid(m107)					close(m107_close)				reload(small_arms/StartReload))
("fire_sound" stuff(mc_milan_v1)	mid(silenced_val)			close(mc5_close)				reload(small_arms/StartReload))
("fire_sound" stuff(mk14_v1)		mid(m77)					close(m77_close)				reload(small_arms/StartReload))
("fire_sound" stuff(mk14_v2)		mid(m77)					close(m77_close)				reload(small_arms/StartReload))
("fire_sound" stuff(mk14_v3)		mid(m77)					close(m77_close)				reload(small_arms/StartReload))
("fire_sound" stuff(rem700_v1)		mid(hdr_sup)				close(hdr_sup_close)			reload(small_arms/StartReload))
("fire_sound" stuff(rem700_v2)		mid(SG43)					close(SG43_close)				reload(small_arms/StartReload))
("fire_sound" stuff(rem700_v3)		mid(SG43)					close(SG43_close)				reload(small_arms/StartReload))
("fire_sound" stuff(svd_v1)			mid(dragunov)				close(dragunov_close)			reload(ak47))
("fire_sound" stuff(svd_v2)			mid(dragunov)				close(dragunov_close)			reload(ak47))
("fire_sound" stuff(svd_v3)			mid(dragunov)				close(dragunov_close)			reload(ak47))
("fire_sound" stuff(svd_v4)			mid(silenced_ak74)			close(silenced_ak74_close)		reload(ak47))
("fire_sound" stuff(svd_v5)			mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(svdk_v1)		mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(svu_v1)			mid(dragunov)				close(dragunov_close)			reload(ak47))
("fire_sound" stuff(vityaz-sn_v1) 	mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(vityaz-sn_v2)   mid(m4)						close(m4_close)					reload(m16))
("fire_sound" stuff(vityaz-sn_v3)	mid(silenced_val)			close(silenced_val_close)		reload(m16))
("fire_sound" stuff(vks_v1)			mid(silenced_m21bs)			close(silenced_m21bs_close)		reload(ak47))
("fire_sound" stuff(vss_v1)			mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(vss_v1s)		mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(vss_v2)			mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(vss_vintorez_v1) mid(silenced_val)			close(silenced_val_close)		reload(ak47))
("fire_sound" stuff(wa2000_v1)		mid(enfield)				close(enfield_close)			reload(small_arms/StartReload))
("fire_sound" stuff(xm109_v1)		mid(xm109)					close(xm109_close)				reload(small_arms/StartReload))
("fire_sound" stuff(xm109_v2)		mid(xm109)					close(xm109_close)				reload(small_arms/StartReload))
("fire_sound" stuff(xm109_v3)		mid(xm109_sup)				close(xm109_sup_close)			reload(small_arms/StartReload))
;------------------------shotgun
("fire_sound" stuff(aa12_v1)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(aa12h_v1)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(aa12h_v2)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(aa12h_v3)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(origin_v1)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(origin_v2)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(origin_v3)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(origin_v4)		mid(origin12sil)			close(origin12sil_close)		reload(small_arms/StartReload))
("fire_sound" stuff(protecta_v1)	mid(sweeper)				close(sweeper_close)			reload(small_arms/StartReload))
("fire_sound" stuff(saiga12k_v1)	mid(saiga)					close(saiga_close)				reload(ak47))
("fire_sound" stuff(spas12_v1)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
("fire_sound" stuff(spas12_v2)		mid(origin)					close(origin_close)				reload(small_arms/StartReload))
;------------------------smg
("fire_sound" stuff(bizon_v1)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(bizon_v2)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(bizon_v3)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(bizon_v4)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(bizon_v4c)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(cz_evo_v1)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(cz_evo_v2)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(cz_evo_v3)		mid(p90_sil)				close(p90_sil_close)			reload(mp5))
("fire_sound" stuff(cz_evo_v4)		mid(p90_sil)				close(p90_sil_close)			reload(mp5))
("fire_sound" stuff(fn_p90_v1)		mid(p90)					close(p90_close)				reload(mp5))
("fire_sound" stuff(fn_p90_v2)		mid(p90)					close(p90_close)				reload(mp5))
("fire_sound" stuff(fn_p90_v3)		mid(p90)					close(p90_close)				reload(mp5))
("fire_sound" stuff(fn_p90_v4)		mid(p90_sil)				close(p90_sil_close)			reload(mp5))
("fire_sound" stuff(groza_v1)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(groza_v2)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(groza_v3)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(groza_v4)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(kacpdw_v1)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(kacpdw_v2)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(kacpdw_v3)		mid(silenced_m4)			close(silenced_m4_close)		reload(m16))
("fire_sound" stuff(lynx300_v1)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(lynx300_v2)		mid(arx160)					close(arx160_close)				reload(m16))
("fire_sound" stuff(mp5_v1)			mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(mp5_v1b)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(MP5_reload))
("fire_sound" stuff(mp5_v1m)		mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(mp5_v2)			mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(mp5_v3)			mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(mp5_v4)			mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(mp7_v1)			mid(mp7)					close(mp7_close)				reload(mp7_reload))
("fire_sound" stuff(mp7_v2)			mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp7_reload))
("fire_sound" stuff(mp7_v2m)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp7_reload))
("fire_sound" stuff(mp7_v2s)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp7_reload))
("fire_sound" stuff(mp7_v3)			mid(mp7)					close(mp7_close)				reload(mp7_reload))
("fire_sound" stuff(plr-16_v1)		mid(ar70)					close(ar70_close)				reload(m16))
("fire_sound" stuff(plr-16_v2)		mid(ar70)					close(ar70_close)				reload(m16))
("fire_sound" stuff(pof9_v1)		mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(pof9_v2)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(MP5_reload))
("fire_sound" stuff(pp19_01_v1)		mid(bizon)					close(bizon_close)				reload(mp5))
("fire_sound" stuff(pp19_v1)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp5))
("fire_sound" stuff(pp19_v2)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp5))
("fire_sound" stuff(pp19_v3)		mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp5))
("fire_sound" stuff(ppsh41_drum)	mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(psg9_prokolot)	mid(beretta)				close(beretta_close3)			reload(mp5))
("fire_sound" stuff(psg9_prokolot_v2) mid(beretta)				close(beretta_close3)			reload(mp5))
("fire_sound" stuff(sigsauer_v1)	mid(sig)					close(sig_close)				reload(mp5))
("fire_sound" stuff(sigsauer_v2)	mid(sig)					close(sig_close)				reload(mp5))
("fire_sound" stuff(sigsauer_v3)	mid(sig)					close(sig_close)				reload(mp5))
("fire_sound" stuff(sigsauer_v4)	mid(silenced_mp5)			close(silenced_mp5_close)		reload(mp5))
("fire_sound" stuff(skorpion_v1)	mid(skorpion)				close(skorpion_close)			reload(mp5))
("fire_sound" stuff(stg44_v1)		mid(stg44)					close(stg44_close)				reload(stg44_reload))
("fire_sound" stuff(tar21_v1)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(tar21_v2)		mid(groza)					close(groza_close)				reload(ak47))
("fire_sound" stuff(tar21_v3)		mid(uzi)					close(uzi_close)				reload(mp5))
("fire_sound" stuff(tec9_v1)		mid(mp5)					close(mp5_close)				reload(MP5_reload))
("fire_sound" stuff(ump45_v1)		mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
("fire_sound" stuff(ump45_v1b)		mid(ump)					close(ump_close)				reload(mp5))
("fire_sound" stuff(ump45_v1h)		mid(ump)					close(ump_close)				reload(mp5))
("fire_sound" stuff(ump45_v2)		mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
("fire_sound" stuff(ump45_v2b)		mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
("fire_sound" stuff(ump45_v2h)		mid(ump)					close(ump_close)				reload(mp5))
("fire_sound" stuff(ump45_v3h)		mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
("fire_sound" stuff(uzi_v1)			mid(uzi)					close(uzi_close)				reload(mp5))
("fire_sound" stuff(uzi_v2)			mid(uzi)					close(uzi_close)				reload(mp5))
("fire_sound" stuff(uzi_v3)			mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
("fire_sound" stuff(vector_ft_v1)	mid(uzi)					close(uzi_close)				reload(mp5))
("fire_sound" stuff(vector_ft_v2)	mid(uzi)					close(uzi_close)				reload(mp5))
("fire_sound" stuff(vector_ft_v3)	mid(silenced_ump)			close(silenced_ump_close)		reload(mp5))
;------------------------pistol
("fire_sound" stuff(beretta_v2)		mid(silenced_pistol1)		close(silenced_pistol1_close)	reload(glock))
("fire_sound" stuff(beretta_v1)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(desert_eagle_v1) mid(desert_eagle) 			close(desert_eagle_close)		reload(glock))
("fire_sound" stuff(desert_eagle_v2) mid(desert_eagle) 			close(desert_eagle_close)		reload(glock))
("fire_sound" stuff(dwd_v1)			mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(gsh18)			mid(gsh)					close(gsh_close)				reload(glock))
("fire_sound" stuff(hudson_v1)		mid(gsh)					close(gsh_close)				reload(glock))
("fire_sound" stuff(hudson_v2)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(ksj_v1)			mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(m93r_v1)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(m93r_v2)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(m1911_v1)		mid(m1911)					close(m1911_close)				reload(glock))
("fire_sound" stuff(m1911_v2)		mid(m1911)					close(m1911_close)				reload(glock))
("fire_sound" stuff(m1911_v3)		mid(m1911)					close(m1911_close)				reload(glock))
("fire_sound" stuff(m1911_v4)		mid(m1911)					close(m1911_close)				reload(glock))
("fire_sound" stuff(m1911_v5)		mid(m1911)					close(m1911_close)				reload(glock))
("fire_sound" stuff(mp40sw_v1)		mid(makarov)				close(makarov_close)			reload(glock))
("fire_sound" stuff(p226_v1)		mid(glock)					close(glock_close)				reload(glock))
("fire_sound" stuff(p320_v1)		mid(makarov)				close(makarov_close)			reload(glock))
("fire_sound" stuff(p320_v2)		mid(makarov)				close(makarov_close)			reload(glock))
("fire_sound" stuff(pistol_v1)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(pistol_v1b)		mid(makarov)				close(makarov_close)			reload(glock))
("fire_sound" stuff(pistol_v1c)		mid(glock)					close(glock_close)				reload(glock))
("fire_sound" stuff(pistol_v1m)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(pistol_v2)		mid(beretta)				close(beretta_close2)			reload(glock))
("fire_sound" stuff(pistol_v2b)		mid(gsh)					close(gsh_close)				reload(glock))
("fire_sound" stuff(pistol_v2m)		mid(beretta)				close(beretta_close2)			reload(glock))
("fire_sound" stuff(pistol_v3)		mid(colt)					close(colt_close)				reload(glock))
("fire_sound" stuff(pistol_v3c)		mid(colt)					close(colt_close)				reload(glock))
("fire_sound" stuff(pistol_v3b)		mid(gsh)					close(gsh_close3)				reload(glock))
("fire_sound" stuff(pistol_v4)		mid(silenced_pistol1)		close(silenced_pistol1_close)	reload(glock))
("fire_sound" stuff(pistol_v4c)		mid(silenced_pistol1)		close(silenced_pistol1_close)	reload(glock))
("fire_sound" stuff(pistol_v4b) 	mid(silenced_pistol2)		close(silenced_pistol2_close)	reload(glock))
("fire_sound" stuff(usp_v1)			mid(beretta)				close(beretta_close3)			reload(glock))
("fire_sound" stuff(usp_v2)			mid(beretta)				close(beretta_close3)			reload(glock))
("fire_sound" stuff(walter_ppk)		mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(walter_ppq5)	mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(walther_p99)	mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(x16_microroni_v1) mid(beretta)				close(beretta_close)			reload(glock))
("fire_sound" stuff(x16_v1)			mid(beretta)				close(beretta_close)			reload(colt45_reload))
("fire_sound" stuff(x16_v2)			mid(beretta)				close(beretta_close)			reload(colt45_reload))
("fire_sound" stuff(x16_v3) 		mid(silenced_pistol1) 		close(silenced_pistol1_close) 	reload(colt45_reload))

{"stuff weapon sniper"
	{on spawn
		{add_view "bullet_tail_fast" "tail_fast" "bullet_view"}
	}
	{on "fire"
		{view show	"tail_fast"}
		{view start	"tail_fast"}
		{delay 2
			{view hide	"tail_fast"}
			{view pause	"tail_fast"}
		}
	}
	{on animation_event "clear_casing"
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop" bone "shell" copy ;slicer_tail
			{impulse forward 2 com  }
		}
		{delay 0
			{view hide "shell"}	
		}
	}		
}


(define "fx_muzzle"
	{"stuff weapon %tag"
		{on spawn
			{add_view 	"%tag"	"fx_muzzle" "foresight3"}
		}		
		{on "fire"
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{kill_delay "fire"}						
			{view start "fx_muzzle"}
			{delay 0.1 "fire"
				{view pause	"fx_muzzle"}
			}
		}
	}
)
("fx_muzzle" 	tag(fx_rifle) )
("fx_muzzle" 	tag(fx_mgun) )




{"stuff weapon flash_single_side_rifle_grade1"
	{on spawn
		{add_view 	"smoke_heat_barrel" 				"smoke" 		"fx_main"}
		{add_view 	"muzzle_front_rifle_grade1" 		"fx_muzzle" 	"fx_main"}
		{add_view 	"smoke_sil_small" 	"stage1_fire" 	"fx_main"}
	}
	{on "fire"	
		{if rand 0.2
				{view start "stage1_fire"}
				{view show "stage1_fire"}
		}
		{kill_delay "fire"}	
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight3" }
		{view start "fx_muzzle"}
		{delay 0.15 "fire"
			{view start "smoke"}
			{view pause	"fx_muzzle"}
		}
		{delay 0.8 0.5 "fire"
			{view hide	"stage1_fire"}
			{view pause	"stage1_fire"}
		}
		{delay 3 1 "fire"
			{view pause	"smoke"}
		}
	}
}







{"stuff weapon fx_heavy_mgun"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fx_main"}
		{add_view 	"muzzle_front_hmgun" 		"fx_muzzle" "fx_main"}
		{view hide	"fx_muzzle"}
		{view pause	"fx_muzzle"}
		{add_view 	"smoke_sil_small" 	"stage1_fire" 	"fx_main"}
		;{add_view 	"heat_stage1" 		"stage1" 		"fx_main"}
	}
	{on "reload"	
		{if tagged "fire_move"	
			{start_sound "weapon/clear/hmg/action_ads"}
		}
	}
	{on "fire"	
		{kill_delay "fire"}	
		{start_sound "weapon/bolt_move/hmg/belt"}
		{delay 0.1 "fire"
			{start_sound "weapon/bolt_move/hmg/belt_end"}
		}
		{delay 0.15 "fire"
			{view start "smoke"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{if rand 0.2
			{view start "stage1_fire"}
			{view show "stage1_fire"}
		}
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small_gun" "foresight3" }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{view show "fx_muzzle"}
		{delay 0.15 "fire"
			{view start "smoke"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 0.8 0.5 "fire"
			{view hide	"stage1_fire"}
			{view pause	"stage1_fire"}
		}
		{delay 3 1 "fire"
			{view pause	"smoke"}
		}
	}
}


{"stuff weapon flash_four_sided_long"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fx_main"}
		{add_view 	"muzzle_front_shorted" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_front" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_front" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_front" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_front" 	"fx_muzzle" "fx_point03"}
		{view hide	"fx_muzzle"}
		{view pause	"fx_muzzle"}
		{add_view 	"smoke_sil_small" 	"stage1_fire" 	"fx_main"}
		;{add_view 	"heat_stage1" 		"stage1" 		"fx_main"}
	}
	{on "fire"	
		{if rand 0.2
				{view start "stage1_fire"}
				{view show "stage1_fire"}
		}
		{kill_delay "fire"}	
		{if prop "at_rifle_set"
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 5 2 rnd_dir 0.1} {gravity 0} }
			{spawn "distant_small_gun" "foresight3" }
		else
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "distant_small" "foresight3" }
		}
		{view start "fx_muzzle"}
		{view show "fx_muzzle"}
		{delay 0.15 "fire"
			{view start "smoke"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 0.8 0.5 "fire"
			{view hide	"stage1_fire"}
			{view pause	"stage1_fire"}
		}
		{delay 3 1 "fire"
			{view pause	"smoke"}
		}
	}
}

{"stuff weapon flash_two_sided_long"
	{on spawn
		{add_view 	"muzzle_front_small" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single2" 			"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single2" 			"fx_muzzle" "fx_point01"}
	}
	{on "fire"	
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.7
			{start_sound "interior/hrifle"}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}

{"stuff weapon flash_two_sided_smg_short"
	{on spawn
		{add_view 	"muzzle_front_small_short" 	"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single_short" 		"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single_short" 		"fx_muzzle" "fx_point01"}
	}
	{on "fire"	
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.15 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}




{"stuff weapon flash_four_sided_big"
	{on spawn
		{add_view 	"muzzle_front_mgun_fire" 		"fx_muzzle_fire" "fx_main"}
		{add_view 	"muzzle_front_mgun" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
	}
	{on "fire" overload
		{view start "fx_muzzle"}
		{if rand 0.25 
			{view start "fx_muzzle_fire"}
		}		
		{delay 0.1 "fire"
			{view hide	"fx_muzzle_fire"}
			{view pause	"fx_muzzle_fire"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight3" }
		{if stuff_filled "buck" 1
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 75 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 75 rnd_dir 1}
				{gravity 1}
				
			}
		else stuff_filled "trace" 1
			{if rand 0.7
				{spawn "piece_trace" "foresight3" x}
			}
		}
		{if rand 0.7
			{start_sound "interior/hrifle"}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}


{"stuff weapon flash_four_sided_short"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
	}
	{on "fire" overload
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "foresight3" }
		{if stuff_filled "buck" 1
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 85 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 90 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 92 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 87 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 75 rnd_dir 1}
				{gravity 1}
				
			}
			{spawn "fraction" "foresight3" x
				{impulse dir 75 rnd_dir 1}
				{gravity 1}
				
			}
		else stuff_filled "trace" 1
			{if rand 0.7
				{spawn "piece_trace" "foresight3" x}
			}
		}
		{if rand 0.7
			{start_sound "interior/hrifle"}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}


{"stuff weapon flash_two_sided"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
	}
	{on "fire"	
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}

{"stuff weapon silenced_xm109"
	{on spawn
		{add_view 	"flash_gun_silencer" 		"fx_main" "foresight3"}
		{add_view 	"smoke_sil" 				"fx_fire_hot" "foresight3"}
		{view hide	"fx_main"}
		{view pause	"fx_main"}
		{view hide	"fx_fire_hot"}
		{view pause	"fx_fire_hot"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fxshell"}
		{add_view 	"smoke_heat_barrel2" 		"smoke_recoil" 	"fx_eject"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"foresight3"}
		{add_view 	"heat_stage1_fire" 			"stage1_fire" "fx_main"}
		{add_view 	"heat_stage1" 				"stage1" "fx_main"}
	}
	{on animation_end "heat"
		{view start "stage1"}
		{delay 7 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "heat" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
		{if tagged "fire_hold"				
			{view start "stage1_fire"}
			{delay 0.5 
				{view pause "stage1_fire"}
			}
			{start_sound "weapon/heat/"}
		}
	}
	{on animation_event "open_bolt" overload
		{start_sound "weapon/bolt_move/heavy"}	
	}		
;	{on animation_event "close_bolt"
;		{start_sound "weapon/bolt_move/heavy"}	
;	}		
	; {on animation_event "charge_load"
		; {start_sound "weapon/armed/snrifle_series/boltopen"}	
	; }		
	{on "fire" overload
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{ani_play "fire" }
		{kill_delay "heat"}
		{if not tagged "heat"				
			{ani_play "heat" +0.2 resume callback}
			{tags add "heat"}
		}
		{delay 3 
			{ani_play "heat" -0.2 resume }
			{tags remove "heat"}
		}
		;{spawn "distant_small_gun" "foresight3" }
		{spawn "smoke_shotgun_shell" "fxshell" x}
		{if rand 0.1
			{spawn "sparks01s" "foresight3" x}
		else rand 0.1
			{spawn "sparks02s" "foresight3" x}
		else rand 0.1
			{spawn "sparks03s" "foresight3" x}
		}	
		{view start "fx_main"}
		{delay 0.03 "fire"
			{view start "smoke"}
			{view start "smoke_recoil"}
			{view show	"fx_fire_hot"}
			{view start	"fx_fire_hot"}
			{view hide	"fx_main"}
			{view pause	"fx_main"}
		}
		{delay 1 0.7
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}
			{view pause "smoke_recoil"}
		}
		{delay 3 1
			{view pause "smoke"}
		}
	}		
	{on "reload"
		{ani_play "heat" -0.25 resume }
	}
}


{"stuff weapon flash_two_sided_heavy_xm109"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fxshell"}
		{add_view 	"smoke_heat_barrel2" 		"smoke_recoil" 	"fx_eject"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"foresight3"}
		{add_view 	"muzzle_front_shotgun" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 			"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 			"fx_muzzle" "fx_point01"}
		{add_view 	"heat_stage1_fire" 			"stage1_fire" "fx_main"}
		{add_view 	"heat_stage1" 				"stage1" "fx_main"}
	}
	{on animation_end "heat"
		{view start "stage1"}
		{delay 7 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "heat" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
		{if tagged "fire_hold"				
			{view start "stage1_fire"}
			{delay 0.5 
				{view pause "stage1_fire"}
			}
			{start_sound "weapon/heat/"}
		}
	}
	{on animation_event "open_bolt"
		{start_sound "weapon/bolt_move/heavy"}	
	}		
;	{on animation_event "close_bolt"
;		{start_sound "weapon/bolt_move/heavy"}	
;	}		
	; {on animation_event "charge_load"
		; {start_sound "weapon/armed/snrifle_series/boltopen"}	
	; }		
	{on "fire" overload
		{spawn "distant_small_grass_set" "foresight3" x}
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 6 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{ani_play "fire" }
		{kill_delay "heat"}
		{if not tagged "heat"				
			{ani_play "heat" +0.1 resume callback}
			{tags add "heat"}
		}
		{delay 3
			{ani_play "heat" -0.2 resume }
			{tags remove "heat"}
		}
		{spawn "distant_small_gun" "foresight3" }
		{spawn "smoke_shotgun_shell" "fxshell" x}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view start "smoke"}
			{view start "smoke_recoil"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 2 0.5
			{view pause "smoke_recoil"}
		}
		{delay 3 1
			{view pause "smoke"}
		}
		{spawn "spark_small_shotgun" "foresight3" x}
		{if rand 0.1 
			{spawn "spheredust_small_short2" "fxshell" x}
		}		
	}		
	{on "reload"
		{ani_play "heat" -0.25 resume }
	}
}


{"stuff weapon b725"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fxshell"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"foresight3"}
		{add_view 	"muzzle_front_shotgun" 		"fx_muzzle" 	"fx_main"}
		{tags add "riflehand" }
	}
	{on "fire"
		{spawn "distant_small_gun" "foresight3" }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 6 3 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "fx_main" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{spawn "trace_linear" "fx_main" x }
		{view start "fx_muzzle"}
		{view show "fx_muzzle"}
		{delay 0.1 "fire"
			{view start "smoke"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
		{delay 3 1
			{view pause "smoke"}
		}
		{spawn "spark_small_shotgun" "foresight3" x}
	}
}

{"stuff weapon flash_two_sided_heavy"
	{on spawn
		{add_view 	"muzzle_front_mgun" 			"fx_muzzle" 	"fx_main"}
		{add_view 	"muzzle_front_mgun_fire" 		"fx_muzzle_fire" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{if rand 0.25 
			{view start "fx_muzzle_fire"}
		}		
		{delay 0.1 "fire"
			{view hide	"fx_muzzle_fire"}
			{view pause	"fx_muzzle_fire"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_two_sided_rifle"
	{on spawn
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view pause	"fx_muzzle"}
		}
	}
}

{"stuff weapon flash_single_sided_rifle"
	{on spawn
		{if not prop "silenced"
			{add_view 	"muzzle_front" 		"fx_muzzle" "foresight3"}
		}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_pistol"
	{on spawn
		{add_view 	"muzzle_front_small2" 		"fx_muzzle" "foresight3"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}


{"stuff weapon flash_single_sided_pistol_heavy"
	{on spawn
		{add_view 	"muzzle_front_pistol_heavy" 		"fx_muzzle" "fx_main"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
	{on animation_event "clear_casing"
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop" bone "shell_drop" copy ;slicer_tail
			{impulse forward 3 2 cx 0.3 com  }
		}
		{delay 0
			{view hide "shell_drop"}	
		}
		{delay 0.3
			{view show "shell_drop"}	
		}
	}		
}










{"stuff weapon flash_smg_short"
	{on spawn
		{add_view 	"muzzle_single" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_line" 			"fx_muzzle" "fx_spark"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.4
			{spawn "sparks01s" "fx_spark" x}
		else rand 0.5
			{spawn "sparks02s" "fx_spark" x}
		else rand 0.6
			{spawn "sparks03s" "fx_spark" x}
		}	
		{if rand 0.7
			{spawn "spark_small_gun" "fx_spark" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_pistol_avto"
	{on spawn
		{add_view 	"muzzle_single" 		"fx_muzzle" "foresight3"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.7
			{spawn "spark_small_gun" "foresight3" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_pistol_avto"
	{on spawn
		{add_view 	"muzzle_front_pistol" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point01"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 2 1 rnd_dir 0.1} {gravity 0} }
		{if rand 0.7
			{spawn "spark_small_gun" "fx_main" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_pistol_muzb"
	{on spawn
		{add_view 	"muzzle_front_small" 		"fx_muzzle" "fx_main"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_six_sided_pistol"
	{on spawn
		{add_view 	"muzzle_front_pistol" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point04"}
		{add_view 	"muzzle_single_pistol" 		"fx_muzzle" "fx_point05"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.4
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "spark_small_gun" "fx_main" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_smg_short"
	{on spawn
		{add_view 	"muzzle_front_pistol" 		"fx_muzzle" "fx_main"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.2
			{spawn "spark_small_gun" "fx_main" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_smg"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "foresight3"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_single_sided_smg2"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "foresight3"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_five_sided_rifle"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_four_sided_rifle"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_six_sided_rifle"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point05"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_six_sided_smg"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point05"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.3
			{spawn "sparks01" "foresight3" x}
		else rand 0.3
			{spawn "sparks02" "foresight3" x}
		else rand 0.3
			{spawn "sparks03" "foresight3" x}
		else rand 0.3
			{spawn "sparks04" "foresight3" x}
		else rand 0.3
			{spawn "sparks05" "foresight3" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_six_sided_rifle_small"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point05"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{if rand 0.3
			{spawn "spark_small_gun" "fx_main" x}
		}
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_six_sided_mgun"
	{on spawn
		{add_view 	"muzzle_front_mgun" 			"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_front_mgun_fire" 		"fx_muzzle_fire" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point05"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{if rand 0.2 
			{view start "fx_muzzle_fire"}
		}		
		{delay 0.1 "fire"
			{view hide	"fx_muzzle_fire"}
			{view pause	"fx_muzzle_fire"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}
{"stuff weapon flash_five_sided_mgun"
	{on spawn
		{add_view 	"muzzle_front_mgun_fire" 		"fx_muzzle_fire" "fx_main"}
		{add_view 	"muzzle_front_mgun" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point04"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{if rand 0.2 
			{view start "fx_muzzle_fire"}
		}		
		{delay 0.1 "fire"
			{view hide	"fx_muzzle_fire"}
			{view pause	"fx_muzzle_fire"}
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}

{"stuff weapon flash_four_sided_smg"
	{on spawn
		{add_view 	"muzzle_front" 		"fx_muzzle" "fx_main"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point00"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point01"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point02"}
		{add_view 	"muzzle_single" 	"fx_muzzle" "fx_point03"}
	}
	{on "fire"
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{view start "fx_muzzle"}
		{delay 0.1 "fire"
			{view hide	"fx_muzzle"}
			{view pause	"fx_muzzle"}
		}
	}
}


{"stuff weapon m32"
	{on spawn
		;{add_view "flash_gun_shot" "flashbarrel" "foresight3"}
	}
	{on "fire"
		{spawn "flash_gun_shot_short" "foresight3" x}
		;{view show	"flashbarrel"}
		;{view start	"flashbarrel"}
		{delay 0.4 "fire"
			{view hide	"flashbarrel"}
			{view pause	"flashbarrel"}
		}
	}
}

{"stuff weapon protecta"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fxshell"}
		{add_view 	"smoke_heat_barrel2" 		"smoke_recoil" 	"fx_eject"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 		"fx_main"}
		{add_view 	"muzzle_front_shorted" 	"fx_muzzle_buck" "fx_main"}
		{add_view 	"muzzle_front_shorted" 	"fx_muzzle_slug" "fx_main"}
		{add_view 	"heat_stage1_fire" 	"stage1_fire" "fx_main"}
		{add_view 	"heat_stage1" 		"stage1" "fx_main"}
		{view hide	"fx_muzzle_buck"}
		{view pause	"fx_muzzle_buck"}
		{view hide	"fx_muzzle_slug"}
		{view pause	"fx_muzzle_slug"}
	}
	{on "fire" overload
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{kill_delay "heat"}
		{if not tagged "heat"				
			{ani_play "heat" +0.3 resume callback}
			{tags add "heat"}
		}
		{delay 3 "heat"
			{ani_play "heat" -0.4 resume }
			{tags remove "heat"}
		}
		{spawn "distant_small" "foresight3" }
		{if rand 0.1
			{spawn "spark_recoil" "fx_fire03" x}
			{spawn "spark_recoil" "fx_fire02" x}
			{spawn "spark_recoil" "fx_fire01" x}
			{spawn "spark_recoil" "fx_fire00" x}
			{start_sound "interior/hrifle"}
		else rand 0.1
			{spawn "spark_recoil" "fx_fire00" x}
		else rand 0.1
			{spawn "smoke_shotgun_shell" "fx_fire03" x}
			{spawn "smoke_shotgun_shell" "fx_fire02" x}
			{spawn "smoke_shotgun_shell" "fx_fire01" x}
			{spawn "smoke_shotgun_shell" "fx_fire00" x}
		}	
		{if stuff_filled "slug" 1 
			{tags add "slug"}
			{tags remove "buck"}
			{view start "fx_muzzle_slug"}
			{delay 0.03 "fire"
				{view start "smoke"}
				{view start "smoke_recoil"}
				{view hide	"fx_muzzle_slug"}
				{view pause	"fx_muzzle_slug"}
			}
		else 
			{tags add "buck"}
			{tags remove "slug"}
			{view start "fx_muzzle_buck"}
			{view show "fx_muzzle_buck"}
			{delay 0.1 "fire"
				{view start "smoke"}
				{view start "smoke_recoil"}
				{view hide	"fx_muzzle_buck"}
				{view pause	"fx_muzzle_buck"}
			}
			(define "fraction"
				{spawn "fraction" "foresight3" x
					{impulse dir %dir rnd_dir %rnd_dir}
					{gravity %gravity}
					
				}
			)
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(70) rnd_dir(0.75) gravity(1))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
			("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		else stuff_filled "ammo" 
			{view start "fx_muzzle_buck"}
			{delay 0.03 "fire"
				{view start "smoke"}
				{view start "smoke_recoil"}
				{view hide	"fx_muzzle_buck"}
				{view pause	"fx_muzzle_buck"}
			}
			(define "fraction"
				{spawn "fraction" "foresight3" x
					{impulse dir %dir rnd_dir %rnd_dir}
					{gravity %gravity}
					
				}
			)
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(70) rnd_dir(3) gravity(1))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
			("fraction" dir(65) rnd_dir(3) gravity(0.5))
		}
		{ani_play "recoil" 1}
	}
	{on animation_event "eject"	
		{spawn "12gauge_hp" "FXshell" z
			{impulse up 1 forward 5 1 cx 0.5 com  }
		}
		{start_sound "weapon/shell_eject/shell308"}	
	}
	{on animation_end "heat"
		{view start "stage1"}
		{delay 7 
			{view hide	"stage1"}
			{view pause	"stage1"}
		}
		{burn volume "heat" fx "smoke_heat_barrel" time 4 fake even_law}
		{tags add "stage1"}
		{if tagged "fire_hold"				
			{view start "stage1_fire"}
			{delay 0.5 
				{view pause "stage1_fire"}
			}
			{start_sound "weapon/heat/"}
		}
	}
}

{"stuff weapon masterkey"
	{on spawn
		{add_view 	"smoke_heat_barrel" 		"smoke" 			"brass_alt"}
		{add_view 	"smoke_heat_barrel2" 		"smoke_recoil" 		"brass_alt"}
		{add_view 	"smoke_heat_barrel" 		"smoke" 			"flash_alt"}
		{add_view 	"muzzle_front_shorted" 		"fx_muzzle_buck" 	"flash_alt"}
		{add_view 	"muzzle_single" 			"fx_muzzle_buck" "flash_alt_00"}
		{add_view 	"muzzle_single" 			"fx_muzzle_buck" "flash_alt_01"}
		{view hide	"fx_muzzle_buck"}
		{view pause	"fx_muzzle_buck"}
	}
	{on animation_event "clear_casing_12x55" overload
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop_12_55" bone "shell_drop_masterkey" copy ;slicer_tail
			{impulse forward 0.6 cx -0.1 0.1 com  }
		}
		{delay 0
			{view hide "shell_drop_masterkey"}	
		}
	}
	{on "fire_masterkey" overload ; clear_casing_12x55
		{start_sound "weapon/shot/small_arms/sweeper/"}
		{ani_play "recoil_masterkey" }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "fx_shoot_hit_sparks" "flash_alt" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
		{spawn "distant_small" "flash_alt" }
		{if rand 0.4
			{spawn "spark_recoil" "brass_alt" x}
			{start_sound "interior/hrifle"}
		}	
		{view start "fx_muzzle_buck"}
		{view show "fx_muzzle_buck"}
		{delay 0.1 "fire"
			{view start "smoke"}
			{view start "smoke_recoil"}
			{view hide	"fx_muzzle_buck"}
			{view pause	"fx_muzzle_buck"}
		}
		(define "fraction"
			{spawn "fraction" "flash_alt" x
				{impulse dir %dir rnd_dir %rnd_dir}
				{gravity %gravity}
				
			}
		)
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(70) rnd_dir(0.75) gravity(1))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
		("fraction" dir(65) rnd_dir(0.75) gravity(0.5))
	}
}



(define "shotgun_barrel"
	{"stuff weapon %tag"
		{on spawn
			{add_view 	"heat_stage1_fire" 				"stage1_fire" 		"fx_main"}
			{add_view 	"heat_stage1" 					"stage1" 			"fx_main"}
			{add_view 	"smoke_heat_barrel" 			"smoke" 			"fxshell"}
			{add_view 	"smoke_heat_barrel2" 			"smoke_recoil" 		"fx_eject"}
			{add_view 	"smoke_heat_barrel" 			"smoke" 			"foresight3"}


			{add_view 	"smoke_heat_barrel" 		"smoke" 			"fxshell"}
			{add_view 	"smoke_heat_barrel" 		"smoke" 			"fx_main"}
			{add_view 	"muzzle_front_shorted" 		"fx_muzzle_buck" 	"fx_main"}
			{add_view 	"muzzle_front_shorted" 		"fx_muzzle_slug" 	"fx_main"}
			{add_view 	"muzzle_front_hmgun" 		"fx_muzzle_dragon" 	"fx_main"}
			
			
			{add_view 	"fx_fire_hot_dragon" 		"fire_hot" 	"fx_main"}
			
			
			
			{view hide	"fx_muzzle_buck"}
			{view pause	"fx_muzzle_buck"}
			{view hide	"fx_muzzle_slug"}
			{view pause	"fx_muzzle_slug"}

			{add_view 	"flash_gun_silencer_small" 		"fx_main_sil" 			"fx_main_sil"}
			{add_view 	"fire_sil" 						"fx_fire_hot" 			"fx_main_sil"}
			{view hide	"fx_fire_hot"}
			{view pause	"fx_fire_hot"}			
			{view hide	"fire_hot"}
			{view pause	"fire_hot"}			
		}
		{on "fire" overload
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
			{spawn "trace_linear" "foresight3" x }
			{spawn "trace_linear" "foresight3" x }
			{spawn "trace_linear" "foresight3" x }
			{spawn "trace_linear" "foresight3" x }
			{spawn "trace_linear" "foresight3" x }
			{spawn "trace_linear" "foresight3" x }
			{ani_play "hit_charm" }
			{kill_delay "heat"}
			{kill_delay "fire_hot"}
			{if not tagged "heat"				
				{ani_play "heat" +0.3 resume callback}
				{tags add "heat"}
			}
			{delay 3 "heat"
				{ani_play "heat" -0.4 resume }
				{tags remove "heat"}
			}
			{if not tagged "0_bullet"
				{ani_play "recoil" 1}
			else
				{start_sound "weapon/shell_eject/shell12"}	
				{ani_play "empty" 1 }
			}
			; {if prop "autoload"
				; {spawn "smoke_shotgun_shell" "fxshell" x}
			; }
			{spawn "distant_small" "fx_main" }
			{if rand 0.2
				{spawn "sparks01s" "fx_main_sil" x}
				{spawn "sparks01" "fx_main" x}
			else rand 0.2
				{spawn "sparks02" "fx_main" x}
			else rand 0.2
				{spawn "sparks02s" "fx_main_sil" x}
				{spawn "sparks03" "fx_main" x}
			else rand 0.2
				{spawn "sparks04" "fx_main" x}
			else rand 0.2
				{spawn "sparks05" "fx_main" x}
			else rand 0.2
				{spawn "sparks03s" "fx_main_sil" x}
				{spawn "sparks06" "fx_main" x}
			else rand 0.2
				{spawn "sparks07" "fx_main" x}
			}	
			{delay 1.2 0.2 "fire_hot"
				{view hide	"fx_fire_hot"}
				{view pause	"fx_fire_hot"}
			}
			{if stuff_filled "slug" 1 
				{tags add "slug"}
				{tags remove "buck"}
				{view start "fx_main_sil"}
				{view start "fx_muzzle_slug"}
				{view show "fx_muzzle_slug"}
				{delay 0.03 "fire"
					{view show	"fx_fire_hot"}
					{view start	"fx_fire_hot"}
					{view hide	"fx_main_sil"}
					{view pause	"fx_main_sil"}
					{view start "smoke"}
					{view hide	"fx_muzzle_slug"}
					{view pause	"fx_muzzle_slug"}
				}
			else stuff_filled "dragon" 1 
				{start_sound "hit/small/bullet_fire/"}	
				{view start "fx_muzzle_dragon"}
				{view show "fx_muzzle_dragon"}
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "fx_shoot_hit_sparks" "foresight3" x {impulse dir 4 2 rnd_dir 0.1} {gravity 0} }
				{spawn "trace_linear" "foresight3" x }
				{spawn "trace_linear" "foresight3" x }
				{spawn "trace_linear" "foresight3" x }
				{spawn "trace_linear" "foresight3" x }
				{spawn "trace_linear" "foresight3" x }
				{spawn "trace_linear" "foresight3" x }
				{delay 0.03 "fire"
					{view show	"fire_hot"}
					{view start	"fire_hot"}
					{view hide "fx_muzzle_dragon"}
					{view pause "fx_muzzle_dragon"}
				}
				{delay 0.35 "fire"
					{view hide	"fire_hot"}
					{view pause	"fire_hot"}
				}
				{tags add "dragon"}
				{tags remove "buck"}
				{tags remove "slug"}
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "dragon_fire" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
			else 
				{view start "fx_muzzle_buck"}
				{view show "fx_muzzle_buck"}
				{view start "fx_main_sil"}
				{delay 0.03 "fire"
					{view show	"fx_fire_hot"}
					{view start	"fx_fire_hot"}
					{view hide	"fx_main_sil"}
					{view pause	"fx_main_sil"}
					{view hide "fx_muzzle_buck"}
					{view pause "fx_muzzle_buck"}
				}
				{tags add "buck"}
				{tags remove "slug"}
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
				{spawn "fraction" "foresight3" x {impulse dir %dir rnd_dir %rnd_dir} {gravity %gravity} }
			}		
		}
		{on animation_end "heat"
			{view start "stage1"}
			{delay 7 
				{view hide	"stage1"}
				{view pause	"stage1"}
			}
			{burn volume "heat" fx "smoke_heat_barrel" time 4 fake even_law}
			{tags add "stage1"}
			{if tagged "fire_hold"				
				{view start "stage1_fire"}
				{delay 0.5 
					{view pause "stage1_fire"}
				}
				{start_sound "weapon/heat/"}
			}
		}
	}
)
("shotgun_barrel" tag(5inch) 	dir(75) 	rnd_dir(2) 		gravity(0.8) )
("shotgun_barrel" tag(7inch) 	dir(80) 	rnd_dir(1.7) 	gravity(0.7) )
("shotgun_barrel" tag(10inch) 	dir(85) 	rnd_dir(1.5) 	gravity(0.7) )
("shotgun_barrel" tag(15inch) 	dir(100) 	rnd_dir(1) 		gravity(0.5) )
("shotgun_barrel" tag(20inch) 	dir(115) 	rnd_dir(0.6) 	gravity(0.4) )

(define "flash_fx"
	{"stuff weapon %tag"
		{on spawn
			{add_view "laser_sight_w"			"lasersight00"	"lasersight00"}
			{add_view "diod_green"				"diod_green"	"fxload" in_manual }
			{add_view "diod_red"				"diod_red"		"fxload" in_manual }
			{add_view "diod_green"				"diod_green"	"pointer01" in_manual }
			{add_view "diod_red"				"diod_red"		"pointer01" in_manual }
			{if not prop "silenced"
				{add_view "%flash" "flashbarrel" "foresight3"}
			}
		}
	}
)

(define "flash_fx2"
	{"stuff weapon %tag"
		{on spawn
			{add_view "%flash" "flashbarrel_s" "shooter00"}
			{add_view "%flash" "flashbarrel_s" "shooter01"}
		}
	}
)
("flash_fx" tag(flash_set4)		flash(flash_gun_m79))
("flash_fx" tag(m40)			flash(flash_gun_big))
("flash_fx" tag(hmgun_set)		flash(flash_gun_atr30))
("flash_fx" tag(smg_s)			flash(flash_gun_small_sparks))
("flash_fx" tag(shotgun2)		flash(flash_gun_shot_short))
("flash_fx2" tag(shotgun_bm)	flash(flash_gun_shot_short))
("flash_fx" tag(heavy_pistol)	flash(flash_gun_set2))


{"stuff weapon riflehand"
	{on animation_event "open_bolt_handle"
		{if tagged "reload"
			{start_sound "weapon/boltopen/empty_eject/"}	
		else
			{start_sound "weapon/boltopen/boltopen"}	
		}
	}		
	{on animation_event "close_bolt_handle"
		{start_sound "weapon/boltopen/bolt_load/"}	
	}		
	; {on animation_event "charge_load"
		; {start_sound "weapon/armed/snrifle_series/boltopen"}	
	; }		
	{on animation_event "clear_casing"
		{start_sound "weapon/shell_eject/shell12"}	
		{tear "shell_drop" bone "shell" copy ;slicer_tail
			{impulse forward 2 com  }
		}
		{delay 0
			{view hide "shell"}	
		}
	}		
	{on "fire" ;stand anim fast
		{ani_play "fire"}
		{delay 0.6
			{if not tagged "reload"
				{ani_play "charge" 1}
			}
		}
	}
}
(define "bullet_filling_00"
	("bullet_filling" args 00)	("bullet_filling" args 01)
	("bullet_filling" args 02)	("bullet_filling" args 03)
	("bullet_filling" args 04)	("bullet_filling" args 05)
	("bullet_filling" args 06)	("bullet_filling" args 07)
	("bullet_filling" args 08)	("bullet_filling" args 09)
	("bullet_filling" args 10)	("bullet_filling" args 11)
	("bullet_filling" args 12)	("bullet_filling" args 13)
	("bullet_filling" args 14)	("bullet_filling" args 15)
	("bullet_filling" args 16)	("bullet_filling" args 17)
	("bullet_filling" args 18)	("bullet_filling" args 19)
	("bullet_filling" args 20)	("bullet_filling" args 21)
	("bullet_filling" args 22)	("bullet_filling" args 23)
	("bullet_filling" args 24)	("bullet_filling" args 25)
	("bullet_filling" args 26)	("bullet_filling" args 27)
	("bullet_filling" args 28)	("bullet_filling" args 29)
	("bullet_filling" args 30)	("bullet_filling" args 31)
	("bullet_filling" args 32)	("bullet_filling" args 33)
	("bullet_filling" args 34)	("bullet_filling" args 35)
	("bullet_filling" args 36)	("bullet_filling" args 37)
	("bullet_filling" args 38)	("bullet_filling" args 39)
	("bullet_filling" args 40)	("bullet_filling" args 41)
	("bullet_filling" args 42)	("bullet_filling" args 43)
	("bullet_filling" args 44)	("bullet_filling" args 45)
	("bullet_filling" args 46)	("bullet_filling" args 47)
	("bullet_filling" args 48)	("bullet_filling" args 49)
	("bullet_filling" args 50)	("bullet_filling" args 51)
	("bullet_filling" args 52)	("bullet_filling" args 53)
	("bullet_filling" args 54)	("bullet_filling" args 55)
	("bullet_filling" args 56)	("bullet_filling" args 57)
	("bullet_filling" args 58)	("bullet_filling" args 59)
	("bullet_filling" args 60)	("bullet_filling" args 61)
	("bullet_filling" args 62)	("bullet_filling" args 63)
	("bullet_filling" args 64)	("bullet_filling" args 65)
	("bullet_filling" args 66)	("bullet_filling" args 67)
	("bullet_filling" args 68)	("bullet_filling" args 69)
	("bullet_filling" args 70)	("bullet_filling" args 71)
	("bullet_filling" args 72)	("bullet_filling" args 73)
	("bullet_filling" args 74)	("bullet_filling" args 75)
)
(define "bullet_filling_99"
	("bullet_filling" args 99)	("bullet_filling" args 98)
	("bullet_filling" args 97)	("bullet_filling" args 96)
	("bullet_filling" args 95)	("bullet_filling" args 94)
	("bullet_filling" args 93)	("bullet_filling" args 92)
	("bullet_filling" args 91)	("bullet_filling" args 90)
	("bullet_filling" args 89)	("bullet_filling" args 88)
	("bullet_filling" args 87)	("bullet_filling" args 86)
	("bullet_filling" args 85)	("bullet_filling" args 84)
	("bullet_filling" args 83)	("bullet_filling" args 82)
	("bullet_filling" args 81)	("bullet_filling" args 80)
	("bullet_filling" args 79)	("bullet_filling" args 78)
	("bullet_filling" args 77)	("bullet_filling" args 76)
	("bullet_filling" args 75)	("bullet_filling" args 74)
	("bullet_filling" args 73)	("bullet_filling" args 72)
	("bullet_filling" args 71)	("bullet_filling" args 70)
	("bullet_filling" args 69)	("bullet_filling" args 68)
	("bullet_filling" args 67)	("bullet_filling" args 66)
	("bullet_filling" args 65)	("bullet_filling" args 64)
	("bullet_filling" args 63)	("bullet_filling" args 62)
	("bullet_filling" args 61)	("bullet_filling" args 60)
	("bullet_filling" args 59)	("bullet_filling" args 58)
	("bullet_filling" args 57)	("bullet_filling" args 56)
	("bullet_filling" args 55)	("bullet_filling" args 54)
	("bullet_filling" args 53)	("bullet_filling" args 52)
	("bullet_filling" args 51)	("bullet_filling" args 50)
	("bullet_filling" args 49)	("bullet_filling" args 48)
	("bullet_filling" args 47)	("bullet_filling" args 46)
	("bullet_filling" args 45)	("bullet_filling" args 44)
	("bullet_filling" args 43)	("bullet_filling" args 42)
	("bullet_filling" args 41)	("bullet_filling" args 40)
	("bullet_filling" args 39)	("bullet_filling" args 38)
	("bullet_filling" args 37)	("bullet_filling" args 36)
	("bullet_filling" args 35)	("bullet_filling" args 34)
	("bullet_filling" args 33)	("bullet_filling" args 32)
	("bullet_filling" args 31)	("bullet_filling" args 30)
	("bullet_filling" args 29)	("bullet_filling" args 28)
	("bullet_filling" args 27)	("bullet_filling" args 26)
	("bullet_filling" args 25)	("bullet_filling" args 24)
	("bullet_filling" args 23)	("bullet_filling" args 22)
	("bullet_filling" args 21)	("bullet_filling" args 20)
	("bullet_filling" args 19)	("bullet_filling" args 18)
	("bullet_filling" args 17)	("bullet_filling" args 16)
	("bullet_filling" args 15)	("bullet_filling" args 14)
	("bullet_filling" args 13)	("bullet_filling" args 12)
	("bullet_filling" args 11)	("bullet_filling" args 10)
	("bullet_filling" args 09)	("bullet_filling" args 08)
	("bullet_filling" args 07)	("bullet_filling" args 06)
	("bullet_filling" args 05)	("bullet_filling" args 04)
	("bullet_filling" args 03)	("bullet_filling" args 02)
	("bullet_filling" args 01)	("bullet_filling" args 00)
)
{"stuff weapon"
	{on spawn
		{if stuff_filled "ap" 1
			{bone show "tape_ap"}			
		else stuff_filled "fg" 1
			{bone show "tape_fg"}			
		else
			{bone hide "tape_ap"}			
			{bone hide "tape_fg"}			
		}		
		{tags add "first_load"}
		{if tagged "first_load"
			{ani_play "shot_small00" -10}
		}
		{link_sound "heat"						"weapon/heat/cooldown_pings" 	}	
		{call "random_skin"}
		{call "move"}
		{bone hide "stock_tactical_detail"}
		{bone hide "stock_stable_detail"}
		{bone hide "grip1"}
		{bone hide "grip2"}
		{bone hide "grip3"}
		{bone hide "grip4"}
		{bone hide "perk"}
		{bone hide "perk1"}
		{bone hide "perk2"}
		{bone hide "perk3"}
		{bone hide "perk4"}
		{bone hide "veteran1"}
		{bone hide "veteran2"}
		{bone hide "veteran3"}
		{bone hide "veteran4"}
		{bone hide "veteran5"}
		{if not "texmods"
			{ani_play "view_upgrade" 1}
			{set "texmods" 1}
			{if rand 0.4
				{bone show "stock_tactical_detail"}
			else rand 0.4
				{bone show "stock_stable_detail"}
			}
			{if rand 0.3
				{tex_mod "r"}
			else rand 0.3
				{tex_mod "r2"}
			else rand 0.3
				{tex_mod "r3"}
			else rand 0.3
				{tex_mod "r4"}
			}
			{if rand 0.2
				{bone show "perk1"}
			else rand 0.2
				{bone show "perk2"}
			else rand 0.2
				{bone show "perk3"}
			else rand 0.2
				{bone show "perk4"}
			else rand 0.2
				{bone show "perk"}
			}			
			{if rand 0.3
				{bone show "grip1"}
			else rand 0.3
				{bone show "grip2"}
			else rand 0.3
				{bone show "grip3"}
			else rand 0.3
				{bone show "grip4"}
			}			
		}
		{if rain
			{tex_mod "wet"}	
		}
	}
	{on "reload"
		{play_sound "reload"}
		{delay 1
			{if stuff_filled "ap" 1
				{bone show "tape_ap"}			
			else stuff_filled "fg" 1
				{bone show "tape_fg"}			
			else
				{bone hide "tape_ap"}			
				{bone hide "tape_fg"}			
			}		
		}		
		{delay 2
			{ani_play "shot_small00" resume}
		}	
	}	
	{on "fire"
		{play_sound "mid"}
		{play_sound "far"}
		{play_sound "action_recoil"}
		(define "bullet_filling"
			{if bone "bullet%0" visible
				{tags add "bullet%0"}
			else
				{ani_play "shot_small%0" resume}
				{tags remove "bullet%0"}
			}
		)
		("bullet_filling_99")
		{if not tagged "ready_shot" 
			{if "broken"
				{if rand 0.1
					{spawn "sparks01" "fxshell" x}
				else rand 0.1
					{spawn "sparks02" "fxshell" x}
				else rand 0.1
					{spawn "sparks07" "fxshell" x}
				}	
			}
			{if not tagged "riflehand"
				{kill_delay "fire_hold"}
				{if not tagged "fire_hold"				
					{tags add "fire_hold"}
				}
				{delay 3 "fire_hold"
					{tags remove "fire_hold"}
					{view pause "smoke"}				
				}
				;{view hide	"led_hold"}
				;{view pause	"led_hold"}
				;{view show	"led_fire"}
				;{view start	"led_fire"}
				{ani_play "hit" resume loop}
				;---------------------
				{if not tagged "fire_move"				
					{ani_play "fire_move" +5 resume callback }
					{tags add "fire_move"}
				}
				{delay 0.2
					{tags remove "fire_move"}
				}
				{delay 0.1 "fire_hold"
					{ani_play "fire_move" -12 resume callback }
				}
				;---------------------
				{if not tagged "0_bullet"
					{ani_play "recoil" }
				else
					{start_sound "weapon/shell_eject/shell12"}	
					{ani_play "empty" }
				}
				
				;{set "fire_stand" 1}
				;{ani_play "fire" loop}
				{view show	"flashbarrel"}
				{view start	"flashbarrel"}
				;{tex_mod "fire"}			
				;{view hide	"diod_red"}
				;{view pause	"diod_red"}
				;{view show	"diod_green"}
				;{view start	"diod_green"}
				{view show	"flashbarrel_s"}
				{view start	"flashbarrel_s"}
				{view start "shell"}
				{delay 0.1 "shell"
					{view pause "shell"}
					{call "fire_stand"}
				}
				{delay 0.4 "fire"
					{ani_play "end" 1}
					;{set "fire_stand" 0}
					{view hide	"flashbarrel_s"}
					{view pause	"flashbarrel_s"}
					{view hide	"flashbarrel"}
					{view pause	"flashbarrel"}
					{view hide	"diod_green"}
					{tex_mod "hold"}			
					;{view pause	"diod_green"}
					;{view show	"diod_red"}
					;{view start	"diod_red"}
				}
				{delay 1 "stand_anim"
					{ani_stop "hit"}
					;{view show	"led_hold"}
					;{view start	"led_hold"}
					;{ani_stop "fire"}
					;{ani_play "stand" loop}
				}
				{delay 1.6 
					{view pause "smoke_recoil"}
					;{ani_stop "stand"}
					;{ani_play "stand" 0.5}
					;{delay 1 "2"
					;	{ani_stop "stand"}
					;}
				}
			}
		}
	}
	{on "diode"
		{if	"reload"
			{view hide	"diod_green"}
			{view pause	"diod_green"}
			{view show	"diod_red"}
			{view start	"diod_red"}
			{delay 0.3	
				{view hide	"diod_red"}
				{view pause	"diod_red"}
				{view show	"diod_green"}
				{view start	"diod_green"}
				{call "diode"}	
			}
		}
	}
	{on "reload_part"
		{ani_play "reload" 0.3}
	}
	{on "cross_break_40m"
		{ani_play "break_act" 1}
	}
	{on "link"
;		(define "bullet_filling"
;			{if bone "bullet%0" visible
;				{ani_play "shot_small%0" }
;				;{tags add "bullet%0"}
;			else
;				;{tags remove "bullet%0"}
;			}
;		)
;		("bullet_filling_00")
		{if tagged "ui"
			{ani_play "flashlight_sf_l_ui" -0.4}
			{ani_play "flashlight_sf_r_ui" -0.4}
			{ani_play "peq10_l_ui" -0.4}
			{ani_play "peq15_l_ui" -0.4}
			{ani_play "peq10_r_ui" -0.4}
			{ani_play "peq15_r_ui" -0.4}
			{ani_play "laser1mw_l_ui" -0.4}
			{ani_play "laser1mw_r_ui" -0.4}
			{ani_play "laser5mw_l_ui" -0.4}
			{ani_play "laser5mw_r_ui" -0.4}
			{ani_play "tactical_laser_l_ui" -0.4}
			{ani_play "tactical_laser_r_ui" -0.4}
			{ani_play "tactical_laser2_l_ui" -0.4}
			{ani_play "tactical_laser2_r_ui" -0.4}
			{ani_play "zenitco_l_ui" -0.4}
			{ani_play "zenitco_r_ui" -0.4}
			{ani_play "liner_l_ui" -0.4}
			{ani_play "liner_r_ui" -0.4}
			{ani_play "lasercylinder1_l_ui" -0.4}
			{ani_play "lasercylinder1_r_ui" -0.4}
			{ani_play "lasercylinder3_l_ui" -0.4}
			{ani_play "lasercylinder3_r_ui" -0.4}
			{ani_play "lasercylinder4_l_ui" -0.4}
			{ani_play "lasercylinder4_r_ui" -0.4}
		}
		{if tagged "rotate"
			{tags remove "rotate"}
			{ani_play "upgrade" -3}
		}
		{add_view "laser_sight"				"fx_laser"		"fx_laser_set"}
		{add_view "sight_laser"				"fx_laser_sight"		"fx_laser_sight"}
		{add_view "sight_laser"				"fx_laser_sight"		"sight_glow"}
		{add_view "sight_laser"				"fx_laser_sight"		"sight_glow_small"}
		{add_view "headlight_weapon3"		"fx_light"		"fx_light_set"}		
		;{call "laser00_on"}
		{view start "fx_laser_sight"}
		{view show "fx_laser_sight"}
		; {if not sunlight
			; {if rand 0.5
				; {call "lights00_on"}
			; }
		; else
			; {call "lights_off"}
			; {call "lights_off"}
		; }
		{view start	"lasersight00"}
	}
	; {on "laser00_on"
		; {delay 0.8 
			; {if not tagged "laser"
				; {set "laser" 1}
				; {view start "fx_laser"}
				; {view show "fx_laser"}
			; }
		; }
	; }
	; {on "lights00_on"
		; {delay 0.8 
			; {if not "light"
				; {set "light" 1}
				; {view start "fx_light"}
				; {view show "fx_light"}
			; }	
		; }	
	; }	
	{on "lights_off"
		;{set "light" 0}
		;{set "laser" 0}
		{view stop "fx_light"}
		{view hide "fx_light"}
		{view stop "fx_laser"}
		{view hide "fx_laser"}
	}
	{on animation_event "clear_casing_small_invisible"
		{start_sound "weapon/shell_eject/shell5"}	
		{tear "shell_drop_small" bone "shell_drop" copy ;slicer_tail
			{impulse forward 0.5 com  }
		}
	}		
	{on "link_human"
		{play_sound "holster"}
		{delay 0.4
			{ani_play "prepare"}
		}
	}
	{on "unlink_human"
		{ani_play "prepare" -1}
	}
	{on "case_eject"
		{view start "shell"}
		{view show	"ejectsmoke"}
		{view start	"ejectsmoke"}
		{delay 0.1 "shell"
			{view pause "shell"}
			{view hide	"ejectsmoke"}
			{view pause	"ejectsmoke"}
		}
	}
	{on "weapon_reload"
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{call "magazine_delay"}
		{play_sound "eject_clip"}
		{delay 0.075
			{stop_sound "action_recoil"}
		}
	}
	(define "magazine"
		{on "magazine_delay" %override
			{delay %cut
				{view hide "bullet"}
				{tear "piece_tiny_steel" bone "magazine" copy
					%impulse
				}
				{delay 0
					{view hide "magazine"}
					{delay %show
						{view show "magazine"}
						{view show "bullet"}
					}
				}
			}
		}
	)
	("magazine" cut(0) show(1.8) override() impulse({impulse up -0.01 com}))

	(define "drop"
		{on ground_hit %override
			{if terrain_fx "road"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "ice"
				{start_sound "weapon/drop/%material/rock"}
			
			else terrain_fx "snow"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "sand"
				{start_sound "weapon/drop/%material/snow"}
			
			else terrain_fx "bridge_wood"
				{start_sound  "weapon/drop/%material/wood"}
			
			else terrain_fx "shallow_water"

			else terrain_fx "water"

			else
				{start_sound "weapon/drop/%material/ground"}
			}
		}
	)
	("drop" material(metal) override())
}


{"stuff weapon flame_thrower"
	{on spawn
		{add_view "flamer_fire"			"flame"	"foresight3"}
		{add_view "flamer_fire_barrel"	"fire"	"foresight3"}
	}
	{on "link"
		{view show	"fire"}
		{view start	"fire"}
	}
	{on "fire"
		{view start	"flame"}
		{kill_delay "fire"}
		{delay 0.4 "fire"
			{view pause	"flame"}
		}
	}
}
{"stuff weapon rocketlauncher open"
	{on spawn
		{add_view "smoke_guns"	"open"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight3"}
	}
	{on "fire"
		{spawn "bazooka_shot" "fxshot" x}
		{view start	"open"}
		{view start	"smoke"}
		;{kill_delay "fire"}
		{delay 1.2 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}
	}
}

{"stuff weapon rocketlauncher rpg7hp"
	{on spawn
		{add_view "smoke_guns"	"open"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight3"}
;		(define "ammo_set"
;			{if stuff_filled "%stuff" 
;				{tags add "%stuff"}
;				{volumes "%stuff" enable bullet blast}
;				{bone show "%stuff"}
;			}
;		)
;		("ammo_set" stuff(pg7vs) )
;		("ammo_set" stuff(pg7v)  )
;		("ammo_set" stuff(og7v)  )
;		("ammo_set" stuff(pg7vl) )
;		("ammo_set" stuff(pg7vm) )
;		("ammo_set" stuff(pg7vr) )
;		("ammo_set" stuff(tbg7v) )
	}
	{on "unlink"
		{tags remove "link"}
	}
	{on "link"
		{tags add "link"}
		(define "ammo_set"
			{if stuff_filled "%0" 
				{tags add "%0"}
				{bone show "%0"}				
				{tags add "loaded"}
				{delay 0.1
					{volumes "%0" enable all}
				}					
			}
		)
		("ammo_set" args pg7v)
		("ammo_set" args og7v)
		("ammo_set" args pg7vl)
		("ammo_set" args pg7vm)
		("ammo_set" args pg7vr)
		("ammo_set" args pg7vs )
		("ammo_set" args tbg7v )
	}
	{on "reload"
		(define "ammo_set"
			{volumes "%0" disable all}
			{bone hide "%0"}				
			{delay 3
				{start_sound "weapon/reload/rpg_load"}			
				{ani_play "reload" 0.15}
				{tags add "loaded"}
				{if stuff_filled "%0" 
					{tags remove "%0"}
					{bone show "%0"}				
					{delay 0.1
						{volumes "%0" enable all}
					}					
				}
			}
		)
		("ammo_set" args pg7v)
		("ammo_set" args og7v)
		("ammo_set" args pg7vl)
		("ammo_set" args pg7vm)
		("ammo_set" args pg7vr)
		("ammo_set" args pg7vs )
		("ammo_set" args tbg7v )
	}	
	{on "fire"
		{spawn "rpg_warning" "foresight3" x}
		{if tagged "broken"
			{volumes "ammo_small" disable all}	
			{call "broken_blast"}
			{spawn "fraction_spawn" }
			{spawn "metal_hit_zenite_cs"}	
			{spawn "distant_small_expl"}			
			{blastwave c4 6 r0 3 r1 3}	
			{if rand 0.1
				{tear "fireworks_start" bone "ammo_bone"
					{impulse forward 26 10 com  }
				}
			}
		}
		{tags remove "loaded"}
		(define "ammo_set"
			{tags remove "%0"}
			{bone hide "%0"}
			{volumes "%0" disable all}
		)
		("ammo_set" args pg7v)
		("ammo_set" args og7v)
		("ammo_set" args pg7vl)
		("ammo_set" args pg7vm)
		("ammo_set" args pg7vr)
		("ammo_set" args pg7vs )
		("ammo_set" args tbg7v )
		{spawn "rpg7_fraction1" "fxshot" x}
		{spawn "rpg7_fraction2" "fxshot"x}
		{spawn "rpg7_fraction3" "fxshot"x}
		; {spawn "fraction_rpg" "foresight3" x
			; {impulse dir 120 rnd_dir 1}
			; {gravity 0.1}
			
		; }
		{spawn "rpg_shot" "fxshot" x}
		{view start	"open"}
		{view start	"smoke"}
		;{kill_delay "fire"}
		{delay 1.2 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}
	}
	{on ground_hit
		{if contact_velocity 10
			{if rand 0.5
				{if tagged "loaded"
					;{volumes "ammo_small" disable all}	
					{if tagged "tbg7v"
						{call "blast_thermite"}			
					else
						{call "blast_fg"}			
					}
				}
			}
		}
	}
	{on "blast_thermite"
		{volumes disable bullet blast touch}	
		{if not tagged "blasted"
			{bone cut "ammo_bone"}
			{tags add "blasted"}
			{volumes "ammo_small" disable all}	
			{call "broken_blast"}
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_thermite" }
			{spawn "fraction_spawn"}		
			{blastwave c4 5 r0 3 r1 3}	
			{fire radius 6.6 time 7 heating 1}
			{start_sound "detonation/phosphorus_start/"}
			{spawn "ex_air_norm7"}	
			{spawn "distant_small_expl"}			
		}
	}
	{on "blast_fg"
		{volumes disable bullet blast touch}	
		{if not tagged "blasted"
			{if rand 0.1
				{tear "fireworks_start" bone "ammo_bone"
					{impulse forward 26 10 com  }
				}
			}
			{bone cut "ammo_bone"}
			{tags add "blasted"}
			{call "broken_blast"}
			{spawn "fraction_spawn" }
			{spawn "metal_hit_zenite_cs"}	
			{spawn "distant_small_expl"}			
			{blastwave c4 6 r0 3 r1 3}	
		}
	}
	{on pierce
		{if volume "ammo_small"
			{if not "exploded"
				{set "exploded" 1}
				{volumes disable bullet blast touch}	
				{delay 0
					{if tagged "tbg7v"
						{call "blast_thermite"}			
					else
						{call "blast_fg"}			
					}
				}
			}
		}
	}
	{on blast
		{if min_energy 1.2
			{if not "exploded"
				{set "exploded" 1}
				{if volume "ammo_small"
					{volumes "ammo_small" disable all}	
					{if tagged "tbg7v"
						{call "blast_thermite"}			
					else
						{call "blast_fg"}			
					}
				}
			}
		}	
	}	
}

{"stuff weapon carl_gustav"
	{on spawn
		{add_view "laser_sight_add_guided" "guided" "laser_point"}
		{add_view "smoke_guns"	"open"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight3"}
		{view hide	"guided"}
		{view pause	"guided"}
		(define "ammo_set"
			;{bone hide "%0"}
			{if stuff_filled "%0" 
				{tags add "%0"}
				{bone show "%0"}
			}
		)
		("ammo_set" args hedp4410 )
		("ammo_set" args hedp441d )
		("ammo_set" args heat551 )
		("ammo_set" args heat751 )
	}
	{on "link"
		(define "ammo_set"
			{if stuff_filled "%0" 
				{tags add "%0"}
				{bone show "%0"}				
			}
		)
		("ammo_set" args hedp4410 )
		("ammo_set" args hedp441d )
		("ammo_set" args heat551 )
		("ammo_set" args heat751 )
	}
	{on "reload"
		{view hide	"guided"}
		{view pause	"guided"}
		(define "ammo_set"
			{bone hide "%0"}				
			{delay 2.5
				{ani_play "reload_stand" 0.15}
				{delay 0.5
					{start_sound "weapon/reload/rpg_load"}			
					{tags add "loaded"}
					{if stuff_filled "%0" 
						{tags remove "%0"}
						{delay 0.8
							{bone show "%0"}				
						}
					}
				}
			}
		)
		("ammo_set" args hedp4410 )
		("ammo_set" args hedp441d )
		("ammo_set" args heat551 )
		("ammo_set" args heat751 )
	}	
	{on "fire"
		{if stuff_filled "heat751"
			;{start_sound ""}
			{view show	"guided"}
			{view start	"guided"}
			{delay 3
				{view hide	"guided"}
				{view pause	"guided"}
			}	
		}
		{tags remove "loaded"}
		(define "ammo_set"
			{tags remove "%0"}
			{bone hide "%0"}
		)
		("ammo_set" args hedp4410 )
		("ammo_set" args hedp441d )
		("ammo_set" args heat551 )
		("ammo_set" args heat751 )
		{spawn "rpg_shot" "fxshot" x}
		{view start	"open"}
		{view start	"smoke"}
		;{kill_delay "fire"}
		{delay 1.2 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}
	}
}



{"stuff weapon 9k38"
	{on spawn
		{add_view "smoke_guns"	"open"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight3"}
		{if stuff_filled "ammo" 
			{bone show "rocket"}
			{bone show "starter"}
		}
	}
	{on "link"
		{if stuff_filled "ammo" 
			{bone show "starter"}
			{bone show "rocket"}
		}
	}
	{on animation_event "caps_load"	
		{bone show "starter"}
		{delay 0.4
			{start_sound "weapon/detach"}			
		}
	}
	{on "reload"
		{delay 1.2
			{bone show "rocket"}
			{ani_play "reload_stand" 0.4}
			{delay 0.5
				{start_sound "weapon/reload/rpg_load"}			
				{tags add "loaded"}
				{delay 0.8
					;{bone show ""}				
				}
			}
		}
	}	
	{on "fire"
		{bone hide "starter"}
		{bone hide "rocket"}
		{spawn "atgm_warning" "foresight3" x}
		{delay 0.3
			{spawn "atgm_warning" "foresight3" x}
		}
		{tags remove "loaded"}
		{spawn "rpg_shot" "fxshot" x}
		{view start	"open"}
		{view start	"smoke"}
		;{kill_delay "fire"}
		{delay 1.2 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}
	}
}







{"stuff weapon bgm71tow"
	{on spawn
		{add_view "start_bgm" "fxshot"	"fxshot"}
		{add_view "smoke_tow_tube" "open"	"foresight1"}
		{add_view "smoke_guns"	"open"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight1"}
	}
	{on "link"
	}
	{on "reload"
		{delay 5
			{start_sound "weapon/click/LauncherMissile_click"}	
			{bone hide "tube"}
			{delay 5
				{start_sound "weapon/armed/stuff"}	
				{bone show "tube"}
			}
		}
		{view hide	"guided"}
		{view pause	"guided"}
	}	
	{on "fire"
		{spawn "atgm_warning" "foresight3" x}
		{delay 0.3
			{spawn "atgm_warning" "foresight3" x}
		}
		{spawn "caps_front_fragment_tow" "caps_front" x
			{impulse dir 75 10  fx -35 10}
		}
		{spawn "caps_back_fragment_tow" "caps_back" x
			{impulse dir -30 -15  fx -35 10}
		}
		{view show	"fxshot"}
		{view start	"fxshot"}
		{delay 1.2
			{burn volume fx "smoke_heat" time 5 fake even_law}
			{view hide "fxshot"}
			{view pause "fxshot"}
		}			
		{view start	"open"}
		{view start	"smoke"}
		;{kill_delay "fire"}
		{delay 2.5 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}
	}
}
{"stuff weapon aksu74"
	{on spawn
		{if rand 0.1
			{bone hide "cover"}
		}
	}
}
{"stuff weapon anim_extension"
	{on spawn
		{ani_wind "extended" begin}
	}
	{on "link"
		{delay 0.3
			{ani_play "extended"}
		}
	}
	{on "unlink"
		{ani_play "extended" -1}
	}
}
{"stuff weapon object_thrower"
	{on spawn
		{add_view "flamer_fire_barrel"	"fire"	"foresight3"}
	}
	{on "link"
		{view show	"fire"}
		{view start	"fire"}
	}
	{on "fire" overload
		{spawn "flamethrower_shell" "foresight3" x
			{impulse dir 30 rnd_dir 1}
			{gravity 1}
			{linear_damping 0}
		}
	}
}


{"stuff weapon goh_ww"
	{on spawn
		{add_view "smoke_zenit"	"smoke"	"fxshot"}
		{add_view "smoke_zenit"	"smoke"	"foresight3"}
		{add_view "rpg_shot_stage" "open"	"fxshot"}
	}
	{on "fire"
		{view start	"open"}
		{view start	"smoke"}
		{delay 3 "open"
			{view pause	"open"}
		}
		{delay 2.6 "smoke"
			{view pause	"smoke"}
		}

		{spawn "bazooka_shot_inv"	"fxshot" x}
		{delay 0.2
			{burn volume "body" fx "smoke_heat_barrel" time 0.6 fake even_law}
		}
		{with_effector
			{if terrain_fx "water"
			else terrain_fx "shallow_water"
			else terrain_fx "mud"
			else terrain_fx "snow"
				{spawn "bazooka_snow"	"basis" x}
			else terrain_fx "ice"
				{spawn "bazooka_snow"	"basis" x}
			else
				{spawn "bazooka_dust"	"basis" x}
			}
		}
	}
	{on "link_human" overload
		{delay 1.3
			{ani_play "prepare"}
		}
	}
}

{"stuff weapon wood_stock"
	("drop" material(wood) override(overload))
}

{"stuff weapon auto_eject"
	{on "fire"
		{call "instant_eject"}
	}
	{on "instant_eject"
		{call "case_eject"}
	}
}

{"stuff weapon auto_eject semi_auto"
	{on "instant_eject" overload
		{delay 0.065
			{call "case_eject"}
		}
	}
}

{"stuff weapon bolt_action"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.5}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.6
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}

{"stuff weapon shotgun_double"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}
		(define "double_shot"
			{delay %0
				{tear "piece_tiny_steel" bone "shell%1" copy
					{impulse up -0.01}
				}
				{delay 0
					{view hide "shell%1"}
					{delay 2.0
						{view show "shell%1"}
					}
				}
			}
		)
		("double_shot" args 0.9 1)
		("double_shot" args 1.00 2)
	}
}

{"stuff weapon shotgun_pump"
	{on "fire"
		{tags add "fired"}
		{delay 0.35 "bolt_action"
			{ani_play "bolt_action" 1.0}
			{play_sound "open_bolt"}
			{delay 0.2 
				{call "case_eject"}
			}
		}
		{delay 0.4
			{tags remove "fired"}
		}
		{delay 0.6
			{play_sound "close_bolt"}
		}
	}
	{on "weapon_reload" overload
		{kill_delay "bolt_action"}
		{ani_play "reload"}
		{if tagged "fired"
			{delay 0.55
				{call "case_eject"}
			}
		else
		}
		{delay 5.5
			{play_sound "close_bolt"}
		}
	}
}
{"stuff weapon flare_gun"
	{on "weapon_reload" overload
		{delay 0.5
			{ani_play "reload"}
		}

		{delay 1
			{tear "piece_tiny_steel" bone "flare" copy
				{impulse up -0.01}
			}
			{delay 0
				{view hide "flare"}
				{delay 1.5
					{view show "flare"}
				}
			}
		}
	}
}

(define "flame_fx"
	{"stuff weapon flame_thrower %tag"
		{on spawn
			{add_view "flamer_fire"			"flame"	"foresight3"}
			;//{add_view "flamer_fire_barrel"	"fire"	"foresight3"} ;// does not hide in FoW

			{link_sound "start"	"weapon/shot/flame/handheld/flamer_start"}
			{link_sound "loop"	"weapon/shot/flame/handheld/flamer_loop"}
			{link_sound "end"	"weapon/shot/flame/handheld/flamer_stop"}
		}
		{on "start_burst"
			{play_sound "start"}
			{delay 0.1 "loop"
				{play_sound "loop" 1}
			}
		}
		{on "end_burst"
			{kill_delay "loop"}
			{play_sound "end"}
			{stop_sound "loop"}
		}
		{on "link_human"
			;//{view show	"fire"}
			;//{view start	"fire"}
		}
		{on "unlink_human"
			;//{view pause	"fire"}
		}
		{on "fire" overload
			{spawn "%flame" "foresight3" x
				{impulse forward 30 rnd_dir 0.01 com}
				{gravity 0.65}
				{linear_damping 0}
			}
			{view start "flame"}
			{kill_delay "fire"}
			{delay 0.05
				{spawn "%flame" "foresight3" x
					{impulse forward 30 rnd_dir 0.01 com}
					{gravity 0.65}
					{linear_damping 0}
				}
			}
			{delay 0.1 "fire"
				{view pause "flame"}
			}
		}
	}
)

("flame_fx" tag(range_20)		flame(fx_piece_flame_20))
("flame_fx" tag(range_30)		flame(fx_piece_flame_30))
("flame_fx" tag(range_40)		flame(fx_piece_flame_40))

{"stuff weapon bipod"			;// weapons with bipods
	{on spawn 
		{ani_wind "bipod_open" begin}
	}
	{on "link_human"
		{delay 0.6
			{ani_play "bipod_open"}
		}
	}
	{on "unlink_human"
		{ani_play "bipod_open" -1}
	}
	{on "link"					;// linked to vehicle
		{ani_wind "bipod_open" begin}
	}
	{on "link_open"				;// linked to vehicle opened
		{ani_wind "bipod_open" end}
	}
}

;/*=========== Generic Weapon Settings End ===========*/


;/*=========== SPECIFIC WEAPONS BEGIN ===========*/
;/**=========== ENG WEAPONS Begin ===========**/
{"stuff weapon Bren"				;// props added to Bren Gun
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/ENG/BREN_Gun/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/ENG/BREN_Gun/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/ENG/BREN_Gun/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
;/**=========== ENG WEAPONS End ===========**/
;/**=========== FIN WEAPONS BEGIN ===========**/
{"stuff weapon boys_mk1"					;// props added to 14 mm PST KIV37:
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/AT_Rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/RUS/PTR/"}		; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/RUS/PTR/"}		; Placeholder
	}
	{on "weapon_reload"
		{call "magazine_delay"}
	}
	("magazine" cut(1.00) show(2.75) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon bergmann_m20"				;// props added to 7,65 KP/Bergmann
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/PPS43/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/PPS43/"}	; Placeholder
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon chauchat"					;// props added to 800 PK 15
	{on spawn
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/MAC1931/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/Shared/MAC1931/"}
	}
	("magazine" cut(1.00) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon lahti_l35"					;// props added to 900 PIST 35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/FIN/L35/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/FIN/L35/"}
	}
}
{"stuff weapon suomi_m31_drum"				;// props added to 900 KP 31 w/ Drum Magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/FIN/KP31/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/FIN/KP31/"}
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon suomi_m31_stick"				;// props added to 900 KP 31 w/ Stick Magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/FIN/KP31/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/FIN/KP31/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m26"							;// props added to 762 PK 26
	{on spawn 
		{link_sound "action_recoil"	"weapon/reload/action/recoil/open_bolt_mg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/LS26/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/LS26/"}
	}
}
{"stuff weapon mosin_m27"					;// props added to 762 KIV 91-27
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
	}
}
{"stuff weapon mosin_m39"					;// props added to 762 KIV 39
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/M39/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/M39/"}
	}
}
{"stuff weapon madsen"						;// props added to 762 PK 20
	{on spawn 
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/FIN/LS26/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/FIN/LS26/"}	; Placeholder
	}
}
;/**=========== FIN WEAPONS END ===========**/
;/**=========== GER WEAPONS BEGIN ===========**/
{"stuff weapon mp28"						;// props added to MP 28
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}	; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}	; Placeholder
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mp40"						;// props added to MP 38, MP 40 variants and MP 41
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_smg/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/MP40/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/MP40/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon stg44"						;// props added to StG 44 and MKb 42(H)
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/StG44/"}
		{link_sound "mid"		"weapon/shot/smallarms/s2/d2/GER/StG44/"}
		{link_sound "far"		"weapon/shot/smallarms/s2/d3/GER/StG44/"}
	}
	("magazine" cut(1.20) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon k98"							;// props added to all  K 98k variants
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/K98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/K98k/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/K98k/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/K98k/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/K98k/"}
	}
}
{"stuff weapon g41"							;// props added to G 41
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/G41/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/G41/"}
	}
}
{"stuff weapon g43"							;// props added to all G/K 43 variants
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/G43/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/G43/"}
	}
}
{"stuff weapon fg42"						;// props added to FG 42
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/FG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/FG42/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg13_no_bipod"				;// props added to MG 13
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG13/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG13/"}
	}
	("magazine" cut(1) show(2.45) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg26t"						;// props added to MG 26(t)
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG26t/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/GER/MG26t/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/GER/MG26t/"}
	}
	("magazine" cut(1.0) show(3.0) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon mg34_doubledrum"				;// props added to MG 34 w/ Patronentrommel 34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG34/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG34/"}
	}
	("magazine" cut(1) show(2.25) override(overload) impulse({impulse up 0.5 forward 0.9 0.1}))
}
{"stuff weapon mg34_drum"					;// props added to MG 34 w/ Gurttrommel 34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG34/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG34/"}
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.4 forward 0.9 0.1}))
}
{"stuff weapon mg34_belt"					;// props added to MG 34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG34/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG34/"}
	}
}
{"stuff weapon mg34_belt_long"				;// props added to MG 34
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG34/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG34/"}
	}
}
{"stuff weapon mg42_drum"					;// props added to MG 42 w/ Gurttrommel 34
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG42/"}
	}
	("magazine" cut(1) show(1.95) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon mg42_belt"					;// props added to MG 42
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG42/"}
	}
}
{"stuff weapon mg42_belt_long"				;// props added to MG 42
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/GER/MG42/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/MG42/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/MG42/"}
	}
}
{"stuff weapon luger"						;// props added to P 08
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P08/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P08/"}
	}
}
{"stuff weapon p38"							;// props added to P 38
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/GER/P38/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/GER/P38/"}
	}
}
{"stuff weapon pzb_39"						;// props added to PzB 39
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/AT_Rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/RUS/PTR/"}		; Placeholder
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/RUS/PTR/"}		; Placeholder
	}
}
{"stuff weapon panzerfaust"					;// props added to all Panzerfaust Variants
	{on spawn
		{link_sound "mid"		"weapon/shot/reactive/d2/GER/Panzerfaust/"}
		{link_sound "far"		"weapon/shot/reactive/d3/GER/Panzerfaust/"}
	}
}
{"stuff weapon schiessbecher"				;// props added to all K 98k Rifle Grenade Launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/K98k/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/K98k/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/GER/K98k/Schiessbecher/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/GER/K98k/Schiessbecher/"}
	}
}
;/**=========== GER WEAPONS END ===========**/
;/**=========== RUS WEAPONS BEGIN ===========**/

{"stuff weapon dp_bipod"					;// props added to DP 27
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/DP27/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/DP27/"}
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dt"							;// props added to DT 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/reciprocating/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/DP27/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/DP27/"}
	}
	("magazine" cut(0.75) show(2.5) override(overload) impulse({impulse up 0.3 forward 0.9 0.1 cy 1.5 0.25}))
}
{"stuff weapon dyakonov"					;// props added Mosin-Nagant 1891/30 Rifle Grenade Launchers
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/MN9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/MN9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/Dyakonov/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/Dyakonov/"}
	}
}
{"stuff weapon mosin"						;// props added to all  Mosin-Nagant 1891/30 variants and Mosin Carbine
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/M9130/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/M9130/"}
	}
}
{"stuff weapon mosin_silencer"				;// props added to all  Mosin-Nagant 1891/30 B
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M9130/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M9130/"}
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/Shared/Surpressed_Rifle/"}
	}
}
{"stuff weapon nagant_revolver"				;// props added to Nagant 1895
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/M1895/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/M1895/"}
	}
}
{"stuff weapon nagant_silencer"				;// props added to Nagant 1895 B
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/Shared/Surpressed_Pistol/"}
	}
}
{"stuff weapon ppd40"						;// props added to PPD 40
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_SMG/Type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_drum"					;// props added to PPSh 41 w/ Drum Magazine
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_SMG/Type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}

	}
	("magazine" cut(1.20) show(2.15) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon ppsh41_stick"				;// props added to PPSh 41 w/ Stick Magazine 
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_SMG/Type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/PPSh41/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/PPSh41/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}

{"stuff weapon pps43"						;// props added to PPS 43
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_SMG/Type2/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/RUS/PPS43/"}
		{link_sound "far"		"weapon/shot/smallarms/s1/d3/RUS/PPS43/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon ptrd"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/AT_Rifle/bolt_action/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/RUS/PTR/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/RUS/PTR/"}
	}
	{on "weapon_reload" overload
		{delay 3.2
			{ani_play "reload"}
		}
	}
}
{"stuff weapon ptrs"
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/AT_Rifle/semi_auto/"}
		{link_sound "mid"		"weapon/shot/smallarms/s4/d2/RUS/PTR/"}
		{link_sound "far"		"weapon/shot/smallarms/s4/d3/RUS/PTR/"}
	}
	{on "weapon_reload" overload
		{delay 0.5
			{kill_delay "bolt_action"}
			{ani_play "reload"}
			{view hide "bullet"}
			{call "magazine_delay"}
		}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon svt"							;// props added to AVT 40, SVT 38, SVT 40, and SKT 40
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/closed_bolt/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/RUS/SVT40/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/RUS/SVT40/"}
	}
	("magazine" cut(1.75) show(2.1) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon tt33"						;// props added to TT 33
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/RUS/TT33/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/RUS/TT33/"}
	}
}
;/**=========== RUS WEAPONS END ===========**/
;/**=========== USA WEAPONS Begin ===========**/
{"stuff weapon browning_m2"					;// props added to Browning M2HB .50 Cal
	("magazine" cut(0.1) show(5.85) override(overload) impulse({impulse up -0.01 com}))
}
{"stuff weapon m12_shotgun"
	{on spawn	
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M12/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M12/"}
	}
}
{"stuff weapon browning_m19a4"				;// props added to Browning M1919A4 .30 Cal
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/open_bolt_MG/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1919A4/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1919A4/"}
	}
}
{"stuff weapon bar"							;// props added to M1918A2 BAR 
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/USA/M1918A2_BAR/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1918A2_BAR/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1918A2_BAR/"}
	}
	("magazine" cut(1.05) show(2.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon garand"						;// props added to M1 Garand
	{on spawn
		{add_view "shell_rifle_M1_Garand"	"shell"		"FXshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/USA/M1_Garand/"}
		{link_sound "mid"		"weapon/shot/smallarms/s3/d2/USA/M1_Garand/"}
		{link_sound "far"		"weapon/shot/smallarms/s3/d3/USA/M1_Garand/"}
		{link_sound "eject_clip"	"weapon/reload/M1_Garand/clip_eject/"}
	}
	("magazine" cut(0.1) show(2.9) override(overload) impulse({impulse up 2}))
}
{"stuff weapon garand_grenade_launcher"		;// props added to M1 Garand w/ M7 Grenade Launcher
	{on spawn
		{add_view "shell_rifle_M1_Garand"	"shell"		"FXshell"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/USA/M1_Garand/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1_Garand/M7_Grenade_Launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1_Garand/M7_Grenade_Launcher/"}
	}
}
{"stuff weapon hdm"
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/USA/M1911A1/"}
		{link_sound "mid"		"weapon/shot/smallarms/s1/d2/Shared/Surpressed_Pistol/"}
	}
}
{"stuff weapon m3_grease"					;// props added to M3 Grease Gun
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/USA/M3_GreaseGun/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/USA/M3_GreaseGun/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/USA/M3_GreaseGun/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson"					;// props added to All Thompson Variants
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/USA/M1A1_Thompson/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/USA/M1A1_Thompson/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/USA/M1A1_Thompson/"}
	}
	("magazine" cut(0.75) show(1.6) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon thompson_drum"				;// props added to Thompson with drum
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/USA/M1A1_Thompson/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/USA/M1A1_Thompson/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/USA/M1A1_Thompson/"}
	}
	("magazine" cut(1.05) show(2.15) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine"					;// props added to M1 and M1A1 Carbines
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/USA/M1_Carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/USA/M1_Carbine/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/USA/M1_Carbine/"}
	}
	("magazine" cut(1.05) show(1.95) override(overload) impulse({impulse up -0.01}))
}
{"stuff weapon m1_carbine_grenade_launcher"	;// props added to M1 Carbine w/ M8 Grenade Launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/USA/M1_Carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/USA/M1_Carbine/M8_Grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/USA/M1_Carbine/M8_Grenade_launcher/"}
	}
}
{"stuff weapon m1a1_carbine_grenade_launcher"	;// props added to M1A1 Carbine w/ M8 Grenade Launcher
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s2/recoil/USA/M1_Carbine/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/USA/M1_Carbine/M8_Grenade_launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/USA/M1_Carbine/M8_Grenade_launcher/"}
	}
}
{"stuff weapon m1903"						;// props added to M1903A3 & M1903A4
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M1903A3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M1903A3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/USA/M1903A3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1903A3/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1903A3/"}
	}
}
{"stuff weapon m1903_grenade_launcher"		;// props added to M1903A3 w/ M1 Grenade Launcher
	{on spawn
		{link_sound "open_bolt"		"weapon/reload/open_bolt/M1903A3/"}
		{link_sound "close_bolt"	"weapon/reload/close_bolt/M1903A3/"}
		{link_sound "action_recoil"	"weapon/shot/smallarms/s3/recoil/USA/M1903A3/"}
		{link_sound "mid"			"weapon/shot/smallarms/s3/d2/USA/M1903A3/M1_Grenade_Launcher/"}
		{link_sound "far"			"weapon/shot/smallarms/s3/d3/USA/M1903A3/M1_Grenade_Launcher/"}
	}
}
{"stuff weapon m1911"						;// props added to M1911A1
	{on spawn
		{link_sound "action_recoil"	"weapon/shot/smallarms/s1/recoil/USA/M1911A1/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/USA/M1911A1/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/USA/M1911A1/"}
	}
}
{"stuff weapon recoilless_m18"
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/Shared/Rocket_Launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/Shared/Rocket_Launcher/"}
	}
}
;/**=========== USA WEAPONS END ===========**/
;/*=========== SPECIFIC WEAPONS END ===========*/
;/*=========== SHARED WEAPONS BEGIN ===========*/
{"stuff weapon hipower_1935"				;// props added to FN Browning Hi-Power P35
	{on spawn
		{link_sound "action_recoil"	"weapon/action/recoil/pistol/"}
		{link_sound "mid"			"weapon/shot/smallarms/s1/d2/Shared/FN_Browning_HiPower_P35/"}
		{link_sound "far"			"weapon/shot/smallarms/s1/d3/Shared/FN_Browning_HiPower_P35/"}
	}
}
{"stuff weapon rocket_launcher"				;// props added to all Shoulder Fired Rocket Launchers
	{on spawn
		{link_sound "mid"			"weapon/shot/reactive/d2/Shared/Rocket_Launcher/"}
		{link_sound "far"			"weapon/shot/reactive/d3/Shared/Rocket_Launcher/"}
	}
}
{"stuff weapon shotgun"						;// props added to
	{on spawn
		{link_sound "action_recoil"		"weapon/action/recoil/bolt_action/"}
		{link_sound "mid"			"weapon/shot/smallarms/s2/d2/Shared/Shotgun/"}
		{link_sound "far"			"weapon/shot/smallarms/s2/d3/Shared/Shotgun/"}
	}
}
;/***=========== SHARED WEAPONS END ===========***/