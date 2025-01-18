{"grenade handgrenade"
	{inflammation_time 15}
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
		{volumes "throw" disable contact }
		{volumes "dg" disable contact overlap touch select}
		{volumes "flash" disable contact overlap touch select}
		{volumes "smoke" disable contact overlap touch select}
		{volumes "explosions" disable contact overlap touch select}
		{volumes "frag" disable contact overlap touch select}
		{add_view "tail_grenade" "tail_grenade" "root"}
	}
	{on "onThrow"
		{start_sound "weapon/throw/grenade"}
		{view start "tail_grenade"}
		{if rand 0.8		
			{delay 0.2 -0.2
				{start_sound "detonation/handgrenade_throw"}		
			}
		}
		{volumes "explosions" enable overlap}
		{volumes "flash" enable overlap}
		{volumes "frag" enable overlap}
		{volumes "smoke" enable overlap}
		{delay 2 1.2
			{view stop "tail_grenade"}
		}
		{delay 1
			{volumes "explosions" disable overlap}
			{volumes "flash" disable overlap}
			{volumes "frag" disable overlap}
			{volumes "smoke" disable overlap}
		}
		{tear "fx_piece" bone "ring"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch"
			{impulse up 1 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "pin"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch2"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on "onThrowActivate"
		{tear "fx_piece" bone "pin02"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "ring02"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on contact
		{if stuff_activated
			{if effector "human"
				;{fall_down}
				{impulse up 0.5 }
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			else effector "interior"
				{tags add "interior"}	
			else volume "impulse"
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		}
	}
	{on blast_hit 
		{if min_energy 0.5
			{if rand 0.3
				{stuff_detonate}	
			}
		}
	}
	{on bullet_hit 
		{if rand 0.2
			{spawn "ex_inc_small" "basis"}
			{delete}
			;{stuff_detonate}
		}
	}

	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit sync
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{if rand 0.9
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				}
			else min_speed %3
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/med/"}	
				}
			else min_speed %4
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		grass 			30 14 6 )
		("terrain_fx" args "grass" 			grass 			30 14 6 )
		("terrain_fx" args "road" 			concrete 		30 14 6 )
		("terrain_fx" args "country_road" 	concrete 		30 14 6 )
		("terrain_fx" args "sand" 			sand 			30 14 6 )
		("terrain_fx" args "snow"  			mud 			30 14 6 )
		("terrain_fx" args "water" 			water 			30 14 6 )
		("terrain_fx" args "bridge" 		wood			30 14 6 )
		("terrain_fx" args "bridge_wood" 	wood			30 14 6 )
		("terrain_fx" args "floor" 			carpet 			30 14 6 )
		("terrain_fx" args "rock" 			ground 			30 14 6 )
		("terrain_fx" args "metal" 			metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_mtl" 	 metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_mtl_int" 	metal 			30 14 6 )
		("terrain_fx" args "shoot_emit_ext" 	 concrete 		30 14 6 )
		("terrain_fx" args "shoot_emit_int"  	concrete 		30 14 6 )
		("terrain_fx" args "shoot_emit_int_wood"  	wood 		30 14 6 )
	}
	{on "burn_volume"
		{if not "burned"
			{if volume "body"
				{play_sound "small" 1}
				{set "burned" 1}
				{burn volume fx "smoke_aero_2_small" time 3 fake even_law}	
				{delay 6 5
					{burn volume fx "smoke_aero_small" time 10 fake even_law}
					{delay 2 1
						{stuff_detonate}	
					}
				}
			}
		}
	}
	{on "fall_down"
;		{volumes disable contact}
	}
}


