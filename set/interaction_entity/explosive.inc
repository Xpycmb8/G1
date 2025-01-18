{"mine"
	{inflammation_time 3}
	{on spawn
		{volumes "body" disable all}
		{volumes "body1" disable all}
		; {add_view "mined_view_own"		"mined_own"		"mined_view"}
		; {add_view "diod_red"			"mined_own"		"fx_lamp"}
		; {add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		; {add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on "_explosion"
		{volumes "body1" disable blast}
		{volumes "body" disable blast}
		{stuff_detonate}
	}
	{on "explosion"
		{if mined
			{if rand 0.7
				{start_sound "interior/handgrenade"}
			}
			{call "_explosion"}
		}
	}
	{on "change_state"
		{if mined
			{start_sound "weapon/set"}
			{tags add "mine_planted"}
			{bone hide "folded"}
			{bone show "unfolded"}
			{volumes "body1" disable all}
			{volumes "body1" enable bullet}
			{volumes "body" enable select contact contact_ground blast}
		else
			{tags remove "mine_planted"}
			{bone show "folded"}
			{bone hide "unfolded"}
			{volumes "body" disable all}
			{volumes "body1" enable select touch contact contact_ground blast bullet}
		}
	}
}

{"claymore"
	{inflammation_time 5}
	{on spawn
		{volumes "detection" disable overlap select touch contact contact_ground blast bullet}
		; {add_view "mined_view_own"		"mined_own"		"mined_view"}
		; {add_view "diod_red"			"mined_own"		"fx_lamp"}
		; {add_view "mined_view_enemy"	"mined_enemy"	"mined_view"}
		; {add_view "mined_view_defused"	"defused"		"mined_view"}
		{call "change_state"}
	}
	{on overlap begin
		{if mined
			{call "explosion"}
		}
	}
	{on contact sync
		{if mine_effector "human"
			{call "explosion"}
		else mine_effector "vehicle"
			{call "explosion"}
		else mine_effector "animal"
			{call "explosion"}
		else mine_effector "baze_machinery"
			{call "explosion"}
		else mine_effector "stuff"
			{call "explosion"}
		}
	}
	{on "change_state" overload
		{if mined
			{ani_play "unfolded" 0.5}
			{delay 1
				{start_sound "weapon/set"}
				{tags add "mine_planted"}
				{volumes "body" enable all}
				{volumes "detection" enable overlap select contact contact_ground blast}
			}
		else
			{tags remove "mine_planted"}
			{volumes "detection" disable overlap select touch contact contact_ground blast bullet}
		}
	}
	{on "explosion"
		{if mined
			{start_sound "detonation/handgrenade_throw"}		
			{delay 0.3
				{call "_explosion"}
			}
		}
	}
	{on "_explosion"
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "fraction" "blast_fx" x {impulse rnd_dir 8 2 forward 20 10 com  }}
		{spawn "claymore_blast" "blast_fx" x}
		{volumes "detection" disable all}
		{stuff_detonate}
	}

	{on blast_hit
		{if min_energy 1.5
			{if not stuff "mine"
				{stuff_detonate}
			}
		}
	}
	{on bullet_hit
		{if not stuff "mine"
			{stuff_detonate}
		}
	}
}


{"radio_signal_activator"
	{on "switch"
		{if not tagged "radio_signal"
			{ani_play "move" 1}
			{start_sound "weapon/equip/"}
			{tags add "radio_signal"}
			{spawn "radio_signal" "dynamite_fuse"}
		else 
			{start_sound "weapon/equip/"}
			{tags remove "radio_signal"}
			{ani_play "move" -1}
		}
	}
}


{"dynamite"
	{on "undermine"
		{tags add "fuse dynamite_planted"}
		{add_view "flash_fuse_small" "fire" "fire"}
		{view start "fire"}
		{ani_play "fire" 0.06}
		{delay 1
			{explosive 1}
		}
		{volumes disable touch select}
	}
	{on contact
		{if tagged "fuse"
			{gravity 3}
		}
	}
	{on ground_hit
		{gravity 5}
	}
	{on "onThrow"
		{if stuff_activated
			{tags add "fuse"}
			{add_view "flash_fuse_small" "fire" "fire"}
			{view start "fire"}
			{ani_play "fire" 0.06}
			{volumes disable touch select}
		}
	}
	{on blast
		{if min_energy 0.25
			{stuff_detonate}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
}

{"c4_explosive_planted"
	{inflammation_time 10}
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
		{add_view "marker_c4plant" "marker1" "root" }
		{add_view "marker_set" "marker_set" "root" }	
		{add_view "diod_red3"	"light" "fx_lamp"}
		{add_view "diod_red3"	"light" "fx_light01"}
		{add_view "diod_red3"	"light1" "fx_light"}
		{tex_mod "hold"}
		{volumes "armed" disable contact touch select}
	}
	{on contact
		{if tagged "c4_planted"
			{gravity 3}
		}
	}
	{on ground_hit
		{gravity 5}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{call "_burn"}
		}
	}
	{on "_burn"
		{play_sound "small" 1}
		{burn volume fx "fire_magazine" time 20 fake even_law}
		{delay 5 
			{spawn "metal_crush"}
			{stuff_detonate}
		}
	}
	{on bullet_hit 
		{if stuff "bullet big"
			{if rand 0.1
				{spawn "metal_crush"}
				{stuff_detonate}
			}
		else stuff "bullet"			
			{if rand 0.05
				{spawn "metal_crush"}
				{stuff_detonate}
			}
		}
	}
	{on blast_hit 
		{if min_energy 1
			{stuff_detonate}
		}
	}
	{on "explosion"
		{stuff_detonate}
	}
	{on "remote_start_clutch"
		{delay 0.1
			{view pause "marker_set"}	
			{view start "marker1"}	
		}
		;{start_sound "weapon/special/c4_bomb"}
		{view start "light"}
		{tex_morph "armed" 0.2}
		{delay 0.1
			{view pause "light"}
			{tex_morph "hold" 0.4}
			{delay 0.3
				{call "explosion"}
			}
		}
	}
	{on "remote_start"
		{delay 0.5
			{view pause "marker_set"}	
			{view start "marker1"}	
		}
		{start_sound "weapon/special/c4_bomb"}
		{view start "light"}
		{tex_morph "armed" 0.2}
		{delay 1
			{view pause "light"}
			{tex_morph "hold" 0.4}
			{delay 2.5
				{call "explosion"}
			}
		}
	}
	{on "power"
		{bone show "led"}	
		{view start "light"}
		{view start "light1"}
		{tex_morph "armed" 1}
		{delay 0.01
			{view pause "light"}
			{tex_morph "hold" 1}
			{view pause "light1"}
			{bone hide "led"}	
		}
		{delay 0.9
			{view start "light"}
			{tex_morph "armed" 1}
			{bone show "led"}	
			{view start "light1"}
		}
		{delay 1.1
			{view pause "light1"}
			{tex_morph "hold" 1}
			{view pause "light"}
			{bone hide "led"}	
		}
		{delay_effect 2
			"power"
		}
	}
	{on "change_state"
		{start_sound "weapon/set"}
		{tags add "mine_planted"}
	}
	{on "undermine"
		{start_sound "weapon/armed/с4/detpack_button"}
		{delay 1.2
			{view start "marker_set"}	
		}
		{volumes "select" disable touch select}
		{volumes "body" disable touch select}
		{volumes "armed" enable  touch }	
		{call "pulse"}
		{call "change_state"}
	}
	{on "onThrow"
		{call "pulse"}
		{tags add "c4_planted"}
	}
}

{"c4"
	{on "undermine"
		{tags add "c4_planted"}
	}
	{on "onThrow"
		{tags add "c4_planted"}
	}
}

{"c4_explosive"
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
		{add_view "diod_red3"	"light" "fx_light01"}
		{add_view "diod_red3"	"light1" "fx_light"}
		{tex_mod "hold"}
	}
	{on contact
		{if tagged "c4_planted"
			{gravity 3}
		}
	}
	{on ground_hit
		{gravity 5}
	}
	{on blast
		{if min_energy 1
			{stuff_detonate}
		}
	}
	{inflammation_time 10}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{call "_burn"}
		}
	}
	{on "_burn"
		{play_sound "small" 1}
		{burn volume fx "fire_magazine" time 20 fake even_law}
		{delay 5 
			{spawn "metal_crush"}
			{stuff_detonate}
		}
	}
	{on "power"
		{bone show "led"}	
		{view start "light"}
		{view start "light1"}
		{tex_morph "armed" 1}
		{delay 0.01
			{view pause "light"}
			{tex_morph "hold" 1}
			{view pause "light1"}
			{bone hide "led"}	
		}
		{delay 0.9
			{view start "light"}
			{tex_morph "armed" 1}
			{bone show "led"}	
			{view start "light1"}
		}
		{delay 1.1
			{view pause "light1"}
			{tex_morph "hold" 1}
			{view pause "light"}
			{bone hide "led"}	
		}
		{delay_effect 2
			"power"
		}
	}
	{on "undermine"
		{call "power"}
		{tags add "c4_planted"}
	}
	{on "onThrow"
		{call "power"}
		{tags add "c4_planted"}
	}
}

