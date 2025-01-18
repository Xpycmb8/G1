(define "pressure"
	{"pressure_emitters"
		{on spawn
			{tags add "1000"}
			{ani_play "pressure" loop}		
		}
		{on animation_event "pressure_emitters"	
			{if tagged "%0"
				{tear "pressure_gas" bone "outer" copy 
					{gravity 0}
					{impulse dir 0 forward %0 com  }
				}
			}
		}
	}
	{"tubes_100m_80r"
		{inflammation_time 25}
		{on spawn
			{link_sound "explosion" "detonation/explosion_medium/fuel/oxygen_Tank"}
			{link_sound "move" ""}
			{set "fire" 0}
			{set "exploded" 0}
		}
		{on blast_hit
			{if min_energy 2.0
				;{if volume "inside"
					{if tagged "load" 
						{call "explosion_tube"}
					}
				;}
			}
		}
		{on "explosion_tube"
			{if not "exploded"
				{set "exploded" 1}
				{set "fire" 1}
				{blastwave c4 12 r0 9 r1 9}	
				{fire radius 6 time 7 heating 4}
				{spawn "open_gas_vl_fx"}
				{spawn "distant_big_expl" }
				{spawn "fx_piece_flame_ground_tail"}
				{spawn "fragment_pipes_outer" {impulse up 0 dir 4 2 forward 15 3 com  cx 9 2 cy 9 2} }
				{spawn "fragment_pipes_inner" {impulse up 0 dir 4 2 forward 15 3 com  cx 9 2 cy 9 2} }
				{spawn "fragment_pipes_1" {impulse up 8 1 cx 9 2 cy 9 2 rnd_dir 12 6 no_position} }
				{spawn "fragment_pipes_1" {impulse up 8 1 cx 9 2 cy 9 2 rnd_dir 12 6 no_position}}
				{spawn "oil_drum_sharp_big"  }
				{spawn "emmiters_smoke_big"  }
				{delete}
			}
		}
		{on "burn_volume"
			{if not "burned"
				{set "burned" 1}
				{if tagged "load"
					{if volume "body"
						{burn volume fx "smoke_dead_small3" time 8 fake even_law}
						{delay 5 2
							{call "explosion_tube"}
						}
					}
				}
			}
		}
		{on pierce
			{if tagged "load"
				{if volume "body"
					{if stuff "shell"
						{call "explosion_tube"}
					else stuff "zenite th"
						{if not "fire"
							{set "fire" 1}
							{play_sound "explosion" 1}
							{burn fx "oxygen_fire" time 10}
							{delay 4 2
								{call "explosion_tube"}
							}
						}
					else stuff "bullet"
						{if rand 0.3
							{if not "fire"
								{set "fire" 1}
								{play_sound "explosion" 1}
								{burn fx "oxygen_fire" time 10}
								{delay 4 2
									{call "explosion_tube"}
								}
								{if rand 0.1
									{call "explosion_tube"}
								}
							}					
						}					
					}
				}
			}
		}
		{on contact
			{if effector "thermite"
				{if volume "inside"
					{if tagged "load" 
						{call "explosion_tube"}
					}
				}
			}			
			{if effector "pressure_gas"
				{if volume "inner"
					{with_effector
						{if not tagged "not_transport"	
							{with_effector						
								{if min_mass %0
									{tags add "load"}
									{delay 2 "load"
										{tags remove "load"}
									}
									{kill_delay "load"}
									{ani_play "pressure" +%1 resume callback}
									{with_effector
										{delete}
									}
									{tear "pressure_gas%0" bone "outer" copy 
										{gravity 0}
										{impulse dir 0 forward 10 com  }
									}
									{tear "pressure_gas%0" bone "outer2" copy 
										{gravity 0}
										{impulse dir 0 forward 10 com  }
									}
								else min_mass 0								
								}
							}
						}
					}
				}
			}
		}
	}
	{"cistern_1000l"
		{on contact
			{if effector "pressure_gas"
				{if volume "inner"
					{if min_mass %0
						{ani_play "pressure" +%1 resume callback}
						{with_effector
							{delete}
						}
					else min_mass 0					
					}
				}
			}
		}
	}
	{"fragments_tubes"
		{on spawn
			{burn volume "body" fx "smoke_dead_small3" time 8 fake even_law}
		}
	}
)	
;(* 0.1 1000)			
; ("pressure" args 2	 		2			)
 ("pressure" args 10	 		0.1			)
 ("pressure" args 100	 		1			)
 ("pressure" args 200	 		2			)

{"pressure_gas"
	{on spawn
		{gravity 0}
		{delay 0.1
			{tags add "not_transport"}
			{add_view "smoke_cover-up_big_white" "flame" "root"}
			{view start "flame"}
		}
		{delay 0.5 0.3
			{spawn "open_gas_ph"}
			{delete}
		}
	}
}

{"tubes_editor"
	{on spawn
		{call "editor"}
	}
	{on "editor"
		{start_sound "amb_emitters/fire/emt_fire_drip_01"}
		{tear "pressure_gas100" bone "outer" copy 
			{gravity 0}
			{impulse dir 0 forward 10 com  }
		}
		{delay_effect 0.2 "editor"}
	}
}

{"preview_instal"
	{on spawn
		{call "hide"}
;		{if not tagged "load"
;			{delay 0.4
;				{hide 5}
;			}
;		}
	}
	{on "hide"
		{delay_effect 1 "hide"}
		{if tagged "morph"
			{if not tagged "start"
				{tags add "start"}
				{hide 2}
			}
		}
	}
}




