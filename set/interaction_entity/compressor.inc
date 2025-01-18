{"compressor"
	{on spawn
		{add_view "smoke_bats"			"fans00_broken" 	"engine00"}
		{add_view "smoke_bats"			"fans00_broken" 	"engine00"}
		{add_view "compressor_full"		"fx_smoke" 	"fx_smoke"}
		{link_sound "start"	"props/compressor/start" 	}
		{link_sound "work"	"props/compressor/work" 	}
		{link_sound "stop"	"props/compressor/stop" 	}	
		{set "stop" 1}
		{delay 5 2
			{call "start"}
		}
	}
	{on overlap begin
		{if effector "pressure"
			{if tagged "20bar"
				{with_effector
					{tags add "pressure"}
					{tags add "20bar"}
					{tags remove "15bar"}
					{call "pressure"}
				}
			}
			{if tagged "15bar"
				{with_effector
					{tags add "pressure"}
					{tags add "15bar"}
					{tags remove "20bar"}
					{call "pressure"}
				}
			}
		}		
	}
	{on "rand_stop"
		{if not "stop"
			{if rand 0.2	
				{delay 3 1
					{ani_stop "work"}
					{call "emit_bar"}
				}
			}
		}
	}
	{on pierce 
		{if volume "engine01"
			{if tagged "fans00_broken"
				{if tagged "sound"
					{stop_sound "work"}
					{play_sound "stop"}
					{tags remove "sound"}
				}			
			}
			{tags add "fans01_broken"}
			{if not tagged "pierce_engine01"
				{tags add "pierce_engine01"}
				{if not tagged "pierce_engine00"
					{if not "stop"
						{kill_delay "pressure_x2"}			
						{call "check_bar_work"}
					else
						{call "emit_bar"}
					}
				else
					{kill_delay "loop"}			
					{call "emit_bar_pierce"}
				}
				{ani_stop "fans01_work" }
				{ani_play "fans01_stop" 0.3}
				{spawn "plastic_hit_bul" "engine01" }	
				{view start "fans01_broken"}
				{delay 8 2
					{view stop "fans01_broken"}
				}
			}
		}
		{if volume "engine00"
			{if tagged "fans01_broken"
				{if tagged "sound"
					{stop_sound "work"}
					{play_sound "stop"}
					{tags remove "sound"}
				}			
			}
			{tags add "fans00_broken"}
			{if not tagged "pierce_engine00"
				{tags add "pierce_engine00"}
				{if not tagged "pierce_engine01"
					{if not "stop"
						{kill_delay "pressure_x2"}			
						{call "check_bar_work"}
					else
						{call "emit_bar"}
					}
				else
					{kill_delay "loop"}			
					{call "emit_bar_pierce"}
				}
				{ani_stop "fans00_work" }
				{ani_play "fans00_stop" 0.3}
				{spawn "plastic_hit_bul" "engine00" }	
				{view start "fans00_broken"}
				{delay 8 2
					{view stop "fans00_broken"}
				}
			}
		}
	}
	{on "hand_stop"
		{signal shot 800}
		{tags add "hand_stop"}
		{if not "stop"
			{if tagged "sound"
				{stop_sound "work"}
				{play_sound "stop"}
				{tags remove "sound"}
			}			
			{delay 1
				{view start "fx_smoke"}					
				{delay 3
					{view pause "fx_smoke"}					
				}
				{ani_stop "work"}
				{set "stop" 1}
				{call "emit_bar"}
				{if not tagged "fans00_broken"
					{ani_stop "fans00_work"}
					{if rand 0.5
						{ani_play "fans00_stop" 0.8}
					else
						{ani_play "fans00_stop" 0.4}
					}
				}
				{if not tagged "fans01_broken"
					{ani_stop "fans01_work"}
					{if rand 0.5
						{ani_play "fans01_stop" 0.8}
					else
						{ani_play "fans01_stop" 0.4}
					}
				}
			}
		}
	}
	{on "stop"
		{if not "stop"
			{if tagged "sound"
				{stop_sound "work"}
				{play_sound "stop"}
				{tags remove "sound"}
			}			
			{delay 2 1
				{delay 2 1
					{view start "fx_smoke"}					
					{delay 1
						{view pause "fx_smoke"}					
					}
				}
				{ani_stop "work"}
				{set "stop" 1}
				{call "emit_bar"}
				{if not tagged "fans00_broken"
					{ani_stop "fans00_work"}
					{if rand 0.5
						{ani_play "fans00_stop" 0.8}
					else
						{ani_play "fans00_stop" 0.4}
					}
				}
				{if not tagged "fans01_broken"
					{ani_stop "fans01_work"}
					{if rand 0.5
						{ani_play "fans01_stop" 0.8}
					else
						{ani_play "fans01_stop" 0.4}
					}
				}
			}
		}
	}
	{on "start"
		{if not tagged "hand_stop"
			{if "stop"
				{delay 0.2
					{if not tagged "broken"
						{if tagged "fans00_broken"
							{if not tagged "fans01_broken"
								{set "stop" 0}
								{if not tagged "sound"
									{play_sound "start"}
									{tags add "sound"}
									{delay 3.5 "sound"
										{play_sound "work" 1}
										{stop_sound "start"}
									}
								}
								{ani_play "work" loop}
								{ani_play "fans01_work" loop}
								{spawn "impact_ground2" "engine00" }	
								{view start	"fans00_broken"}
								{if rand 0.5
									{ani_play "fans00_stop" 0.3}
								}
								{delay 4 "bars"
									{view stop	"fans00_broken"}
									{call "start_bar_x1"}
								}
							}
						}
						{if tagged "fans01_broken"
							{if not tagged "fans00_broken"
								{set "stop" 0}
								{delay 0.1
									{if not tagged "sound"
										{play_sound "start"}
										{tags add "sound"}
										{delay 3.5 "sound"
											{play_sound "work" 1}
											{stop_sound "start"}
										}
									}
								}
								{ani_play "work" loop}
								{ani_play "fans00_work" loop}
								{spawn "impact_ground2" "engine01" }	
								{view start	"fans01_broken"}
								{if rand 0.5
									{ani_play "fans01_stop" 0.3}
								}
								{delay 4 "bars"
									{view stop	"fans00_broken"}
									{call "start_bar_x1"}
								}
							}
						}
					}
					{if not tagged "fans00_broken"
						{if not tagged "fans01_broken"
							{set "stop" 0}
							{if not tagged "sound"
								{play_sound "start"}
								{tags add "sound"}
								{delay 3.5 "sound"
									{play_sound "work" 1}
									{stop_sound "start"}
								}
							}
							{ani_play "work" loop}
							{ani_play "fans00_work" loop}
							{delay 1.3 "rand"
								{ani_play "fans01_work" loop}
							}
							{delay 2 "bars"
								{call "start_bar_x2"}
							}
						}
					}
				}
			}
		}
	}
	
	{on animation_event "0bar"	
		{tags remove "2bar"}
		{tags remove "1bar"}
		{tags add "0bar"}
	}
	{on animation_event "1bar"	
		{tags remove "0bar"}
		{tags remove "2bar"}
		{tags add "1bar"}
	}
	{on animation_event "2bar"	
		{tags remove "3bar"}
		{tags remove "1bar"}
		{tags add "2bar"}
	}
	{on animation_event "3bar"	
		{tags remove "4bar"}
		{tags remove "2bar"}
		{tags add "3bar"}
	}
	{on animation_event "4bar"	
		{tags remove "5bar"}
		{tags remove "3bar"}
		{tags add "4bar"}
	}
	{on animation_event "5bar"	
		{tags remove "4bar"}
		{tags remove "6bar"}
		{tags add "5bar"}
	}
	{on animation_event "6bar"	
		{tags remove "5bar"}
		{tags remove "7bar"}
		{tags add "6bar"}
	}
	{on animation_event "7bar"	
		{tags remove "6bar"}
		{tags remove "8bar"}
		{tags add "7bar"}
	}
	{on animation_event "8bar"	
		{tags remove "7bar"}
		{tags remove "9bar"}
		{tags add "8bar"}
	}
	{on animation_event "9bar"	
		{tags remove "8bar"}
		{tags remove "10bar"}
		{tags add "9bar"}
	}
	{on animation_event "10bar"	
		{tags remove "9bar"}
		{tags remove "11bar"}
		{tags add "10bar"}
	}
	{on animation_event "11bar"	
		{tags remove "10bar"}
		{tags remove "12bar"}
		{tags add "11bar"}
	}
	{on animation_event "12bar"	
		{tags remove "11bar"}
		{tags remove "13bar"}
		{tags add "12bar"}
	}
	{on animation_event "13bar"	
		{tags remove "12bar"}
		{tags remove "14bar"}
		{tags add "13bar"}
	}
	{on animation_event "14bar"	
		{tags remove "13bar"}
		{tags remove "15bar"}
		{tags add "14bar"}
	}
	{on animation_event "15bar"	
		{call "start"}
		{tags remove "14bar"}
		{tags remove "16bar"}
		{tags add "15bar"}
	}
	{on animation_event "16bar"	
		{if rand 0.6
			{call "start"}
		}
		{tags remove "15bar"}
		{tags remove "17bar"}
		{tags add "16bar"}
	}
	{on animation_event "17bar"
		{if rand 0.3
			{call "start"}
		}
		{tags remove "16bar"}
		{tags remove "18bar"}
		{tags add "17bar"}
	}
	{on animation_event "18bar"	
		{if rand 0.1
			{call "start"}
		}
		{tags remove "17bar"}
		{tags remove "19bar"}
		{tags add "18bar"}
	}
	{on animation_event "stop"	
		{if not "stop"
			{call "stop"}
		}
	}
	{on "start_bar_x2"
		{ani_play "heat" +0.3 resume callback}
	}
	{on "start_bar_x1"
		{ani_play "heat" +0.1 resume callback}
	}
	{on "emit_bar"
		{ani_play "heat" -0.1 resume callback}
	}
	{on "emit_bar_pierce"
		{ani_play "heat" +0.7 resume callback}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
}




{"compressor_cars"
	{on spawn
		{add_view "water_cooler" "radiator_fx" "radiator_00_fx"}
		{add_view "water_cooler" "radiator_fx" "radiator_01_fx"}
		{add_view "water_cooler" "radiator_fx" "radiator_02_fx"}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone hide	"system_heat"}
		{link_sound "fan_l_start"					"vehicle/ventfans/start" 	}
		{link_sound "fan_l_work"					"vehicle/ventfans/fan_working" 	}
		{link_sound "fan_l_damage_work"				"vehicle/ventfans/fan_broken" 	}
		{link_sound "fan_l_stop"					"vehicle/ventfans/start" 	}	

		{link_sound "fan_r_start"					"vehicle/ventfans/start" 	}
		{link_sound "fan_r_work"					"vehicle/ventfans/fan_working" 	}
		{link_sound "fan_r_damage_work"				"vehicle/ventfans/fan_broken" 	}
		{link_sound "fan_r_stop"					"vehicle/ventfans/start" 	}	

		{link_sound "fan_destroy"				"vehicle/repair" 	}	
		{link_sound "heat"						"weapon/heat/" 	}	
	}
	{on repair
		{if component "radiator"
			{bone hide "radiator_broken"}
			{bone show "radiator"}
		else component "fan_l"
			{bone hide "fan_l_broken"}
			{bone show "fan_l"}
		else component "fan_r"
			{bone hide "fan_r_broken"}
			{bone show "fan_r"}
		}
	}
	{on break
		{if component "radiator"
			{bone hide "radiator"}
			{bone show "radiator_broken"}
			{burn volume "radiator" fx "smoke_heat_barrel" time 3 fake even_law}		
			{view start "radiator_fx"}
			{delay 10 5 
				{view stop "radiator_fx"}
			}			
		else component "fan_l"
			{ani_stop "fan_l_work"}
			{ani_stop "fan_l_start"}
			{ani_stop "fan_l_stop"}
			{stop_sound "fan_l_work"}
			{stop_sound "fan_l_start"}
			{stop_sound "fan_l_stop"}
			{bone show "fan_l_broken"}
			{bone hide "fan_l"}
		else component "fan_r"
			{ani_stop "fan_r_start"}
			{ani_stop "fan_r_stop"}
			{ani_stop "fan_r_work"}
			{stop_sound "fan_r_work"}
			{stop_sound "fan_r_start"}
			{stop_sound "fan_r_stop"}
			{bone show "fan_r_broken"}
			{bone hide "fan_r"}
		else component "engine_fan_r"
			{spawn "car_destroy_engine" "fans_engine_r"}
		else component "engine_fan_l"
			{spawn "car_destroy_engine" "fans_engine_l"}
		}
	}
	{on pierce 
		{if volume "radiator"
			{if work "radiator"
				{components "radiator" break}
			}
		}
		{if volume "fan_l"
			{if work "fan_l"
				{components "fan_l" break}
			}
		}
		{if volume "fan_r"
			{if work "fan_r"
				{components "fan_r" break}
			}
		}
		{if volume "engine_fan_r"
			{if work "engine_fan_r"
				{components "engine_fan_r" break}
			}
		}
		{if volume "engine_fan_l"
			{if work "engine_fan_l"
				{components "engine_fan_l" break}
			}
		}
	}
	{on "stop_fans"
		{if "engine_started"
			{call "start_heater"}
		}
		{if work "fan_l"
			{tags remove "work"}
			{stop_sound "fan_l_work"}
			{play_sound "fan_l_stop"}
			{ani_stop "fan_l_work"}
			{ani_play "fan_l_stop" 1}
		}
		{if work "fan_r"
			{tags remove "work"}
			{stop_sound "fan_r_work"}
			{play_sound "fan_r_stop"}
			{ani_stop "fan_r_work"}
			{ani_play "fan_r_stop" 1}
		}
	}
	{on "start_cooling"
		{if "engine_started"
			{if work "fan_l"
				{tags add "work"}
				{ani_play "fan_l_start" 0.6}
				{play_sound "fan_l_start"}
				{delay 0.5
					{ani_play "fan_l_work" loop}
					{play_sound "fan_l_work" 1}							
					{ani_play "heat_engine" -0.3 resume callback}
				}
			}
			{if work "fan_r"
				{tags add "work"}
				{ani_play "fan_r_start" 0.6}
				{play_sound "fan_r_start" }
				{delay 0.5
					{ani_play "fan_r_work" loop}
					{play_sound "fan_r_work" 1}							
					{ani_play "heat_engine" -0.3 resume callback}
				}
			else
				{ani_play "heat_engine" +0.3 resume callback}			
			}
		else
			{call "cooling_off"}
		}
	}
	{on "start_heater"
		{if "engine_started"
			{ani_play "heat_engine" +0.2 resume callback}
			{if work "radiator"
				{ani_play "heat_engine" +0.1 resume callback}
			}
		}
	}
		; {sequence "heat_engine" 
			; {speed 0.2}
			; {resume} 
			; {events 
				; {5 "cold"}
				; {50 "warm"}
				; {95 "hot"}
			; }
		; }
	{on animation_event "cold"
		{if tagged "work"
			{call "stop_fans"}
		}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone show	"system_cold"}
		{call "start_heater"}
	}
	{on animation_event "warm"	
		{bone hide	"system_hot"}
		{bone show	"system_warm"}
		{bone hide	"system_cold"}
		{if work "radiator"
			{call "start_cooling"}		
		}
	}
	{on animation_event "hot"
		{delay 10 5
			{tags add "hot"}
			{play_sound "heat" 1}
			{burn volume "radiator" fx "smoke_heat_barrel" time 15 fake even_law}		
			{delay 20
				{burn volume "engine_car" fx "smoke_heat_barrel" time 15 fake even_law}		
				{stop_sound "heat" }							
			}
		}
		{bone hide	"system_warm"}
		{bone hide	"system_cold"}
		{bone show	"system_hot"}
	}
	{on "cooling_off"
		{ani_play "heat_engine" -0.02 resume callback}
	}
}



