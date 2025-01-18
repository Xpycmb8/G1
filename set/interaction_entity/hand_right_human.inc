	{on fire "hand_right"
		{kill_delay "fire_hold"}
		(define "signal_shoot_emitters"
			{if effector "stuff weapon %stuff"
				{if tagged "interior"				
					{start_sound "shoot_emitters_int/%sound"}
					{signal shot %signal_interior }
					{tags add "%signal_interior"}
				else 
					{start_sound "shoot_emitters_ext/%sound"}
					{signal shot %signal_exterior }				
				}
			}
		)		
		("signal_shoot_emitters" stuff(heavy_shoot) 					signal_interior(2500) signal_exterior(1750)  sound(heavy) 					)
		("signal_shoot_emitters" stuff(rocketlauncher) 					signal_interior(2500) signal_exterior(1750)  sound(rocketlauncher)			)
		("signal_shoot_emitters" stuff(assaultrifle_silenced_set) 		signal_interior(250)  signal_exterior(150)   sound(assaultrifle_silenced)	)
		("signal_shoot_emitters" stuff(assaultrifle_set) 				signal_interior(600)  signal_exterior(450)   sound(assaultrifle)			)		
		("signal_shoot_emitters" stuff(pistol_silenced_set) 			signal_interior(15)   signal_exterior(5)  	 sound(pistol_silenced)			)
		("signal_shoot_emitters" stuff(pistol_set) 						signal_interior(150)  signal_exterior(100)   sound(pistol)					)
		("signal_shoot_emitters" stuff(shotgun_silenced_set) 			signal_interior(150)  signal_exterior(75)    sound(shotgun_silenced)		)
		("signal_shoot_emitters" stuff(shotgun_set) 					signal_interior(1000) signal_exterior(500)   sound(shotgun)					)
		("signal_shoot_emitters" stuff(shortsmg_silenced_set) 			signal_interior(50)   signal_exterior(25)    sound(pistol_silenced)			)
		("signal_shoot_emitters" stuff(shortsmg_set) 					signal_interior(200)  signal_exterior(125)   sound(pistol)					)		
		("signal_shoot_emitters" stuff(sniper_silenced_set) 			signal_interior(75)   signal_exterior(25)    sound(sniper_silenced)			)	
		("signal_shoot_emitters" stuff(sniper_set) 						signal_interior(300)  signal_exterior(150)   sound(sniper)					)	
		("signal_shoot_emitters" stuff(rifle_silenced_set) 				signal_interior(75)   signal_exterior(35)    sound(rifle_silenced)			)
		("signal_shoot_emitters" stuff(rifle_set) 						signal_interior(900)  signal_exterior(60)    sound(rifle)					)
		("signal_shoot_emitters" stuff(at_rifle_silenced_set) 			signal_interior(300)  signal_exterior(150)   sound(heavy_silenced)			)	
		("signal_shoot_emitters" stuff(at_rifle_set) 					signal_interior(1200) signal_exterior(1000)  sound(heavy)					)			
		("signal_shoot_emitters" stuff(mgun_silenced_set) 				signal_interior(700)  signal_exterior(450)   sound(mgun_silenced)			)	
		("signal_shoot_emitters" stuff(mgun_set) 						signal_interior(1000) signal_exterior(600)   sound(mgun)					)		
		("signal_shoot_emitters" stuff(smg_silenced_set) 				signal_interior(50)   signal_exterior(35)    sound(pistol_silenced)			)	
		("signal_shoot_emitters" stuff(smg_set) 						signal_interior(250)  signal_exterior(150)   sound(pistol)					)	
		{call "stop_idle"}
		; (define "recoil"
			; {if not effector "manual"		
				; {if tagged "stop"
					; ; {if effector "stuff weapon assaultrifle"
						; ; {if not tagged "fire_move"				
							; ; {tags add "fire_move"}
							; ; {if tagged "squat"
								; ; {ani_play "squat_fire_gun" +0.13 resume}				
							; ; else "lying"
								; ; {ani_play "lie_fire_gun" +0.13 resume}				
							; ; else
								; ; {ani_play "stand_fire_rifle_up" +0.13 resume}				
							; ; }
						; ; }
						; ; {delay 0.1 "fire_hold"
							; ; {if tagged "squat"
								; ; {ani_play "squat_fire_gun" -0.2 resume}				
							; ; else "lying"
								; ; {ani_play "lie_fire_gun" -0.2 resume}				
							; ; else
								; ; {ani_play "stand_fire_rifle_up" -0.2 resume}				
							; ; }
						; ; }
					; ; }	
					; {if effector "stuff weapon pistol auto"
						; {if not tagged "fire_move"				
							; {tags add "fire_move"}
							; {if tagged "squat"
								; {ani_play "squat_fire_pistol" +0.01 resume}				
							; else "lying"
								; {ani_play "lie_fire_pistol" +0.01 resume}				
							; else
								; {ani_play "stand_fire_pistol" +0.01 resume}				
							; }
						; }
						; {delay 0.1 "fire_hold"
							; {if tagged "squat"
								; {ani_play "squat_fire_pistol" -0.1 resume}				
							; else "lying"
								; {ani_play "lie_fire_pistol" -0.1 resume}				
							; else
								; {ani_play "stand_fire_pistol" -0.1 resume}				
							; }
						; }
					; }	
					; {delay 0.1
						; {tags remove "fire_move"}
					; }
					; {if effector "stuff weapon %stuff"
						; {if tagged "squat"
							; {ani_play "%anim_squat" %speed }				
						; else "lying"
							; {ani_play "%anim_lying" %speed }				
						; else
							; {ani_play "%anim_stand" %speed  }				
						; }
					; }
				; }
			; }
		; )		
		; ("recoil" stuff(ash_series) 			anim_squat(squat_fire_gun) 			anim_lying(lie_fire_gun) 		anim_stand(stand_fire_rifle_up) speed(1))	
		; ;("recoil" stuff(assaultrifle) 			anim_squat(squat_fire_gun) 			anim_lying(lie_fire_gun) 		anim_stand(stand_fire_rifle_up) speed(+0.2  callback ))		
		; ("recoil" stuff(rifle) 					anim_squat(stand_fire_rifle_up) 	anim_lying(lie_fire_rifle) 		anim_stand(stand_fire_rifle_up) speed(1))	
		; ("recoil" stuff(mgun) 					anim_squat(squat_fire_mgun) 		anim_lying(lie_fire_mgun) 		anim_stand(stand_fire_rifle_up) speed(1))		
		; ("recoil" stuff(pistol semi) 			anim_squat(squat_fire_pistol) 		anim_lying(lie_fire_pistol) 	anim_stand(stand_fire_pistol) speed(1))		
		;	("recoil" stuff(pistol auto) 			anim_squat(squat_fire_pistol) 		anim_lying(lie_fire_pistol) 	anim_stand(stand_fire_pistol) speed(+0.2  callback ))		
		; ("recoil" stuff(rocketlauncher) 		anim_squat(squat_fire_bazooka) 		anim_lying(lie_fire_bazooka) 	anim_stand(stand_fire_bazooka) speed(1))	
		{if effector "stuff weapon rifle"
			{ani_play "move_human_recoil_ciri" 0.6   }
			{ani_play "move_human_recoil" 0.6   }
		else effector "stuff weapon pistol"
			{ani_play "move_human_recoil_ciri" 0.7   }
			{ani_play "move_human_recoil" 0.7 }
		else effector "stuff weapon mgun"
			{ani_play "move_human_recoil_ciri" 1   }
			{ani_play "move_human_recoil" 1   }
		else
			{ani_play "move_human_recoil_ciri" 1  }
			{ani_play "move_human_recoil" 1  }
		}
		{tags add "fire_hold"}
		{delay 3 "fire_hold"
			{tags remove "fire_hold"}
		}
		; {if effector "riflehand"					;edited from goh
			; {delay 0.5							;edited from goh
				; {call "bolt_anim"}				;edited from goh
			; }										;edited from goh
		; }											;edited from goh
		{if effector "shotgun manual"
			{if not tagged "reload"
				{with_effector 
					{delay 0.1
						{ani_play "charge" 1.2 }
					}
				}
				{delay 0.1
					;{if tagged "m37_link"
						{if tagged "squat"
							{ani_play "squat_charge_m37" 1.2 }
						}
						{if tagged "lying"
							{ani_play "lying_charge_m37" 1.2 }
						else tagged "stand"
							{ani_play "squat_charge_m37" 1.2 }
						}
					;}
				}
			}
		}
		{if effector "c4_clutch"
			 {with_effector 
				{tags add "c4_clutch"}
				{delay 0.5
					{tags remove "c4_clutch"}
				}
			 }
			; {if tagged "stop"
				; {if tagged "lying"
					; {ani_play "" 1}
				; else tagged "squat"
					; {ani_play "" 1}
					; {delay 0.25
						; {ani_play "" 1}
					; }
				; else not tagged "squat"
					; {ani_play "" 1}
				; }	
			; else
				; {ani_play "aim_hatched_walk1" 1}
			; }
			{start_sound "weapon/armed/с4"}
		}
		{if effector "hatchet_armed"
			{with_effector ;knife
				{delay 0
					{volumes "knife_armed" enable contact}
					{delay 0.5
						{volumes "knife_armed" disable contact}
					}
				}
			}
			{if tagged "stop"
				{if tagged "lying"
					{ani_play "aim_hatchet_lie" 1.5}
				else tagged "squat"
					{ani_play "squat_throw_small_begin" 2}
					{delay 0.25
						{ani_play "squat_throw_small_end" 2.4}
					}
				else not tagged "squat"
					{ani_play "aim_hatched" 1.5}
				}	
			else
				{if rand 0.4
					{ani_play "aim_hatched_walk1" 1}
				else rand 0.3
					{ani_play "aim_hatched_walk2" 1}
				else 
					{ani_play "aim_hatched_walk3" 1}
				}
			}
			{start_sound "executions/knife/"}
		else effector "knife_armed"
			{with_effector ;knife
				{delay 0
					{volumes "knife_armed" enable contact}
					{delay 0.2
						{volumes "knife_armed" disable contact}
					}
				}
			}
			{if tagged "stop"
				{if not tagged "lying"
					{ani_play "aim_knife" 1.5}
				else 
					{ani_play "aim_knife_lie" 1.5}
				}	
			else
				{ani_play "aim_knife_walk" 1.5}
			}
			{start_sound "executions/knife/"}
		}
		{if effector "knife"
			{start_sound "executions/knife/"}
		}
		{if active
			(define "shell_eject"
				{if effector "stuff weapon %tag"
					{delay 0.05
						{start_sound "weapon/shell_eject/%shell/"}	
					}
				}
			)
			("shell_eject" tag(shell5)				shell(shell5))
			("shell_eject" tag(shell5_inv)			shell(shell5))
			("shell_eject" tag(shell308)			shell(shell308))
			("shell_eject" tag(shell7)				shell(shell7))
			("shell_eject" tag(shell7x51)			shell(shell7))
			("shell_eject" tag(shell9)				shell(shell9))
			("shell_eject" tag(shell9s1)			shell(shell9))
			("shell_eject" tag(shell11)				shell(shell11))
			("shell_eject" tag(shell12)				shell(shell12))
			("shell_eject" tag(shell127x99_inv)		shell(shell12))
			("shell_eject" tag(shell12_inv)			shell(shell12))
			("shell_eject" tag(xm109_series)		shell(shell12))
		}
		{if effector "stuff weapon masterkey"
			{if tagged "ready_shot"			
				(include "shoot_left_auto_3m.inc")
;				{if tagged "reset"
;					{weapon_work "hand_right" 0}
;					{delay 0.1
;						{weapon_work "hand_right" 1}
;					}			
;				}
				{if not tagged "empty_key"	
					{with_effector
						{call "fire_masterkey"}
					}
				else
					{tags remove "ready_shot"}
				}
			}				
		}
		{if effector "stuff weapon m203_launcher"
			{if tagged "ready_shot"			
				{tags remove "ready_shot"}
				{if tagged "ready_m203_fg"		
					{tags add "empty_m203"}
					{tags remove "ready_m203_fg"}
					{with_effector
						{spawn "startsmoke_40mm" "fx_m203" x}
						{spawn "m203_launch_fg" "spawn_m203" x}
						{bone hide "m203"}
						{bone show "m203_empty"}						
					}
					{weapon_work "hand_right" 0}
					{delay 0.1
						{weapon_work "hand_right" 1}
					}			
				}
				{if tagged "ready_m203_thermite"		
					{tags remove "ready_m203_thermite"}
					{tags add "empty_m203"}
					{with_effector
						{spawn "startsmoke_40mm" "fx_m203" x}
						{spawn "m203_launch_thermite" "spawn_m203" x}
						{bone hide "m203"}
					}
					{weapon_work "hand_right" 0}
					{delay 0.1
						{weapon_work "hand_right" 1}
					}			
				}
				{if tagged "ready_m203_flash"		
					{tags add "empty_m203"}
					{tags remove "ready_m203_flash"}
					{with_effector
						{spawn "startsmoke_40mm" "fx_m203" x}
						{spawn "m203_launch_flash" "spawn_m203" x}
						{bone hide "m203"}
						{bone show "m203_empty"}						
					}
					{weapon_work "hand_right" 0}
					{delay 0.1
						{weapon_work "hand_right" 1}
					}			
				}
			}
		}
		{if effector "stuff weapon autoshot"
			{if tagged "auto_fire"			
				(include "shoot_left_auto.inc")
				{if tagged "reset"
					;{able - 1}
					{weapon_work "hand_right" 0}
					{delay 0.06
						{weapon_work "hand_right" 1}
					}			
				}
			}
			{if tagged "auto_fire_3"			
				(include "shoot_left_auto_3.inc")
				{if tagged "reset"
					{weapon_work "hand_right" 0}
					{delay 0.1
						{weapon_work "hand_right" 1}
					}			
				}
			}
		}
		{if effector "stuff weapon counter"
			(include "shoot_left.inc")
			{with_effector
				(include "shoot_left.inc")
			}
		}
		{with_effector
			{if tagged "100_heat_stage"
				;{if rand 0.2
				;	{with_effector
				;		{call "broken_weapon"}
				;	}
				;}		
			}
;			(include "shoot_left.inc") ;lag
			{if "broken"
				{spawn "ex_air_sm" "foresight3" }
				{spawn "sparks01" "fxshell" x}
				{with_effector
					{call "broken_weapon"}
				}
			}
		}
		{if "lying"
			{with_effector
				{if not tagged "socket_lying"
					{tags add "socket_lying"}
					{ani_play "stock" 0.5 }
					{ani_play "socket" 0.5}
					{start_sound "weapon/stock/"}
					{tags remove "socket"}
					;{set "socket" 0}
					;{set "socket_lying" 1}
				}
			}
		else
			{with_effector
				{if tagged "socket_lying"
					{tags remove "socket_lying"}
					{ani_play "stock" -1 }
					{ani_play "socket" -1}
					{start_sound "weapon/stock/"}
					;{set "socket" 1}
					;{set "socket_lying" 0}
				}
			}
			{if effector "stuff weapon assaultrifle"
				{if not user_control
					{call "rand_jammed"}
				}
			else effector "stuff weapon crowbar"
				{if not user_control
					{if not tagged "fast" 
						{if not tagged "normal" 
							{ani_play "melee_attack_01" 1 }
						}
					}
				}
			else effector "stuff weapon smg"
				{if not user_control
					{call "rand_jammed"}
				}
			}
		}		
		{if not "talk"
			{kill_delay "talks"}
			{set "talk" 1}
			{delay 3 "talks"
				{set "talk" 0}
			}			
			{if effector "flashbang"
				{talk "throwing_a_grenade_flash"}
			else effector "smoke"
				{talk "throwing_a_grenade_smoke"}
			else effector "handgrenade"
				{talk "throwing_a_grenade_frag"}
				{if tagged "fast_hit"
					{if rand 0.5
						{with_effector
							{blastwave c4 0.4 r0 2 r1 2}	
							{stuff_detonate}
						}
					}
				}
			else effector "dynamite"
				{talk "throwing_a_grenade_frag"}
			else
				{if not active
					{if rand 0.4
						{talk "cries_in_battle"}
					}
				}
			}
		}
		{if effector "stuff weapon 60_bullet heater"
			{with_effector
				{if tagged "100_heat_stage" 
					{with_effector
						{weapon_work "hand_left" 0}
						{delay 10
							{weapon_work "hand_left" 1}
						}			
					}
				}				
				(include "shoot_left_heat.inc")
				{delay 15 "fire_hold"
					(include "reset_shoot_heat.inc")
				}
			}
		}
		{if effector "stuff weapon 30_bullet heater"
			{with_effector
				{if tagged "100_heat_stage" 
					{with_effector
						{weapon_work "hand_left" 0}
						{delay 10
							{weapon_work "hand_left" 1}
						}			
					}
				}				
				(include "shoot_left_heat.inc")
				{delay 15 "fire_hold"
					(include "reset_shoot_heat.inc")
				}
			}
		}
		{if effector "stuff weapon 20_bullet heater"
			{with_effector
				{if tagged "100_heat_stage" 
					{with_effector
						{weapon_work "hand_left" 0}
						{delay 10
							{weapon_work "hand_left" 1}
						}			
					}
				}				
				(include "shoot_left_heat.inc")
				{delay 15 "fire_hold"
					(include "reset_shoot_heat.inc")
				}
			}
		}
		{if effector "stuff weapon rocketlauncher"
			{if lying
				{if terrain_fx "sand"
					{spawn "dust_rpg_lie_sand" "basis" x}
				else
					{spawn "dust_rpg_lie" "fxshot" x}
				}
			}
			{if tagged "interior"
				{spawn "circledust_norm_rpg" "basis" }
			}		
		}		
		{if effector "stuff weapon sniper"
			{if lying
				{if terrain_fx "sand"
					{spawn "dust_rifle_lie_sand" "foresight3" x}
				else
					{spawn "dust_rifle_lie" "left_hand"}
				}
			}
		else effector "stuff weapon mgun"
			{if lying
				{if terrain_fx "sand"
					{spawn "dust_mgun_lie_sand" "left_hand"}
				else
					{spawn "dust_mgun_lie" "left_hand"}
				}
			}
		}
		{if effector "stuff weapon"
			{if not tagged "ready_shot"			
				{with_effector
					{call "fire"}
				}
			}
		}
	}