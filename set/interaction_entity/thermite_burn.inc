{"thermite_burn"
	{inflammation_time 0}
	{on spawn
		{spawn "ex_th2" }
		;{link_sound "end" 	 "detonation/thermite/end/"				}
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		;{link_sound "flash" "detonation/thermite/flash/"			}
		{call "thermite_burn"}
	}
	{on "thermite_burn"
		{add_view 	"thermite_hit2" 						"fx_fire" "basis"}
		{start_sound "detonation/thermite/flash/"}	
		{view start	"fx_fire"}
		{view show	"fx_fire"}	
		{play_sound "flash" }
		{delay 1.5
			{fire radius 0.7 time 20 heating 8}
			{play_sound "loop" 1}
			{delay 20
				{stop_sound "loop" }
				{play_sound "end" }
				{start_sound "detonation/thermite/end/"}	
				{view stop	"fx_fire"}
				{view hide	"fx_fire"}	
				{delay 3 ;24.5
					{delete}
				}
			}
		}
	}
}


{"thermite_burn_ground"
	{on spawn
		{impulse up 0.1}
		;{link_sound "end" 	 "detonation/thermite/end/"				}
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		;{link_sound "flash" "detonation/thermite/flash/"			}
		{add_view 	"thermite_hit_ground" 						"fx_fire" "basis"}
		{start_sound "detonation/thermite/flash/"}	
		{view start	"fx_fire"}
		{view show	"fx_fire"}	
		{play_sound "flash" }
		{spawn "ex_th2" }
		{delay 1.5
			{burn volume "body" fx "smoke_dead_small3" time 8 fake even_law}
			{fire radius 1 time 20 heating 12}
			{play_sound "loop" 1}
			{delay 20
				{stop_sound "loop" }
				{play_sound "end" }
				{start_sound "detonation/thermite/end/"}	
				{view stop	"fx_fire"}
				{view hide	"fx_fire"}	
				{delay 3 ;24.5
					{spawn "burn_magazine_end" }
					{delete}
				}
			}
		}
	}
}



{"thermite_fire_spawn"
	{on spawn	
		{spawn "fraction_thermite" offset 0 0.5 1.5}
		{spawn "fraction_thermite" offset 0 0.5 1}
		{spawn "fraction_thermite" offset 0 0.5 1}
		{spawn "fraction_thermite" offset 0 -0.5 2}
		{delay 1
			{delete}
		}	
	}
}
{"thermite_fire_big_spawn"
	{on spawn	
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{spawn "fraction_thermite_fast_round" }
		{delay 0.1
			{delete}
		}	
	}
}
{"fraction_thermite_fast_round" ;thermite
	{on spawn
		{fire volume "body" radius 0.1 heating 2  time 4 follow}
		{add_view 	"thermite_hit_small" 				"fx_fire" "body"}
		{add_view 	"thermite_hit_ground_small" 		"fx_fire2" "body"}
		{impulse up 12 4 rnd_dir 6 17}
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		{view start	"fx_fire"}
		{view show	"fx_fire"}	
		{play_sound "loop" 1}
		{delay 1.5
			{gravity 1}
			{fire radius 0.2 time 2 heating 3}
			{delay 5
				{stop_sound "loop" }
				{start_sound "detonation/thermite/end/"}	
				{view stop	"fx_fire"}
				{view hide	"fx_fire"}	
				{delay 1 
					{delete}
				}
			}
		}
	}
	{on contact
		{if not prop "fraction_thermite"
			{if not tagged "burned"
				{tags add "burned"}
				{start_sound "detonation/thermite/flash/"}	
				{fire radius 0.4 time 24 heating 24 effector}
				{view start	"fx_fire2"}
			}
		}
	}
	{on ground_hit
		{if not tagged "burned"
			{view start	"fx_fire2"}
			{tags add "burned"}
			{fall_down}
			{spawn "impact_burnmark_01_blend" }	
			{fire radius 0.2 time 1 heating 24 effector}
		}
	}
}
{"fraction_thermite_fast" ;thermite
	{on spawn
		{fire volume "body" radius 0.1 heating 0.5  time 0.5 follow}
		{add_view 	"thermite_hit_small" 				"fx_fire" "body"}
		{add_view 	"thermite_hit_ground_small" 		"fx_fire2" "body"}
		{impulse up 0 rnd_dir 3 -3 forward -7 -2 com  }
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		{view start	"fx_fire"}
		{view show	"fx_fire"}	
		{play_sound "loop" 1}
		{delay 1.5
			{gravity 1}
			{fire radius 0.2 time 0.5 heating 0.5}
			{delay 5
				{stop_sound "loop" }
				{start_sound "detonation/thermite/end/"}	
				{view stop	"fx_fire"}
				{view hide	"fx_fire"}	
				{delay 1 ;24.5
					{delete}
				}
			}
		}
	}
	{on contact
		{if not prop "fraction_thermite"
			{if not tagged "burned"
				{tags add "burned"}
				{start_sound "detonation/thermite/flash/"}	
				{fire radius 0.2 time 24 heating 5 effector}
				{view start	"fx_fire2"}
			}
		}
	}
	{on ground_hit
		{if not tagged "burned"
			{view start	"fx_fire2"}
			{tags add "burned"}
			{fall_down}
			{spawn "impact_burnmark_01_blend" }	
			{fire radius 0.3 time 7 heating 5}
		}
	}
}
{"fraction_thermite" ;thermite
	{on spawn	
		{add_view 	"thermite_hit2" 				"fx_fire" "body"}
		{add_view 	"thermite_hit_ground_rpg" 		"fx_fire2" "body"}
		{impulse up 0 rnd_dir 2 -2 forward -3 -2 com  }
		;{impulse up 0.5 rnd_dir 2 forward 6 2 com  }
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		{view start	"fx_fire"}
		{view show	"fx_fire"}	
		{play_sound "loop" 1}
		{delay 1.5
			{gravity 1}
			{fire radius 0.2 time 5 heating 8}
			{delay 12
				{stop_sound "loop" }
				{start_sound "detonation/thermite/end/"}	
				{view stop	"fx_fire"}
				{view hide	"fx_fire"}	
				{delay 1 ;24.5
					{delete}
				}
			}
		}
	}
	{on contact
		{if not prop "fraction_thermite"
			{if not tagged "burned"
				{tags add "burned"}
				{start_sound "detonation/thermite/flash/"}	
				{fire radius 0.4 time 24 heating 24 effector}
				{view start	"fx_fire2"}
			}
		}
	}
	{on ground_hit
		{if not tagged "burned"
			{view start	"fx_fire2"}
			{tags add "burned"}
			{fall_down}
			{spawn "impact_burnmark_01_blend" }	
			{spawn "ex_air_norm9"}
			{fire radius 0.2 time 8 heating 24 effector}
		}
	}
}