{"compressor_cars_1"
	{on spawn
		{bone hide	"system_oiltemp"}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone hide	"system_heat"}
		{set "stop" 1}
		{add_view "smoke_bats"						"radiator_broken" 		"radiator"}
		{add_view "smoke_bats"						"fans_broken" 	"fans_engine"}
		{link_sound "start_radiator"				"vehicle/ventfans/start" 	}
		{link_sound "work_radiator"					"vehicle/ventfans/fan_working" 	}
		{link_sound "work_radiator_damage"			"vehicle/ventfans/fan_broken" 	}
		{link_sound "stop_radiator"					"vehicle/ventfans/stop" 	}	
		{link_sound "work_radiator_destroy"			"vehicle/repair" 	}	
	}
	{on pierce sync
		{if volume "radiator"
			{if not tagged "broken_radiator"
				{if rand 0.2
					{delay 10
						{tags add "broken_radiator"}
						{view start "radiator_broken"}
						{bone show	"system_oiltemp"}
					}
				}	
			}	
		}
		{if volume "fans"
			{if tagged "sound"
				{stop_sound "work_radiator"}
				{play_sound "stop_radiator"}
				{tags remove "sound"}
			}
			{tags add "fans_broken"}
			{set_skeleton "_x" sync}
			{if not tagged "pierce_engine"
				{tags add "pierce_engine"}
				{if not "stop"
					{kill_delay "cooling"}			
					{kill_delay "loop"}			
					{ani_stop "fans_work" }
					{ani_play "fans_stop" 0.3}
				}
				{delay 8 2
					{view stop "broken_radiator"}
				}
			}
		}
	}
	{on "stop_fans"
		{if not "stop"
			{kill_delay "heater"}	
			{kill_delay "cooling"}	
			{kill_delay "cooling_off"}	
			{if tagged "sound"
				{stop_sound "work_radiator"}
				{play_sound "stop_radiator"}
				{tags remove "sound"}
			}			
			{delay 2 1
				{stop_sound "work_radiator"}
				{set "stop" 1}
				{if "engine_started"
					{call "start_heater"}
				}
				{if not tagged "fans_broken"
					{ani_stop "fans_work"}
					{ani_play "fans_stop" 0.8}
				}
			}
		}
	}
	{on "start_cooling"
		{if "engine_started"
			{if "stop"
				{delay 0.5 0.1
					{if not tagged "fans_broken"
						{set "stop" 0}
						{delay 0.1
							{if not tagged "sound"
								{play_sound "start_radiator"}
								{tags add "sound"}
								{delay 3.5 "sound"
									{play_sound "work_radiator" 1}
									{stop_sound "start_radiator"}
								}
							}
						}
						;{ani_play "fans_work" loop}
						{delay 2 "cooling_start"
							{call "cooling"}
						}
					}
				}
			}
		else
			{call "cooling_off"}
		}
	}
	{on "start_heater"
		{bone show	"system_cold"}
		{bone hide	"system_warm"}
		{bone hide	"system_hot"}
		{delay 10 ;1
			{tags add "cold"}
			{delay 10 2 "heater" ;2
				{if tagged "cold"
					{tags remove "cold"}
					{if "engine_started"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags add "warm"}
					}
				}
				{delay 10 2 "heater"  ;3
					{if tagged "warm"
						{tags remove "warm"}
						{if "engine_started"
							{bone hide	"system_cold"}
							{bone hide	"system_warm"}
							{bone show	"system_hot"}
							{tags add "hot"}
							{call "start_cooling"}
						}
					}
					{if "engine_started"
						{delay 16 "heater" ;4 
							{if tagged "hot"
								{tags remove "hot"}
								{delay 4 "heater" ;5
									{bone hide	"system_hot"}
									{bone show	"system_heat"}
									{tags add "broken_cooler"}
								}
							}
						}
					else
						{call "cooling_off"}		
					}
				}
			}
		}
	}
	{on "cooling"
		{kill_delay "heater"}	
		{if not tagged "cold"
			{if not tagged "broken_radiator"
				{delay 3 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 6 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 9 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}
			else
				{delay 15 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 25 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 40 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}			
			}			
		}
	}
	{on "cooling_off"
		{kill_delay "heater"}	
		{kill_delay "cooling"}	
		{delay 1
			{call "stop_fans"}
		}
		{if not tagged "cold"
			{delay 10 "cooling_off" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 15 "cooling_off" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
		else
			{kill_delay "cooling_off"}	
		}
	}
}