{"explosion_spawn"
	{on spawn
		{stuff_detonate}
	}
}

{"air_bomb"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		;{gravity 14}
		{ani_play "start"}
		{delay 0.5
			{volumes enable contact}
		}
	}
	{on ground_hit sync
		{if min_speed 10
			{call "explosion"}
		}
	}
	{on contact sync
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"air_bomb_stuff"
	{on "explosion"
		{stuff_detonate}
	}
	{on break_armor
		{call "explosion"}
	}
	{on contact sync
		{if min_speed 8
			{call "explosion"}
		}
	}
}

{"artillery_explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{delay 0
			{start_sound "weapon/shot/artillery"}
			{delay 2
				{call "explosion"}
			}
		}
	}
}

{"artillery_explosion_flaer"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{spawn "smoke_red_small"}
		{spawn "smoke_red_norm"}
		{delay 10
			{delay 2
				;{set_radius 20
				{call "explosion"}
			}
			{start_sound "mission/artillery/"}
			{start_sound "weapon/shot/artillery"}
		}
	}
}

{"explosion"
	{on "explosion"
		{stuff_detonate}
	}
	{on spawn
		{call "explosion"}
	}
}
{"explosive_barrel_gas"
	{inflammation_time 6}
	{on spawn
		{set "exploded" 0}
		{link_sound "smoke" "detonation/grenade_smoke/grenade_smoke"}
	}
	{on bullet_hit
		{if stuff "pierce"
			{if stuff "hmgun"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				else stuff_filled "fuel" 195
					{impulse up 12 12 dir 1 1}
					{call "explosion2"}
				else stuff_filled "fuel" 70
					{if rand 0.5
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 5 2
							{stop_sound "smoke"}
							{call "explosion"}
						}
					}
				else stuff_filled "fuel" 20
					{if rand 0.5
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 5 2
							{stop_sound "smoke"}
							{call "explosion"}
						}
					}
				}
			else stuff "zenite"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				else stuff_filled "fuel" 195
					{impulse up 12 12 dir 1 1}
					{call "explosion2"}
				else stuff_filled "fuel" 70
					{if rand 0.8
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 2 1
							{stop_sound "smoke"}
							{call "explosion"}
						}
					}
				else stuff_filled "fuel" 20
					{if rand 0.6
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 5 2
							{stop_sound "smoke"}
							{call "explosion"}
						}
					}
				}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				else stuff_filled "fuel" 195
					{impulse up 12 12 dir 1 1}
					{call "explosion2"}
				else stuff_filled "fuel" 70
					{if rand 0.5
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 5 2
							{stop_sound "smoke"}
							{call "explosion"}
						}
					else rand 0.05
						{call "explosion"}
					}
				else stuff_filled "fuel" 20
					{if rand 0.1
						{tags add "last_shot"}
						{play_sound "smoke" 1}
						{burn fx "drops_water_small_short" fake}
						{delay 5 2
							{stop_sound "smoke"}
							{call "explosion"}
						}
					}
				}
			else stuff "shell"
				{call "explosion"}
			}
		}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 5
				{call "break"}
			}
		else effector "fraction"
			{if rand 0.1
				{play_sound "smoke" 1}
				{burn fx "drops_water_small_short" fake}
				{delay 5 2
					{call "explosion"}
					{stop_sound "smoke"}
				}
			else rand 0.1
				{call "explosion"}
			}
		}
	}
	{on blast_hit 
		{if min_energy 2.2
			{call "explosion"}
		}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not burned
			{set "burned" 1}
			{set "exploded" 1}
			{burn volume "body" fx "smoke_bush" time 20}
			{burn volume "body1" fx "smoke_bush" time 20 }
			{delay 3 2 "sound"
				{blastwave c4 0.4 r0 6 r1 6}	
				{fire radius 2 time 0.5 heating 1}
				{spawn "open_gas_l_fx" "basis"}	
				{burn volume "body1" fx "smoke_dead_wheel" time 20 }
			}
			{delay 6
				{fire radius 3 time 4 heating 5}
			}
			{delay 1 "break_delay" {call "break"}}
		}
	}
	{on "break"
		{if stuff_filled "fuel" 20
			{call "explosion"}
		else
			{stop_sound "burn" 1}
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{ani_play "damage" 1}
			{set "exploded" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{spawn "ex_air_norm4" offset 0 0 7}
			{spawn "car_die_particle" offset 0 0 7}
			{spawn "barrel_die" offset 0 0 7}			
			{blastwave c4 12 r0 2 r1 2 offset 0 0 3}
			{blastwave c4 2 r0 12 r1 12 offset 0 0 3}
			{add_view "smoke_barrel" "smoke" "root"}
			{delete}
			{spawn "fire_mark_2"}
		}
	}
	{on "explosion2"
		{if not "exploded"
			{ani_play "damage" 1}
			{set "exploded" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{spawn "ex_air_norm4" offset 0 0 7}
			{spawn "car_die_particle" offset 0 0 7}
			{spawn "ex_air_norm4" offset 0 0 7}
			{spawn "car_die_particle" offset 0 0 7}
			{spawn "barrel_die" offset 0 0 7}			
			{blastwave c4 18 r0 2 r1 2 offset 0 0 3}
			{blastwave c4 4 r0 12 r1 15 offset 0 0 3}
			{add_view "smoke_barrel" "smoke" "root"}
			{delete}
			{spawn "fire_mark_2"}
		}
	}
	{on ground_hit sync
		{if tagged "last_shot" 
			{call "explosion"}
		}
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}



{"explosive_barrel"
	{inflammation_time 12}
	{on spawn
		{set "exploded" 0}
	}
	{on bullet_hit
		{if stuff "shell"
			{if stuff_filled "fuel" 20
				{if not "fire"
					{set "fire" 1}
					{bullet_detonate}
					{blastwave c4 3 r0 2 r1 4}
					{fire radius 2 time 2 heating 6}
					{spawn "open_gas_m_fx" "basis" }	
					{call "explosion"}
				}
			}
		}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "fuel" 20
				{call "explosion"}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
		else name "blast"
			{call "break"}
		}
	}
	{on contact sync
		{if effector "fraction"
			{if effector_velocity 5
				{call "break"}
			}
		}
	}
	{on "burn"
		{if not burned
			{if stuff_filled "fuel" 20
				{call "burn_volume"}
			}
		}
	}
	{on "burn_volume"
		{if not burned
			{set "burned" 1}
			{if volume "body1"
				{burn volume "body" fx "smoke_bush" time 20}
				{burn volume "body1" fx "smoke_bush" time 20 }
				{delay 4 2 "sound"
					{impulse up 1 0.5 dir 2 1}
					{spawn "open_gas_l_fx" "oil_barrel"}	
					{spawn "open_gas_l_fx" "basis"}	
					{burn volume "body1" fx "smoke_barrel_small2" time 20 fake}
				}
				{delay 6
					{if rand 0.1
						{blastwave c4 0.4 r0 3 r1 3}	
						{blastwave c4 0.1 r0 6 r1 6}	
						{fire radius 3 time 1 heating 1}
						{spawn "open_gas_l_fx" "basis"}	
						{call "break"}
					}
					{fire radius 1 time 4 heating 5}
				}
				{delay 7 "break_delay" 
					{impulse up 3 2.5 dir 2 1}
					{call "break"}
				}
			}
		}
	}
	{on "break"
		{if stuff_filled "fuel" 20
			{call "explosion"}
		else
			{stop_sound "burn" 1}
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{volumes disable bullet blast contact}
			{delay 1
				{volumes enable contact}
			}
			{blastwave c4 5 r0 2 r1 4}
			{spawn "barrel_die" offset 0 0 7}
			{add_view "smoke_barrel" "smoke" "root"}
			{delete}
			{spawn "fire_mark_1"}
		}
	}
	{on ground_hit sync
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}


{"explosive_propane"
	{inflammation_time 3}
	{on spawn
		{set "exploded" 0}
		{link_sound "explosion" "detonation/explosion_medium/fuel/oxygen_Tank"}
		{link_sound "hit" "detonation/fireextinguisher/explosion_fireextinguisher"}
		{set "fire" 0}
	}
	{on bullet_hit
		{if stuff "pierce"
			{if stuff_filled "gas" 20
				{if not "fire"
					{set "fire" 1}
					{spawn "ex_propane" "fx_flamemain" }	
					{bullet_detonate}
					{blastwave c4 3 r0 2 r1 4}
					{fire radius 2 time 2 heating 6}
					{spawn "open_gas_m_fx" "fx_flamemain" }	
					{spawn "propane_blast" "fx_blast" }	
					{call "explosion"}
					{delete}
				}
			}
		}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "gas" 20
				{if rand 0.7
					{if not "fire"
						{set "fire" 1}
						{spawn "ex_propane" "fx_flamemain" }	
						{bullet_detonate}
						{blastwave c4 3 r0 2 r1 4}
						{fire radius 2 time 2 heating 6}
						{spawn "open_gas_m_fx" "fx_flamemain" }	
						{spawn "propane_blast" "fx_blast" }	
						{delete}
						{call "explosion"}
					}
				else rand 0.4
					{if not "fire"
						{ani_play "damage" 1}
						{set "fire" 1}
						{play_sound "hit" 1}
						{spawn "open_gas_small" "fx_flamemain" }	
						{if rand 0.01
							{stop_sound "explosion" 1}
							{bullet_detonate}
							{call "explosion"}
						else
							{burn fx "extingusher_hit" time 4}				
						}				
						{delay 1.5 "open_gas_m"						
							{spawn "open_gas_medium" "fx_flamemain" }	
						}
						{delay 2.5 "open_gas_l"
							{spawn "open_gas_large" "fx_flamemain" }	
						}
						{delay 4.5 "sounds"
							{stop_sound "hit" 1}
						}
					}
				else rand 0.3
					{if not "fire"
						{ani_play "damage" 1}
						{set "fire" 1}
						{play_sound "explosion" 1}
						{burn fx "oxygen_fire" time 10}
						{delay 10 {stop_sound "explosion" 1}}
						{impulse up 1 fx 125}
						{delay 0.3 {impulse up 1 fx 85}}
						{delay 0.7 {impulse up 1 fx 85}}
						{if rand 0.7
							{delay 1.2 {impulse up 2 fy 125}}
						}
						{if rand 0.1
							{stop_sound "explosion" 1}
							{call "explosion"}
						}
					}
				}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{call "break"}
			}
	else name "blast"
			{call "break"}
		}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 5
				{call "explosion"}
			}
		else effector "fraction"
			{call "explosion"}
		}
	}
	{on "burn"
		{tex_morph "b" 5}
		{call "break"}
	}
	{on "burn_volume"
		{if volume "body"
			{tex_morph "b" 5}
		}
	}
	{on blast_hit 
		{if "fire"
			{tex_morph "b" 1}
		}
	}
	{on "break"
		{if stuff_filled "gas" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{if not "fire"
				{set "exploded" 1}
				{blastwave c4 5 r0 2 r1 4}
				{fire radius 2 time 2 heating 6}
				{volumes disable bullet blast contact}
				{delay 1
					{volumes enable contact}
				}
				{delay 3 1
					{blastwave c4 5 r0 2 r1 4}
					{spawn "barrel_die" offset 0 0 7}
					{add_view "smoke_barrel" "smoke" "root"}
					{delete}
					{spawn "fire_mark_1"}
				}
			}
		}
	}
	{on ground_hit sync
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}


