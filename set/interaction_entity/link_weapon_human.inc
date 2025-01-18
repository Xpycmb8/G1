	{on "link_weapon"
		{tags add "link_weapon"}
		{ani_play "link_human_weapon" 0.5 }
		{with_effector ;stuff
			;{set "link_weapon" 1}
			{tags add "link_weapon"}
			(include "reset_shoot_heat.inc")
			(include "reset_shoot.inc")
			(include "tags_add.inc")
		}
		(define "link_weapon"
			{if effector %0
				{tags add %0}
				{start_sound "executions/%1/"}
			}
		)		
		("link_weapon" args "pistol"	 		pistol)
		("link_weapon" args "smg"	 			smg)
		("link_weapon" args "mgun"	 			big)
		("link_weapon" args "rifle"	 			rifle)
		("link_weapon" args "sniper"	 		sniper)
		("link_weapon" args "rocketlauncher"	rpg)
		("link_weapon" args "knife"	 			knife)
		("link_weapon" args "grenade"	 		grenade)
		{if effector "stuff weapon m203_launcher"
			{if not tagged "first_shot"			
				{tags add "first_shot"}
				{tags add "ready_m203_fg"}
			}
		}
		{if effector "shotgun m37"
			{tags add "m37_link"}
			{if tagged "squat"
				{delay 0.7
					{ani_play "squat_link_m37" }
				}
			else tagged "lying"
				{delay 1
					{ani_play "lying_link_m37" }
				}
			else tagged "stand"
				{delay 1
					{ani_play "stand_link_m37" }
				}
			}
		}

		{if effector "stuff weapon pistol"
			{with_effector
				{delay 0.4
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/pistol_series/"}
				}
			}
		else effector "stuff weapon assaultrifle"
			{with_effector ;stuff
				{delay 0.5
					{call "link"}
				}
				{if tagged "first_load"	
					{with_effector ;human
						{delay 0.8
							{if not "blocked"							
								{if tagged "squat"
									{ani_play "squat_bolt_rifle_close" 1 }
								}
								{if tagged "lying"
									{ani_play "lie_bolt_rifle_close" 1 }
								else
									{ani_play "stand_bolt_rifle_close_up" 1 }
								}
							}
						}
						{with_effector ;stuff
							{tags remove "first_load"}
							{delay 0.8
								{start_sound "weapon/armed/aug_series/"}
								{ani_play "armed" 1}
								{ani_play "open_dust_cover" }
							}	
						}
					}
				}
			}
		else effector "stuff weapon aa12_series"
			{with_effector
				{delay 0.7
					{call "link"}
					{ani_play "armed" 0.8}
					{start_sound "weapon/armed/aa12_series/"}
				}
			}
		else effector "stuff weapon xm109_series"
			{with_effector ;stuff
				{delay 0.6
					{call "link"}
				}
				{if tagged "first_load"	
					{tags remove "first_load"}
					{with_effector ;human
						{delay 0.6
							{if tagged "squat"
								{ani_play "squat_bolt_rifle" 0.9 }
							}
							{if tagged "lying"
								{ani_play "lie_bolt_rifle" 0.9 }
							else
								{ani_play "stand_bolt_rifle_up" 0.9 }
							}
						}
						{with_effector ;stuff
							{tags remove "first_load"}
							{delay 0.7
								{ani_play "charge_load" 1}
							}	
						}
					}
				}
			}
		else effector "stuff weapon aa12_series"
			{with_effector
				{delay 0.7
					{call "link"}
					{ani_play "armed" 0.8}
					{start_sound "weapon/armed/aa12_series/"}
				}
			}

		else effector "stuff weapon aug_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/aug_series/"}
				}
			}
		else effector "stuff weapon aug_9mm_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/aug_9mm_series/"}
				}
			}
		else effector "stuff weapon ak_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/ak_series/"}
				}
			}
		else effector "stuff weapon galil_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/galil_series/"}
				}
			}
		else effector "stuff weapon m4a1_series"
			{with_effector
				{delay 1
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/m4a1_series/"}
				}
			}
		else effector "stuff weapon g36_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/g36_series/"}
				}
			}
		else effector "stuff weapon sig_series"
			{with_effector
				{delay 0.5
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/sig_series/"}
				}
			}
		else effector "stuff weapon pp_series"
			{with_effector
				{delay 0.4
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/pp_series/"}
				}
			}
		else effector "stuff weapon mp7_series"
			{with_effector
				{delay 0.4
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/mp7_series/"}
				}
			}
		else effector "stuff weapon mp5_series"
			{with_effector
				{delay 0.4
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/mp5_series/"}
				}
			}
		else effector "stuff weapon ump_series"
			{with_effector
				{delay 0.8
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/ump_series/"}
				}
			}
		else effector "stuff weapon smg_series"
			{with_effector
				{delay 1.2
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/smg_series/"}
				}
			}
		else effector "stuff weapon mg_series"
			{with_effector
				{delay 0.6
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/mg_series/"}
				}
			}
		else effector "stuff weapon mg36_series"
			{with_effector
				{delay 0.6
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/mg36_series/"}
				}
			}
		else effector "stuff weapon riflehand_auto"
			{with_effector ;stuff
				{delay 0.6
					{call "link"}
				}
				{if tagged "first_load"	
					{tags remove "first_load"}
					{with_effector ;human
						{delay 0.6
							{if tagged "squat"
								{ani_play "squat_bolt_rifle" 0.9 }
							}
							{if tagged "lying"
								{ani_play "lie_bolt_rifle" 0.9 }
							else
								{ani_play "stand_bolt_rifle_up" 0.9 }
							}
						}
						{with_effector ;stuff
							{tags remove "first_load"}
							{delay 0.7
								{ani_play "armed" 1}
							}	
						}
					}
				}
			}
		else effector "stuff weapon riflehand"
			{with_effector ;stuff
				{delay 0.6
					{call "link"}
				}
				{if tagged "first_load"	
					{tags remove "first_load"}
					{with_effector ;human
						{delay 0.6
							{if tagged "squat"
								{ani_play "squat_bolt_rifle" 0.9 }
							}
							{if tagged "lying"
								{ani_play "lie_bolt_rifle" 0.9 }
							else
								{ani_play "stand_bolt_rifle_up" 0.9 }
							}
						}
						{with_effector ;stuff
							{tags remove "first_load"}
							{delay 0.7
								{ani_play "charge_load" 1.7}
							}	
						}
					}
				}
			}
		else effector "stuff weapon sniper_series"
			{with_effector
				{delay 0.6
					{call "link"}
					{ani_play "armed" 1}
					{start_sound "weapon/armed/snrifle_series/"}
				}
			}
		else effector "stuff weapon"
			{if "lying"
				{with_effector
					{if not tagged "socket_lying"
						{tags add "socket_lying"}
						{ani_play "stock" 1 }
						{ani_play "socket" 1}
						{start_sound "weapon/stock/"}
						{tags remove "socket" }
						{delay 0.5		
							{ani_play "safe" 1}
						}
					}
				}
			else not "lying"
				{with_effector
					{if tagged "socket_lying"
						{tags remove "socket_lying"}
						{ani_play "stock" -1 }
						{ani_play "socket" -1}
						{start_sound "weapon/stock/"}
						{tags add "socket" }
						{delay 0.5		
							{ani_play "safe" 1}
						}
					}
				}
			}
			{with_effector
				{if "broken"
					{with_effector
						{view start ally neutral "marker_broken"}
						{delay 5
							{view stop "marker_broken"}
						}
					}
				}
				{ani_play "armed" 1}
				{delay 1
					{view show	"led_hold"}
					{view start	"led_hold"}
					{ani_play "cover" 1}
					{ani_play "on" 1}
				}
				{call "link"}
			}			
		}
	}