{"compressor_diesel_1"
	{on spawn
		{bone show	"system_cold"}
		{bone hide	"system_oiltemp"}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone hide	"system_heat"}
		{set "stop" 1}
		{add_view "smoke_bats"						"radiator_broken" 		"radiator"}
		{add_view "smoke_bats"						"fans_broken" 	"fans"}
		{link_sound "start_radiator"				"vehicle/ventfans/start" 	}
		{link_sound "work_radiator"					"vehicle/ventfans/fan_working" 	}
		{link_sound "work_radiator_damage"			"vehicle/ventfans/fan_broken" 	}
		{link_sound "stop_radiator"					"vehicle/ventfans/stop" 	}	
		{link_sound "work_radiator_destroy"			"vehicle/repair" 	}	
	}
	{on pierce sync
		{if volume "radiator"
			{if not tagged "broken_radiator"
				{components "radiator" break}
				{delay 10
					{tags add "broken_radiator"}
					{view start "radiator_broken"}
					{bone show	"system_oiltemp"}
				}
			}	
		}
		{if volume "fans"
			{tags add "fans_broken"}
			{if not "stop"
				{kill_delay "cooling"}			
				{kill_delay "loop"}			
			}
			{delay 8 2
				{view start "fans_broken"}
				{components "radiator" break}
				{view stop "broken_radiator"}
				{delay 20
					{view pause "fans_broken"}
				}
			}
		}
	}
	{on "stop_fans"
		{if not "stop"
			{kill_delay "heater"}	
			{kill_delay "cooling"}	
			{kill_delay "cooling_off"}	
			{delay 2 1
				{set "stop" 1}
				{if "engine_started"
					{call "start_heater"}
				}
			}
		}
	}
	{on "start_heater" ;срабатывает если завели
		{kill_delay "heater"}	
		{delay 10 ;1
			{tags add "cold"}
			{delay 10 "heater" ;2
				{if tagged "cold"
					{if "engine_started"
						{tags remove "cold"}
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags add "warm"}
					}
				}
				{delay 10 "heater"  ;3
					{if "engine_started"
						{if tagged "warm"
							{tags remove "warm"}
							{bone hide	"system_cold"}
							{bone hide	"system_warm"}
							{bone show	"system_hot"}
							{tags add "hot"}
							{call "start_cooling"}
						}
					else
						{call "cooling_off"}		
					}
				}
			}
		}
	}
	{on "start_cooling"
		{if "engine_started"
			{if "stop"
				{delay 0.5 0.1
					{if tagged "fans_broken"
						{view start "fans_broken"}
						{start_sound "vehicle/cpu/warm"}					
						{delay 3 
							{view pause "fans_broken"}
						}
					else
						{set "stop" 0}
						{delay 2 "cooling_start"
							{call "cooling"}
						}
					}
				}
			}
		else
			{call "cooling_off"}
		}
	}
	{on "cooling"
		{kill_delay "heater"}	
		{if not tagged "cold"
			{if tagged "broken_radiator"
				{delay 15 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 25 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 40 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}			
			else
				{delay 3 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 6 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 9 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}
			}			
		}
	}
	{on "cooling_off"
		{kill_delay "heater"}	
		{kill_delay "cooling"}	
		{delay 1
			{call "stop_fans"}
		}
		{if not tagged "cold"
			{delay 10 "cooling_off" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 15 "cooling_off" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
		else
			{kill_delay "cooling_off"}	
		}
	}
}


