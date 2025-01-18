{"small_tire"
	{inflammation_time 24}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on "fueled_stuff"
		{tags add "fueled_stuff"}
		{add_view "fuel_ground" "fuel_pierce" "root"}
		{delay 3
			{set "fire" 1}
			{view show	"fuel_pierce"}
			{view start	"fuel_pierce"}
		}
		{delay 8 4				
			{spawn "open_gas_small" "root" }
			{delay 20
				{view hide	"fuel_pierce"}
				{view pause	"fuel_pierce"}
			}
			{delay 35
				{set "fire" 0}
			}
		}
	}
	{on "match"
		{if rand 0.05
			{tags add "not_fuel"}
			{if not "fire"
				{delay 5 3
					{burn volume "body" fx "smoke_aero_2_small" time 20 fake even_law}	
					{delay 10 5
						{call "burn_volume"}
					}
				}
			}
		else
			{delay 0.8
				{tags add "fueled"}
				{spawn "open_gas_s" "basis"}	
				{delay 2
					{fire radius 0.5 time 12 heating 3}
					{burn volume "flame" fx "smoke_aero_2_small" time 12 fake even_law}	
				}
			}
		}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "fire_body"
		{if tagged "fire_body"
			{spawn "piece_wheel_fire_no_vol" random_position 1 }
			{delay_effect 1 "fire_body"}
		else
			{kill_delay "fire_body"}
		}
	}
	{on "burn_volume"
		{if not burned
			{if volume "tire"
				{set "burned" 1}
				{burn volume "body" fx "smoke_fire_tire" time 8 }
				{burn volume "body2" fx "smoke_fire_tire" time 8 }
				{burn volume "body3" fx "smoke_fire_tire" time 8 }
				{burn volume "body4" fx "smoke_fire_tire" time 8 }
				{burn volume "body5" fx "smoke_fire_tire" time 8 }
				{delay 6 3
					{tags add "fire_body"}
					{call "fire_body"}
					{start_sound "fire/small"}
					{link_sound 	"burn"			"fire/big/big_fire1"}
					{link_sound 	"small"			"fire/small_stuff/fire_small"}
					{burn volume fx "smoke_dead_wheel" time 165 }
					;{burn volume "body1" fx "smoke_dead_norm" time 160 }
					{fire radius 0.5 time 3 heating 0.5}

					{burn volume "body" fx "smoke_dead_wheel" time 130 }
					{burn volume "body2" fx "smoke_dead_wheel" time 130 }
					{burn volume "body3" fx "smoke_dead_wheel" time 50 }
					{burn volume "body4" fx "smoke_dead_wheel" time 50 }
					{burn volume "body5" fx "smoke_dead_wheel" time 50 }
					{fire volume "body" radius 2 time 120}
					{fire volume "body2" radius 2 time 120}
					{fire volume "tire" radius 2 time 80}
					{add_view "smoke_black_big2"	"fire_big"	"tire_pile"	}
					{delay 3 
						{view hide	"fuel_pierce"}
						{view pause	"fuel_pierce"}
						{tex_morph "_burned0" 25}
						{fire radius 1 time 30 heating 0.5}
						{if "big"
							{play_sound "burn" 1}
						else
							{play_sound "small" 1}					
						}
					}
					{delay 30
						{fire radius 1 time 30 heating 2}
						{view start "fire_big"}
						{delay 60
							{tags remove "fire_body"}
							{stop_sound "burn" }
							{stop_sound "small" }
							{view stop "fire_big"}
						}	
					}
					{burn time 160}
					{delay 120 "break_delay" {call "break"}}
				}
			}
		}
	}
}