{"blasted_barrel"
	{inflammation_time 3}
	{on spawn
		{set "exploded" 0}
		{link_sound "explosion" "detonation/explosion_medium/fuel/oxygen_Tank"}
		{link_sound "hit" "detonation/fireextinguisher/explosion_fireextinguisher"}
		{set "fire" 0}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "gas" 20
				{if rand 0.7
					{if not "fire"
						{spawn "open_gas_m_fx" "basis" }	
						{spawn "metal_hit_br_small_semtex" }	
						{spawn "oil_drum_sharp" "basis" }	
						{call "explosion"}
					}
				else rand 0.3
					{if not "fire"
						{play_sound "explosion" 1}
						{burn fx "oxygen_fire" time 10}
						{impulse up 1 fx 35}
						{delay 4 2
							{spawn "oil_drum_sharp" "basis" }	
							{call "explosion"}
							{stop_sound "explosion" 1}
						}
						{if rand 0.1
							{spawn "oil_drum_sharp" "basis" }	
							{stop_sound "explosion" 1}
							{call "explosion"}
						}
					}
				}
			else stuff "zenite"
				{if stuff_filled "gas" 20
					{if not "fire"
						{spawn "open_gas_m_fx" "basis" }	
						{spawn "metal_hit_br_small_semtex" }	
						{spawn "oil_drum_sharp" "basis" }	
						{call "explosion"}
					}
				}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			else stuff "shell"
				{if stuff_filled "gas" 20
					{if not "fire"
						{spawn "oil_drum_sharp_blast" "basis" }	
						{stop_sound "explosion" 1}
						{call "explosion"}
						{delete}
					}
				}
			}
	else name "blast"
			{spawn "oil_drum_sharp_blast" "basis" }	
			{stop_sound "explosion" 1}
			{call "explosion"}
		}
	}
	{on contact 
		{if effector "vehicle"
			{if effector_velocity 10
				{spawn "oil_drum_sharp" "basis" }	
				{call "explosion"}
			}
		else effector "knife"
			{if rand 0.04
				{if not "fire"
					{play_sound "explosion" 1}
					{burn fx "oxygen_fire" time 10}
					{delay 7 5
						{spawn "oil_drum_sharp" "basis" }	
						{call "explosion"}
						{stop_sound "explosion" 1}
					}
				}
			}
		else effector "fraction"
			{spawn "oil_drum_sharp" "basis" }	
			{call "explosion"}
		}
	}
	{on "burn_volume"
		{if volume "body"
			{delay 2 1
				{tex_morph "b" 1}
				{burn volume "body" fx "smoke_bush" time 20}
				{burn volume "body1" fx "smoke_bush" time 20 }
				{tex_morph "b" 5}
				{delay 5 3
					{burn volume "body" fx "smoke_dead_wheel" time 3}
					{burn volume "body1" fx "smoke_dead_wheel" time 3 }
					{delay 1
						{spawn "oil_drum_sharp" "basis" }	
						{call "explosion"}
						{stop_sound "explosion" 1}
					}
				}
			}
		}
	}
	{on blast_hit 
		{if not "exploded"
			{if not "fire"
				{spawn "open_gas_m_fx" "basis" }	
				{spawn "metal_hit_br_small_semtex" }	
				{spawn "oil_drum_sharp_blast" "basis" }	
				{blastwave c4 5 r0 5 r1 5}
				{blastwave c4 1 r0 8 r1 8}
				{spawn "ex_air_norm" }	
				{fire radius 10 time 3 heating 25}
				{fire radius 2 time 0.5 heating 30}
				{volumes disable bullet blast contact}
				{spawn "fire_mark_1"}
				{set "fire" 1}
				{set "exploded" 1}
				{delete}
			}
		}
		{if "fire"
			{tex_morph "b" 1}
		}
	}
	{on "break"
		{if stuff_filled "gas" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{if not "fire"
				{blastwave c4 5 r0 5 r1 5}
				{blastwave c4 1 r0 8 r1 8}
				{spawn "ex_air_norm" }	
				{fire radius 2 time 2 heating 6}
				{volumes disable bullet blast contact}
				{spawn "fire_mark_1"}
				{set "fire" 1}
				{set "exploded" 1}
				{delete}
			}
		}
	}
	{on ground_hit sync
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}