{"compressor_diesel_tank"
	{on spawn
		{bone hide	"system_oiltemp"}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone hide	"system_heat"}
		{set "stop" 1}
		{add_view "smoke_bats"						"radiator_broken" 		"radiator"}
		{add_view "smoke_bats"						"fans_broken" 	"fans"}
		{link_sound "start_radiator"				"vehicle/engine/med_rpm/radiator/fan_whine_low_start" 	}
		{link_sound "work_radiator"					"vehicle/engine/med_rpm/radiator/fan_whine_low" 	}
		{link_sound "stop_radiator"					"vehicle/engine/med_rpm/radiator/fan_whine_low_stop" 	}	
		{link_sound "work_radiator_destroy"			"vehicle/repair" 	}	
		{link_sound "work_radiator_damage"			"vehicle/ventfans/fan_broken" 	}
	}
	{on pierce sync
		{if volume "radiator"
			{if not tagged "broken_radiator"
				{if rand 0.2
					{delay 10
						{tags add "broken_radiator"}
						{view start "radiator_broken"}
						{bone show	"system_oiltemp"}
					}
				}	
			}	
		}
		{if volume "fans"
			{if tagged "sound"
				{stop_sound "work_radiator"}
				{play_sound "stop_radiator"}
				{tags remove "sound"}
			}
			{tags add "fans_broken"}
			{if not tagged "pierce_engine"
				{tags add "pierce_engine"}
				{if not "stop"
					{kill_delay "cooling"}			
					{kill_delay "loop"}			
					{ani_stop "fans_work" }
					{ani_play "fans_stop" 0.3}
				}
				{delay 8 2
					{view stop "broken_radiator"}
				}
			}
		}
	}
	{on "stop_fans"
		{if not "stop"
			{kill_delay "heater"}	
			{kill_delay "cooling"}	
			{kill_delay "cooling_off"}	
			{if tagged "sound"
				{stop_sound "work_radiator"}
				{play_sound "stop_radiator"}
				{tags remove "sound"}
			}			
			{delay 2 1
				{stop_sound "work_radiator"}
				{set "stop" 1}
				{if "engine_started"
					{call "start_heater"}
				}
				{if not tagged "fans_broken"
					{ani_stop "fans_work"}
					{ani_play "fans_stop" 0.8}
				}
			}
		}
	}
	{on "start_cooling"
		{if "engine_started"
			{if "stop"
				{delay 0.5
					{if not tagged "fans_broken"
						{set "stop" 0}
						{delay 0.1
							{if not tagged "sound"
								{burn volume "radiator_dust" fx "radiator_exshaut" time 6 fake even_law}
								{play_sound "start_radiator"}
								{tags add "sound"}
								{delay 3.5 "sound"
									{play_sound "work_radiator" 1}
									{stop_sound "start_radiator"}
								}
							}
						}
						{ani_play "fans_work" loop}
						{delay 2 "cooling_start"
							{call "cooling"}
						}
					}
				}
			}
		else
			{call "cooling_off"}
		}
	}
	{on "start_heater"
		{bone show	"system_cold"}
		{bone hide	"system_warm"}
		{bone hide	"system_hot"}
		{delay 10 ;1
			{tags add "cold"}
			{delay 10 2 "heater" ;2
				{if tagged "cold"
					{tags remove "cold"}
					{if "engine_started"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags add "warm"}
					}
				}
				{delay 10 2 "heater"  ;3
					{if tagged "warm"
						{tags remove "warm"}
						{if "engine_started"
							{bone hide	"system_cold"}
							{bone hide	"system_warm"}
							{bone show	"system_hot"}
							{tags add "hot"}
							{call "start_cooling"}
						}
					}
					{if "engine_started"
						{delay 20 "heater" ;4 
							{if tagged "hot"
								{tags remove "hot"}
								{delay 4 "heater" ;5
									{bone hide	"system_hot"}
									{bone show	"system_heat"}
									{tags add "broken_cooler"}
									{view start "radiator_broken"}
									{delay 10
										{view stop "radiator_broken"}
									}							
								}
							}
						}
					else
						{call "cooling_off"}		
					}
				}
			}
		}
	}
	{on "cooling"
		{kill_delay "heater"}	
		{if not tagged "cold"
			{if not tagged "broken_radiator"
				{delay 3 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 6 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 9 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}
			else
				{delay 15 "cooling" 
					{if tagged "hot"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "hot"}
						{tags add "warm"}
					}
				}
				{delay 25 "cooling" 
					{if tagged "warm"
						{bone show	"system_cold"}
						{bone hide	"system_warm"}
						{bone hide	"system_hot"}
						{tags remove "warm"}
						{tags add "cold"}
					}
				}
				{delay 40 "cooling" 
					{call "stop_fans"}
					{if "engine_started"
						{call "start_heater"}
					else
						{call "cooling_off"}				
						{kill_delay "cooling"}	
					}
				}			
			}			
		}
	}
	{on "cooling_off"
		{kill_delay "heater"}	
		{kill_delay "cooling"}	
		{delay 1
			{call "stop_fans"}
		}
		{if not tagged "cold"
			{delay 10 "cooling_off" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 15 "cooling_off" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
		else
			{kill_delay "cooling_off"}	
		}
	}
}



