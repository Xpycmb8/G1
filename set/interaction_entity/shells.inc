(define "mag_drop_def"
	("mag_drop"  surface("ground") 					sound(carpet) 			vel(1) )
	("mag_drop"  surface("grass") 					sound(grass) 			vel(1) )
	("mag_drop"  surface("road") 					sound(concrete) 		vel(1) )
	("mag_drop"  surface("country_road") 			sound(mud)				vel(1) )
	("mag_drop"  surface("sand") 					sound(sand) 			vel(1) )
	("mag_drop"  surface("snow")  					sound(mud) 				vel(1) )
	("mag_drop"  surface("water") 					sound(water) 			vel(1) )
	("mag_drop"  surface("bridge") 					sound(wood_solid) 		vel(1) )
	("mag_drop"  surface("bridge_wood") 			sound(wood_hollow)		vel(1) )
	("mag_drop"  surface("floor") 					sound(carpet) 			vel(1) )
	("mag_drop"  surface("rock") 					sound(ground)			vel(1) )
	("mag_drop"  surface("metal") 					sound(metal) 			vel(1) )
	("mag_drop"  surface("shoot_emit_mtl")  		sound(metal) 			vel(1) )
	("mag_drop"  surface("shoot_emit_ext_sand")  	sound(sand) 			vel(1) )
	("mag_drop"  surface("shoot_emit_ext")  		sound(grass) 			vel(1) )
	("mag_drop"  surface("shoot_emit_int")  		sound(carpet) 			vel(1) )
	("mag_drop"  surface("shoot_emit_int_wood")  	sound(wood_solid) 		vel(1) )
	("mag_drop"  surface("concrete") 				sound(concrete) 		vel(5) )
	("mag_drop"  surface("steel") 					sound(metal) 			vel(5) )
	("mag_drop"  surface("armor") 					sound(metal) 			vel(5) )
	("mag_drop"  surface("wood") 					sound(wood_hollow)		vel(5) )
	("mag_drop"  surface("misc") 					sound(carpet) 			vel(5) )
)
(define "mag_drop_tags"
	{"%tags"
		{on contact
			(define "mag_drop"
				{with_effector
					{if not "link_weapon"
						{with_effector
							{if not effector "human"
								{if min_speed %vel
									{if material %surface 
										{start_sound "hit/magazine_drops/%sound/%def_sound/"}	
									}
								}
							}
						}
					}
				}
			)
			("mag_drop_def")
		}
		{on ground_hit
			(define "mag_drop"
				{if min_speed %vel
					{if terrain_fx %surface 
						{start_sound "hit/magazine_drops/%sound/%def_sound/"}	;dust hit
					}
				}
				{if terrain_fx "water"
					{view stop "smoke_shell"}
				}
			)
			("mag_drop_def")
		}
	}
)
("mag_drop_tags"  tags(ak_metal_drop) 	def_sound(ak_metal))
("mag_drop_tags"  tags(ak_poly_drop) 	def_sound(ak_poly))
("mag_drop_tags"  tags(ar_metal_drop) 	def_sound(ar_metal))
("mag_drop_tags"  tags(ar_poly_drop) 	def_sound(ar_poly))
("mag_drop_tags"  tags(smg_metal_drop) 	def_sound(smg_metal))
("mag_drop_tags"  tags(smg_poly_drop) 	def_sound(smg_poly))
("mag_drop_tags"  tags(large_drum_drop) def_sound(large_drum))
{"magazine"
	{inflammation_time 10}
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
		{volumes disable contact}
		{delay 1
			{volumes enable contact}
		}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "shell fg"
				{impulse up 4.4 3.2 dir 1 0.5}
			else stuff "rocketlauncher"
				{impulse up 4.9 3.5 dir 5 2.5}
			else stuff "zenite"
				{impulse up 4.4 3.2 dir 1 0.5}
			else stuff "hmgun"
				{impulse up 2.9 1.5 dir 5 2.5}
			else stuff "bullet sm_ic"
				{impulse up 2.7 1.4 dir 3 2.5}
			else stuff "bullet big"
				{impulse up 2.6 1.4 dir 3 2.5}
			else stuff "bullet normal ap"
				{impulse up 2.1 1.1 dir 2 1.5}
			else stuff "bullet normal"
				{impulse up 1.5 0.6 dir 1 0.5}
			else stuff "bullet"
				{impulse up 1.2 0.6 dir 1 0.5}
			}
		}
	}
	{on "blast_physics"
		{if min_energy 15
			{impulse up 9 1 dir 7 2}
		else min_energy 4
			{impulse up 6 1 dir 2 1}
		else min_energy 0.3
			{impulse up 2 1 dir 2 1}
		}
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
		{blastwave c4 0.1 r0 0.1 r1 0.1}		
		{impulse up 0.3 0.2 cx 3 com}
		{spawn "burn_magazine" }
		{delay_effect 0.4 0.1 "explosion_m"}
	}
	{on "_burn"
		{play_sound "small" 1}
		{burn volume fx "fire_magazine" time 20 fake even_law}
		{delay 8 2 
			{call "explosion_m"}
			{delay 18
				{blastwave c4 0.2 r0 0.1 r1 0.2}		
				{impulse up 1.6 cx 4 com}
				{spawn "burn_magazine_end" }
				{stop_sound "small" }
				{delete}
			}
		}
	}
}