{"explosive_oxygen"
	{inflammation_time 3}
	{on spawn
		{set "exploded" 0}
		{link_sound "explosion" "detonation/explosion_medium/fuel/oxygen_Tank"}
		{link_sound "hit" "detonation/fireextinguisher/explosion_fireextinguisher"}
		{set "fire" 0}
	}
	{on bullet_hit
		{if stuff "shell"
			{if stuff_filled "fuel" 20
				{if not "fire"
					{set "fire" 1}
					{bullet_detonate}
					{blastwave c4 3 r0 2 r1 4}
					{fire radius 2 time 2 heating 6}
					{spawn "open_gas_m_fx" }	
					{spawn "barrel_die" offset 0 0 4}
					{add_view "smoke_barrel" "smoke" "root"}
					{spawn "fx_piece_fire" offset 0 0 4}
					{spawn "fx_piece_fire" offset 0 0 4}
					{spawn "fx_piece_fire" offset 0 0 4}
					{spawn "fx_piece_fire" offset 0 0 4}
					{spawn "fire_mark_1"}
					{delete}
				}
			}
		}
	}
	{on break_armor
		{if name "pierce"
			{if stuff_filled "fuel" 20
				{if rand 0.2
					{if not "fire"
						{ani_play "damage" 1}
						{set "fire" 1}
						{play_sound "hit" 1}
						{spawn "open_gas_small" "fx_flamemain" }	
						{if rand 0.01
							{stop_sound "explosion" 1}
							{bullet_detonate}
							{call "explosion"}
						else
							{burn fx "extingusher_hit" time 4}				
						}				
						{delay 1.5 "open_gas_m"						
							{spawn "open_gas_medium" "fx_flamemain" }	
						}
						{delay 2.5 "open_gas_l"
							{spawn "open_gas_large" "fx_flamemain" }	
						}
						{delay 4.5 "sounds"
							{stop_sound "hit" 1}
						}
					}
				else rand 0.2
					{if not "fire"
						{ani_play "damage" 1}
						{set "fire" 1}
						{play_sound "explosion" 1}
						{burn fx "oxygen_fire" time 10}
						{delay 10 {stop_sound "explosion" 1}}
						{impulse up 1 fx 125}
						{delay 0.3 {impulse up 1 fx 85}}
						{delay 0.7 {impulse up 1 fx 85}}
						{if rand 0.7
							{delay 1.2 {impulse up 2 fy 125}}
						}
						{if rand 0.1
							{stop_sound "explosion" 1}
							{call "explosion"}
						}
					}
				}
			else stuff "bullet"
				{if stuff_filled "water" 20
					{burn fx "drops_water_small_short" fake}
				}
			}
	else name "blast"
			{call "break"}
		}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 5
				{call "explosion"}
			}
		else effector "fraction"
			{call "explosion"}
		}
	}
	{on "burn"
		{tex_morph "b" 5}
		{call "break"}
	}
	{on "burn_volume"
		{if volume "body"
			{tex_morph "b" 5}
		}
	}
	{on blast_hit 
		{if "fire"
			{tex_morph "b" 1}
		}
	}
	{on "break"
		{if stuff_filled "fuel" 20
			{call "explosion"}
		else
			{spawn "car_die_particle"}
			{volumes disable bullet blast contact}
			{hide 0.3}
		}
	}
	{on "explosion"
		{if not "exploded"
			{if not "fire"
				{set "exploded" 1}
				{blastwave c4 5 r0 2 r1 4}
				{fire radius 2 time 2 heating 6}
				{volumes disable bullet blast contact}
				{delay 1
					{volumes enable contact}
				}
				{delay 3 1
					{blastwave c4 5 r0 2 r1 4}
					{spawn "barrel_die" offset 0 0 7}
					{add_view "smoke_barrel" "smoke" "root"}
					{delete}
					{spawn "fire_mark_1"}
				}
			}
		}
	}
	{on ground_hit sync
		{if "exploded"
			{blastwave c4 2 r0 4 r1 6}
			{spawn "barrel_die" offset 0 0 7}
			{delete}
		}
	}
}