{"tire"
	{inflammation_time 24}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		;{call "break"}
	}
	{on contact sync
		{if can_crush
			{call "break"}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "break"
		{call "disable_volumes"}
		{call "crush_fx"}
		{call "check_structure"}
		;{delay 0.2 {delete}}
	}
	{on "fueled_stuff"
		{tags add "fueled_stuff"}
		{add_view "fuel_ground" "fuel_pierce" "root"}
		{delay 3
			{set "fire" 1}
			{view show	"fuel_pierce"}
			{view start	"fuel_pierce"}
		}
		{delay 8 4				
			{spawn "open_gas_small" "root" }
			{delay 20
				{view hide	"fuel_pierce"}
				{view pause	"fuel_pierce"}
			}
			{delay 35
				{set "fire" 0}
			}
		}
	}
	{on "match"
		{if rand 0.05
			{tags add "not_fuel"}
			{if not "fire"
				{delay 5 3
					{burn volume "body" fx "smoke_aero_2_small" time 20 fake even_law}	
					{delay 10 5
						{call "burn_volume"}
					}
				}
			}
		else
			{delay 0.8
				{tags add "fueled"}
				{spawn "open_gas_s" "basis"}	
				{delay 2
					{fire radius 0.5 time 12 heating 3}
					{burn volume "flame" fx "smoke_aero_2_small" time 12 fake even_law}	
				}
			}
		}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not burned
			{if volume "tire"
				{start_sound "fire/small"}
				{set "burned" 1}
				{link_sound 	"burn"			"fire/big/big_fire1"}
				{link_sound 	"small"			"fire/small_stuff/fire_small"}
				{burn volume fx "smoke_dead_wheel" time 165 }
				;{burn volume "body1" fx "smoke_dead_norm" time 160 }
				{fire radius 0.5 time 3 heating 0.5}
				{burn volume "body2" fx "smoke_dead_tree1" time 130 }
				{burn volume "body3" fx "smoke_dead_wheel" time 50 }
				{burn volume "body4" fx "smoke_dead_tree1" time 50 }
				{burn volume "body5" fx "smoke_dead_tree1" time 50 }
				{fire volume "body2" radius 2 time 120}
				{fire volume "tire" radius 2 time 80}
				{add_view "smoke_black_big2"	"fire_big"	"tire_pile"	}
				{delay 3 "sound"
					{view hide	"fuel_pierce"}
					{view pause	"fuel_pierce"}
					{tex_morph "_burned0" 25}
					{fire radius 1 time 30 heating 0.5}
					{if "big"
						{play_sound "burn" 1}
					else
						{play_sound "small" 1}					
					}
				}
				{delay 30
					{fire radius 1 time 30 heating 2}
					{view start "fire_big"}
					{delay 60
						{stop_sound "burn" }
						{stop_sound "small" }
						{view stop "fire_big"}
					}	
				}
				{burn time 160}
				{delay 120 "break_delay" {call "break"}}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}

{"shed"
	{inflammation_time 4}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on pierce
		{if stuff "zenite"
			{if rand 0.2		
				{call "break"}
			}
		else stuff "zenite fg"
			{if rand 0.6		
				{call "break"}
			}
		else stuff "shell fg"
			{call "break"}
		else stuff "shell"
			{if rand 0.8		
				{call "break"}
			}
		else stuff "rocketlauncher"
			{if rand 0.4		
				{call "break"}
			}
		}
	}
	{on break_armor
		;{call "break"}
	}
	{on contact sync
		{if can_crush
			{call "break"}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "break"
		{call "disable_volumes"}
		{call "crush_fx"}
		{call "check_structure"}
		{delay 0.2 {delete}}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}

{"wood shed"
	{on "crush_fx"
		{spawn "wood_crush_big" "root"}
	}
}

{"wood shed small"
	{on "crush_fx" overload
		{spawn "wood_crush_small" "root"}
	}
}

{"concrete shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "stone_crush_big" "root"}
	}
}

{"steel shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_norm" "root"}
	}
}

{"misc shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_big" "root"}
	}
}

{"water_capacity shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "drops_water_big" "root"}
	}
}

{"shed cellar1"
	{on "crush_fx"
		{spawn "trash_1" "root"}
	}
}