{"grenade fg"
	{on "onThrow"
		{if rand 0.99		
			{delay 4.5 0.5
				{stuff_detonate}	
			}
		else
			{delay 6 0.5
				{burn volume fx "smoke_heat" time 3 fake even_law}
			}
		}
		{delay 1.5
			{if stuff_activated
				{spawn "grenade_danger" }
			}
			{call "show_marker1"}
		}
		{delay 3.5
			{if stuff_activated
				{spawn "grenade_danger" }
			}
			{call "show_marker2"}
		}
	}
}
{"grenade drop_grenade"
	{on spawn
		{delay 0.2 -0.2
			{start_sound "detonation/handgrenade_throw"}		
		}
		{volumes disable contact }
		{impulse dir 2 1 cx 5 2 cy 5 2 rnd_dir 3 no_position}
		;{view start "tail_grenade"}
		{delay 1
			{volumes enable contact }
		}	
		{delay 3.5 1
			{stuff_detonate}	
		}
	}
}
{"grenade flashbang"
	{on spawn
		{volumes "throw" disable contact }
		{volumes "flash" disable contact overlap touch select}
		{add_view "tail_grenade" "tail_grenade" "root"}
		{add_view "flashbang_d" "detonation" "fx_set01"}
		{add_view "flashbang_d" "detonation" "fx_set02"}
		{add_view "flashbang_d" "detonation" "fx_set03"}
	}
	{on "onThrow"
		{if rand 0.99		
			{delay 2.5 -1
				{blastwave c4 0.5 r0 1 r1 1}	
				{view start "detonation"}
				{spawn "m84_flashbang_burnt"}
				{spawn "shellhole_orient" "fx_set01"}
				{spawn "shellhole_orient" "fx_set02"}
				{if rand 0.8		
					{spawn "shellhole_orient" "fx_set03"}
				}
				{if rand 0.4		
					{spawn "impact_burnmark_01_blend" "fx_set01"}
				}
				{if rand 0.6		
					{spawn "impact_burnmark_02_blend" "fx_set02"}
				}
				{stuff_detonate}
			}
		else
			{view start "detonation"}
			{spawn "m84_flashbang_burnt"}
			{stuff_detonate}
		}
		{start_sound "weapon/throw/flashbang"}
		{spawn "detonation_fb" "pin"}
		{view start "tail_grenade"}
		{if rand 0.8		
			{delay 0.2 -0.2
				{start_sound "detonation/handgrenade_throw"}		
			}
		}
		{volumes "flash" enable overlap}
		{delay 2 1.2
			{view stop "tail_grenade"}
		}
		{delay 1
			{volumes "flash" disable overlap}
		}
		{tear "fx_piece" bone "ring"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch"
			{impulse up 1 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "pin"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch2"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on "onThrowActivate"
		{tear "fx_piece" bone "pin02"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "ring02"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on bullet_hit 
		{if rand 0.2
			{spawn "ex_inc_small" "basis"}
			{delete}
			;{stuff_detonate}
		}
	}
	{on contact 
		{if stuff_activated
			{if effector "human"
				{call "fall_down"}
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			else effector "interior"
				{tags add "interior"}	
			else volume "impulse"
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		}
		(define "contact_fx"
			{if min_speed %2
				{if effector %0 
					{if rand 0.8
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				}
			else min_speed %3
				{if effector %0 
					{start_sound "hit/small/grenade/%1/med/"}	
				}
			else min_speed 2
				{if effector %0 
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
		)
		("contact_fx" args "concrete" 		concrete 	15 5 )
		("contact_fx" args "steel" 			metal 		15 5 )
		("contact_fx" args "wood" 			wood 		15 5 )
		("contact_fx" args "flesh" 			flesh		15 5 )
		("contact_fx" args "misc" 			carpet 		15 5 )
		("contact_fx" args "rock" 			concrete 	15 5 )
		{if stuff_activated
			{if effector "human"
				{fall_down}
				{impulse up 0.5 }
			else effector "cannon"
				{link_grenade_to_nearest_human teleport}
			else effector "interior"
				{tags add "interior"}	
			else volume "impulse"
				{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
			}
		}
	}
	{on ground_hit sync
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{if rand 0.9
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				}
			else min_speed %3
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/med/"}	
				}
			else min_speed %4
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		grass 			30 14 6 )
		("terrain_fx" args "grass" 			grass 			30 14 6 )
		("terrain_fx" args "road" 			concrete 		30 14 6 )
		("terrain_fx" args "country_road" 	concrete 		30 14 6 )
		("terrain_fx" args "sand" 			sand 			30 14 6 )
		("terrain_fx" args "snow"  			mud 			30 14 6 )
		("terrain_fx" args "water" 			water 			30 14 6 )
		("terrain_fx" args "bridge" 		wood			30 14 6 )
		("terrain_fx" args "bridge_wood" 	wood			30 14 6 )
		("terrain_fx" args "floor" 			carpet 			30 14 6 )
		("terrain_fx" args "rock" 			ground 			30 14 6 )
		("terrain_fx" args "metal" 			metal 			30 14 6 )
	}
	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on "fall_down"
;		{volumes disable contact}
		{fall_down}
	}
}

{"grenade semtex"
	{on spawn
		{add_view "fx_lamp_red" "fx_lamp" "fx_lamp"}
		{link_sound "start"	"detonation/semtex/semtex_beep_2sec" 	}
		{view hide	"fx_lamp"}
		{view stop	"fx_lamp"}
	}
	{on "onThrow"
		{call "lamp"}
		{start_sound "weapon/throw/grenade"}
		{delay 2
			{play_sound "start"}
		}
	}
	{on "lamp"
		{view show	"fx_lamp"}
		{view start	"fx_lamp"}
		{delay 0.5 
			{view hide	"fx_lamp"}
			{view stop	"fx_lamp"}
			{delay 0.5
				{view show	"fx_lamp"}
				{view start	"fx_lamp"}
				{delay 0.4 
					{view hide	"fx_lamp"}
					{view stop	"fx_lamp"}
					{delay 0.4
						{view show	"fx_lamp"}
						{view start	"fx_lamp"}
						{delay 0.3 
							{view hide	"fx_lamp"}
							{view stop	"fx_lamp"}
							{delay 0.3
								{view show	"fx_lamp"}
								{view start	"fx_lamp"}
								{delay 0.2 
									{view hide	"fx_lamp"}
									{view stop	"fx_lamp"}
									{delay 0.2
										{view show	"fx_lamp"}
										{view start	"fx_lamp"}
										{delay 0.15
											{view hide	"fx_lamp"}
											{view stop	"fx_lamp"}
											{delay 0.15
												{view show	"fx_lamp"}
												{view start	"fx_lamp"}
												{delay 0.05
													{view hide	"fx_lamp"}
													{view stop	"fx_lamp"}
													{delay 0.05
														{view show	"fx_lamp"}
														{view start	"fx_lamp"}
														{delay 0.05
															{view hide	"fx_lamp"}
															{view stop	"fx_lamp"}
															{delay 0.05
																{view show	"fx_lamp"}
																{view start	"fx_lamp"}
																{delay 0.03
																	{view hide	"fx_lamp"}
																	{view stop	"fx_lamp"}
																	{delay 0.03
																		{view show	"fx_lamp"}
																		{view start	"fx_lamp"}
																		{delay 0.03
																			{view hide	"fx_lamp"}
																			{view stop	"fx_lamp"}
																			{delay 0.02
																				{view show	"fx_lamp"}
																				{view start	"fx_lamp"}
																				{delay 0.02
																					{view hide	"fx_lamp"}
																					{view stop	"fx_lamp"}
																					{delay 0.02
																						{view show	"fx_lamp"}
																						{view start	"fx_lamp"}
																						{delay 0.02
																							{view hide	"fx_lamp"}
																							{view stop	"fx_lamp"}
																							{delay 0.02
																								{view show	"fx_lamp"}
																								{view start	"fx_lamp"}
																								{call "blast_semtex"}
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
							}
						}
					}
				}
			}
		}
	}
	{on contact
		(define "contact_fx"
			{if effector %0 
				{tags add %0}
				{if min_speed %2
					{if rand 0.8
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				else min_speed %3
					{start_sound "hit/small/grenade/%1/med/"}	
				else min_speed 2
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
		)
		("contact_fx" args "concrete" 		concrete 	15 5 )
		("contact_fx" args "steel" 			metal 		15 5 )
		("contact_fx" args "wood" 			wood 		15 5 )
		("contact_fx" args "flesh" 			flesh		15 5 )
		("contact_fx" args "misc" 			carpet 		15 5 )
		("contact_fx" args "rock" 			concrete 	15 5 )
		{if stuff_activated
			{if effector "human"
				{stop_sound "start"}
				{call "blast_semtex"}
			else effector "vehicle"
				{tags add "vehicle"}
				{tags remove "steel"}
			else effector "not_touch"
				{stop_sound "start"}
			else effector "glass_frame_engine_new"
				{spawn	"glass_hit_small" }
				{stop_sound "start"}
			else 
				{gravity 0}
				{fall_down}
			}
		}
	}
	{on "blast_semtex"
		{if tagged "flesh"
			{stuff_detonate}	
			{spawn "ex_air_big"}					
		else tagged "wood"
			{spawn "wood_hit_big"}					
			{stuff_detonate}	
		else tagged "concrete"
			{spawn "stone_hit_br_big"}					
			{stuff_detonate}	
		else tagged "misc"
			{spawn "ex_air_big"}					
			{stuff_detonate}	
		else tagged "vehicle"
			{spawn "metal_hit_fg"}					
			{spawn "metal_hit_br_small_semtex" "basis"}					
			{stuff_detonate}	
		else tagged "steel"
			{spawn "metal_hit_fg"}					
			{stuff_detonate}	
		}
	}
	{on bullet_hit 
		{if rand 0.2
			{stop_sound "start"}
			{stuff_detonate}
		}
	}
;	{on blast_hit
;		{if min_energy 1.5
;			{stuff_detonate}	
;		}
;	}

	{on "activate"
		{call "hide_marker"}
	}
	{on "in_hole"
		{break_window_in_hole}
		{link_grenade_to_nearest_human}
	}
	{on ground_hit
		{if terrain_fx "shoot_emit_road"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_loud_road"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_sand"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_loud_sand"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_mtl"
			{tags add "expl_emitters_mtl"}
		}
		{if terrain_fx "shoot_emit_mtl_int"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_loud"
			{tags add "expl_emitters_loud"}
		}
		{if terrain_fx "shoot_emit_int"
			{tags add "expl_emitters_loud"}
		}
		{gravity 3}
		{fall_down}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{if rand 0.9
						{spawn "spheredust_small_short2"}
					}
					{start_sound "hit/small/grenade/%1/hard/"}	
				}
			else min_speed %3
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/med/"}	
				}
			else min_speed %4
				{if terrain_fx %0 
					{start_sound "hit/small/grenade/%1/soft/"}	
				}
			}
			{spawn "spheredust_small_short2"}
		)
		("terrain_fx" args "ground" 		grass 			30 14 6 )
		("terrain_fx" args "grass" 			grass 			30 14 6 )
		("terrain_fx" args "road" 			concrete 		30 14 6 )
		("terrain_fx" args "country_road" 	concrete 		30 14 6 )
		("terrain_fx" args "sand" 			sand 			30 14 6 )
		("terrain_fx" args "snow"  			mud 			30 14 6 )
		("terrain_fx" args "water" 			water 			30 14 6 )
		("terrain_fx" args "bridge" 		wood			30 14 6 )
		("terrain_fx" args "bridge_wood" 	wood			30 14 6 )
		("terrain_fx" args "floor" 			carpet 			30 14 6 )
		("terrain_fx" args "rock" 			ground 			30 14 6 )
		("terrain_fx" args "metal" 			metal 			30 14 6 )
	}
	{on "fall_down"
;		{volumes disable contact}
	}
}

{"grenade thermite"
	{on spawn
		;{link_sound ""	"detonation/thermite/end" 	}
	}
	{on "onThrow"
		{volumes disable contact }
		{delay 0.4
			{volumes enable contact }
		}
	}
	{on contact
		{if stuff_activated
			{delete}
		}
	}
	{on ground_hit
		{if stuff_activated
			{spawn "grenade_thermite_burn_ground" }
			{spawn "impact_burnmark_01_blend" }	
			{fire radius 0.3 time 1 heating 24 effector}
			{delete}
		}
	}
}


{"grenade dynamite"
	{on "undermine"
		{delay 7
			{call "show_marker1"}
		}
		{delay 9
			{call "show_marker2"}
		}
	}
	{on "onThrow"
		{call "undermine"}
	}
}

{"grenade training"
	{on spawn
		{tags add "grenade"}
	}
}
{"grenade gas"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
	}
	{on "add_smoke"
		{add_view "gas_smoke_activate"	"smoke_activate" "smoke"}
		{add_view "gas_smoke_0"			"smoke1" "root"}
		{add_view "gas_smoke_1"			"smoke2" "root"}
		{add_view "gas_smoke_2"			"smoke3" "root"}
		{add_view "gas_smoke_3"			"smoke4" "root"}
		{add_view "gas_smoke_4"			"smoke5" "root"}
		{add_view "gas_smoke_5"			"smoke6" "root"}
	}
	{on "onThrow"
		{volumes disable touch select}
	}
	{on "loop"
		{impulse dir -0.2 up 0.2 cx 1 cy 1}		
		{delay_effect 0.5
			"loop"
		}	
	}	
	{on "activate"	
		;{call "loop"}
		{ani_play "activate" loop}		
		{tags add "gas"}
		{update_visibility_patch}
		{delay 2.2
			{view start "smoke_activate"}
			{view start "smoke1"}
			{spawn "ex_gas_grenade"}
			{start_sound "detonation/smoke_start/"}
			{spawn "gas_vol_s"}
			{delay 2
				{play_sound "smoke" 1}
			}
			{update_visibility_patch}
		}
		{delay 3
			{view stop "smoke1"}
			{view start "smoke2"}
		}
		{delay 5
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 8
			{view stop "smoke3"}
			{view start "smoke4"}
		}
		{delay 12
			{spawn "gas_vol_m"}
			{view stop "smoke4"}
			{view start "smoke5"}
		}
		{delay 29
			{view stop "smoke_activate"}
			{spawn "gas_vol_l"}
			{view stop "smoke5"}
			{view start "smoke6"}
		}
		{delay 45
			{ani_stop "activate" }		
			{view stop "smoke4"}
			{stop_sound "smoke"}
		}
		{delay 46
			{hide 1}
		}
	}
	{on ground_hit
		{impulse up 0.5 0.5 cx 1 com}
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}
{"grenade contact"
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on contact
		;{if "small"
			{if stuff_activated
				{call "contact_detonate"}
			}
		;}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate}
	}
	{on "fall_down" overload}
	{on blast
		{if min_energy 0.5
			{call "detonate"}
		}
	}
}

{"grenade smoke_ai"
	{on spawn
		{volumes "body" disable contact}
		{volumes "ring" disable contact}
		{volumes "clutch" disable contact}
		{volumes "pin" disable contact}
		{delay 0.3
			{volumes "body" enable contact}
			{volumes "ring" enable contact}
			{volumes "clutch" enable contact}
			{volumes "pin" enable contact}
		}
		{impulse up 2 1 dir 2 forward 7 3 fz 1 com  }
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
		{start_sound "weapon/throw/smoke/grenade_pin_smoke"}			
		{tear "fx_piece" bone "ring"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch"
			{impulse up 1 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "pin"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on "add_smoke"
;		{add_view "smoke_cover-up_small"	"smoke1" "smoke"}
		{add_view "smoke_cover-up_norm"		"smoke2" "smoke"}
		{add_view "smoke_cover-up_big"		"smoke3" "smoke"}
	}
	{on "activate"
		{spawn "ex_smoke_grenade"}
		{start_sound "detonation/smoke_start/"}
		{ani_play "activate" loop}		
		{volumes disable touch select}
		{play_sound "smoke" 1}
		{tags add "smoke"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 3
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 5
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 25
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 27
			{hide 1}
		}
	}
	{on ground_hit
		{if not "activated"
			{set "activated" 1}
			{if under_water
				{hide 1}
			else
				{delay 1
					{call "activate"}
				}
			}
		}
	}
	{on contact
		{if not "activated"
			{set "activated" 1}
			{delay 1
				{call "activate"}
			}
		}
	}
}

{"grenade smoke"
	{on spawn
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
	}
	{on "add_smoke"
;		{add_view "smoke_cover-up_small"	"smoke1" "root"}
		{add_view "smoke_cover-up_norm"		"smoke2" "root"}
		{add_view "smoke_cover-up_big"		"smoke3" "root"}
	}
	{on "onThrow"
		{burn volume "body" fx "smoke_grenade_throw" time 5 fake even_law}		
		{start_sound "weapon/throw/smoke/grenade_pin_smoke"}			
		{volumes disable touch select}
		{view start "tail_grenade"}
		{if rand 0.8		
			{delay 0.2 -0.2
				{start_sound "detonation/handgrenade_throw/"}		
			}
		}
		{volumes "explosions" enable overlap}
		{volumes "flash" enable overlap}
		{volumes "frag" enable overlap}
		{volumes "smoke" enable overlap}
		{delay 2 1.2
			{view stop "tail_grenade"}
		}
		{delay 1
			{volumes "explosions" disable overlap}
			{volumes "flash" disable overlap}
			{volumes "frag" disable overlap}
			{volumes "smoke" disable overlap}
		}
		{tear "fx_piece" bone "ring"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch"
			{impulse up 1 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "pin"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
		{tear "fx_piece" bone "clutch2"
			{impulse up 0 dir 1 0 cx 1 0 cy 1 0 rnd_dir 1 no_position}
		}
	}
	{on "activate"
		{play_sound "smoke" 1}
		{tags add "smoke"}
;		{call "hide_marker"}
;		{view stop "smoke1"}
		{view start "smoke2"}
		{volumes "smoke1" enable visible}
		{update_visibility_patch}
		{delay 3
			{view stop "smoke2"}
			{view start "smoke3"}
		}
		{delay 5
			{volumes "smoke1" disable visible}
			{volumes "smoke2" enable visible}
			{update_visibility_patch}
		}
		{delay 60
			{view stop "smoke3"}
			{stop_sound "smoke"}
		}
		{delay 62
			{hide 1}
		}
	}
	{on ground_hit
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 3
						{call "activate"}
					}
				}
			}
		}
	}
	{on contact
		{if stuff_activated
			{if not "activated"
				{set "activated" 1}
				{delay 3
					{call "activate"}
				}
			}
		}
	}
}

{"grenade contact armed"
	{on spawn
		{view hide "armed"}
		{add_view "armed_apx"		"tail" "fx_light"}
		{add_view "slicer_tail3"		"tail" "basis"}
		{add_view "slicer_tail3"		"tail" "pin"}
	}
	{on ground_hit
		{if stuff_activated
			{if not name "water"
				{call "ground_detonate"}
			}
		}
	}
	{on "in_hole" overload}
	{on "onThrow"
		{view hide "hold"}
		{view show "armed"}
		{start_sound "weapon/set/"}
		{view start "tail"}
	}
	{on contact
		{if "small"
			{if stuff_activated
				{call "contact_detonate"}
			}
		}
	}
	{on "ground_detonate"
		{call "detonate"}
	}
	{on "contact_detonate"
		{call "detonate"}
	}
	{on "detonate"
		{stuff_detonate}
	}
	{on "fall_down" overload}
	{on blast
		{if min_energy 0.5
			{call "detonate"}
		}
	}
}

{"grenade smoke yellow"
	{on "add_smoke" overload
		{add_view "smoke_yellow_small"	"smoke1" "root"}
		{add_view "smoke_yellow_norm"	"smoke2" "root"}
		{add_view "smoke_yellow_big"	"smoke3" "root"}
	}
}

{"grenade smoke mortar_smoke"
	{on spawn
		{volumes disable touch select}
		{call "activate"}
	}
}

{"molotov_coctail"
	{inflammation_time 2}
	{on spawn
		{volumes "contact" disable contact}	
		{link_sound "fire" "weapon/throw/fire/"}
		{add_view "fire_wick" "wick" "wick" }
	}
	{on "burn_volume"
		{if not "burned"
			{if volume "body"
				{set "burned" 1}
				{burn volume fx "smoke_aero_2_small" time 2 fake even_law}	
				{delay 2 1
					{spawn "glass_hit_bottle" }			
					{spawn "open_fuel_small" }	
					{delete}								
				}
			}
		}
	}
	{on "onThrowActivate"
		{volumes "contact" enable contact}	
		{tags add "activate"}
		{start_sound "weapon/throw/molotov/"}
		{view start "wick"}
		{delay 0.5
			{ani_play "wick" loop}			
			{play_sound "fire" 1}
		}
	}
	{on bullet_hit
		{if rand 0.1
			{fire radius 1.5 time 2 heating 6 effector}
			{spawn "glass_hit_bottle" }			
			{call "detonate"}
		}
		{if tagged "activate" 
			{fire radius 1.5 time 2 heating 6 effector}
			{call "detonate"}
		else
			{if stuff "bullet ic"
				{fire radius 1.5 time 2 heating 6 effector}
				{spawn "glass_hit_bottle" }			
				{call "detonate"}
			else
				{spawn "glass_hit_bottle" }			
				{spawn "open_fuel_small" }			
				{delete}	
			}
		}
	}
	{on blast
		{if min_energy 0.3
			{fire radius 1.5 time 2 heating 6 effector}
			{call "detonate"}
		}
	}
	{on "detonate"
		{fire radius 1.5 time 2 heating 8 effector}
		{start_sound "hit/small/bottle"}
		{stop_sound "fire" }
		{delete}	
	}
	
	{on ground_hit
		{if tagged "activate" 
			{if under_water
				{view pause "wick"}
				{stop_sound "fire" }
			else
				{volumes disable bullet contact blast}
				{set "burned" 1}
				{spawn "ex_molot_ground"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{spawn "ex_molot_fire_impact"}
				{call "detonate"}
			}
		}
	}
	{on contact
		{if tagged "activate" 
			{call "detonate"}
		}
	}
	; {on "ground_detonate"
		; {fire radius 2 time 5}
	; }
	; {on "contact_detonate" overload
		; {if effector "construction"
			; {volumes disable bullet contact blast}
			; {fire radius 1.5 time 2 heating 9 effector}
			; {call "detonate"}
		; else
		; ;	{fire radius 1.5 time 2 heating 20 effector follow}
			; {fire radius 0.7 time 0.7 heating 30 effector}
			; {call "detonate"}
		; }
	; }
}
{"grenade_ph"
	{on spawn
		{impulse up 0.2 dir 2 forward 25 fz 1 com  }
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
		{add_view "smoke_red_small2"		"smoke" "root"}
		{start_sound "weapon/throw/smoke"}
		{link_sound "air" ""}
		{view start "smoke"}
		{volumes disable touch select}
	}
	{on "activate"
		{delay 10
			{play_sound "smoke" }
			{stop_sound "smoke"}
		}
		{delay 14
			{view stop "smoke3"}
			{start_sound "detonation/mortar_incoming"}
			{delay 1.5
				{hide 1}
				{spawn "start_phosphorus"}
			}
		}
	}
	{on ground_hit
		{if not "activated"
			{set "activated" 1}
			{if under_water
				{hide 1}
			else
				{delay 1
					{call "activate"}
				}
			}
		}
	}
	{on contact
		{if not "activated"
			{set "activated" 1}
			{delay 1
				{call "activate"}
			}
		}
	}
}


(define "drop_helpers"
	{"smoke_paradrop_ammo_%tag"
		{on spawn
			{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
			{add_view "smoke_red_small2"		"smoke" "root"}
		}
		{on "onThrow"
			{start_sound "weapon/throw/grenade"}
			{view start "smoke"}
			{volumes disable touch select}
		}
		{on "activate"
			{delay 10
				;{play_sound "smoke" }
				{stop_sound "smoke"}
			}
			{delay 25
				{view stop "smoke"}
				{spawn "military_carepackage_%tag" offset 0 0 2100}
				{hide 1}
			}
		}
		{on ground_hit
			{if not "activated"
				{set "activated" 1}
				{if under_water
					{hide 1}
				else
					{delay 1
						{call "activate"}
					}
				}
			}
		}
		{on contact
			{if not "activated"
				{set "activated" 1}
				{delay 1
					{call "activate"}
				}
			}
		}
	}
)
("drop_helpers" tag(rus))
("drop_helpers" tag(grm))
("drop_helpers" tag(reb))
("drop_helpers" tag(usa))






{"grenade_art"
	{on spawn
		{impulse up 0.2 dir 2 forward 25 fz 1 com  }
		{call "add_smoke"}
		{link_sound "smoke" "detonation/grenade_smoke/smoke_grenade"}
		{add_view "smoke_red_small2"		"smoke" "root"}
		{start_sound "weapon/throw/smoke"}
		{link_sound "air" ""}
		{view start "smoke"}
		{volumes disable touch select}
	}
	{on "activate"
		{delay 10
			{play_sound "smoke" }
			{stop_sound "smoke"}
		}
		{delay 14
			{view stop "smoke3"}
			{delay 1.5
				{hide 1}
				{spawn "start_artilery_spawn" offset 0 0 1600}
			}
		}
	}
	{on ground_hit
		{if not "activated"
			{set "activated" 1}
			{if under_water
				{hide 1}
			else
				{delay 1
					{call "activate"}
				}
			}
		}
	}
	{on contact
		{if not "activated"
			{set "activated" 1}
			{delay 1
				{call "activate"}
			}
		}
	}
}