{"compressor_diesel_tank_two"
	{on spawn
		{bone hide	"system_oiltemp"}
		{bone hide	"system_hot"}
		{bone hide	"system_warm"}
		{bone hide	"system_heat"}
		{set "stop" 1}
		{add_view "smoke_bats"						"radiator_broken" 		"radiator"}




		{link_sound "start_radiator"				"vehicle/engine/med_rpm/radiator/fan_whine_low_start" 	}
		{link_sound "work_radiator"					"vehicle/engine/med_rpm/radiator/fan_whine_low" 	}
		{link_sound "stop_radiator"					"vehicle/engine/med_rpm/radiator/fan_whine_low_stop" 	}	
		{link_sound "work_radiator_destroy"			"vehicle/repair" 	}	
		{link_sound "work_radiator_damage"			"vehicle/ventfans/fan_broken" 	}
	}
	{on pierce sync
		{if volume "radiator_l"
			{if not tagged "broken_radiator_l"
				{if rand 0.5
					{delay 2
						{tags add "broken_radiator_l"}
						{view start "radiator_broken_l"}
						{components "radiator_l" break}
						{bone show	"system_oiltemp"}
					}
				}	
			}	
		}
		{if volume "radiator_r"
			{if not tagged "broken_radiator_r"
				{if rand 0.5
					{delay 2
						{tags add "broken_radiator_r"}
						{view start "radiator_broken_r"}
						{bone show	"system_oiltemp"}
						{components "radiator_r" break}
					}
				}	
			}	
		}
	}
	

	{on "stop_fans"
		{if not tagged "stop"
			{kill_delay "heater"}	
			{kill_delay "cooling"}	
			{kill_delay "cooling_off"}	
			{stop_sound "work_radiator"}
			{play_sound "stop_radiator"}
			{delay 2 1
				{if "engine_started"
					{call "start_heater"}
				}
				{ani_stop "radiator_r_fans_work" }
				{ani_stop "radiator_l_fans_work" }
			}
		}
	}
	{on "start_cooling"
		{if "engine_started"
			{if "stop"
				{delay 0.5 0.1
					{if not tagged "broken_radiator_r"
						{set "stop" 0}
						{delay 0.1
							{play_sound "start_radiator"}
							{delay 3.5 "sound"
								{play_sound "work_radiator" 1}
								{stop_sound "start_radiator"}
							}
						}
						{ani_play "radiator_r_fans_work" loop}
						{delay 0.5 "cooling_start_r"
							{call "check"}
						}
					}
					{delay 0.5 0.1
						{if not tagged "broken_radiator_l"
							{set "stop" 0}
							{delay 0.1
								{play_sound "start_radiator"}
								{delay 3.5 "sound"
									{play_sound "work_radiator" 1}
									{stop_sound "start_radiator"}
								}
							}
							{ani_play "radiator_l_fans_work" loop}
							{delay 2 "cooling_start_l"
								{call "check"}
							}
						}
					}
				}
			}
		else
			{call "cooling_off"}
		}
	}
	{on "start_heater"
		{bone show	"system_cold"}
		{bone hide	"system_warm"}
		{bone hide	"system_hot"}
		{delay 10 ;1
			{tags add "cold"}
			{delay 10 2 "heater" ;2
				{if tagged "cold"
					{tags remove "cold"}
					{if "engine_started"
						{bone hide	"system_cold"}
						{bone show	"system_warm"}
						{bone hide	"system_hot"}
						{tags add "warm"}
					}
				}
				{delay 10 2 "heater"  ;3
					{if tagged "warm"
						{tags remove "warm"}
						{if "engine_started"
							{bone hide	"system_cold"}
							{bone hide	"system_warm"}
							{bone show	"system_hot"}
							{tags add "hot"}
							{call "start_cooling"}
						}
					}
					{if "engine_started"
						{delay 16 "heater" ;4 
							{if tagged "hot"
								{tags remove "hot"}
								{delay 4 "heater" ;5
									{bone hide	"system_hot"}
									{bone show	"system_heat"}
									{tags add "broken_cooler"}
								}
							}
						}
					else
						{call "cooling_off"}		
					}
				}
			}
		}
	}
	
	{on "check"	 ;проверка на два тега для старта охлаждения
		{if not tagged "set1"
			{tags add "set1"}		
			{delay 2 "set" 
				{tags remove "set1"}	
				{if not tagged "blocked"
					{call "cooling_x1"}
				}
			}		
		else tagged "set1"
			{kill_delay "set"}
			{tags add "blocked"}		
			{delay 2 
				{call "cooling_x2"}
			}
		}	
	}
	{on "cooling_x2"
		{tags remove "blocked"}		
		{kill_delay "heater"}	
		{if not tagged "cold"
			{delay 3 "cooling" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 6 "cooling" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
			{delay 9 "cooling" 
				{call "stop_fans"}
				{if "engine_started"
					{call "start_heater"}
				else
					{call "cooling_off"}				
					{kill_delay "cooling"}	
				}
			}
		}
	}
	{on "cooling_x1"
		{tags remove "blocked"}		
		{kill_delay "heater"}	
		{if not tagged "cold"
			{delay 6 "cooling" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 12 "cooling" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
			{delay 18 "cooling" 
				{call "stop_fans"}
				{if "engine_started"
					{call "start_heater"}
				else
					{call "cooling_off"}				
					{kill_delay "cooling"}	
				}
			}
		}
	}
	{on "cooling_off"
		{kill_delay "heater"}	
		{kill_delay "cooling"}	
		{delay 1
			{call "stop_fans"}
		}
		{if not tagged "cold"
			{delay 10 "cooling_off" 
				{if tagged "hot"
					{bone hide	"system_cold"}
					{bone show	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "hot"}
					{tags add "warm"}
				}
			}
			{delay 15 "cooling_off" 
				{if tagged "warm"
					{bone show	"system_cold"}
					{bone hide	"system_warm"}
					{bone hide	"system_hot"}
					{tags remove "warm"}
					{tags add "cold"}
				}
			}
		else
			{kill_delay "cooling_off"}	
		}
	}
}