{"flameable"
	{inflammation_time 3}
	{on spawn
		{add_view "oxygen_fire_end" "oxygen_fire_b3"		"fx_flamemain"}
		{add_view "oxygen_fire_small" "oxygen_fire_b2"		"fx_flamemain"}
		{add_view "batt_fire" "oxygen_fire_b"		"fx_flamemain"}		
		{add_view "fire_ground_set" "fx_flame00"		"fx_flame00"}
		{add_view "fire_ground_set" "fx_flame01"		"fx_flame01"}
		{add_view "fire_ground_set" "fx_flame02"		"fx_flame02"}
		{add_view "open_gas_start" "open_gas_start"		"fx_flamemain"}
		{add_view "open_gas_work" "open_gas_work"		"fx_flamemain"}
		{set "exploded" 0}
		{link_sound "match" "fire/small_stuff/fire_small"}
		{link_sound "explosion" "detonation/explosion_medium/fuel/oxygen_Tank"}
		{link_sound "loop" "detonation/explosion_medium/fuel/oxygen_Tank_long"}
		{link_sound "idle" "push/open_gas/open_gas_idle"}
		{link_sound "end" "push/open_gas/open_gas_end"}
		{link_sound "start" "push/open_gas/open_gas_start"}
		{set "fire" 0}
	}
	{on "open_gas"
		{if not "fire"
		{delay 1
			{start_sound "push/open_gas/pipe_out"}
			{set "fire" 1}
			;{spawn "open_gas_s" "fx_flamemain" }	
			{play_sound "start" 1}
			{view start "open_gas_start"}
			{delay 2
				{stop_sound "start" }
				{play_sound "idle" 1}
				{view stop "open_gas_start"}
				{view start "open_gas_work"}
				{spawn "open_gas_small" "fx_flamemain" }	
				{delay 5
					{spawn "open_gas_medium" "fx_flamemain" }	
					{delay 7
						{stop_sound "idle" }
						{play_sound "end" }
						{view stop "open_gas_work"}
						{spawn "open_gas_large" "fx_flamemain" }	
						{volumes "flame" disable all}
					}
				}
			}
		}
		}
	}
	{on "impulse"
		{impulse	up 0.4 dir 0.5 forward -2 cx 0 1 cy 0 1 fx 0 1 fy 0 1 fz 0 1 }
		{if rand 0.1
			{spawn "piece_wheel_fire" "fx_flame00" }
		else rand 0.1 
			{spawn "piece_wheel_fire" "fx_flame02" }
		}
		{delay_effect 0.3 "impulse"}
	}	
	{on "match"
		{if not "fire"
		{play_sound "match" 1}
		{start_sound "fire/small/Oil_Ignite_Low_01"}
		{burn volume "flame" fx "match" time 5 fake even_law}
		{delay 2
			{burn volume "flame" fx "smoke_aero_2_small" time 12 fake even_law}	
			{delay 7
				{set "fire" 1}
				{burn volume "flame" fx "smoke_aero_small" time 25 fake even_law}	
				{delay 5	
					{spawn "piece_wheel_fire" "fx_flame00" }
					{view start "fx_flame00"}
					{delay 6 1
						{spawn "piece_wheel_fire" "fx_flame01" }
						{view start "fx_flame01"}
						{delay 6 1
						{spawn "piece_wheel_fire" "fx_flame02" }
							{view start "fx_flame02"}
							{delay 9
								{spawn "ex_inc_small" "fx_flamemain"}		
								{ani_play "flame" loop}
								{play_sound "explosion" 1}
								{burn volume "flame" fx "smoke_aero_small" time 8 fake even_law}
								{view start "oxygen_fire_b"}
								{delay 6 1
									{start_sound "fire/small/Oil_Ignite_Low_02"}
									{view start "oxygen_fire_b2"}
									{delay 1
										{stop_sound "explosion" }
										{play_sound "loop" 1}
										{view stop "oxygen_fire_b"}
										{delay 5
											{set "exploded" 1}
											{view start "oxygen_fire_b3"}
											{start_sound "fire/biggest/"}
											{view stop "fx_flame00"}
											{view stop "fx_flame01"}
											{view stop "fx_flame02"}
											{if rand 0.7
												{burn volume "body" fx "smoke_aero_2_small" time 8 fake even_law}
												{call "impulse"} ;		{impulse up 0 dir 5 1 forward 12 5 com  fx 2}
												{delay 5
													{call "explosion"}
												}
											}
											{if rand 0.5
												{burn volume "flame" fx "smoke_aero_2_small" time 8 fake even_law}
												{start_sound "fire/detonation/"}
												{delay 3
													{call "explosion"}
												}
											}
											{delay 7
												{view start "oxygen_fire_b2"}
												{view stop "oxygen_fire_b3"}
												{delay 2
													{ani_stop "flame" }
													{view start "oxygen_fire_b"}
													{view stop "oxygen_fire_b2"}
													{delay 2
														{stop_sound "match" }
														{view stop "oxygen_fire_b"}
														{delay 1
															{stop_sound "loop" }
														}
													}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

{"balloon"
	{on break_armor
		{if name "pierce"
			{if rand 0.2
				{bullet_detonate}
				{if stuff_filled "fuel" 5
					{call "explosion"}
				}
			}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{spawn "flamer_die"}
			{spawn "fire_molot_ground"}
			{blastwave c4 10 r0 1 r1 1.5}
			{fire radius 6 time 2 heating 6}
			{delete}
		}
	}
}
{"set_extinguisher"
	{on spawn
		{set "exploded" 1}
		{impulse up 3 2 dir 1 0.5}
		{link_sound "explosion" "detonation/fireextinguisher/explosion_fireextinguisher"}
		{stop_sound "explosion" 1}
		{set "fire" 1}
	}
}

{"explosive_extinguisher"
	{on spawn
		{set "exploded" 0}
		{link_sound "explosion" "detonation/fireextinguisher/explosion_fireextinguisher"}
		{set "fire" 0}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 5
				{call "explosion"}
			}
		else effector "fraction" ;дробь
			{call "explosion"}
		}
	}
	{on pierce
		{if not "fire"
			{set "fire" 1}
			{play_sound "explosion" 1}
			{if rand 0.1
				{stop_sound "explosion" 1}
				{bullet_detonate}
				{call "explosion"}
			else
				{burn fx "extingusher_hit" time 4}				
			}				
			{delay 4.5 {stop_sound "explosion" 1}}
			{impulse up 1 fx 65}
			{delay 0.3 {impulse up 1 fx 25}}
			{delay 0.7 {impulse up 1 fx 25}}
			{if rand 0.7
				{delay 1.2 {impulse up 8 fy 125}}
			}
		}
	}
	{on blast_hit
		{if rand 0.2
			{impulse up 5 2 dir 1 0.5}
			{call "explosion"}
		}	
	}
	{on "explosion"
		{if not "exploded"
			{set "fire" 1}
			{set "exploded" 1}
			{if altitude 0.5
				{impulse up 0 dir -3 6 forward 6 2 com  fx -5 10}
			else altitude 0
				{impulse up 7 2.5 dir 1 0.5}
			}
			{if rand 0.2
				{blastwave c4 6 r0 1 r1 1.5}
				{impulse up 16 2.5 dir 1 0.5}
			}	
			{set_skeleton "_x" }
			{burn volume fx "smoke_white2" time 10 fake even_law}
			{spawn "ex_extinguisher"}
			{blastwave c4 3 r0 1 r1 1.5}
		}
	}
}





{"explosive_missile"
	{inflammation_time 3}
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
		{set "exploded" 0}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 12
				{call "explosion"}
			}
		else effector "fraction"
			{if rand 0.1
				{delay 2
					{call "explosion"}
				}
			else rand 0.1
				{call "explosion"}
			}
		}
	}
	{on pierce
		{if volume "explosive"
			{if rand 0.6
				{call "explosion"}
			}
		}
	}
	{on blast_hit
		{if min_energy 0.2
			{call "explosion"}
		}
	}
	{on "explosion_m"
		(define "terrain_fx"
			{if terrain_fx %0 
				{start_sound "expl_emitters/magazine/%1/"}	
			}
		)
		("terrain_fx" args "ground" 		ext 		 	)
		("terrain_fx" args "grass" 			ext 			 	)
		("terrain_fx" args "road" 			ext 		 	)
		("terrain_fx" args "country_road" 	ext 			 	)
		("terrain_fx" args "sand" 			ext 			 	)
		("terrain_fx" args "snow"  			ext 			 	)
		("terrain_fx" args "water" 			ext 			 	)
		("terrain_fx" args "bridge" 		ext 		   )
		("terrain_fx" args "bridge_wood" 	ext		   )
		("terrain_fx" args "floor" 			ext 			   )
		("terrain_fx" args "rock" 			ext 		   )
		("terrain_fx" args "metal" 			ext 			   )
		("terrain_fx" args "floor" 				imt 			 )
		("terrain_fx" args "shoot_emit_mtl" 				ext 			 )
		("terrain_fx" args "shoot_emit_ext_sand" 			ext 			 )
		("terrain_fx" args "shoot_emit_ext" 				ext 			 )
		("terrain_fx" args "shoot_emit_int" 				int 			 )
		("terrain_fx" args "shoot_emit_int_wood" 			int 			 )
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{call "_burn"}
		}
	}
	{on "_burn"
		{burn volume "explosive" fx "smoke_aero_4_small" time 12 }
		{delay 8 2 
			{if rand 0.4
				{spawn "thermite_hit" "cluster05" x}	
				{spawn "blast_phosphorus" "cluster05" x}	
			}
			{burn volume "explosive" fx "smoke_dead_small_cars" time 20 }
			{play_sound "small" 1}
			{delay 6
				{spawn "ex_air_norm7" "cluster01"}
				{call "slow_explosion"}
			}
			{delay 25
				{call "fast_explosion"}
			}
			{delay 35
				{call "explosion"}
			}
		}
	}
	{on "slow_explosion"
		{call "explosion_m"}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster01" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster02" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster03" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster04" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster05" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster06" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster07" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster08" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster09" }
		}
		{if rand 0.3
			{spawn "blast_phosphorus" "cluster04" }	
		}
		{if rand 0.3
			{spawn "blast_phosphorus" "cluster01" }	
		}
		{if rand 0.1
			{spawn "fraction_thermite" "cluster01" }	
		}
		{if rand 0.1
			{spawn "fraction_thermite" "cluster03" }	
		}
		{if rand 0.1
			{spawn "fraction_thermite" "cluster05" }	
		}
		{delay_effect 1.5 0.5 "fast_explosion"}
	}
	{on "fast_explosion"
		{call "explosion_m"}
		{if rand 0.4
			{spawn "fraction_thermite" "cluster01" }	
		}
		{if rand 0.4
			{spawn "fraction_thermite" "cluster03" }	
		}
		{if rand 0.4
			{spawn "fraction_thermite" "cluster05" }	
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster01" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster02" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster03" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster04" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster05" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster06" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster07" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster08" }
		}
		{if rand 0.3
			{spawn "ex_air_norm7" "cluster09" }
		}
		{if rand 0.3
			{spawn "blast_phosphorus" "cluster04" }	
		}
		{if rand 0.3
			{spawn "blast_phosphorus" "cluster01" }	
		}
		{delay_effect 0.4 0.2 "fast_explosion"}
	}
	{on "break"
		{call "explosion"}
	}
	{on "explosion"
		{if not "exploded"
			{tex_morph "burned" 1}
			{burn volume "explosive" fx "smoke_dead_small3" time 8 fake even_law}
			{fire volume "explosive" radius 1 heating 1  time 8 follow}
			{impulse up 2 1 dir 2 com  fx 2 cx 2 1 cy 2 1 rnd_dir 1}
			{start_sound "detonation/missile"}
			(define "cut_part"
				{spawn "metal_hit_atgm" %0}
				{spawn "propane_blast_rocket" %0}
				{tear "piece_big_steel_missile" bone %0
					{impulse up 12 4 dir 21 -50 com  fx 25 cx 12 2 cy 12 2 rnd_dir 1}					
				}
			)	
			("cut_part" args "cluster01"		0.9)
			("cut_part" args "cluster02"		0.9)
			("cut_part" args "cluster03"		0.9)
			("cut_part" args "cluster04"		0.9)
			("cut_part" args "cluster05"		0.9)
			("cut_part" args "cluster06"		0.9)
			("cut_part" args "cluster07"		0.9)
			("cut_part" args "cluster08"		0.9)
			("cut_part" args "cluster09"		0.9)
			{set "exploded" 1}
			{blastwave c4 1 r0 25 r1 25}	
			{blastwave c4 35 r0 8 r1 8}	
			{spawn "ex_fg_medium_art" }
			{delay 0.2
				{start_sound "detonation/missile"}
				{blastwave c4 3 r0 10 r1 10}	
				{spawn "ex_fg_medium_atgm" }	
			}
			{delay 0.5
				{blastwave c4 2 r0 50 r1 50}	
				{fire radius 6 time 5 heating 12}
				{spawn "fuel_sparks" offset 0 0 7}			
				{delete}
			}
		}
	}
}

{"explosive_stuff"
	{inflammation_time 7}
	{on break_armor
		{call "explosion"}
	}
	{on "burn"
		{call "explosion"}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
;			{con "explosion"}
			{stuff_detonate}
		}
	}
}

{"mine-jump"
	{on spawn
		{delay 0.1
			{add_view "grenade_tail" "engine_ex" "tail" }
			{view start "engine_ex"}
			{ani_play "explosion" 9}
			{start_sound "detonation/mine-jump"}
		}
		{delay 0.5
			{explosive 1}
		}
		{volumes disable touch select}
		{delay 0.7
			{call "explosion"}
		}
	}
	{on "explosion"
		{stuff_detonate}
			{spawn "ex_air_big" "tail" x}
			{delete}
	}
}









{"bomb_500"
	{inflammation_time 15}
	{on spawn
		{set "exploded" 0}
		;{link_sound "smoke" "//"}
	}
	{on pierce
		{if volume "explosive"
			{if stuff "hmgun"
				{if rand 0.5
					{call "explosion"}
				}
			else stuff "zenite"
				{if rand 0.6
					{call "explosion"}
				}
			else stuff "bullet"
				{if rand 0.5
					{call "explosion"}
				}
			else stuff "shell"
				{call "explosion"}
			}
		}
	}
	{on contact sync
		{if effector "vehicle"
			{if effector_velocity 5
				{call "explosion"}
			}
		else effector "fraction"
			{if rand 0.1
				{call "explosion"}
			}
		}
	}
	{on blast_hit 
		{if min_energy 3
			{call "explosion"}
		}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not burned
			{set "burned" 1}
			{set "exploded" 1}
			{if volume "body"
				{burn volume fx "smoke_hoods" time 5 fake even_law}
				{delay 3 2 
					{burn volume "body" fx "smoke_dead_wheel" time 5 }
					{delay 3
						{call "explosion"}
					}
				}
			}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{blastwave c4 500 r0 25 r1 25}	
			{spawn "distant_big_expl" offset 0 0 10}
			{spawn "ex_fg_500kg"}
			{spawn "cannon_add_mark_big"}
			{spawn "fraction_spawn_big" offset 0 0 10}
			{delay 0
				{blastwave c4 35 r0 80 r1 80 }	
				{delay 0
					{blastwave c4 7.5 r0 120 r1 120 }	
					{delete}
				}
			}
		}
	}
	{on ground_hit sync
		{if min_speed 15
			{call "explosion"}		
		}
	}
}