{"40mm_base"
	{inflammation_time 3}
	{on spawn
		{link_sound "small"			"fire/drop_magazine"}
	}
	{on contact
		{if rand 0.5
			{if contact_velocity 10
				{if tagged "blasted"
					{volumes disable all }	
					{stuff_detonate}				
				}
			}
		}
		(define "contact_fx"
			{if not effector "human"
				{if volume "m203"
					{if min_speed %2
						{if material %0 
							;{tags add %0 }
							{start_sound "hit/casing/50bmg/%1/"}	
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
		;("contact_fx" args "" 		 					5 )
	}
	{on ground_hit sync
		{if rand 0.5
			{if contact_velocity 10
				{if tagged "blasted"
					{volumes disable all }	
					{stuff_detonate}				
				}
			}
		}
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
	{on blast_hit
		{tags add "blasted"}
		{delay 3
			{tags remove "blasted"}
		}
		{if min_energy 2
			{volumes disable all }	
			{stuff_detonate}	
		}
	}
	{on "burn"
		{if not burned
			{call "burn_volume"}
		}
	}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{burn volume fx "smoke_aero_2_small" time 3 fake even_law}	
			{delay 3 2
				{play_sound "small" 1}
				{burn volume fx "smoke_aero_small" time 4 fake even_law}
				{delay 2.5 2
					{if rand 0.8
						{stuff_detonate}
					else
						{spawn "m203_launch" "m203" x}
						{delete}
					}		
				}
			}
		}
	}
}




{"shell9x19"
	{on spawn
		{if not prop "stuff"
			{volumes disable contact}	;prevent destroing at spawn moment
			{delay 0.6 
				{volumes enable contact }
			}
			{add_view "smoke_smg" "smoke_shell" "basis"}
			{view start "smoke_shell"}
			{delay 1 0.5
				{view stop "smoke_shell"}
			}
		}
	}
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
	;						{if effector "vehicle"
	;							{impulse up 0.2 0.1 cx 1 com}
	;						}
							{if material %0 
	;							{if rand 0.3 
	;								{spawn "spheredust_small_short2" }
	;							else rand 0.1 
	;								{spawn "spheredust_small_short" }
	;							}
								{start_sound "hit/casings/9x19/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
;		{if rand 0.3 
;			{spawn "spheredust_small_short2" }
;		else rand 0.1 
;			{spawn "spheredust_small_short" }
;		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/9x19/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}
{"shell762"
	{on spawn
		{if not prop "stuff"
			{volumes disable all}	
			{delay 0.5 
				{volumes enable contact }
			}
			{add_view "smoke_smg" "smoke_shell" "basis"}
			{view start "smoke_shell"}
			{delay 1 0.5
				{view stop "smoke_shell"}
			}
		}
	}
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "stuff"
						{if min_speed %2
							{if material %0 
								{start_sound "hit/casings/762/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
;		{if rand 0.3 
;			{spawn "spheredust_small_short2" }
;		else rand 0.1 
;			{spawn "spheredust_small_short" }
;		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/762/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}
{"shell556"
	{on spawn
		{if not prop "stuff"
			{volumes disable contact}	;prevent destroing at spawn moment
			{delay 0 
				{volumes enable contact }
			}
			{add_view "smoke_smg" "smoke_shell" "root"}
			{view start "smoke_shell"}
			{delay 1 0.5
				{view stop "smoke_shell"}
			}
		}
	}
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "stuff"
						{if min_speed %2
	;						{if effector "vehicle"
	;							{impulse up 0.2 0.1 cx 1 com}
	;						}
							{if material %0 
	;							{if rand 0.3 
	;								{spawn "spheredust_small_short2" }
	;							else rand 0.1 
	;								{spawn "spheredust_small_short" }
	;							}
								{start_sound "hit/casings/556/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
;		{if rand 0.3 
;			{spawn "spheredust_small_short2" }
;		else rand 0.1 
;			{spawn "spheredust_small_short" }
;		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/556/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}
{"shells_127x99"
	{on spawn	
		{add_view "shell_smoke_fire" "shell_smoke_fire" "shell_smoke"}
		{add_view "smoke_shell_gauge" "smoke_shell" "basis"}
		{volumes disable contact}	;prevent destroing at spawn moment
		{view start "smoke_shell"}
		{delay 0.4 
			{volumes enable contact }
		}
		{delay 3.5 0.5
			{view stop "smoke_shell"}
		}
		{if rand 0.1
			{view start "shell_smoke_fire"}
			{delay 2
				{view stop "shell_smoke_fire"}
			}
		}
	}
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{start_sound "hit/casings/50bmg/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.1 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/50bmg/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}

{"12_gaugehp"
	{on spawn
		{volumes disable contact}	;prevent destroing at spawn moment
		{delay 0
			{volumes enable contact }
		}
		{add_view "smoke_shell_gauge" "smoke_shell" "fxsmoke"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{if rand 0.04 
			{add_view 	"sl_shot2" 	"shot1" "fxsmoke"}
			{view start "shot1"}
			{delay 0.2
				{view pause "shot1"}
			}
		else rand 0.3 
			{delay 0.1
				{spawn "spark_recoil" "fxsmoke" x}
			}
		else rand 0.3 
			{add_view 	"sl_shot3" 	"shot2" "fxsmoke"}
			{view start "shot2"}
			{delay 0.4
				{view pause "shot2"}
			}
		}
	}	
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
	;						{if effector "vehicle"
	;							{impulse up 0.2 0.1 cx 1 com}
	;						}
							{if material %0 
	;							{if rand 0.3 
	;								{spawn "spheredust_small_short2" }
	;							else rand 0.1 
	;								{spawn "spheredust_small_short" }
	;							}
								{start_sound "hit/casings/12gauge/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
;		{if rand 0.3 
;			{spawn "spheredust_small_short2" }
;		else rand 0.1 
;			{spawn "spheredust_small_short" }
;		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/12gauge/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}

{"12_gauge"
	{on spawn
		{delay 0.1
			{volumes disable contact}	;prevent destroing at spawn moment
		}
		{delay 0.4 
			{volumes enable contact }
		}
		{add_view "smoke_smg" "smoke_shell" "basis"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{if rand 0.04 
			{add_view 	"sl_shot2" 	"fraction" "basis"}
			{view start "fraction"}
			{delay 0.2 0.1 "t"
				{view pause "fraction"}
				;{spawn "metal_hit_sl"}
			}
		else rand 0.02 
			{add_view 	"flash_fuse_small" 	"fraction3" "basis"}
			{view start "fraction3"}
			{delay 0.15 0.1 "f"
				{view pause "fraction3"}
			}
		}
	}	
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
	;						{if effector "vehicle"
	;							{impulse up 0.2 0.1 cx 1 com}
	;						}
							{if material %0 
	;							{if rand 0.3 
	;								{spawn "spheredust_small_short2" }
	;							else rand 0.1 
	;								{spawn "spheredust_small_short" }
	;							}
								{start_sound "hit/casings/12gauge/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
;		{if rand 0.3 
;			{spawn "spheredust_small_short2" }
;		else rand 0.1 
;			{spawn "spheredust_small_short" }
;		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/12gauge/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}


{"shells_med"
	{on spawn
		{volumes disable contact}	;prevent destroing at spawn moment
		{delay 0.1 
			{volumes enable contact }
		}
		{add_view "smoke_zenit" "smoke_shell" "fxsmoke"}
		{view start "smoke_shell"}
		{delay 2 0.5
			{view stop "smoke_shell"}
		}
	}
	{on contact
		(define "contact_fx"
			{if not linked
				{if not effector "human"
					{if not effector "shells_guns"
						{if min_speed %2
							{if material %0 
								{start_sound "hit/casings/medium/%1/"}	
							}
						}
					}
				}
			}
		)
		("contact_fx" args "concrete" 	concrete 		5 )
		("contact_fx" args "steel" 		metal 			5 )
		("contact_fx" args "armor" 		metal 			5 )
		("contact_fx" args "wood" 		wood_hollow		5 )
		("contact_fx" args "misc" 		carpet 			5 )
	}
	{on ground_hit
		{if rand 0.1 
			{spawn "spheredust_small_short2" }
		else rand 0.1 
			{spawn "spheredust_small_short" }
		}
		(define "terrain_fx"
			{if min_speed %2
				{if terrain_fx %0 
					{start_sound "hit/casings/medium/%1/"}	
				}
			}
		)
		("terrain_fx" args "ground" 		concrete 		2 	)
		("terrain_fx" args "grass" 			grass 			2 	)
		("terrain_fx" args "road" 			concrete 		2 	)
		("terrain_fx" args "country_road" 	mud 			2 	)
		("terrain_fx" args "sand" 			sand 			2 	)
		("terrain_fx" args "snow"  			mud 			2 	)
		("terrain_fx" args "water" 			water 			2 	)
		("terrain_fx" args "bridge" 		wood_solid 		2   )
		("terrain_fx" args "bridge_wood" 	wood_hollow		2   )
		("terrain_fx" args "floor" 			carpet 			2   )
		("terrain_fx" args "rock" 			concrete 		2   )
		("terrain_fx" args "metal" 			metal 			2   )
		("terrain_fx" args "shoot_emit_mtl" 				metal 			2 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 			2 )
		("terrain_fx" args "shoot_emit_ext" 				grass 			2 )
		("terrain_fx" args "shoot_emit_int" 				carpet 			2 )
		("terrain_fx" args "shoot_emit_int_wood" 			wood_solid 			2 )
	}
}


