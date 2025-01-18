{"glass_frame_engine_new2"
	{on pierce
		{if volume "shard"
			{if rand 0.5
				{spawn	"glass_hit_small" }
				{tear "piece_small_glass" bone from_volume
					{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
				}
			}
		}
	}
}
{"glass_frame_engine_new_simple"
	{on spawn
		{volumes "glass_front_wind_full_damage" disable contact_ground contact blast bullet}
		{volumes "glass_front_wind_full_broken" disable contact_ground contact blast bullet}
		{bone hide	"glass_front_wind_full_damage"}
		{bone hide	"glass_front_wind_full_broken"}
	}
	{on "glass_crack"
		{tags add "glass_crack"}
		{call "glass_crack_loop"}
		{delay 10 6
			{tags remove "glass_crack"}
		}
	}		
	{on "glass_crack_loop"
		{if tagged "glass_crack"
			{start_sound "crush/small/glass_crack"}	
			{delay_effect 4 1 "glass_crack_loop"}
		else
			{kill_delay "glass_crack"}
		}
	}
	{on pierce
		(define "bullet_hit"
			{if stuff %0
				{if volume "glass_front_wind_full"
					{if rand %1
						{if not tagged "damage_glass_front_wind_full"
							{call "glass_crack"}
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							{tags add "damage_glass_front_wind_full"}
							{bone hide "glass_front_wind_full" }
							{bone show "glass_front_wind_full_damage" }
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %3
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{call "glass_crack"}
								{tags add "broken_glass_front_wind_full"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								{bone show "glass_front_wind_full_broken"}
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
							}
						}
					}
				}
				{if rand %1
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{call "glass_crack"}
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
				}
			}
		)
		;                  stuff   		    первичный   вторичный финальный
		("bullet_hit" args "shell"			1 			1 			1	1)
		("bullet_hit" args "heavy_zenite"	1 			1 			1	1)
		("bullet_hit" args "zenite"			0.9 		0.7 		0.5	1)
		("bullet_hit" args "bullet big"		0.7 		0.7 		0.5	0.8)
		("bullet_hit" args "bullet normal"	0.5 		0.4 		0.2	0.4)
		("bullet_hit" args "bullet small"	0.4 		0.3 		0.1	0.3)
	}
	{on contact 		
		{if effector "semtex"	
			{impulse up 2 1 dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}
		}
		{if not effector "obstacle"	
			(define "contact_hit"
				{if effector %0
					{if min_mass 20 
						{if volume "glass_front_wind_full"
							{if rand %1
								{if not tagged "damage_glass_front_wind_full"
									{delay 0
										("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
										{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
										{tags add "damage_glass_front_wind_full"}
										{bone hide "glass_front_wind_full" }
										{bone show "glass_front_wind_full_damage" }
									}
								}
							}
						}
						{if volume "glass_front_wind_full_damage"
							{if rand %3
								{if tagged "damage_glass_front_wind_full"
									{if not tagged "broken_glass_front_wind_full"
										{tags add "broken_glass_front_wind_full"}
										{bone hide "glass_front_wind_full_damage"}
										{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
										{bone show "glass_front_wind_full_broken"}
										("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
									}
								}
							}
						}
						{if rand %1
							{if volume "glass_front_wind"
								{if not tagged "damage_glass_front_wind"
									{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
									{tags add "damage_glass_front_wind"}
									{bone hide "glass_front_wind" }
									{bone show "glass_front_wind_damage" }
								}
							}
						}				
					}
				}
			)
			;                  ------   первичный вторичный финальный
			("contact_hit" args "fraction"	1 	0.7 	1	)
			("contact_hit" args "vehicle"	1 	1 		1	)
			("contact_hit" args "grenade"	0.9 0.7 	0.5	)
			("contact_hit" args "weight"	1 0.9 		0.8	)
			("contact_hit" args "stuff"		0.6 0.3 	0.1	)
		}
	}
	{on blast
		{if min_energy 2
			{if not tagged "break_all_glass"
				{tags add "break_all_glass"}
				;{if volume "inside_blast"
					{call "break_all_glass_expl"}
				;}
			}
		}
		(define "blast_hit"
			{if min_energy %blast
				{if volume "glass_front_wind_full"
					{if rand %first
						{if not tagged "damage_glass_front_wind_full"
							{bone show "glass_front_wind_full_damage" }
							{bone hide "glass_front_wind_full" }
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{tags add "damage_glass_front_wind_full"}
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %end
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{bone show "glass_front_wind_full_broken"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
								{tags add "broken_glass_front_wind_full"}
							}
						}
					}
				}
				{if rand %first
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("blast_hit" blast(6) first(1)     second(1)     end(1)     shard(1))
		("blast_hit" blast(4)  first(0.8)   second(0.7)   end(0.4)   shard(1))
		("blast_hit" blast(2)  first(0.8)   second(0.5)   end(0.3)     shard(1))
		("blast_hit" blast(0.1)  first(0.7)   second(0.1)   end(0.1)   shard(1))
	}
	{on ground_hit 
		(define "ground_hit"
			{if contact_velocity %hit
				{if volume "glass_front_wind_full"
					{if rand %first
						{if not tagged "damage_glass_front_wind_full"
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							{tags add "damage_glass_front_wind_full"}
							{bone hide "glass_front_wind_full" }
							{bone show "glass_front_wind_full_damage" }
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %end
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{tags add "broken_glass_front_wind_full"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								{bone show "glass_front_wind_full_broken"}
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
							}
						}
					}
				}
				{if rand %first
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("ground_hit" hit(30) first(1)     second(1)       end(1)       shard(1))
		("ground_hit" hit(15) first(0.5)   second(0.4)     end(0.2)     shard(1))
		("ground_hit" hit(1) first(0.1)    second(0.1)     end(0.1)     shard(0.5))
	}
	
	{on "hit_all_new_glass"
		{tags remove "glass_crack"}
		{bone show "glass_front_full_broken_bone"}
		{bone hide "glass_front_full_damage_bone"}
		{bone hide "glass_front_wind_full"}
		("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
		("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
	}
	{on "break_all_new_glass"
		{bone cut "glass_front_full_broken_bone"}
		{bone cut "glass_front_full_damage_bone"}
		{bone cut "glass_front_wind_full"}
		("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
		("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
	}
}

{"glass_frame_engine_new"
	{on spawn
		{volumes "glass_front_wind_full_damage" disable contact_ground contact blast bullet}
		{volumes "glass_front_wind_full_broken" disable contact_ground contact blast bullet}
		{volumes "glass_back_damage" disable contact_ground contact blast bullet}
		{volumes "glass_l1_damage" disable contact_ground contact blast bullet}
		{volumes "glass_l2_damage" disable contact_ground contact blast bullet}
		{volumes "glass_l3_damage" disable contact_ground contact blast bullet}
		{volumes "glass_l4_damage" disable contact_ground contact blast bullet}
		{volumes "glass_r1_damage" disable contact_ground contact blast bullet}
		{volumes "glass_r2_damage" disable contact_ground contact blast bullet}
		{volumes "glass_r3_damage" disable contact_ground contact blast bullet}
		{volumes "glass_r4_damage" disable contact_ground contact blast bullet}
		;{ani_play "set_glass" 1 }		
		(define "hide_bone"
			{volumes "glass_%0"  		disable contact_ground contact blast bullet}
			{volumes "glass_back_%0"  	disable contact_ground contact blast bullet}
			{volumes "glass_r_%0"  		disable contact_ground contact blast bullet}
			{volumes "glass_r1_%0" 		disable contact_ground contact blast bullet}
			{volumes "glass_r2_%0" 		disable contact_ground contact blast bullet}
			{volumes "glass_r3_%0" 		disable contact_ground contact blast bullet}
			{volumes "glass_l_%0"  		disable contact_ground contact blast bullet}
			{volumes "glass_l1_%0" 		disable contact_ground contact blast bullet}
			{volumes "glass_l2_%0" 		disable contact_ground contact blast bullet}
			{volumes "glass_l3_%0" 		disable contact_ground contact blast bullet}
			;{bone hide "glass_%0"  }
			;{bone hide "glass_back_%0"  }
			;{bone hide "glass_r_%0"  }
			;{bone hide "glass_r1_%0" }
			;{bone hide "glass_r2_%0" }
			;{bone hide "glass_r3_%0" }
			;{bone hide "glass_l_%0"  }
			;{bone hide "glass_l1_%0" }
			;{bone hide "glass_l2_%0" }
			;{bone hide "glass_l3_%0" }
		)
		("hide_bone" args sharp_00)
		("hide_bone" args sharp_01)
		("hide_bone" args sharp_02)
		("hide_bone" args sharp_03)
		("hide_bone" args sharp_04)
		("hide_bone" args sharp_05)
		("hide_bone" args sharp_06)
		("hide_bone" args sharp_07)
		("hide_bone" args sharp_08)
		("hide_bone" args sharp_09)
		("hide_bone" args sharp_10)
		("hide_bone" args sharp_11)
		("hide_bone" args sharp_12)
		("hide_bone" args sharp_13)
		("hide_bone" args sharp_14)
		("hide_bone" args sharp_15)
		("hide_bone" args sharp_16)
		("hide_bone" args sharp_17)
		("hide_bone" args sharp_18)
		("hide_bone" args sharp_19)
		("hide_bone" args sharp_20)
		("hide_bone" args sharp_21)
		("hide_bone" args sharp_22)
		("hide_bone" args sharp_23)
		("hide_bone" args sharp_24)
		("hide_bone" args sharp_25)
		; {bone hide	"glass_broken"}
		; {bone hide	"glass_damage"}
		; {bone hide	"glass_r1_broken"}
		; {bone hide	"glass_l1_broken"}
		; {bone hide	"glass_r1_damage"}
		; {bone hide	"glass_l1_damage"}
		; {bone hide	"glass_r2_broken"}
		; {bone hide	"glass_l2_broken"}
		; {bone hide	"glass_r2_damage"}
		; {bone hide	"glass_l2_damage"}
		; {bone hide	"glass_r3_broken"}
		; {bone hide	"glass_l3_broken"}
		; {bone hide	"glass_r3_damage"}
		; {bone hide	"glass_l3_damage"}
		; {bone hide	"glass_front_wind_l_broken"}
		; {bone hide	"glass_front_wind_r_broken"}
		; {bone hide	"glass_front_wind_full_damage"}
		; {bone hide	"glass_front_wind_full_broken"}
		; {bone hide	"glass_b_r_broken"}
		; {bone hide	"glass_b_l_broken"}
		; {bone hide	"glass_back_damage"}
		; {bone hide	"glass_back_broken"}
	}
	{on "break_r1"
		{if not tagged "broken_glass_r"
			{tags add "damage_glass_r"}
			{tags add "broken_glass_r"}
			{bone hide "glass_r1_damage"}
			{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
			{bone show "glass_r1_broken"}
			(define "bone_hide"
				{bone hide "%hide"}
				{spawn	"glass_hit_car" "%hide"}
				{bone hide "%hide_damage"}
				{bone show "%hide_broken"}
			)
			("bone_hide" hide(glass_r1) )
			("volume" args "glass_r1_damage" "glass_r1_broken")
			{call "glass_r1_blast"}
		}
		{if not tagged "damage_glass_r1"
			{call "glass_crack"}
			{tags add "damage_glass_r1"}
			{bone hide "glass_r1" }
			{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
			{bone show "glass_r1_damage" }
			("volume" args "glass_r1" "glass_r1_damage")
		}
		{if tagged "damage_glass_r1"
			{if not tagged "broken_glass_r1"
				{tags add "broken_glass_r1"}
				{bone hide "glass_r1_damage"}
				{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
				{bone show "glass_r1_broken"}
				{call "glass_r1_set"}
				("volume" args "glass_r1_damage" "glass_r1_broken")
			}
		}
	}
	{on "break_l1"
		{if not tagged "broken_glass_l1"
			{tags add "damage_glass_l1"}
			{tags add "broken_glass_l1"}
			(define "bone_hide"
				{bone hide "%hide"}
				{spawn	"glass_hit_car" "%hide"}
				{bone hide "%hide_damage"}
				{bone show "%hide_broken"}
			)
			{bone hide "glass_l1_damage"}
			{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
			{bone show "glass_l1_broken"}
			("bone_hide" hide(glass_l1) )
			("volume" args "glass_l1_damage" "glass_l1_broken")
			{call "glass_l1_blast"}
		}
		{if not tagged "damage_glass_l1"
			{call "glass_crack"}
			{tags add "damage_glass_l1"}
			{bone hide "glass_l1" }
			{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
			{bone show "glass_l1_damage" }
			("volume" args "glass_l1" "glass_l1_damage")
		}
		{if tagged "damage_glass_l1"
			{if not tagged "broken_glass_l1"
				{tags add "broken_glass_l1"}
				{bone hide "glass_l1_damage"}
				{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
				{bone show "glass_l1_broken"}
				{call "glass_l1_set"}
				("volume" args "glass_l1_damage" "glass_l1_broken")
			}
		}
	}
	{on "glass_crack"
		{tags add "glass_crack"}
		{call "glass_crack_loop"}
		{delay 10 6
			{tags remove "glass_crack"}
		}
	}		
	{on "glass_crack_loop"
		{if tagged "glass_crack"
			{start_sound "crush/small/glass_crack"}	
			{delay_effect 4 1 "glass_crack_loop"}
		else
			{kill_delay "glass_crack"}
		}
	}

	
	
	{on pierce
		(define "bullet_hit"
			{if stuff "shell"
				{if volume "glass_r1"
					{if not tagged "broken_glass_r"
						{tags add "damage_glass_r"}
						{tags add "broken_glass_r"}
						{bone hide "glass_r1_damage"}
						{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
						{bone show "glass_r1_broken"}
						(define "bone_hide"
							{bone hide "%hide"}
							{spawn	"glass_hit_car" "%hide"}
							{bone hide "%hide_damage"}
							{bone show "%hide_broken"}
						)
						("bone_hide" hide(glass_r1) )
						("volume" args "glass_r1_damage" "glass_r1_broken")
						{call "glass_r1_blast"}
					}
				}
				{if volume "glass_l1"
					{if not tagged "broken_glass_l1"
						{tags add "damage_glass_l1"}
						{tags add "broken_glass_l1"}
						(define "bone_hide"
							{bone hide "%hide"}
							{spawn	"glass_hit_car" "%hide"}
							{bone hide "%hide_damage"}
							{bone show "%hide_broken"}
						)
						{bone hide "glass_l1_damage"}
						{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
						{bone show "glass_l1_broken"}
						("bone_hide" hide(glass_l1) )
						("volume" args "glass_l1_damage" "glass_l1_broken")
						{call "glass_l1_blast"}
					}
				}
			}
			{if stuff %0
				{if volume "glass_back"
					{if rand %1
						{if not tagged "damage_glass_back"
							("volume" args "glass_back" "glass_back_damage")
							{spawn "glass_hit_shrap_small" "glass_back_damage" } ; - new create
							{tags add "damage_glass_back"}
							{bone hide "glass_back" }
							{bone show "glass_back_damage" }
							{call "glass_crack"}
						}
					}
				}
				{if volume "glass_back_damage"
					{if rand %2
						{if tagged "damage_glass_back"
							{if not tagged "broken_glass_back"
								{call "glass_crack"}
								{tags add "broken_glass_back"}
								{bone hide "glass_back_damage"}
								{spawn "glass_hit_shrap_small" "glass_back" } ; - new create
								{bone show "glass_back_broken"}
								{call "glass_back_set"}
								("volume" args "glass_back_damage" "glass_back_broken")
							}
						}
					}
				}
				{if volume "glass_front_wind_full"
					{if rand %1
						{if not tagged "damage_glass_front_wind_full"
							{call "glass_crack"}
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							{tags add "damage_glass_front_wind_full"}
							{bone hide "glass_front_wind_full" }
							{bone show "glass_front_wind_full_damage" }
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %3
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{call "glass_crack"}
								{tags add "broken_glass_front_wind_full"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								{bone show "glass_front_wind_full_broken"}
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
							}
						}
					}
				}
				{if rand %1
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{call "glass_crack"}
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
					{if volume "glass_front_wind_r"
						{if not tagged "damage_glass_front_wind_r"
							{call "glass_crack"}
							{spawn "glass_hit_shrap_small" "glass_front_wind_r" } ; - new create
							{tags add "damage_glass_front_wind_r"}
							{bone hide "glass_front_wind_r" }
							{bone show "glass_front_wind_r_broken" }
						}
					}
					{if volume "glass_front_wind_l"
						{if not tagged "damage_glass_front_wind_l"
							{call "glass_crack"}
							{spawn "glass_hit_shrap_small" "glass_front_wind_l" } ; - new create
							{tags add "damage_glass_front_wind_l"}
							{bone hide "glass_front_wind_l" }
							{bone show "glass_front_wind_l_broken" }
						}
					}
					{if volume "glass"
						{if not tagged "damage_glass"
							{call "glass_crack"}
							{tags add "damage_glass"}							
							{bone hide "glass" }
							{spawn "glass_hit_shrap_small" "glass" } ; - new create
							{bone show "glass_damage" }
							{volumes "glass" disable all}
							{volumes "glass_damage" enable contact_ground contact blast bullet}
						}
					}				
					{if volume "glass_r"
						{if not tagged "damage_glass_r"
							{call "glass_crack"}
							{tags add "damage_glass_r"}
							{bone hide "glass_r" }
							{spawn "glass_hit_shrap_small" "glass_r" } ; - new create
							{bone show "glass_r_damage" }
							{volumes "glass_r" disable all}
							{volumes "glass_r_damage" enable contact_ground contact blast bullet}
						}
					}				
					{if volume "glass_r1"
						{if not tagged "damage_glass_r1"
							{call "glass_crack"}
							{tags add "damage_glass_r1"}
							{bone hide "glass_r1" }
							{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
							{bone show "glass_r1_damage" }
							("volume" args "glass_r1" "glass_r1_damage")
						}
					}				
					{if volume "glass_r2"
						{if not tagged "damage_glass_r2"
							{call "glass_crack"}
							{tags add "damage_glass_r2"}
							{bone hide "glass_r2" }
							{spawn "glass_hit_shrap_small" "glass_r2" } ; - new create
							{bone show "glass_r2_damage" }
							("volume" args "glass_r2" "glass_r2_damage")
						}
					}				
					{if volume "glass_r3"
						{if not tagged "damage_glass_r3"
							{call "glass_crack"}
							{tags add "damage_glass_r3"}
							{bone hide "glass_r3" }
							{spawn "glass_hit_shrap_small" "glass_r3" } ; - new create
							{bone show "glass_r3_damage" }
							("volume" args "glass_r3" "glass_r3_damage")
						}
					}				
					{if volume "glass_l"
						{if not tagged "damage_glass_l"
							{call "glass_crack"}
							{tags add "damage_glass_l"}
							{bone hide "glass_l" }
							{spawn "glass_hit_shrap_small" "glass_l" } ; - new create
							{bone show "glass_l_damage" }
							("volume" args "glass_l" "glass_l_damage")
						}
					}				
					{if volume "glass_l1"
						{if not tagged "damage_glass_l1"
							{call "glass_crack"}
							{tags add "damage_glass_l1"}
							{bone hide "glass_l1" }
							{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
							{bone show "glass_l1_damage" }
							("volume" args "glass_l1" "glass_l1_damage")
						}
					}				
					{if volume "glass_l2"
						{if not tagged "damage_glass_l2"
							{call "glass_crack"}
							{tags add "damage_glass_l2"}
							{bone hide "glass_l2" }
							{spawn "glass_hit_shrap_small" "glass_l2" } ; - new create
							{bone show "glass_l2_damage" }
							("volume" args "glass_l2" "glass_l2_damage")
						}
					}				
					{if volume "glass_l3"
						{if not tagged "damage_glass_l3"
							{call "glass_crack"}
							{tags add "damage_glass_l3"}
							{bone hide "glass_l3" }
							{spawn "glass_hit_shrap_small" "glass_l3" } ; - new create
							{bone show "glass_l3_damage" }
							("volume" args "glass_l3" "glass_l3_damage")
						}
					}				
				}				
				{if rand %2
					{if volume "glass_damage"
						{if tagged "damage_glass"
							{if not tagged "broken_glass"
								{tags add "broken_glass"}
								{bone hide "glass_reinforced" }
								{bone hide "glass_damage"}
								{spawn "glass_hit_shrap_small2" "glass" } ; - new create
								{bone show "glass_broken"}
								{call "glass_set"}
								("volume" args "glass_damage" "glass_broken")
							}
						}
					}
					{if volume "glass_r_damage"
						{if tagged "damage_glass_r"
							{if not tagged "broken_glass_r"
								{tags add "broken_glass_r"}
								{bone hide "glass_r_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r" } ; - new create
								{bone show "glass_r_broken"}
								{call "glass_r_set"}
								("volume" args "glass_r_damage" "glass_r_broken")
							}
						}
					}
					{if volume "glass_r1_damage"
						{if tagged "damage_glass_r1"
							{if not tagged "broken_glass_r1"
								{tags add "broken_glass_r1"}
								{bone hide "glass_r1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
								{bone show "glass_r1_broken"}
								{call "glass_r1_set"}
								("volume" args "glass_r1_damage" "glass_r1_broken")
							}
						}
					}
					{if volume "glass_r2_damage"
						{if tagged "damage_glass_r2"
							{if not tagged "broken_glass_r2"
								{tags add "broken_glass_r2"}
								{bone hide "glass_r2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r2" } ; - new create
								{bone show "glass_r2_broken"}
								{call "glass_r2_set"}
								("volume" args "glass_r2_damage" "glass_r2_broken")
							}
						}
					}
					{if volume "glass_r3_damage"
						{if tagged "damage_glass_r3"
							{if not tagged "broken_glass_r3"
								{tags add "broken_glass_r3"}
								{bone hide "glass_r3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r3" } ; - new create
								{bone show "glass_r3_broken"}
								{call "glass_r3_set"}
								("volume" args "glass_r3_damage" "glass_r3_broken")
							}
						}
					}
					{if volume "glass_l_damage"
						{if tagged "damage_glass_l"
							{if not tagged "broken_glass_l"
								{tags add "broken_glass_l"}
								{bone hide "glass_l_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l" } ; - new create
								{bone show "glass_l_broken"}
								{call "glass_l_set"}
								("volume" args "glass_l_damage" "glass_l_broken")
							}
						}
					}
					{if volume "glass_l1_damage"
						{if tagged "damage_glass_l1"
							{if not tagged "broken_glass_l1"
								{tags add "broken_glass_l1"}
								{bone hide "glass_l1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
								{bone show "glass_l1_broken"}
								{call "glass_l1_set"}
								("volume" args "glass_l1_damage" "glass_l1_broken")
							}
						}
					}
					{if volume "glass_l2_damage"
						{if tagged "damage_glass_l2"
							{if not tagged "broken_glass_l2"
								{tags add "broken_glass_l2"}
								{bone hide "glass_l2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l2" } ; - new create
								{bone show "glass_l2_broken"}
								{call "glass_l2_set"}
								("volume" args "glass_l2_damage" "glass_l2_broken")
							}
						}
					}
					{if volume "glass_l3_damage"
						{if tagged "damage_glass_l3"
							{if not tagged "broken_glass_l3"
								{tags add "broken_glass_l3"}
								{bone hide "glass_l3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l3" } ; - new create
								{bone show "glass_l3_broken"}
								{call "glass_l3_set"}
								("volume" args "glass_l3_damage" "glass_l3_broken")
							}
						}
					}
				}
				{if volume "shard"
					{if rand %3
						{bone hide "glass_reinforced" }
						{spawn "glass_broken_02" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_05" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_06" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_07" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{tear "piece_delete" bone from_volume							
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  stuff   		    первичный   вторичный финальный
		("bullet_hit" args "shell"			1 			1 			1	1)
		("bullet_hit" args "heavy_zenite"	1 			1 			1	1)
		("bullet_hit" args "zenite"			0.9 		0.7 		0.5	1)
		("bullet_hit" args "bullet big"		0.7 		0.7 		0.5	0.8)
		("bullet_hit" args "bullet normal"	0.5 		0.4 		0.2	0.4)
		("bullet_hit" args "bullet small"	0.4 		0.3 		0.1	0.3)
	}
	{on contact 		
		{if effector "semtex"	
			{impulse up 2 1 dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}
		}
		{if not effector "obstacle"	
			(define "contact_hit"
				{if effector %0
					{if volume "glass_back"
						{if rand %1
							{if not tagged "damage_glass_back"
								("volume" args "glass_back" "glass_back_damage")
								{spawn "glass_hit_shrap_small" "glass_back_damage" } ; - new create
								{tags add "damage_glass_back"}
								{bone hide "glass_back" }
								{bone show "glass_back_damage" }
							}
						}
					}
					{if volume "glass_back_damage"
						{if rand %2
							{if tagged "damage_glass_back"
								{if not tagged "broken_glass_back"
									{tags add "broken_glass_back"}
									{bone hide "glass_back_damage"}
									{spawn "glass_hit_shrap_small2" "glass_back" } ; - new create
									{bone show "glass_back_broken"}
									{call "glass_back_set"}
									("volume" args "glass_back_damage" "glass_back_broken")
								}
							}
						}
					}
					{if volume "glass_front_wind_full"
						{if rand %1
							{if not tagged "damage_glass_front_wind_full"
								{delay 0
									("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
									{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
									{tags add "damage_glass_front_wind_full"}
									{bone hide "glass_front_wind_full" }
									{bone show "glass_front_wind_full_damage" }
								}
							}
						}
					}
					{if volume "glass_front_wind_full_damage"
						{if rand %3
							{if tagged "damage_glass_front_wind_full"
								{if not tagged "broken_glass_front_wind_full"
									{tags add "broken_glass_front_wind_full"}
									{bone hide "glass_front_wind_full_damage"}
									{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
									{bone show "glass_front_wind_full_broken"}
									("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
								}
							}
						}
					}
					{if rand %1
						{if volume "glass_front_wind"
							{if not tagged "damage_glass_front_wind"
								{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
								{tags add "damage_glass_front_wind"}
								{bone hide "glass_front_wind" }
								{bone show "glass_front_wind_damage" }
							}
						}
						{if volume "glass_front_wind_r"
							{if not tagged "damage_glass_front_wind_r"
								{spawn "glass_hit_shrap_small" "glass_front_wind_r" } ; - new create
								{tags add "damage_glass_front_wind_r"}
								{bone hide "glass_front_wind_r" }
								{bone show "glass_front_wind_r_broken" }
							}
						}
						{if volume "glass_front_wind_l"
							{if not tagged "damage_glass_front_wind_l"
								{spawn "glass_hit_shrap_small" "glass_front_wind_l" } ; - new create
								{tags add "damage_glass_front_wind_l"}
								{bone hide "glass_front_wind_l" }
								{bone show "glass_front_wind_l_broken" }
							}
						}
						{if volume "glass"
							{if not tagged "damage_glass"
								{tags add "damage_glass"}
								{bone hide "glass" }
								{spawn "glass_hit_shrap_small" "glass" } ; - new create
								{bone show "glass_damage" }
								{volumes "glass" disable all}
								{volumes "glass_damage" enable contact_ground contact blast bullet}
							}
						}				
						{if volume "glass_r"
							{if not tagged "damage_glass_r"
								{tags add "damage_glass_r"}
								{bone hide "glass_r" }
								{spawn "glass_hit_shrap_small" "glass_r" } ; - new create
								{bone show "glass_r_damage" }
								{volumes "glass_r" disable all}
								{volumes "glass_r_damage" enable contact_ground contact blast bullet}
							}
						}				
						{if volume "glass_r1"
							{if not tagged "damage_glass_r1"
								{tags add "damage_glass_r1"}
								{bone hide "glass_r1" }
								{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
								{bone show "glass_r1_damage" }
								("volume" args "glass_r1" "glass_r1_damage")
							}
						}				
						{if volume "glass_r2"
							{if not tagged "damage_glass_r2"
								{tags add "damage_glass_r2"}
								{bone hide "glass_r2" }
								{spawn "glass_hit_shrap_small" "glass_r2" } ; - new create
								{bone show "glass_r2_damage" }
								("volume" args "glass_r2" "glass_r2_damage")
							}
						}				
						{if volume "glass_r3"
							{if not tagged "damage_glass_r3"
								{tags add "damage_glass_r3"}
								{bone hide "glass_r3" }
								{spawn "glass_hit_shrap_small" "glass_r3" } ; - new create
								{bone show "glass_r3_damage" }
								("volume" args "glass_r3" "glass_r3_damage")
							}
						}				
						{if volume "glass_l"
							{if not tagged "damage_glass_l"
								{tags add "damage_glass_l"}
								{bone hide "glass_l" }
								{spawn "glass_hit_shrap_small" "glass_l" } ; - new create
								{bone show "glass_l_damage" }
								("volume" args "glass_l" "glass_l_damage")
							}
						}				
						{if volume "glass_l1"
							{if not tagged "damage_glass_l1"
								{tags add "damage_glass_l1"}
								{bone hide "glass_l1" }
								{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
								{bone show "glass_l1_damage" }
								("volume" args "glass_l1" "glass_l1_damage")
							}
						}				
						{if volume "glass_l2"
							{if not tagged "damage_glass_l2"
								{tags add "damage_glass_l2"}
								{bone hide "glass_l2" }
								{spawn "glass_hit_shrap_small" "glass_l2" } ; - new create
								{bone show "glass_l2_damage" }
								("volume" args "glass_l2" "glass_l2_damage")
							}
						}				
						{if volume "glass_l3"
							{if not tagged "damage_glass_l3"
								{tags add "damage_glass_l3"}
								{bone hide "glass_l3" }
								{spawn "glass_hit_shrap_small" "glass_l3" } ; - new create
								{bone show "glass_l3_damage" }
								("volume" args "glass_l3" "glass_l3_damage")
							}
						}				
					}				
					{if rand %2
						{if volume "glass_damage"
							{if tagged "damage_glass"
								{if not tagged "broken_glass"
									{delay 0
										{bone hide "glass_reinforced" }
										{tags add "broken_glass"}
										{bone hide "glass_damage"}
										{spawn "glass_hit_shrap_small2" "glass" } ; - new create
										{bone show "glass_broken"}
										{call "glass_set"}
										("volume" args "glass_damage" "glass_broken")
									}
								}
							}
						}
						{if volume "glass_r_damage"
							{if tagged "damage_glass_r"
								{if not tagged "broken_glass_r"
									{delay 0
										{tags add "broken_glass_r"}
										{bone hide "glass_r_damage"}
										{spawn "glass_hit_shrap_small2" "glass_r" } ; - new create
										{bone show "glass_r_broken"}
										{call "glass_r_set"}
										("volume" args "glass_r_damage" "glass_r_broken")
									}
								}
							}
						}
						{if volume "glass_r1_damage"
							{if tagged "damage_glass_r1"
								{if not tagged "broken_glass_r1"
									{delay 0
										{tags add "broken_glass_r1"}
										{bone hide "glass_r1_damage"}
										{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
										{bone show "glass_r1_broken"}
										{call "glass_r1_set"}
										("volume" args "glass_r1_damage" "glass_r1_broken")
									}
								}
							}
						}
						{if volume "glass_r2_damage"
							{if tagged "damage_glass_r2"
								{if not tagged "broken_glass_r2"
									{delay 0
										{tags add "broken_glass_r2"}
										{bone hide "glass_r2_damage"}
										{spawn "glass_hit_shrap_small2" "glass_r2" } ; - new create
										{bone show "glass_r2_broken"}
										{call "glass_r2_set"}
										("volume" args "glass_r2_damage" "glass_r2_broken")
									}
								}
							}
						}
						{if volume "glass_r3_damage"
							{if tagged "damage_glass_r3"
								{if not tagged "broken_glass_r3"
									{delay 0
										{tags add "broken_glass_r3"}
										{bone hide "glass_r3_damage"}
										{spawn "glass_hit_shrap_small2" "glass_r3" } ; - new create
										{bone show "glass_r3_broken"}
										{call "glass_r3_set"}
										("volume" args "glass_r3_damage" "glass_r3_broken")
									}
								}
							}
						}
						{if volume "glass_l_damage"
							{if tagged "damage_glass_l"
								{if not tagged "broken_glass_l"
									{delay 0
										{tags add "broken_glass_l"}
										{bone hide "glass_l_damage"}
										{spawn "glass_hit_shrap_small2" "glass_l" } ; - new create
										{bone show "glass_l_broken"}
										{call "glass_l_set"}
										("volume" args "glass_l_damage" "glass_l_broken")
									}
								}
							}
						}
						{if volume "glass_l1_damage"
							{if tagged "damage_glass_l1"
								{if not tagged "broken_glass_l1"
									{delay 0
										{tags add "broken_glass_l1"}
										{bone hide "glass_l1_damage"}
										{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
										{bone show "glass_l1_broken"}
										{call "glass_l1_set"}
										("volume" args "glass_l1_damage" "glass_l1_broken")
									}
								}
							}
						}
						{if volume "glass_l2_damage"
							{if tagged "damage_glass_l2"
								{if not tagged "broken_glass_l2"
									{delay 0
										{tags add "broken_glass_l2"}
										{bone hide "glass_l2_damage"}
										{spawn "glass_hit_shrap_small2" "glass_l2" } ; - new create
										{bone show "glass_l2_broken"}
										{call "glass_l2_set"}
										("volume" args "glass_l2_damage" "glass_l2_broken")
									}
								}
							}
						}
						{if volume "glass_l3_damage"
							{if tagged "damage_glass_l3"
								{if not tagged "broken_glass_l3"
									{delay 0
										{tags add "broken_glass_l3"}
										{bone hide "glass_l3_damage"}
										{spawn "glass_hit_shrap_small2" "glass_l3" } ; - new create
										{bone show "glass_l3_broken"}
										{call "glass_l3_set"}
										("volume" args "glass_l3_damage" "glass_l3_broken")
									}
								}
							}
						}
					}
					{if volume "shard"
						{if min_mass 100 
							{tear "piece_small_glass" bone from_volume
								{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
							}
						else min_mass 10
							{if rand %2
								{tear "piece_small_glass" bone from_volume
									{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
								}
							}
						}
					}
				}
			)
			;                  ------   первичный вторичный финальный
			("contact_hit" args "fraction"	1 	0.7 	1	)
			("contact_hit" args "vehicle"	1 	1 		1	)
			("contact_hit" args "grenade"	0.9 0.7 	0.5	)
			("contact_hit" args "weight"	1 0.9 		0.8	)
			("contact_hit" args "stuff"		0.6 0.3 	0.1	)
		}
	}
	{on blast
		{if min_energy 2
			{if not tagged "break_all_glass"
				;{if volume "inside_blast"
					{tags add "break_all_glass"}
					{call "break_all_glass_expl"}
				;}
			}
		}
		(define "blast_hit"
			{if min_energy %blast
				{if volume "glass_back"
					{if rand %first
						{if not tagged "damage_glass_back"						
							("volume" args "glass_back" "glass_back_damage")
							{spawn "glass_hit_shrap_small" "glass_back_damage" } ; - new create
							{tags add "damage_glass_back"}
							{bone hide "glass_back" }
							{bone show "glass_back_damage" }							
						}
					}
				}
				{if volume "glass_back_damage"
					{if tagged "damage_glass_back"
						{if rand %second
							{if not tagged "broken_glass_back"
								{tags add "broken_glass_back"}
								{bone hide "glass_back_damage"}
								{spawn "glass_hit_shrap_small2" "glass_back" } ; - new create
								{bone show "glass_back_broken"}
								{call "glass_back_set"}
								("volume" args "glass_back_damage" "glass_back_broken")
							}
						}
					}
				}
				{if volume "glass_front_wind_full"
					{if rand %first
						{if not tagged "damage_glass_front_wind_full"
							{bone show "glass_front_wind_full_damage" }
							{bone hide "glass_front_wind_full" }
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{tags add "damage_glass_front_wind_full"}
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %end
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{bone show "glass_front_wind_full_broken"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
								{tags add "broken_glass_front_wind_full"}
							}
						}
					}
				}
				{if rand %first
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
					{if volume "glass_front_wind_r"
						{if not tagged "damage_glass_front_wind_r"
							{spawn "glass_hit_shrap_small" "glass_front_wind_r" } ; - new create
							{tags add "damage_glass_front_wind_r"}
							{bone hide "glass_front_wind_r" }
							{bone show "glass_front_wind_r_broken" }
						}
					}
					{if volume "glass_front_wind_l"
						{if not tagged "damage_glass_front_wind_l"
							{spawn "glass_hit_shrap_small" "glass_front_wind_l" } ; - new create
							{tags add "damage_glass_front_wind_l"}
							{bone hide "glass_front_wind_l" }
							{bone show "glass_front_wind_l_broken" }
						}
					}
					{if volume "glass"
						{if not tagged "damage_glass"
							{tags add "damage_glass"}
							{bone hide "glass" }
							{spawn "glass_hit_shrap_small" "glass" } ; - new create
							{bone show "glass_damage" }
							{volumes "glass" disable all}
							{volumes "glass_damage" enable contact_ground contact blast bullet}
						}
					}				
					{if volume "glass_r"
						{if not tagged "damage_glass_r"
							{tags add "damage_glass_r"}
							{bone hide "glass_r" }
							{spawn "glass_hit_shrap_small" "glass_r" } ; - new create
							{bone show "glass_r_damage" }
							{volumes "glass_r" disable all}
							{volumes "glass_r_damage" enable contact_ground contact blast bullet}
						}
					}				
					{if volume "glass_r1"
						{if not tagged "damage_glass_r1"
							{bone show "glass_r1_damage" }
							{tags add "damage_glass_r1"}
							{bone hide "glass_r1" }
							{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
							("volume" args "glass_r1" "glass_r1_damage")
						}
					}				
					{if volume "glass_r2"
						{if not tagged "damage_glass_r2"
							{bone show "glass_r2_damage" }
							{tags add "damage_glass_r2"}
							{bone hide "glass_r2" }
							{spawn "glass_hit_shrap_small" "glass_r2" } ; - new create
							("volume" args "glass_r2" "glass_r2_damage")
						}
					}				
					{if volume "glass_r3"
						{if not tagged "damage_glass_r3"
							{tags add "damage_glass_r3"}
							{bone hide "glass_r3" }
							{spawn "glass_hit_shrap_small" "glass_r3" } ; - new create
							{bone show "glass_r3_damage" }
							("volume" args "glass_r3" "glass_r3_damage")
						}
					}				
					{if volume "glass_l"
						{if not tagged "damage_glass_l"
							{tags add "damage_glass_l"}
							{bone hide "glass_l" }
							{spawn "glass_hit_shrap_small" "glass_l" } ; - new create
							{bone show "glass_l_damage" }
							("volume" args "glass_l" "glass_l_damage")
						}
					}				
					{if volume "glass_l1"
						{if not tagged "damage_glass_l1"
							{tags add "damage_glass_l1"}
							{bone hide "glass_l1" }
							{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
							{bone show "glass_l1_damage" }
							("volume" args "glass_l1" "glass_l1_damage")
						}
					}				
					{if volume "glass_l2"
						{if not tagged "damage_glass_l2"
							{tags add "damage_glass_l2"}
							{bone hide "glass_l2" }
							{spawn "glass_hit_shrap_small" "glass_l2" } ; - new create
							{bone show "glass_l2_damage" }
							("volume" args "glass_l2" "glass_l2_damage")
						}
					}				
					{if volume "glass_l3"
						{if not tagged "damage_glass_l3"
							{tags add "damage_glass_l3"}
							{bone hide "glass_l3" }
							{spawn "glass_hit_shrap_small" "glass_l3" } ; - new create
							{bone show "glass_l3_damage" }
							("volume" args "glass_l3" "glass_l3_damage")
						}
					}				
				}				
				{if rand %second
					{if volume "glass_damage"
						{if tagged "damage_glass"
							{if not tagged "broken_glass"
								{tags add "broken_glass"}
								{bone hide "glass_damage"}
								{bone hide "glass_reinforced" }
								{spawn "glass_hit_shrap_small2" "glass" } ; - new create
								{bone show "glass_broken"}
								{call "glass_set"}
								("volume" args "glass_damage" "glass_broken")
							}
						}
					}
					{if volume "glass_r_damage"
						{if tagged "damage_glass_r"
							{if not tagged "broken_glass_r"
								{tags add "broken_glass_r"}
								{bone hide "glass_r_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r" } ; - new create
								{bone show "glass_r_broken"}
								{call "glass_r_set"}
								("volume" args "glass_r_damage" "glass_r_broken")
							}
						}
					}
					{if volume "glass_r1_damage"
						{if tagged "damage_glass_r1"
							{if not tagged "broken_glass_r1"
								{tags add "broken_glass_r1"}
								{bone hide "glass_r1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
								{bone show "glass_r1_broken"}
								{call "glass_r1_set"}
								("volume" args "glass_r1_damage" "glass_r1_broken")
							}
						}
					}
					{if volume "glass_r2_damage"
						{if tagged "damage_glass_r2"
							{if not tagged "broken_glass_r2"
								{tags add "broken_glass_r2"}
								{bone hide "glass_r2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r2" } ; - new create
								{bone show "glass_r2_broken"}
								{call "glass_r2_set"}
								("volume" args "glass_r2_damage" "glass_r2_broken")
							}
						}
					}
					{if volume "glass_r3_damage"
						{if tagged "damage_glass_r3"
							{if not tagged "broken_glass_r3"
								{tags add "broken_glass_r3"}
								{bone hide "glass_r3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r3" } ; - new create
								{bone show "glass_r3_broken"}
								{call "glass_r3_set"}
								("volume" args "glass_r3_damage" "glass_r3_broken")
							}
						}
					}
					{if volume "glass_l_damage"
						{if tagged "damage_glass_l"
							{if not tagged "broken_glass_l"
								{tags add "broken_glass_l"}
								{bone hide "glass_l_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l" } ; - new create
								{bone show "glass_l_broken"}
								{call "glass_l_set"}
								("volume" args "glass_l_damage" "glass_l_broken")
							}
						}
					}
					{if volume "glass_l1_damage"
						{if tagged "damage_glass_l1"
							{if not tagged "broken_glass_l1"
								{tags add "broken_glass_l1"}
								{bone hide "glass_l1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
								{bone show "glass_l1_broken"}
								{call "glass_l1_set"}
								("volume" args "glass_l1_damage" "glass_l1_broken")
							}
						}
					}
					{if volume "glass_l2_damage"
						{if tagged "damage_glass_l2"
							{if not tagged "broken_glass_l2"
								{tags add "broken_glass_l2"}
								{bone hide "glass_l2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l2" } ; - new create
								{bone show "glass_l2_broken"}
								{call "glass_l2_set"}
								("volume" args "glass_l2_damage" "glass_l2_broken")
							}
						}
					}
					{if volume "glass_l3_damage"
						{if tagged "damage_glass_l3"
							{if not tagged "broken_glass_l3"
								{tags add "broken_glass_l3"}
								{bone hide "glass_l3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l3" } ; - new create
								{bone show "glass_l3_broken"}
								{call "glass_l3_set"}
								("volume" args "glass_l3_damage" "glass_l3_broken")
							}
						}
					}
				}
				{if volume "shard"
					{if rand %shard
						{spawn "glass_broken_02" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_05" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_06" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{spawn "glass_broken_07" {impulse dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}}
						{tear "piece_delete" bone from_volume							
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("blast_hit" blast(6) first(1)     second(1)     end(1)     shard(1))
		("blast_hit" blast(4)  first(0.8)   second(0.7)   end(0.4)   shard(1))
		("blast_hit" blast(2)  first(0.8)   second(0.5)   end(0.3)     shard(1))
		("blast_hit" blast(0.1)  first(0.7)   second(0.1)   end(0.1)   shard(1))
	}
	{on ground_hit 
		(define "ground_hit"
			{if contact_velocity %hit
				{if volume "glass_back"
					{if rand %first
						{if not tagged "damage_glass_back"
							("volume" args "glass_back" "glass_back_damage")
							{spawn "glass_hit_shrap_small" "glass_back_damage" } ; - new create
							{tags add "damage_glass_back"}
							{bone hide "glass_back" }
							{bone show "glass_back_damage" }
						}
					}
				}
				{if volume "glass_back_damage"
					{if rand %second
						{if tagged "damage_glass_back"
							{if not tagged "broken_glass_back"
								{tags add "broken_glass_back"}
								{bone hide "glass_back_damage"}
								{spawn "glass_hit_car" "glass_back" } ; - new create
								{bone show "glass_back_broken"}
								{call "glass_back_set"}
								("volume" args "glass_back_damage" "glass_back_broken")
							}
						}
					}
				}
				{if volume "glass_front_wind_full"
					{if rand %first
						{if not tagged "damage_glass_front_wind_full"
							("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
							{spawn "glass_hit_shrap_small" "glass_front_wind_full" } ; - new create
							{tags add "damage_glass_front_wind_full"}
							{bone hide "glass_front_wind_full" }
							{bone show "glass_front_wind_full_damage" }
						}
					}
				}
				{if volume "glass_front_wind_full_damage"
					{if rand %end
						{if tagged "damage_glass_front_wind_full"
							{if not tagged "broken_glass_front_wind_full"
								{tags add "broken_glass_front_wind_full"}
								{bone hide "glass_front_wind_full_damage"}
								{spawn "glass_hit_shrap_small2" "glass_front_wind_full_damage" } ; - new create
								{bone show "glass_front_wind_full_broken"}
								("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
							}
						}
					}
				}
				{if rand %first
					{if volume "glass_front_wind"
						{if not tagged "damage_glass_front_wind"
							{spawn "glass_hit_shrap_small" "glass_front_wind" } ; - new create
							{tags add "damage_glass_front_wind"}
							{bone hide "glass_front_wind" }
							{bone show "glass_front_wind_damage" }
						}
					}
					{if volume "glass_front_wind_r"
						{if not tagged "damage_glass_front_wind_r"
							{spawn "glass_hit_shrap_small" "glass_front_wind_r" } ; - new create
							{tags add "damage_glass_front_wind_r"}
							{bone hide "glass_front_wind_r" }
							{bone show "glass_front_wind_r_broken" }
						}
					}
					{if volume "glass_front_wind_l"
						{if not tagged "damage_glass_front_wind_l"
							{spawn "glass_hit_shrap_small" "glass_front_wind_l" } ; - new create
							{tags add "damage_glass_front_wind_l"}
							{bone hide "glass_front_wind_l" }
							{bone show "glass_front_wind_l_broken" }
						}
					}
					{if volume "glass_r"
						{if not tagged "damage_glass_r"
							{tags add "damage_glass_r"}
							{bone hide "glass_r" }
							{spawn "glass_hit_shrap_small" "glass_r" } ; - new create
							{bone show "glass_r_damage" }
							{volumes "glass_r" disable all}
							{volumes "glass_r_damage" enable contact_ground contact blast bullet}
						}
					}				
					{if volume "glass_r1"
						{if not tagged "damage_glass_r1"
							{tags add "damage_glass_r1"}
							{bone hide "glass_r1" }
							{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
							{bone show "glass_r1_damage" }
							("volume" args "glass_r1" "glass_r1_damage")
						}
					}				
					{if volume "glass_r2"
						{if not tagged "damage_glass_r2"
							{tags add "damage_glass_r2"}
							{bone hide "glass_r2" }
							{spawn "glass_hit_shrap_small" "glass_r2" } ; - new create
							{bone show "glass_r2_damage" }
							("volume" args "glass_r2" "glass_r2_damage")
						}
					}				
					{if volume "glass_r3"
						{if not tagged "damage_glass_r3"
							{tags add "damage_glass_r3"}
							{bone hide "glass_r3" }
							{spawn "glass_hit_shrap_small" "glass_r3" } ; - new create
							{bone show "glass_r3_damage" }
							("volume" args "glass_r3" "glass_r3_damage")
						}
					}				
					{if volume "glass_l"
						{if not tagged "damage_glass_l"
							{tags add "damage_glass_l"}
							{bone hide "glass_l" }
							{spawn "glass_hit_shrap_small" "glass_l" } ; - new create
							{bone show "glass_l_damage" }
							("volume" args "glass_l" "glass_l_damage")
						}
					}				
					{if volume "glass_l1"
						{if not tagged "damage_glass_l1"
							{tags add "damage_glass_l1"}
							{bone hide "glass_l1" }
							{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
							{bone show "glass_l1_damage" }
							("volume" args "glass_l1" "glass_l1_damage")
						}
					}				
					{if volume "glass_l2"
						{if not tagged "damage_glass_l2"
							{tags add "damage_glass_l2"}
							{bone hide "glass_l2" }
							{spawn "glass_hit_shrap_small" "glass_l2" } ; - new create
							{bone show "glass_l2_damage" }
							("volume" args "glass_l2" "glass_l2_damage")
						}
					}				
					{if volume "glass_l3"
						{if not tagged "damage_glass_l3"
							{tags add "damage_glass_l3"}
							{bone hide "glass_l3" }
							{spawn "glass_hit_shrap_small" "glass_l3" } ; - new create
							{bone show "glass_l3_damage" }
							("volume" args "glass_l3" "glass_l3_damage")
						}
					}				
				}				
				{if rand %second
					{if volume "glass_r_damage"
						{if tagged "damage_glass_r"
							{if not tagged "broken_glass_r"
								{tags add "broken_glass_r"}
								{bone hide "glass_r_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r" } ; - new create
								{bone show "glass_r_broken"}
								{call "glass_r_set"}
								("volume" args "glass_r_damage" "glass_r_broken")
							}
						}
					}
					{if volume "glass_r1_damage"
						{if tagged "damage_glass_r1"
							{if not tagged "broken_glass_r1"
								{tags add "broken_glass_r1"}
								{bone hide "glass_r1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
								{bone show "glass_r1_broken"}
								{call "glass_r1_set"}
								("volume" args "glass_r1_damage" "glass_r1_broken")
							}
						}
					}
					{if volume "glass_r2_damage"
						{if tagged "damage_glass_r2"
							{if not tagged "broken_glass_r2"
								{tags add "broken_glass_r2"}
								{bone hide "glass_r2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r2" } ; - new create
								{bone show "glass_r2_broken"}
								{call "glass_r2_set"}
								("volume" args "glass_r2_damage" "glass_r2_broken")
							}
						}
					}
					{if volume "glass_r3_damage"
						{if tagged "damage_glass_r3"
							{if not tagged "broken_glass_r3"
								{tags add "broken_glass_r3"}
								{bone hide "glass_r3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_r3" } ; - new create
								{bone show "glass_r3_broken"}
								{call "glass_r3_set"}
								("volume" args "glass_r3_damage" "glass_r3_broken")
							}
						}
					}
					{if volume "glass_l_damage"
						{if tagged "damage_glass_l"
							{if not tagged "broken_glass_l"
								{tags add "broken_glass_l"}
								{bone hide "glass_l_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l" } ; - new create
								{bone show "glass_l_broken"}
								{call "glass_l_set"}
								("volume" args "glass_l_damage" "glass_l_broken")
							}
						}
					}
					{if volume "glass_l1_damage"
						{if tagged "damage_glass_l1"
							{if not tagged "broken_glass_l1"
								{tags add "broken_glass_l1"}
								{bone hide "glass_l1_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
								{bone show "glass_l1_broken"}
								{call "glass_l1_set"}
								("volume" args "glass_l1_damage" "glass_l1_broken")
							}
						}
					}
					{if volume "glass_l2_damage"
						{if tagged "damage_glass_l2"
							{if not tagged "broken_glass_l2"
								{tags add "broken_glass_l2"}
								{bone hide "glass_l2_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l2" } ; - new create
								{bone show "glass_l2_broken"}
								{call "glass_l2_set"}
								("volume" args "glass_l2_damage" "glass_l2_broken")
							}
						}
					}
					{if volume "glass_l3_damage"
						{if tagged "damage_glass_l3"
							{if not tagged "broken_glass_l3"
								{tags add "broken_glass_l3"}
								{bone hide "glass_l3_damage"}
								{spawn "glass_hit_shrap_small2" "glass_l3" } ; - new create
								{bone show "glass_l3_broken"}
								{call "glass_l3_set"}
								("volume" args "glass_l3_damage" "glass_l3_broken")
							}
						}
					}
				}
				{if volume "shard"
					{if rand %shard
						{tear "piece_small_glass" bone from_volume
							{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("ground_hit" hit(30) first(1)     second(1)       end(1)       shard(1))
		("ground_hit" hit(15) first(0.5)   second(0.4)     end(0.2)     shard(1))
		("ground_hit" hit(1) first(0.1)    second(0.1)     end(0.1)     shard(0.5))
	}
	
	{on "hit_all_new_glass"
		{tags remove "glass_crack"}
		{bone show "glass_front_full_broken_bone"}
		{bone hide "glass_front_full_damage_bone"}
		{bone hide "glass_front_wind_full"}
		(define "bone_hide"
			{bone hide "%hide"}
			{spawn	"glass_hit_car" "%hide"}
			{bone hide "%hide_damage"}
			{bone show "%hide_broken"}
		)
		("bone_hide" hide(glass_l) )
		("bone_hide" hide(glass_l1) )
		("bone_hide" hide(glass_l2) )
		("bone_hide" hide(glass_l3) )
		("bone_hide" hide(glass_r) )
		("bone_hide" hide(glass_r1) )
		("bone_hide" hide(glass_r2) )
		("bone_hide" hide(glass_r3) )
		("bone_hide" hide(glass_back) )
		("volume" args "glass_l_damage" "glass_l_broken")
		("volume" args "glass_l1_damage" "glass_l1_broken")
		("volume" args "glass_l2_damage" "glass_l2_broken")
		("volume" args "glass_l3_damage" "glass_l3_broken")
		("volume" args "glass_r_damage" "glass_r_broken")
		("volume" args "glass_r1_damage" "glass_r1_broken")
		("volume" args "glass_r2_damage" "glass_r2_broken")
		("volume" args "glass_r3_damage" "glass_r3_broken")
		("volume" args "glass_back_damage" "glass_back_broken")
		("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
		("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
		{call "glass_back_blast"}
		{call "glass_l_blast"}
		{call "glass_l1_blast"}
		{call "glass_l2_blast"}
		{call "glass_l3_blast"}
		{call "glass_r_blast"}
		{call "glass_r1_blast"}
		{call "glass_r2_blast"}
		{call "glass_r3_blast"}
	}
	{on "break_all_new_glass"
		{if not tagged "exploded_glass"
			{tags add "exploded_glass"}
			{bone cut "glass_front_full_broken_bone"}
			{bone cut "glass_front_full_damage_bone"}
			{bone cut "glass_front_wind_full"}
			(define "bone_hide"
				{bone cut "%hide"}
				{bone cut "%hide_damage"}
				{bone show "%hide_broken"}
			)
			("bone_hide" hide(glass_l) )
			("bone_hide" hide(glass_l1) )
			("bone_hide" hide(glass_l2) )
			("bone_hide" hide(glass_l3) )
			("bone_hide" hide(glass_r) )
			("bone_hide" hide(glass_r1) )
			("bone_hide" hide(glass_r2) )
			("bone_hide" hide(glass_r3) )
			("bone_hide" hide(glass_back) )
			("volume" args "glass_l_damage" "glass_l_broken")
			("volume" args "glass_l1_damage" "glass_l1_broken")
			("volume" args "glass_l2_damage" "glass_l2_broken")
			("volume" args "glass_l3_damage" "glass_l3_broken")
			("volume" args "glass_r_damage" "glass_l_broken")
			("volume" args "glass_r1_damage" "glass_r1_broken")
			("volume" args "glass_r2_damage" "glass_r2_broken")
			("volume" args "glass_r3_damage" "glass_r3_broken")
			("volume" args "glass_back_damage" "glass_back_broken")
			("volume" args "glass_front_wind_full_damage" "glass_front_wind_full_broken")
			("volume" args "glass_front_wind_full" "glass_front_wind_full_damage")
			{call "glass_back_blast"}
			{call "glass_l_blast"}
			{call "glass_l1_blast"}
			{call "glass_l2_blast"}
			{call "glass_l3_blast"}
			{call "glass_r_blast"}
			{call "glass_r1_blast"}
			{call "glass_r2_blast"}
			{call "glass_r3_blast"}
		}
	}
	{on "glass_set"
		{bone show "glass_sharp_00"}
		{bone show "glass_sharp_01"}
		{bone show "glass_sharp_02"}
		{bone show "glass_sharp_03"}
		{bone show "glass_sharp_04"}
		{bone show "glass_sharp_05"}
		{bone show "glass_sharp_06"}
		{bone show "glass_sharp_07"}
		{bone show "glass_sharp_08"}
		{bone show "glass_sharp_09"}
		{bone show "glass_sharp_10"}
		{bone show "glass_sharp_11"}
		{bone show "glass_sharp_12"}
		{bone show "glass_sharp_13"}
		{bone show "glass_sharp_14"}
		{bone show "glass_sharp_15"}
		{bone show "glass_sharp_16"}
		{bone show "glass_sharp_17"}
		{bone show "glass_sharp_18"}
		{bone show "glass_sharp_19"}
		{bone show "glass_sharp_20"}
		{bone show "glass_sharp_21"}
		{bone show "glass_sharp_22"}
		{bone show "glass_sharp_23"}
		{bone show "glass_sharp_24"}
		{bone show "glass_sharp_25"}
		{volumes "glass_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_back_set"
		{bone show "glass_back_sharp_00"}
		{bone show "glass_back_sharp_01"}
		{bone show "glass_back_sharp_02"}
		{bone show "glass_back_sharp_03"}
		{bone show "glass_back_sharp_04"}
		{bone show "glass_back_sharp_05"}
		{bone show "glass_back_sharp_06"}
		{bone show "glass_back_sharp_07"}
		{bone show "glass_back_sharp_08"}
		{bone show "glass_back_sharp_09"}
		{bone show "glass_back_sharp_10"}
		{bone show "glass_back_sharp_11"}
		{bone show "glass_back_sharp_12"}
		{bone show "glass_back_sharp_13"}
		{bone show "glass_back_sharp_14"}
		{bone show "glass_back_sharp_15"}
		{bone show "glass_back_sharp_16"}
		{bone show "glass_back_sharp_17"}
		{bone show "glass_back_sharp_18"}
		{bone show "glass_back_sharp_19"}
		{bone show "glass_back_sharp_20"}
		{bone show "glass_back_sharp_21"}
		{bone show "glass_back_sharp_22"}
		{bone show "glass_back_sharp_23"}
		{bone show "glass_back_sharp_24"}
		{bone show "glass_back_sharp_25"}
		{volumes "glass_back_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_back_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_l_set"
		{bone show "glass_l_sharp_00"}
		{bone show "glass_l_sharp_01"}
		{bone show "glass_l_sharp_02"}
		{bone show "glass_l_sharp_03"}
		{bone show "glass_l_sharp_04"}
		{bone show "glass_l_sharp_05"}
		{bone show "glass_l_sharp_06"}
		{bone show "glass_l_sharp_07"}
		{bone show "glass_l_sharp_08"}
		{bone show "glass_l_sharp_09"}
		{bone show "glass_l_sharp_10"}
		{bone show "glass_l_sharp_11"}
		{bone show "glass_l_sharp_12"}
		{bone show "glass_l_sharp_13"}
		{bone show "glass_l_sharp_14"}
		{bone show "glass_l_sharp_15"}
		{bone show "glass_l_sharp_16"}
		{bone show "glass_l_sharp_17"}
		{bone show "glass_l_sharp_18"}
		{bone show "glass_l_sharp_19"}
		{bone show "glass_l_sharp_20"}
		{bone show "glass_l_sharp_21"}
		{bone show "glass_l_sharp_22"}
		{bone show "glass_l_sharp_23"}
		{bone show "glass_l_sharp_24"}
		{bone show "glass_l_sharp_25"}
		{volumes "glass_l_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_l_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_r_set"
		{bone show "glass_r_sharp_00"}
		{bone show "glass_r_sharp_01"}
		{bone show "glass_r_sharp_02"}
		{bone show "glass_r_sharp_03"}
		{bone show "glass_r_sharp_04"}
		{bone show "glass_r_sharp_05"}
		{bone show "glass_r_sharp_06"}
		{bone show "glass_r_sharp_07"}
		{bone show "glass_r_sharp_08"}
		{bone show "glass_r_sharp_09"}
		{bone show "glass_r_sharp_10"}
		{bone show "glass_r_sharp_11"}
		{bone show "glass_r_sharp_12"}
		{bone show "glass_r_sharp_13"}
		{bone show "glass_r_sharp_14"}
		{bone show "glass_r_sharp_15"}
		{bone show "glass_r_sharp_16"}
		{bone show "glass_r_sharp_17"}
		{bone show "glass_r_sharp_18"}
		{bone show "glass_r_sharp_19"}
		{bone show "glass_r_sharp_20"}
		{bone show "glass_r_sharp_21"}
		{bone show "glass_r_sharp_22"}
		{bone show "glass_r_sharp_23"}
		{bone show "glass_r_sharp_24"}
		{bone show "glass_r_sharp_25"}
		{volumes "glass_r_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_r_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_l1_set"
		{bone show "glass_l1_sharp_00"}
		{bone show "glass_l1_sharp_01"}
		{bone show "glass_l1_sharp_02"}
		{bone show "glass_l1_sharp_03"}
		{bone show "glass_l1_sharp_04"}
		{bone show "glass_l1_sharp_05"}
		{bone show "glass_l1_sharp_06"}
		{bone show "glass_l1_sharp_07"}
		{bone show "glass_l1_sharp_08"}
		{bone show "glass_l1_sharp_09"}
		{bone show "glass_l1_sharp_10"}
		{bone show "glass_l1_sharp_11"}
		{bone show "glass_l1_sharp_12"}
		{bone show "glass_l1_sharp_13"}
		{bone show "glass_l1_sharp_14"}
		{bone show "glass_l1_sharp_15"}
		{bone show "glass_l1_sharp_16"}
		{bone show "glass_l1_sharp_17"}
		{bone show "glass_l1_sharp_18"}
		{bone show "glass_l1_sharp_19"}
		{bone show "glass_l1_sharp_20"}
		{bone show "glass_l1_sharp_21"}
		{bone show "glass_l1_sharp_22"}
		{bone show "glass_l1_sharp_23"}
		{bone show "glass_l1_sharp_24"}
		{bone show "glass_l1_sharp_25"}
	}
	{on "glass_r1_set"
		{bone show "glass_r1_sharp_00"}
		{bone show "glass_r1_sharp_01"}
		{bone show "glass_r1_sharp_02"}
		{bone show "glass_r1_sharp_03"}
		{bone show "glass_r1_sharp_04"}
		{bone show "glass_r1_sharp_05"}
		{bone show "glass_r1_sharp_06"}
		{bone show "glass_r1_sharp_07"}
		{bone show "glass_r1_sharp_08"}
		{bone show "glass_r1_sharp_09"}
		{bone show "glass_r1_sharp_10"}
		{bone show "glass_r1_sharp_11"}
		{bone show "glass_r1_sharp_12"}
		{bone show "glass_r1_sharp_13"}
		{bone show "glass_r1_sharp_14"}
		{bone show "glass_r1_sharp_15"}
		{bone show "glass_r1_sharp_16"}
		{bone show "glass_r1_sharp_17"}
		{bone show "glass_r1_sharp_18"}
		{bone show "glass_r1_sharp_19"}
		{bone show "glass_r1_sharp_20"}
		{bone show "glass_r1_sharp_21"}
		{bone show "glass_r1_sharp_22"}
		{bone show "glass_r1_sharp_23"}
		{bone show "glass_r1_sharp_24"}
		{bone show "glass_r1_sharp_25"}
		{volumes "glass_r1_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_r1_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_l2_set"
		{bone show "glass_l2_sharp_00"}
		{bone show "glass_l2_sharp_01"}
		{bone show "glass_l2_sharp_02"}
		{bone show "glass_l2_sharp_03"}
		{bone show "glass_l2_sharp_04"}
		{bone show "glass_l2_sharp_05"}
		{bone show "glass_l2_sharp_06"}
		{bone show "glass_l2_sharp_07"}
		{bone show "glass_l2_sharp_08"}
		{bone show "glass_l2_sharp_09"}
		{bone show "glass_l2_sharp_10"}
		{bone show "glass_l2_sharp_11"}
		{bone show "glass_l2_sharp_12"}
		{bone show "glass_l2_sharp_13"}
		{bone show "glass_l2_sharp_14"}
		{bone show "glass_l2_sharp_15"}
		{bone show "glass_l2_sharp_16"}
		{bone show "glass_l2_sharp_17"}
		{bone show "glass_l2_sharp_18"}
		{bone show "glass_l2_sharp_19"}
		{bone show "glass_l2_sharp_20"}
		{bone show "glass_l2_sharp_21"}
		{bone show "glass_l2_sharp_22"}
		{bone show "glass_l2_sharp_23"}
		{bone show "glass_l2_sharp_24"}
		{bone show "glass_l2_sharp_25"}
		{volumes "glass_l2_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_l2_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_r2_set"
		{bone show "glass_r2_sharp_00"}
		{bone show "glass_r2_sharp_01"}
		{bone show "glass_r2_sharp_02"}
		{bone show "glass_r2_sharp_03"}
		{bone show "glass_r2_sharp_04"}
		{bone show "glass_r2_sharp_05"}
		{bone show "glass_r2_sharp_06"}
		{bone show "glass_r2_sharp_07"}
		{bone show "glass_r2_sharp_08"}
		{bone show "glass_r2_sharp_09"}
		{bone show "glass_r2_sharp_10"}
		{bone show "glass_r2_sharp_11"}
		{bone show "glass_r2_sharp_12"}
		{bone show "glass_r2_sharp_13"}
		{bone show "glass_r2_sharp_14"}
		{bone show "glass_r2_sharp_15"}
		{bone show "glass_r2_sharp_16"}
		{bone show "glass_r2_sharp_17"}
		{bone show "glass_r2_sharp_18"}
		{bone show "glass_r2_sharp_19"}
		{bone show "glass_r2_sharp_20"}
		{bone show "glass_r2_sharp_21"}
		{bone show "glass_r2_sharp_22"}
		{bone show "glass_r2_sharp_23"}
		{bone show "glass_r2_sharp_24"}
		{bone show "glass_r2_sharp_25"}
		{volumes "glass_r2_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_r2_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_l3_set"
		{bone show "glass_l3_sharp_00"}
		{bone show "glass_l3_sharp_01"}
		{bone show "glass_l3_sharp_02"}
		{bone show "glass_l3_sharp_03"}
		{bone show "glass_l3_sharp_04"}
		{bone show "glass_l3_sharp_05"}
		{bone show "glass_l3_sharp_06"}
		{bone show "glass_l3_sharp_07"}
		{bone show "glass_l3_sharp_08"}
		{bone show "glass_l3_sharp_09"}
		{bone show "glass_l3_sharp_10"}
		{bone show "glass_l3_sharp_11"}
		{bone show "glass_l3_sharp_12"}
		{bone show "glass_l3_sharp_13"}
		{bone show "glass_l3_sharp_14"}
		{bone show "glass_l3_sharp_15"}
		{bone show "glass_l3_sharp_16"}
		{bone show "glass_l3_sharp_17"}
		{bone show "glass_l3_sharp_18"}
		{bone show "glass_l3_sharp_19"}
		{bone show "glass_l3_sharp_20"}
		{bone show "glass_l3_sharp_21"}
		{bone show "glass_l3_sharp_22"}
		{bone show "glass_l3_sharp_23"}
		{bone show "glass_l3_sharp_24"}
		{bone show "glass_l3_sharp_25"}
		{volumes "glass_l3_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_l3_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_r3_set"
		{bone show "glass_r3_sharp_00"}
		{bone show "glass_r3_sharp_01"}
		{bone show "glass_r3_sharp_02"}
		{bone show "glass_r3_sharp_03"}
		{bone show "glass_r3_sharp_04"}
		{bone show "glass_r3_sharp_05"}
		{bone show "glass_r3_sharp_06"}
		{bone show "glass_r3_sharp_07"}
		{bone show "glass_r3_sharp_08"}
		{bone show "glass_r3_sharp_09"}
		{bone show "glass_r3_sharp_10"}
		{bone show "glass_r3_sharp_11"}
		{bone show "glass_r3_sharp_12"}
		{bone show "glass_r3_sharp_13"}
		{bone show "glass_r3_sharp_14"}
		{bone show "glass_r3_sharp_15"}
		{bone show "glass_r3_sharp_16"}
		{bone show "glass_r3_sharp_17"}
		{bone show "glass_r3_sharp_18"}
		{bone show "glass_r3_sharp_19"}
		{bone show "glass_r3_sharp_20"}
		{bone show "glass_r3_sharp_21"}
		{bone show "glass_r3_sharp_22"}
		{bone show "glass_r3_sharp_23"}
		{bone show "glass_r3_sharp_24"}
		{bone show "glass_r3_sharp_25"}
		{volumes "glass_r3_sharp_00" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_01" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_02" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_03" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_04" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_05" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_06" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_07" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_08" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_09" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_10" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_11" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_12" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_13" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_14" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_15" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_16" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_17" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_18" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_19" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_20" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_21" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_22" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_23" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_24" enable contact_ground contact blast bullet}
		{volumes "glass_r3_sharp_25" enable contact_ground contact blast bullet}
	}
	{on "glass_back_blast"
		{bone cut "glass_back_sharp_00"}
		{bone cut "glass_back_sharp_01"}
		{bone cut "glass_back_sharp_02"}
		{bone cut "glass_back_sharp_03"}
		{bone cut "glass_back_sharp_04"}
		{bone cut "glass_back_sharp_05"}
		{bone cut "glass_back_sharp_06"}
		{bone cut "glass_back_sharp_07"}
		{bone cut "glass_back_sharp_08"}
		{bone cut "glass_back_sharp_09"}
		{bone cut "glass_back_sharp_10"}
		{bone cut "glass_back_sharp_11"}
		{bone cut "glass_back_sharp_12"}
		{bone cut "glass_back_sharp_13"}
		{bone cut "glass_back_sharp_14"}
		{bone cut "glass_back_sharp_15"}
		{bone cut "glass_back_sharp_16"}
		{bone cut "glass_back_sharp_17"}
		{bone cut "glass_back_sharp_18"}
		{bone cut "glass_back_sharp_19"}
		{bone cut "glass_back_sharp_20"}
		{bone cut "glass_back_sharp_21"}
		{bone cut "glass_back_sharp_22"}
		{bone cut "glass_back_sharp_23"}
		{bone cut "glass_back_sharp_24"}
		{bone cut "glass_back_sharp_25"}
		{volumes "glass_back_sharp_00" disable all}
		{volumes "glass_back_sharp_01" disable all}
		{volumes "glass_back_sharp_02" disable all}
		{volumes "glass_back_sharp_03" disable all}
		{volumes "glass_back_sharp_04" disable all}
		{volumes "glass_back_sharp_05" disable all}
		{volumes "glass_back_sharp_06" disable all}
		{volumes "glass_back_sharp_07" disable all}
		{volumes "glass_back_sharp_08" disable all}
		{volumes "glass_back_sharp_09" disable all}
		{volumes "glass_back_sharp_10" disable all}
		{volumes "glass_back_sharp_11" disable all}
		{volumes "glass_back_sharp_12" disable all}
		{volumes "glass_back_sharp_13" disable all}
		{volumes "glass_back_sharp_14" disable all}
		{volumes "glass_back_sharp_15" disable all}
		{volumes "glass_back_sharp_16" disable all}
		{volumes "glass_back_sharp_17" disable all}
		{volumes "glass_back_sharp_18" disable all}
		{volumes "glass_back_sharp_19" disable all}
		{volumes "glass_back_sharp_20" disable all}
		{volumes "glass_back_sharp_21" disable all}
		{volumes "glass_back_sharp_22" disable all}
		{volumes "glass_back_sharp_23" disable all}
		{volumes "glass_back_sharp_24" disable all}
		{volumes "glass_back_sharp_25" disable all}
	}
	{on "glass_l_blast"
		{bone cut "glass_l_sharp_00"}
		{bone cut "glass_l_sharp_01"}
		{bone cut "glass_l_sharp_02"}
		{bone cut "glass_l_sharp_03"}
		{bone cut "glass_l_sharp_04"}
		{bone cut "glass_l_sharp_05"}
		{bone cut "glass_l_sharp_06"}
		{bone cut "glass_l_sharp_07"}
		{bone cut "glass_l_sharp_08"}
		{bone cut "glass_l_sharp_09"}
		{bone cut "glass_l_sharp_10"}
		{bone cut "glass_l_sharp_11"}
		{bone cut "glass_l_sharp_12"}
		{bone cut "glass_l_sharp_13"}
		{bone cut "glass_l_sharp_14"}
		{bone cut "glass_l_sharp_15"}
		{bone cut "glass_l_sharp_16"}
		{bone cut "glass_l_sharp_17"}
		{bone cut "glass_l_sharp_18"}
		{bone cut "glass_l_sharp_19"}
		{bone cut "glass_l_sharp_20"}
		{bone cut "glass_l_sharp_21"}
		{bone cut "glass_l_sharp_22"}
		{bone cut "glass_l_sharp_23"}
		{bone cut "glass_l_sharp_24"}
		{bone cut "glass_l_sharp_25"}
		{volumes "glass_l_sharp_00" disable all}
		{volumes "glass_l_sharp_01" disable all}
		{volumes "glass_l_sharp_02" disable all}
		{volumes "glass_l_sharp_03" disable all}
		{volumes "glass_l_sharp_04" disable all}
		{volumes "glass_l_sharp_05" disable all}
		{volumes "glass_l_sharp_06" disable all}
		{volumes "glass_l_sharp_07" disable all}
		{volumes "glass_l_sharp_08" disable all}
		{volumes "glass_l_sharp_09" disable all}
		{volumes "glass_l_sharp_10" disable all}
		{volumes "glass_l_sharp_11" disable all}
		{volumes "glass_l_sharp_12" disable all}
		{volumes "glass_l_sharp_13" disable all}
		{volumes "glass_l_sharp_14" disable all}
		{volumes "glass_l_sharp_15" disable all}
		{volumes "glass_l_sharp_16" disable all}
		{volumes "glass_l_sharp_17" disable all}
		{volumes "glass_l_sharp_18" disable all}
		{volumes "glass_l_sharp_19" disable all}
		{volumes "glass_l_sharp_20" disable all}
		{volumes "glass_l_sharp_21" disable all}
		{volumes "glass_l_sharp_22" disable all}
		{volumes "glass_l_sharp_23" disable all}
		{volumes "glass_l_sharp_24" disable all}
		{volumes "glass_l_sharp_25" disable all}
	}
	{on "glass_r_blast"
		{bone cut "glass_r_sharp_00"}
		{bone cut "glass_r_sharp_01"}
		{bone cut "glass_r_sharp_02"}
		{bone cut "glass_r_sharp_03"}
		{bone cut "glass_r_sharp_04"}
		{bone cut "glass_r_sharp_05"}
		{bone cut "glass_r_sharp_06"}
		{bone cut "glass_r_sharp_07"}
		{bone cut "glass_r_sharp_08"}
		{bone cut "glass_r_sharp_09"}
		{bone cut "glass_r_sharp_10"}
		{bone cut "glass_r_sharp_11"}
		{bone cut "glass_r_sharp_12"}
		{bone cut "glass_r_sharp_13"}
		{bone cut "glass_r_sharp_14"}
		{bone cut "glass_r_sharp_15"}
		{bone cut "glass_r_sharp_16"}
		{bone cut "glass_r_sharp_17"}
		{bone cut "glass_r_sharp_18"}
		{bone cut "glass_r_sharp_19"}
		{bone cut "glass_r_sharp_20"}
		{bone cut "glass_r_sharp_21"}
		{bone cut "glass_r_sharp_22"}
		{bone cut "glass_r_sharp_23"}
		{bone cut "glass_r_sharp_24"}
		{bone cut "glass_r_sharp_25"}
		{volumes "glass_r_sharp_00" disable all}
		{volumes "glass_r_sharp_01" disable all}
		{volumes "glass_r_sharp_02" disable all}
		{volumes "glass_r_sharp_03" disable all}
		{volumes "glass_r_sharp_04" disable all}
		{volumes "glass_r_sharp_05" disable all}
		{volumes "glass_r_sharp_06" disable all}
		{volumes "glass_r_sharp_07" disable all}
		{volumes "glass_r_sharp_08" disable all}
		{volumes "glass_r_sharp_09" disable all}
		{volumes "glass_r_sharp_10" disable all}
		{volumes "glass_r_sharp_11" disable all}
		{volumes "glass_r_sharp_12" disable all}
		{volumes "glass_r_sharp_13" disable all}
		{volumes "glass_r_sharp_14" disable all}
		{volumes "glass_r_sharp_15" disable all}
		{volumes "glass_r_sharp_16" disable all}
		{volumes "glass_r_sharp_17" disable all}
		{volumes "glass_r_sharp_18" disable all}
		{volumes "glass_r_sharp_19" disable all}
		{volumes "glass_r_sharp_20" disable all}
		{volumes "glass_r_sharp_21" disable all}
		{volumes "glass_r_sharp_22" disable all}
		{volumes "glass_r_sharp_23" disable all}
		{volumes "glass_r_sharp_24" disable all}
		{volumes "glass_r_sharp_25" disable all}
	}
	{on "glass_l1_blast"
		{bone cut "glass_l1_sharp_00"}
		{bone cut "glass_l1_sharp_01"}
		{bone cut "glass_l1_sharp_02"}
		{bone cut "glass_l1_sharp_03"}
		{bone cut "glass_l1_sharp_04"}
		{bone cut "glass_l1_sharp_05"}
		{bone cut "glass_l1_sharp_06"}
		{bone cut "glass_l1_sharp_07"}
		{bone cut "glass_l1_sharp_08"}
		{bone cut "glass_l1_sharp_09"}
		{bone cut "glass_l1_sharp_10"}
		{bone cut "glass_l1_sharp_11"}
		{bone cut "glass_l1_sharp_12"}
		{bone cut "glass_l1_sharp_13"}
		{bone cut "glass_l1_sharp_14"}
		{bone cut "glass_l1_sharp_15"}
		{bone cut "glass_l1_sharp_16"}
		{bone cut "glass_l1_sharp_17"}
		{bone cut "glass_l1_sharp_18"}
		{bone cut "glass_l1_sharp_19"}
		{bone cut "glass_l1_sharp_20"}
		{bone cut "glass_l1_sharp_21"}
		{bone cut "glass_l1_sharp_22"}
		{bone cut "glass_l1_sharp_23"}
		{bone cut "glass_l1_sharp_24"}
		{bone cut "glass_l1_sharp_25"}
	}
	{on "glass_r1_blast"
		{bone cut "glass_r1_sharp_00"}
		{bone cut "glass_r1_sharp_01"}
		{bone cut "glass_r1_sharp_02"}
		{bone cut "glass_r1_sharp_03"}
		{bone cut "glass_r1_sharp_04"}
		{bone cut "glass_r1_sharp_05"}
		{bone cut "glass_r1_sharp_06"}
		{bone cut "glass_r1_sharp_07"}
		{bone cut "glass_r1_sharp_08"}
		{bone cut "glass_r1_sharp_09"}
		{bone cut "glass_r1_sharp_10"}
		{bone cut "glass_r1_sharp_11"}
		{bone cut "glass_r1_sharp_12"}
		{bone cut "glass_r1_sharp_13"}
		{bone cut "glass_r1_sharp_14"}
		{bone cut "glass_r1_sharp_15"}
		{bone cut "glass_r1_sharp_16"}
		{bone cut "glass_r1_sharp_17"}
		{bone cut "glass_r1_sharp_18"}
		{bone cut "glass_r1_sharp_19"}
		{bone cut "glass_r1_sharp_20"}
		{bone cut "glass_r1_sharp_21"}
		{bone cut "glass_r1_sharp_22"}
		{bone cut "glass_r1_sharp_23"}
		{bone cut "glass_r1_sharp_24"}
		{bone cut "glass_r1_sharp_25"}
		{volumes "glass_r1_sharp_00" disable all}
		{volumes "glass_r1_sharp_01" disable all}
		{volumes "glass_r1_sharp_02" disable all}
		{volumes "glass_r1_sharp_03" disable all}
		{volumes "glass_r1_sharp_04" disable all}
		{volumes "glass_r1_sharp_05" disable all}
		{volumes "glass_r1_sharp_06" disable all}
		{volumes "glass_r1_sharp_07" disable all}
		{volumes "glass_r1_sharp_08" disable all}
		{volumes "glass_r1_sharp_09" disable all}
		{volumes "glass_r1_sharp_10" disable all}
		{volumes "glass_r1_sharp_11" disable all}
		{volumes "glass_r1_sharp_12" disable all}
		{volumes "glass_r1_sharp_13" disable all}
		{volumes "glass_r1_sharp_14" disable all}
		{volumes "glass_r1_sharp_15" disable all}
		{volumes "glass_r1_sharp_16" disable all}
		{volumes "glass_r1_sharp_17" disable all}
		{volumes "glass_r1_sharp_18" disable all}
		{volumes "glass_r1_sharp_19" disable all}
		{volumes "glass_r1_sharp_20" disable all}
		{volumes "glass_r1_sharp_21" disable all}
		{volumes "glass_r1_sharp_22" disable all}
		{volumes "glass_r1_sharp_23" disable all}
		{volumes "glass_r1_sharp_24" disable all}
		{volumes "glass_r1_sharp_25" disable all}
	}
	{on "glass_l2_blast"
		{bone cut "glass_l2_sharp_00"}
		{bone cut "glass_l2_sharp_01"}
		{bone cut "glass_l2_sharp_02"}
		{bone cut "glass_l2_sharp_03"}
		{bone cut "glass_l2_sharp_04"}
		{bone cut "glass_l2_sharp_05"}
		{bone cut "glass_l2_sharp_06"}
		{bone cut "glass_l2_sharp_07"}
		{bone cut "glass_l2_sharp_08"}
		{bone cut "glass_l2_sharp_09"}
		{bone cut "glass_l2_sharp_10"}
		{bone cut "glass_l2_sharp_11"}
		{bone cut "glass_l2_sharp_12"}
		{bone cut "glass_l2_sharp_13"}
		{bone cut "glass_l2_sharp_14"}
		{bone cut "glass_l2_sharp_15"}
		{bone cut "glass_l2_sharp_16"}
		{bone cut "glass_l2_sharp_17"}
		{bone cut "glass_l2_sharp_18"}
		{bone cut "glass_l2_sharp_19"}
		{bone cut "glass_l2_sharp_20"}
		{bone cut "glass_l2_sharp_21"}
		{bone cut "glass_l2_sharp_22"}
		{bone cut "glass_l2_sharp_23"}
		{bone cut "glass_l2_sharp_24"}
		{bone cut "glass_l2_sharp_25"}
		{volumes "glass_l2_sharp_00" disable all}
		{volumes "glass_l2_sharp_01" disable all}
		{volumes "glass_l2_sharp_02" disable all}
		{volumes "glass_l2_sharp_03" disable all}
		{volumes "glass_l2_sharp_04" disable all}
		{volumes "glass_l2_sharp_05" disable all}
		{volumes "glass_l2_sharp_06" disable all}
		{volumes "glass_l2_sharp_07" disable all}
		{volumes "glass_l2_sharp_08" disable all}
		{volumes "glass_l2_sharp_09" disable all}
		{volumes "glass_l2_sharp_10" disable all}
		{volumes "glass_l2_sharp_11" disable all}
		{volumes "glass_l2_sharp_12" disable all}
		{volumes "glass_l2_sharp_13" disable all}
		{volumes "glass_l2_sharp_14" disable all}
		{volumes "glass_l2_sharp_15" disable all}
		{volumes "glass_l2_sharp_16" disable all}
		{volumes "glass_l2_sharp_17" disable all}
		{volumes "glass_l2_sharp_18" disable all}
		{volumes "glass_l2_sharp_19" disable all}
		{volumes "glass_l2_sharp_20" disable all}
		{volumes "glass_l2_sharp_21" disable all}
		{volumes "glass_l2_sharp_22" disable all}
		{volumes "glass_l2_sharp_23" disable all}
		{volumes "glass_l2_sharp_24" disable all}
		{volumes "glass_l2_sharp_25" disable all}
	}
	{on "glass_r2_blast"
		{bone cut "glass_r2_sharp_00"}
		{bone cut "glass_r2_sharp_01"}
		{bone cut "glass_r2_sharp_02"}
		{bone cut "glass_r2_sharp_03"}
		{bone cut "glass_r2_sharp_04"}
		{bone cut "glass_r2_sharp_05"}
		{bone cut "glass_r2_sharp_06"}
		{bone cut "glass_r2_sharp_07"}
		{bone cut "glass_r2_sharp_08"}
		{bone cut "glass_r2_sharp_09"}
		{bone cut "glass_r2_sharp_10"}
		{bone cut "glass_r2_sharp_11"}
		{bone cut "glass_r2_sharp_12"}
		{bone cut "glass_r2_sharp_13"}
		{bone cut "glass_r2_sharp_14"}
		{bone cut "glass_r2_sharp_15"}
		{bone cut "glass_r2_sharp_16"}
		{bone cut "glass_r2_sharp_17"}
		{bone cut "glass_r2_sharp_18"}
		{bone cut "glass_r2_sharp_19"}
		{bone cut "glass_r2_sharp_20"}
		{bone cut "glass_r2_sharp_21"}
		{bone cut "glass_r2_sharp_22"}
		{bone cut "glass_r2_sharp_23"}
		{bone cut "glass_r2_sharp_24"}
		{bone cut "glass_r2_sharp_25"}
		{volumes "glass_r2_sharp_00" disable all}
		{volumes "glass_r2_sharp_01" disable all}
		{volumes "glass_r2_sharp_02" disable all}
		{volumes "glass_r2_sharp_03" disable all}
		{volumes "glass_r2_sharp_04" disable all}
		{volumes "glass_r2_sharp_05" disable all}
		{volumes "glass_r2_sharp_06" disable all}
		{volumes "glass_r2_sharp_07" disable all}
		{volumes "glass_r2_sharp_08" disable all}
		{volumes "glass_r2_sharp_09" disable all}
		{volumes "glass_r2_sharp_10" disable all}
		{volumes "glass_r2_sharp_11" disable all}
		{volumes "glass_r2_sharp_12" disable all}
		{volumes "glass_r2_sharp_13" disable all}
		{volumes "glass_r2_sharp_14" disable all}
		{volumes "glass_r2_sharp_15" disable all}
		{volumes "glass_r2_sharp_16" disable all}
		{volumes "glass_r2_sharp_17" disable all}
		{volumes "glass_r2_sharp_18" disable all}
		{volumes "glass_r2_sharp_19" disable all}
		{volumes "glass_r2_sharp_20" disable all}
		{volumes "glass_r2_sharp_21" disable all}
		{volumes "glass_r2_sharp_22" disable all}
		{volumes "glass_r2_sharp_23" disable all}
		{volumes "glass_r2_sharp_24" disable all}
		{volumes "glass_r2_sharp_25" disable all}
	}
	{on "glass_l3_blast"
		{bone cut "glass_l3_sharp_00"}
		{bone cut "glass_l3_sharp_01"}
		{bone cut "glass_l3_sharp_02"}
		{bone cut "glass_l3_sharp_03"}
		{bone cut "glass_l3_sharp_04"}
		{bone cut "glass_l3_sharp_05"}
		{bone cut "glass_l3_sharp_06"}
		{bone cut "glass_l3_sharp_07"}
		{bone cut "glass_l3_sharp_08"}
		{bone cut "glass_l3_sharp_09"}
		{bone cut "glass_l3_sharp_10"}
		{bone cut "glass_l3_sharp_11"}
		{bone cut "glass_l3_sharp_12"}
		{bone cut "glass_l3_sharp_13"}
		{bone cut "glass_l3_sharp_14"}
		{bone cut "glass_l3_sharp_15"}
		{bone cut "glass_l3_sharp_16"}
		{bone cut "glass_l3_sharp_17"}
		{bone cut "glass_l3_sharp_18"}
		{bone cut "glass_l3_sharp_19"}
		{bone cut "glass_l3_sharp_20"}
		{bone cut "glass_l3_sharp_21"}
		{bone cut "glass_l3_sharp_22"}
		{bone cut "glass_l3_sharp_23"}
		{bone cut "glass_l3_sharp_24"}
		{bone cut "glass_l3_sharp_25"}
		{volumes "glass_l3_sharp_00" disable all}
		{volumes "glass_l3_sharp_01" disable all}
		{volumes "glass_l3_sharp_02" disable all}
		{volumes "glass_l3_sharp_03" disable all}
		{volumes "glass_l3_sharp_04" disable all}
		{volumes "glass_l3_sharp_05" disable all}
		{volumes "glass_l3_sharp_06" disable all}
		{volumes "glass_l3_sharp_07" disable all}
		{volumes "glass_l3_sharp_08" disable all}
		{volumes "glass_l3_sharp_09" disable all}
		{volumes "glass_l3_sharp_10" disable all}
		{volumes "glass_l3_sharp_11" disable all}
		{volumes "glass_l3_sharp_12" disable all}
		{volumes "glass_l3_sharp_13" disable all}
		{volumes "glass_l3_sharp_14" disable all}
		{volumes "glass_l3_sharp_15" disable all}
		{volumes "glass_l3_sharp_16" disable all}
		{volumes "glass_l3_sharp_17" disable all}
		{volumes "glass_l3_sharp_18" disable all}
		{volumes "glass_l3_sharp_19" disable all}
		{volumes "glass_l3_sharp_20" disable all}
		{volumes "glass_l3_sharp_21" disable all}
		{volumes "glass_l3_sharp_22" disable all}
		{volumes "glass_l3_sharp_23" disable all}
		{volumes "glass_l3_sharp_24" disable all}
		{volumes "glass_l3_sharp_25" disable all}
	}
	{on "glass_r3_blast"
		{bone cut "glass_r3_sharp_00"}
		{bone cut "glass_r3_sharp_01"}
		{bone cut "glass_r3_sharp_02"}
		{bone cut "glass_r3_sharp_03"}
		{bone cut "glass_r3_sharp_04"}
		{bone cut "glass_r3_sharp_05"}
		{bone cut "glass_r3_sharp_06"}
		{bone cut "glass_r3_sharp_07"}
		{bone cut "glass_r3_sharp_08"}
		{bone cut "glass_r3_sharp_09"}
		{bone cut "glass_r3_sharp_10"}
		{bone cut "glass_r3_sharp_11"}
		{bone cut "glass_r3_sharp_12"}
		{bone cut "glass_r3_sharp_13"}
		{bone cut "glass_r3_sharp_14"}
		{bone cut "glass_r3_sharp_15"}
		{bone cut "glass_r3_sharp_16"}
		{bone cut "glass_r3_sharp_17"}
		{bone cut "glass_r3_sharp_18"}
		{bone cut "glass_r3_sharp_19"}
		{bone cut "glass_r3_sharp_20"}
		{bone cut "glass_r3_sharp_21"}
		{bone cut "glass_r3_sharp_22"}
		{bone cut "glass_r3_sharp_23"}
		{bone cut "glass_r3_sharp_24"}
		{bone cut "glass_r3_sharp_25"}
		{volumes "glass_r3_sharp_00" disable all}
		{volumes "glass_r3_sharp_01" disable all}
		{volumes "glass_r3_sharp_02" disable all}
		{volumes "glass_r3_sharp_03" disable all}
		{volumes "glass_r3_sharp_04" disable all}
		{volumes "glass_r3_sharp_05" disable all}
		{volumes "glass_r3_sharp_06" disable all}
		{volumes "glass_r3_sharp_07" disable all}
		{volumes "glass_r3_sharp_08" disable all}
		{volumes "glass_r3_sharp_09" disable all}
		{volumes "glass_r3_sharp_10" disable all}
		{volumes "glass_r3_sharp_11" disable all}
		{volumes "glass_r3_sharp_12" disable all}
		{volumes "glass_r3_sharp_13" disable all}
		{volumes "glass_r3_sharp_14" disable all}
		{volumes "glass_r3_sharp_15" disable all}
		{volumes "glass_r3_sharp_16" disable all}
		{volumes "glass_r3_sharp_17" disable all}
		{volumes "glass_r3_sharp_18" disable all}
		{volumes "glass_r3_sharp_19" disable all}
		{volumes "glass_r3_sharp_20" disable all}
		{volumes "glass_r3_sharp_21" disable all}
		{volumes "glass_r3_sharp_22" disable all}
		{volumes "glass_r3_sharp_23" disable all}
		{volumes "glass_r3_sharp_24" disable all}
		{volumes "glass_r3_sharp_25" disable all}
	}
	{on "break_all_glass_new"
		{delay 9 3
			{if not tagged "damage_glass_r"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_r"}
				{bone hide "glass_r" }
				{spawn "glass_hit_shrap_small" "glass_r" } ; - new create
				{bone show "glass_r_damage" }
				{volumes "glass_r" disable all}
				{volumes "glass_r_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_r"
				{if not tagged "broken_glass_r"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_r"}
					{bone hide "glass_r_damage"}
					{spawn "glass_hit_shrap_small2" "glass_r" } ; - new create
					{bone show "glass_r_broken"}
					{call "glass_r_set"}
					{volumes "glass_r_damage" disable all}
					{volumes "glass_r_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_l"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_l"}
				{bone hide "glass_l" }
				{spawn "glass_hit_shrap_small" "glass_l" } ; - new create
				{bone show "glass_l_damage" }
				{volumes "glass_l" disable all}
				{volumes "glass_l_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_l"
				{if not tagged "broken_glass_l"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_l"}
					{bone hide "glass_l_damage"}
					{spawn "glass_hit_shrap_small2" "glass_l" } ; - new create
					{bone show "glass_l_broken"}
					{call "glass_l_set"}
					{volumes "glass_l_damage" disable all}
					{volumes "glass_l_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_r1"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_r1"}
				{bone hide "glass_r1" }
				{spawn "glass_hit_shrap_small" "glass_r1" } ; - new create
				{bone show "glass_r1_damage" }
				{volumes "glass_r1" disable all}
				{volumes "glass_r1_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_r1"
				{if not tagged "broken_glass_r1"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_r1"}
					{bone hide "glass_r1_damage"}
					{spawn "glass_hit_shrap_small2" "glass_r1" } ; - new create
					{bone show "glass_r1_broken"}
					{call "glass_r1_set"}
					{volumes "glass_r1_damage" disable all}
					{volumes "glass_r1_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_l1"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_l1"}
				{bone hide "glass_l1" }
				{spawn "glass_hit_shrap_small" "glass_l1" } ; - new create
				{bone show "glass_l1_damage" }
				{volumes "glass_l1" disable all}
				{volumes "glass_l1_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_l1"
				{if not tagged "broken_glass_l1"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_l1"}
					{bone hide "glass_l1_damage"}
					{spawn "glass_hit_shrap_small2" "glass_l1" } ; - new create
					{bone show "glass_l1_broken"}
					{call "glass_l1_set"}
					{volumes "glass_l1_damage" disable all}
					{volumes "glass_l1_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_r2"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_r2"}
				{bone hide "glass_r2" }
				{spawn "glass_hit_shrap_small" "glass_r2" } ; - new create
				{bone show "glass_r2_damage" }
				{volumes "glass_r2" disable all}
				{volumes "glass_r2_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_r2"
				{if not tagged "broken_glass_r2"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_r2"}
					{bone hide "glass_r2_damage"}
					{spawn "glass_hit_shrap_small2" "glass_r2" } ; - new create
					{bone show "glass_r2_broken"}
					{call "glass_r2_set"}
					{volumes "glass_r2_damage" disable all}
					{volumes "glass_r2_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_l2"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_l2"}
				{bone hide "glass_l2" }
				{spawn "glass_hit_shrap_small" "glass_l2" } ; - new create
				{bone show "glass_l2_damage" }
				{volumes "glass_l2" disable all}
				{volumes "glass_l2_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_l2"
				{if not tagged "broken_glass_l2"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_l2"}
					{bone hide "glass_l2_damage"}
					{spawn "glass_hit_shrap_small2" "glass_l2" } ; - new create
					{bone show "glass_l2_broken"}
					{call "glass_l2_set"}
					{volumes "glass_l2_damage" disable all}
					{volumes "glass_l2_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_r3"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_r3"}
				{bone hide "glass_r3" }
				{spawn "glass_hit_shrap_small" "glass_r3" } ; - new create
				{bone show "glass_r3_damage" }
				{volumes "glass_r3" disable all}
				{volumes "glass_r3_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_r3"
				{if not tagged "broken_glass_r3"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_r3"}
					{bone hide "glass_r3_damage"}
					{spawn "glass_hit_shrap_small2" "glass_r3" } ; - new create
					{bone show "glass_r3_broken"}
					{call "glass_r3_set"}
					{volumes "glass_r3_damage" disable all}
					{volumes "glass_r3_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 9 3
			{if not tagged "damage_glass_l3"
				{start_sound "hit/small/grenade/glass/med/"}	
				{tags add "damage_glass_l3"}
				{bone hide "glass_l3" }
				{spawn "glass_hit_shrap_small" "glass_l3" } ; - new create
				{bone show "glass_l3_damage" }
				{volumes "glass_l3" disable all}
				{volumes "glass_l3_damage" enable contact_ground contact blast bullet}
			}
		}
		{delay 25 5
			{if tagged "damage_glass_l3"
				{if not tagged "broken_glass_l3"
					{start_sound "hit/small/grenade/glass/hard/"}	
					{tags add "broken_glass_l3"}
					{bone hide "glass_l3_damage"}
					{spawn "glass_hit_shrap_small2" "glass_l3" } ; - new create
					{bone show "glass_l3_broken"}
					{call "glass_l3_set"}
					{volumes "glass_l3_damage" disable all}
					{volumes "glass_l3_broken" enable contact_ground contact blast bullet}
				}
			}
		}
		{delay 32
			{call "check_burn_fragment"}
			{delay 45
				{tags add "check_burn_fragment"}
			}
		}
	}
	{on "check_burn_fragment"
		{if not tagged "check_burn_fragment"
			(define "burn_part"
				{if rand 0.1
					{tear "piece_small_glass" bone %0
						{start_sound "hit/small/grenade/glass/soft/"}	
						;{spawn	"glass_hit_small" %0 }
						{impulse up 0.1}
					}
				}
			)
			("burn_part" args "glass_l_sharp_00" )
			("burn_part" args "glass_l_sharp_01" )
			("burn_part" args "glass_l_sharp_02" )
			("burn_part" args "glass_l_sharp_03" )
			("burn_part" args "glass_l_sharp_04" )
			("burn_part" args "glass_l_sharp_05" )
			("burn_part" args "glass_l_sharp_06" )
			("burn_part" args "glass_l_sharp_07" )
			("burn_part" args "glass_l_sharp_08" )
			("burn_part" args "glass_l_sharp_09" )
			("burn_part" args "glass_l_sharp_10" )
			("burn_part" args "glass_l_sharp_11" )
			("burn_part" args "glass_l_sharp_12" )
			("burn_part" args "glass_l_sharp_13" )
			("burn_part" args "glass_l_sharp_14" )
			("burn_part" args "glass_l_sharp_15" )
			("burn_part" args "glass_l_sharp_16" )
			("burn_part" args "glass_l_sharp_17" )
			("burn_part" args "glass_l_sharp_18" )
			("burn_part" args "glass_l_sharp_19" )
			("burn_part" args "glass_l_sharp_20" )
			("burn_part" args "glass_l_sharp_21" )
			("burn_part" args "glass_l_sharp_22" )
			("burn_part" args "glass_l_sharp_23" )
			("burn_part" args "glass_l_sharp_24" )
			("burn_part" args "glass_l_sharp_25" )
			("burn_part" args "glass_r_sharp_00" )
			("burn_part" args "glass_r_sharp_01" )
			("burn_part" args "glass_r_sharp_02" )
			("burn_part" args "glass_r_sharp_03" )
			("burn_part" args "glass_r_sharp_04" )
			("burn_part" args "glass_r_sharp_05" )
			("burn_part" args "glass_r_sharp_06" )
			("burn_part" args "glass_r_sharp_07" )
			("burn_part" args "glass_r_sharp_08" )
			("burn_part" args "glass_r_sharp_09" )
			("burn_part" args "glass_r_sharp_10" )
			("burn_part" args "glass_r_sharp_11" )
			("burn_part" args "glass_r_sharp_12" )
			("burn_part" args "glass_r_sharp_13" )
			("burn_part" args "glass_r_sharp_14" )
			("burn_part" args "glass_r_sharp_15" )
			("burn_part" args "glass_r_sharp_16" )
			("burn_part" args "glass_r_sharp_17" )
			("burn_part" args "glass_r_sharp_18" )
			("burn_part" args "glass_r_sharp_19" )
			("burn_part" args "glass_r_sharp_20" )
			("burn_part" args "glass_r_sharp_21" )
			("burn_part" args "glass_r_sharp_22" )
			("burn_part" args "glass_r_sharp_23" )
			("burn_part" args "glass_r_sharp_24" )
			("burn_part" args "glass_r_sharp_25" )
			("burn_part" args "glass_l1_sharp_00" )
			("burn_part" args "glass_l1_sharp_01" )
			("burn_part" args "glass_l1_sharp_02" )
			("burn_part" args "glass_l1_sharp_03" )
			("burn_part" args "glass_l1_sharp_04" )
			("burn_part" args "glass_l1_sharp_05" )
			("burn_part" args "glass_l1_sharp_06" )
			("burn_part" args "glass_l1_sharp_07" )
			("burn_part" args "glass_l1_sharp_08" )
			("burn_part" args "glass_l1_sharp_09" )
			("burn_part" args "glass_l1_sharp_10" )
			("burn_part" args "glass_l1_sharp_11" )
			("burn_part" args "glass_l1_sharp_12" )
			("burn_part" args "glass_l1_sharp_13" )
			("burn_part" args "glass_l1_sharp_14" )
			("burn_part" args "glass_l1_sharp_15" )
			("burn_part" args "glass_l1_sharp_16" )
			("burn_part" args "glass_l1_sharp_17" )
			("burn_part" args "glass_l1_sharp_18" )
			("burn_part" args "glass_l1_sharp_19" )
			("burn_part" args "glass_l1_sharp_20" )
			("burn_part" args "glass_l1_sharp_21" )
			("burn_part" args "glass_l1_sharp_22" )
			("burn_part" args "glass_l1_sharp_23" )
			("burn_part" args "glass_l1_sharp_24" )
			("burn_part" args "glass_l1_sharp_25" )
			("burn_part" args "glass_r1_sharp_00" )
			("burn_part" args "glass_r1_sharp_01" )
			("burn_part" args "glass_r1_sharp_02" )
			("burn_part" args "glass_r1_sharp_03" )
			("burn_part" args "glass_r1_sharp_04" )
			("burn_part" args "glass_r1_sharp_05" )
			("burn_part" args "glass_r1_sharp_06" )
			("burn_part" args "glass_r1_sharp_07" )
			("burn_part" args "glass_r1_sharp_08" )
			("burn_part" args "glass_r1_sharp_09" )
			("burn_part" args "glass_r1_sharp_10" )
			("burn_part" args "glass_r1_sharp_11" )
			("burn_part" args "glass_r1_sharp_12" )
			("burn_part" args "glass_r1_sharp_13" )
			("burn_part" args "glass_r1_sharp_14" )
			("burn_part" args "glass_r1_sharp_15" )
			("burn_part" args "glass_r1_sharp_16" )
			("burn_part" args "glass_r1_sharp_17" )
			("burn_part" args "glass_r1_sharp_18" )
			("burn_part" args "glass_r1_sharp_19" )
			("burn_part" args "glass_r1_sharp_20" )
			("burn_part" args "glass_r1_sharp_21" )
			("burn_part" args "glass_r1_sharp_22" )
			("burn_part" args "glass_r1_sharp_23" )
			("burn_part" args "glass_r1_sharp_24" )
			("burn_part" args "glass_r1_sharp_25" )
			{delay_effect 4 2 "check_burn_fragment"}
		}
	}
}

{"glass_frame_engine"
	{on spawn
		{bone hide	"glass_shard_door_l_00"}
		{bone hide	"glass_shard_door_l_01"}
		{bone hide	"glass_shard_door_l_02"}
		{bone hide	"glass_shard_door_l_03"}
		{bone hide	"glass_shard_door_l_04"}
		{bone hide	"glass_shard_door_l_05"}
		{bone hide	"glass_shard_door_l_06"}
		{bone hide	"glass_shard_door_l_07"}
		{bone hide	"glass_shard_door_l_08"}
		{bone hide	"glass_shard_door_l_09"}
		{bone hide	"glass_shard_door_l_10"}
		{bone hide	"glass_shard_door_l_11"}
		{bone hide	"glass_shard_door_l_12"}
		{bone hide	"glass_shard_door_l_13"}
		{bone hide	"glass_shard_door_l_14"}
		{bone hide	"glass_shard_door_l_15"}
		{bone hide	"glass_shard_door_l_16"}
		{bone hide	"glass_shard_door_l_17"}
		{bone hide	"glass_shard_door_l_18"}
		{bone hide	"glass_shard_door_l_19"}
		{bone hide	"glass_shard_door_l_20"}
		{bone hide	"glass_shard_door_l_21"}
		{bone hide	"glass_shard_door_l_22"}
		{bone hide	"glass_shard_door_l_23"}
		{bone hide	"glass_shard_door_l_24"}
		{bone hide	"glass_shard_door_r_00"}
		{bone hide	"glass_shard_door_r_01"}
		{bone hide	"glass_shard_door_r_02"}
		{bone hide	"glass_shard_door_r_03"}
		{bone hide	"glass_shard_door_r_04"}
		{bone hide	"glass_shard_door_r_05"}
		{bone hide	"glass_shard_door_r_06"}
		{bone hide	"glass_shard_door_r_07"}
		{bone hide	"glass_shard_door_r_08"}
		{bone hide	"glass_shard_door_r_09"}
		{bone hide	"glass_shard_door_r_10"}
		{bone hide	"glass_shard_door_r_11"}
		{bone hide	"glass_shard_door_r_12"}
		{bone hide	"glass_shard_door_r_13"}
		{bone hide	"glass_shard_door_r_14"}
		{bone hide	"glass_shard_door_r_15"}
		{bone hide	"glass_shard_door_r_16"}
		{bone hide	"glass_shard_door_r_17"}
		{bone hide	"glass_shard_door_r_18"}
		{bone hide	"glass_shard_door_r_19"}
		{bone hide	"glass_shard_door_r_20"}
		{bone hide	"glass_shard_door_r_21"}
		{bone hide	"glass_shard_door_r_22"}
		{bone hide	"glass_shard_door_r_23"}
		{bone hide	"glass_shard_door_r_24"}
		{bone hide	"glass_shard_l_00"}
		{bone hide	"glass_shard_l_01"}
		{bone hide	"glass_shard_l_02"}
		{bone hide	"glass_shard_l_03"}
		{bone hide	"glass_shard_l_04"}
		{bone hide	"glass_shard_l_05"}
		{bone hide	"glass_shard_l_06"}
		{bone hide	"glass_shard_l_07"}
		{bone hide	"glass_shard_l_08"}
		{bone hide	"glass_shard_l_09"}
		{bone hide	"glass_shard_l_10"}
		{bone hide	"glass_shard_l_11"}
		{bone hide	"glass_shard_l_12"}
		{bone hide	"glass_shard_l_13"}
		{bone hide	"glass_shard_l_14"}
		{bone hide	"glass_shard_l_15"}
		{bone hide	"glass_shard_l_16"}
		{bone hide	"glass_shard_l_17"}
		{bone hide	"glass_shard_l_18"}
		{bone hide	"glass_shard_l_19"}
		{bone hide	"glass_shard_l_20"}
		{bone hide	"glass_shard_l_21"}
		{bone hide	"glass_shard_l_22"}
		{bone hide	"glass_shard_l_23"}
		{bone hide	"glass_shard_l_24"}
		{bone hide	"glass_shard_r_00"}
		{bone hide	"glass_shard_r_01"}
		{bone hide	"glass_shard_r_02"}
		{bone hide	"glass_shard_r_03"}
		{bone hide	"glass_shard_r_04"}
		{bone hide	"glass_shard_r_05"}
		{bone hide	"glass_shard_r_06"}
		{bone hide	"glass_shard_r_07"}
		{bone hide	"glass_shard_r_08"}
		{bone hide	"glass_shard_r_09"}
		{bone hide	"glass_shard_r_10"}
		{bone hide	"glass_shard_r_11"}
		{bone hide	"glass_shard_r_12"}
		{bone hide	"glass_shard_r_13"}
		{bone hide	"glass_shard_r_14"}
		{bone hide	"glass_shard_r_15"}
		{bone hide	"glass_shard_r_16"}
		{bone hide	"glass_shard_r_17"}
		{bone hide	"glass_shard_r_18"}
		{bone hide	"glass_shard_r_19"}
		{bone hide	"glass_shard_r_20"}
		{bone hide	"glass_shard_r_21"}
		{bone hide	"glass_shard_r_22"}
		{bone hide	"glass_shard_r_23"}
		{bone hide	"glass_shard_r_24"}
		{volumes "glass_shard_r_00" disable contact blast bullet}
		{volumes "glass_shard_r_01" disable contact blast bullet}
		{volumes "glass_shard_r_02" disable contact blast bullet}
		{volumes "glass_shard_r_03" disable contact blast bullet}
		{volumes "glass_shard_r_04" disable contact blast bullet}
		{volumes "glass_shard_r_05" disable contact blast bullet}
		{volumes "glass_shard_r_06" disable contact blast bullet}
		{volumes "glass_shard_r_07" disable contact blast bullet}
		{volumes "glass_shard_r_08" disable contact blast bullet}
		{volumes "glass_shard_r_09" disable contact blast bullet}
		{volumes "glass_shard_r_10" disable contact blast bullet}
		{volumes "glass_shard_r_11" disable contact blast bullet}
		{volumes "glass_shard_r_12" disable contact blast bullet}
		{volumes "glass_shard_r_13" disable contact blast bullet}
		{volumes "glass_shard_r_14" disable contact blast bullet}
		{volumes "glass_shard_r_15" disable contact blast bullet}
		{volumes "glass_shard_r_16" disable contact blast bullet}
		{volumes "glass_shard_r_17" disable contact blast bullet}
		{volumes "glass_shard_r_18" disable contact blast bullet}
		{volumes "glass_shard_r_19" disable contact blast bullet}
		{volumes "glass_shard_r_20" disable contact blast bullet}
		{volumes "glass_shard_r_21" disable contact blast bullet}
		{volumes "glass_shard_r_22" disable contact blast bullet}
		{volumes "glass_shard_r_23" disable contact blast bullet}
		{volumes "glass_shard_r_24" disable contact blast bullet}
		{volumes "glass_shard_l_00" disable contact blast bullet}
		{volumes "glass_shard_l_01" disable contact blast bullet}
		{volumes "glass_shard_l_02" disable contact blast bullet}
		{volumes "glass_shard_l_03" disable contact blast bullet}
		{volumes "glass_shard_l_04" disable contact blast bullet}
		{volumes "glass_shard_l_05" disable contact blast bullet}
		{volumes "glass_shard_l_06" disable contact blast bullet}
		{volumes "glass_shard_l_07" disable contact blast bullet}
		{volumes "glass_shard_l_08" disable contact blast bullet}
		{volumes "glass_shard_l_09" disable contact blast bullet}
		{volumes "glass_shard_l_10" disable contact blast bullet}
		{volumes "glass_shard_l_11" disable contact blast bullet}
		{volumes "glass_shard_l_12" disable contact blast bullet}
		{volumes "glass_shard_l_13" disable contact blast bullet}
		{volumes "glass_shard_l_14" disable contact blast bullet}
		{volumes "glass_shard_l_15" disable contact blast bullet}
		{volumes "glass_shard_l_16" disable contact blast bullet}
		{volumes "glass_shard_l_17" disable contact blast bullet}
		{volumes "glass_shard_l_18" disable contact blast bullet}
		{volumes "glass_shard_l_19" disable contact blast bullet}
		{volumes "glass_shard_l_20" disable contact blast bullet}
		{volumes "glass_shard_l_21" disable contact blast bullet}
		{volumes "glass_shard_l_22" disable contact blast bullet}
		{volumes "glass_shard_l_23" disable contact blast bullet}
		{volumes "glass_shard_l_24" disable contact blast bullet}
		{volumes "glass_shard_door_r_00" disable contact blast bullet}
		{volumes "glass_shard_door_r_01" disable contact blast bullet}
		{volumes "glass_shard_door_r_02" disable contact blast bullet}
		{volumes "glass_shard_door_r_03" disable contact blast bullet}
		{volumes "glass_shard_door_r_04" disable contact blast bullet}
		{volumes "glass_shard_door_r_05" disable contact blast bullet}
		{volumes "glass_shard_door_r_06" disable contact blast bullet}
		{volumes "glass_shard_door_r_07" disable contact blast bullet}
		{volumes "glass_shard_door_r_08" disable contact blast bullet}
		{volumes "glass_shard_door_r_09" disable contact blast bullet}
		{volumes "glass_shard_door_r_10" disable contact blast bullet}
		{volumes "glass_shard_door_r_11" disable contact blast bullet}
		{volumes "glass_shard_door_r_12" disable contact blast bullet}
		{volumes "glass_shard_door_r_13" disable contact blast bullet}
		{volumes "glass_shard_door_r_14" disable contact blast bullet}
		{volumes "glass_shard_door_r_15" disable contact blast bullet}
		{volumes "glass_shard_door_r_16" disable contact blast bullet}
		{volumes "glass_shard_door_r_17" disable contact blast bullet}
		{volumes "glass_shard_door_r_18" disable contact blast bullet}
		{volumes "glass_shard_door_r_19" disable contact blast bullet}
		{volumes "glass_shard_door_r_20" disable contact blast bullet}
		{volumes "glass_shard_door_r_21" disable contact blast bullet}
		{volumes "glass_shard_door_r_22" disable contact blast bullet}
		{volumes "glass_shard_door_r_23" disable contact blast bullet}
		{volumes "glass_shard_door_r_24" disable contact blast bullet}
		{volumes "glass_shard_door_l_00" disable contact blast bullet}
		{volumes "glass_shard_door_l_01" disable contact blast bullet}
		{volumes "glass_shard_door_l_02" disable contact blast bullet}
		{volumes "glass_shard_door_l_03" disable contact blast bullet}
		{volumes "glass_shard_door_l_04" disable contact blast bullet}
		{volumes "glass_shard_door_l_05" disable contact blast bullet}
		{volumes "glass_shard_door_l_06" disable contact blast bullet}
		{volumes "glass_shard_door_l_07" disable contact blast bullet}
		{volumes "glass_shard_door_l_08" disable contact blast bullet}
		{volumes "glass_shard_door_l_09" disable contact blast bullet}
		{volumes "glass_shard_door_l_10" disable contact blast bullet}
		{volumes "glass_shard_door_l_11" disable contact blast bullet}
		{volumes "glass_shard_door_l_12" disable contact blast bullet}
		{volumes "glass_shard_door_l_13" disable contact blast bullet}
		{volumes "glass_shard_door_l_14" disable contact blast bullet}
		{volumes "glass_shard_door_l_15" disable contact blast bullet}
		{volumes "glass_shard_door_l_16" disable contact blast bullet}
		{volumes "glass_shard_door_l_17" disable contact blast bullet}
		{volumes "glass_shard_door_l_18" disable contact blast bullet}
		{volumes "glass_shard_door_l_19" disable contact blast bullet}
		{volumes "glass_shard_door_l_20" disable contact blast bullet}
		{volumes "glass_shard_door_l_21" disable contact blast bullet}
		{volumes "glass_shard_door_l_22" disable contact blast bullet}
		{volumes "glass_shard_door_l_23" disable contact blast bullet}
		{volumes "glass_shard_door_l_24" disable contact blast bullet}
	}
	{on contact 
		{if effector "semtex"	
			{impulse up 2 1 dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}
		}
		{if not effector "obstacle"	
			{if effector "stuff"
				{if volume "glass_front_00"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{spawn	"glass_hit2" "fx_break_f_l_00" x}
						{spawn	"glass_hit3" "fx_break_f_l_01" x}
						{spawn	"glass_hit3" "fx_break_f_l_02" x}
						{spawn	"break_glass_01" "fx_break_f_l_01" x}
						{spawn	"break_glass_02" "fx_break_f_l_02" x}
						{spawn	"break_glass_03" "fx_break_f_l_03" x}
						{spawn	"break_glass_04" "fx_break_f_l_04" x}
						{bone hide "glass_front_00"}
						{volumes "glass_front_00" disable all}
						{if rand 0.5
							{bone show	"glass_shard_l_00"}
							{volumes "glass_shard_l_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_l_01"}
							{volumes "glass_shard_l_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_l_02" enable contact blast bullet}
							{bone show	"glass_shard_l_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_03" enable contact blast bullet}
							{bone show	"glass_shard_l_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_04" enable contact blast bullet}
							{bone show	"glass_shard_l_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_05" enable contact blast bullet}
							{bone show	"glass_shard_l_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_06" enable contact blast bullet}
							{bone show	"glass_shard_l_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_07" enable contact blast bullet}
							{bone show	"glass_shard_l_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_08" enable contact blast bullet}
							{bone show	"glass_shard_l_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_l_09"}
							{volumes "glass_shard_l_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_l_10" enable contact blast bullet}
							{bone show	"glass_shard_l_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_11" enable contact blast bullet}
							{bone show	"glass_shard_l_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_12" enable contact blast bullet}
							{bone show	"glass_shard_l_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_13" enable contact blast bullet}
							{bone show	"glass_shard_l_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_14" enable contact blast bullet}
							{bone show	"glass_shard_l_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_15" enable contact blast bullet}
							{bone show	"glass_shard_l_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_16" enable contact blast bullet}
							{bone show	"glass_shard_l_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_17" enable contact blast bullet}
							{bone show	"glass_shard_l_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_18" enable contact blast bullet}
							{bone show	"glass_shard_l_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_19" enable contact blast bullet}
							{bone show	"glass_shard_l_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_20" enable contact blast bullet}
							{bone show	"glass_shard_l_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_21" enable contact blast bullet}
							{bone show	"glass_shard_l_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_22" enable contact blast bullet}
							{bone show	"glass_shard_l_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_23" enable contact blast bullet}
							{bone show	"glass_shard_l_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_24" enable contact blast bullet}
							{bone show	"glass_shard_l_24"}
						}
					}
				}
				{if volume "glass_front_01"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_front_01" disable all}
						{spawn	"glass_hit2" "fx_break_f_r_00" x}
						{spawn	"glass_hit3" "fx_break_f_r_01" x}
						{spawn	"glass_hit3" "fx_break_f_r_02" x}
						{spawn	"break_glass_01" "fx_break_f_r_01" x}
						{spawn	"break_glass_02" "fx_break_f_r_02" x}
						{spawn	"break_glass_03" "fx_break_f_r_03" x}
						{spawn	"break_glass_04" "fx_break_f_r_04" x}
						{bone hide	"glass_front_01"}
						{if rand 0.5
							{bone show	"glass_shard_r_00"}
							{volumes "glass_shard_r_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_r_01"}
							{volumes "glass_shard_r_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_r_02" enable contact blast bullet}
							{bone show	"glass_shard_r_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_03" enable contact blast bullet}
							{bone show	"glass_shard_r_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_04" enable contact blast bullet}
							{bone show	"glass_shard_r_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_05" enable contact blast bullet}
							{bone show	"glass_shard_r_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_06" enable contact blast bullet}
							{bone show	"glass_shard_r_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_07" enable contact blast bullet}
							{bone show	"glass_shard_r_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_08" enable contact blast bullet}
							{bone show	"glass_shard_r_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_r_09"}
							{volumes "glass_shard_r_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_r_10" enable contact blast bullet}
							{bone show	"glass_shard_r_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_11" enable contact blast bullet}
							{bone show	"glass_shard_r_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_12" enable contact blast bullet}
							{bone show	"glass_shard_r_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_13" enable contact blast bullet}
							{bone show	"glass_shard_r_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_14" enable contact blast bullet}
							{bone show	"glass_shard_r_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_15" enable contact blast bullet}
							{bone show	"glass_shard_r_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_16" enable contact blast bullet}
							{bone show	"glass_shard_r_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_17" enable contact blast bullet}
							{bone show	"glass_shard_r_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_18" enable contact blast bullet}
							{bone show	"glass_shard_r_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_19" enable contact blast bullet}
							{bone show	"glass_shard_r_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_20" enable contact blast bullet}
							{bone show	"glass_shard_r_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_21" enable contact blast bullet}
							{bone show	"glass_shard_r_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_22" enable contact blast bullet}
							{bone show	"glass_shard_r_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_23" enable contact blast bullet}
							{bone show	"glass_shard_r_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_24" enable contact blast bullet}
							{bone show	"glass_shard_r_24"}
						}
					}
				}
				{if volume "glass_l"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_l" disable all}
						{spawn	"glass_hit2" "fx_break_l_00" x}
						{spawn	"glass_hit3" "fx_break_l_01" x}
						{spawn	"glass_hit3" "fx_break_l_02" x}
						{spawn	"break_glass_01" "fx_break_l_01" x}
						{spawn	"break_glass_02" "fx_break_l_02" x}
						{spawn	"break_glass_03" "fx_break_l_03" x}
						{spawn	"break_glass_04" "fx_break_l_04" x}
						{bone hide	"glass_l"}
						{if rand 0.5
							{bone show	"glass_shard_door_l_00"}
							{volumes "glass_shard_door_l_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_l_01"}
							{volumes "glass_shard_door_l_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_02" enable contact blast bullet}
							{bone show	"glass_shard_door_l_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_03" enable contact blast bullet}
							{bone show	"glass_shard_door_l_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_04" enable contact blast bullet}
							{bone show	"glass_shard_door_l_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_05" enable contact blast bullet}
							{bone show	"glass_shard_door_l_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_06" enable contact blast bullet}
							{bone show	"glass_shard_door_l_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_07" enable contact blast bullet}
							{bone show	"glass_shard_door_l_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_08" enable contact blast bullet}
							{bone show	"glass_shard_door_l_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_l_09"}
							{volumes "glass_shard_door_l_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_10" enable contact blast bullet}
							{bone show	"glass_shard_door_l_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_11" enable contact blast bullet}
							{bone show	"glass_shard_door_l_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_12" enable contact blast bullet}
							{bone show	"glass_shard_door_l_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_13" enable contact blast bullet}
							{bone show	"glass_shard_door_l_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_14" enable contact blast bullet}
							{bone show	"glass_shard_door_l_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_15" enable contact blast bullet}
							{bone show	"glass_shard_door_l_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_16" enable contact blast bullet}
							{bone show	"glass_shard_door_l_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_17" enable contact blast bullet}
							{bone show	"glass_shard_door_l_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_18" enable contact blast bullet}
							{bone show	"glass_shard_door_l_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_19" enable contact blast bullet}
							{bone show	"glass_shard_door_l_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_20" enable contact blast bullet}
							{bone show	"glass_shard_door_l_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_21" enable contact blast bullet}
							{bone show	"glass_shard_door_l_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_22" enable contact blast bullet}
							{bone show	"glass_shard_door_l_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_23" enable contact blast bullet}
							{bone show	"glass_shard_door_l_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_24" enable contact blast bullet}
							{bone show	"glass_shard_door_l_24"}
						}
					}
				}
				{if volume "glass_r"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_r" disable all}
						{spawn	"glass_hit2" "fx_break_r_00" x}
						{spawn	"glass_hit3" "fx_break_r_01" x}
						{spawn	"glass_hit3" "fx_break_r_02" x}
						{spawn	"break_glass_01" "fx_break_r_01" x}
						{spawn	"break_glass_02" "fx_break_r_02" x}
						{spawn	"break_glass_03" "fx_break_r_03" x}
						{spawn	"break_glass_04" "fx_break_r_04" x}
						{bone hide	"glass_r"}
						{if rand 0.5
							{bone show	"glass_shard_door_r_00"}
							{volumes "glass_shard_door_r_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_r_01"}
							{volumes "glass_shard_door_r_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_02" enable contact blast bullet}
							{bone show	"glass_shard_door_r_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_03" enable contact blast bullet}
							{bone show	"glass_shard_door_r_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_04" enable contact blast bullet}
							{bone show	"glass_shard_door_r_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_05" enable contact blast bullet}
							{bone show	"glass_shard_door_r_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_06" enable contact blast bullet}
							{bone show	"glass_shard_door_r_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_07" enable contact blast bullet}
							{bone show	"glass_shard_door_r_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_08" enable contact blast bullet}
							{bone show	"glass_shard_door_r_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_r_09"}
							{volumes "glass_shard_door_r_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_10" enable contact blast bullet}
							{bone show	"glass_shard_door_r_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_11" enable contact blast bullet}
							{bone show	"glass_shard_door_r_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_12" enable contact blast bullet}
							{bone show	"glass_shard_door_r_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_13" enable contact blast bullet}
							{bone show	"glass_shard_door_r_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_14" enable contact blast bullet}
							{bone show	"glass_shard_door_r_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_15" enable contact blast bullet}
							{bone show	"glass_shard_door_r_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_16" enable contact blast bullet}
							{bone show	"glass_shard_door_r_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_17" enable contact blast bullet}
							{bone show	"glass_shard_door_r_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_18" enable contact blast bullet}
							{bone show	"glass_shard_door_r_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_19" enable contact blast bullet}
							{bone show	"glass_shard_door_r_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_20" enable contact blast bullet}
							{bone show	"glass_shard_door_r_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_21" enable contact blast bullet}
							{bone show	"glass_shard_door_r_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_22" enable contact blast bullet}
							{bone show	"glass_shard_door_r_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_23" enable contact blast bullet}
							{bone show	"glass_shard_door_r_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_24" enable contact blast bullet}
							{bone show	"glass_shard_door_r_24"}
						}
					}
				}
				{if volume "shard"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.5
						{spawn	"glass_hit_small" }
						{tear "piece_small_glass" bone from_volume
							{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
			else effector "fraction"
				{if volume "glass_front_00"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{spawn	"glass_hit2" "fx_break_f_l_00" x}
						{spawn	"glass_hit3" "fx_break_f_l_01" x}
						{spawn	"glass_hit3" "fx_break_f_l_02" x}
						{spawn	"break_glass_01" "fx_break_f_l_01" x}
						{spawn	"break_glass_02" "fx_break_f_l_02" x}
						{spawn	"break_glass_03" "fx_break_f_l_03" x}
						{spawn	"break_glass_04" "fx_break_f_l_04" x}
						{bone hide "glass_front_00"}
						{volumes "glass_front_00" disable all}
						{if rand 0.5
							{bone show	"glass_shard_l_00"}
							{volumes "glass_shard_l_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_l_01"}
							{volumes "glass_shard_l_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_l_02" enable contact blast bullet}
							{bone show	"glass_shard_l_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_03" enable contact blast bullet}
							{bone show	"glass_shard_l_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_04" enable contact blast bullet}
							{bone show	"glass_shard_l_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_05" enable contact blast bullet}
							{bone show	"glass_shard_l_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_06" enable contact blast bullet}
							{bone show	"glass_shard_l_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_07" enable contact blast bullet}
							{bone show	"glass_shard_l_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_08" enable contact blast bullet}
							{bone show	"glass_shard_l_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_l_09"}
							{volumes "glass_shard_l_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_l_10" enable contact blast bullet}
							{bone show	"glass_shard_l_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_11" enable contact blast bullet}
							{bone show	"glass_shard_l_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_12" enable contact blast bullet}
							{bone show	"glass_shard_l_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_13" enable contact blast bullet}
							{bone show	"glass_shard_l_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_14" enable contact blast bullet}
							{bone show	"glass_shard_l_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_15" enable contact blast bullet}
							{bone show	"glass_shard_l_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_16" enable contact blast bullet}
							{bone show	"glass_shard_l_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_17" enable contact blast bullet}
							{bone show	"glass_shard_l_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_18" enable contact blast bullet}
							{bone show	"glass_shard_l_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_19" enable contact blast bullet}
							{bone show	"glass_shard_l_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_20" enable contact blast bullet}
							{bone show	"glass_shard_l_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_21" enable contact blast bullet}
							{bone show	"glass_shard_l_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_22" enable contact blast bullet}
							{bone show	"glass_shard_l_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_23" enable contact blast bullet}
							{bone show	"glass_shard_l_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_l_24" enable contact blast bullet}
							{bone show	"glass_shard_l_24"}
						}
					}
				}
				{if volume "glass_front_01"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_front_01" disable all}
						{spawn	"glass_hit2" "fx_break_f_r_00" x}
						{spawn	"glass_hit3" "fx_break_f_r_01" x}
						{spawn	"glass_hit3" "fx_break_f_r_02" x}
						{spawn	"break_glass_01" "fx_break_f_r_01" x}
						{spawn	"break_glass_02" "fx_break_f_r_02" x}
						{spawn	"break_glass_03" "fx_break_f_r_03" x}
						{spawn	"break_glass_04" "fx_break_f_r_04" x}
						{bone hide	"glass_front_01"}
						{if rand 0.5
							{bone show	"glass_shard_r_00"}
							{volumes "glass_shard_r_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_r_01"}
							{volumes "glass_shard_r_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_r_02" enable contact blast bullet}
							{bone show	"glass_shard_r_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_03" enable contact blast bullet}
							{bone show	"glass_shard_r_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_04" enable contact blast bullet}
							{bone show	"glass_shard_r_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_05" enable contact blast bullet}
							{bone show	"glass_shard_r_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_06" enable contact blast bullet}
							{bone show	"glass_shard_r_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_07" enable contact blast bullet}
							{bone show	"glass_shard_r_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_08" enable contact blast bullet}
							{bone show	"glass_shard_r_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_r_09"}
							{volumes "glass_shard_r_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_r_10" enable contact blast bullet}
							{bone show	"glass_shard_r_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_11" enable contact blast bullet}
							{bone show	"glass_shard_r_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_12" enable contact blast bullet}
							{bone show	"glass_shard_r_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_13" enable contact blast bullet}
							{bone show	"glass_shard_r_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_14" enable contact blast bullet}
							{bone show	"glass_shard_r_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_15" enable contact blast bullet}
							{bone show	"glass_shard_r_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_16" enable contact blast bullet}
							{bone show	"glass_shard_r_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_17" enable contact blast bullet}
							{bone show	"glass_shard_r_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_18" enable contact blast bullet}
							{bone show	"glass_shard_r_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_19" enable contact blast bullet}
							{bone show	"glass_shard_r_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_20" enable contact blast bullet}
							{bone show	"glass_shard_r_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_21" enable contact blast bullet}
							{bone show	"glass_shard_r_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_22" enable contact blast bullet}
							{bone show	"glass_shard_r_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_23" enable contact blast bullet}
							{bone show	"glass_shard_r_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_r_24" enable contact blast bullet}
							{bone show	"glass_shard_r_24"}
						}
					}
				}
				{if volume "glass_l"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_l" disable all}
						{spawn	"glass_hit2" "fx_break_l_00" x}
						{spawn	"glass_hit3" "fx_break_l_01" x}
						{spawn	"glass_hit3" "fx_break_l_02" x}
						{spawn	"break_glass_01" "fx_break_l_01" x}
						{spawn	"break_glass_02" "fx_break_l_02" x}
						{spawn	"break_glass_03" "fx_break_l_03" x}
						{spawn	"break_glass_04" "fx_break_l_04" x}
						{bone hide	"glass_l"}
						{if rand 0.5
							{bone show	"glass_shard_door_l_00"}
							{volumes "glass_shard_door_l_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_l_01"}
							{volumes "glass_shard_door_l_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_02" enable contact blast bullet}
							{bone show	"glass_shard_door_l_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_03" enable contact blast bullet}
							{bone show	"glass_shard_door_l_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_04" enable contact blast bullet}
							{bone show	"glass_shard_door_l_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_05" enable contact blast bullet}
							{bone show	"glass_shard_door_l_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_06" enable contact blast bullet}
							{bone show	"glass_shard_door_l_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_07" enable contact blast bullet}
							{bone show	"glass_shard_door_l_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_08" enable contact blast bullet}
							{bone show	"glass_shard_door_l_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_l_09"}
							{volumes "glass_shard_door_l_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_10" enable contact blast bullet}
							{bone show	"glass_shard_door_l_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_11" enable contact blast bullet}
							{bone show	"glass_shard_door_l_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_12" enable contact blast bullet}
							{bone show	"glass_shard_door_l_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_13" enable contact blast bullet}
							{bone show	"glass_shard_door_l_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_14" enable contact blast bullet}
							{bone show	"glass_shard_door_l_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_15" enable contact blast bullet}
							{bone show	"glass_shard_door_l_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_16" enable contact blast bullet}
							{bone show	"glass_shard_door_l_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_17" enable contact blast bullet}
							{bone show	"glass_shard_door_l_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_18" enable contact blast bullet}
							{bone show	"glass_shard_door_l_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_19" enable contact blast bullet}
							{bone show	"glass_shard_door_l_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_20" enable contact blast bullet}
							{bone show	"glass_shard_door_l_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_21" enable contact blast bullet}
							{bone show	"glass_shard_door_l_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_22" enable contact blast bullet}
							{bone show	"glass_shard_door_l_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_23" enable contact blast bullet}
							{bone show	"glass_shard_door_l_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_l_24" enable contact blast bullet}
							{bone show	"glass_shard_door_l_24"}
						}
					}
				}
				{if volume "glass_r"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.3
						{volumes "glass_r" disable all}
						{spawn	"glass_hit2" "fx_break_r_00" x}
						{spawn	"glass_hit3" "fx_break_r_01" x}
						{spawn	"glass_hit3" "fx_break_r_02" x}
						{spawn	"break_glass_01" "fx_break_r_01" x}
						{spawn	"break_glass_02" "fx_break_r_02" x}
						{spawn	"break_glass_03" "fx_break_r_03" x}
						{spawn	"break_glass_04" "fx_break_r_04" x}
						{bone hide	"glass_r"}
						{if rand 0.5
							{bone show	"glass_shard_door_r_00"}
							{volumes "glass_shard_door_r_00" enable contact blast bullet}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_r_01"}
							{volumes "glass_shard_door_r_01" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_02" enable contact blast bullet}
							{bone show	"glass_shard_door_r_02"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_03" enable contact blast bullet}
							{bone show	"glass_shard_door_r_03"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_04" enable contact blast bullet}
							{bone show	"glass_shard_door_r_04"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_05" enable contact blast bullet}
							{bone show	"glass_shard_door_r_05"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_06" enable contact blast bullet}
							{bone show	"glass_shard_door_r_06"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_07" enable contact blast bullet}
							{bone show	"glass_shard_door_r_07"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_08" enable contact blast bullet}
							{bone show	"glass_shard_door_r_08"}
						}
						{if rand 0.5
							{bone show	"glass_shard_door_r_09"}
							{volumes "glass_shard_door_r_09" enable contact blast bullet}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_10" enable contact blast bullet}
							{bone show	"glass_shard_door_r_10"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_11" enable contact blast bullet}
							{bone show	"glass_shard_door_r_11"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_12" enable contact blast bullet}
							{bone show	"glass_shard_door_r_12"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_13" enable contact blast bullet}
							{bone show	"glass_shard_door_r_13"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_14" enable contact blast bullet}
							{bone show	"glass_shard_door_r_14"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_15" enable contact blast bullet}
							{bone show	"glass_shard_door_r_15"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_16" enable contact blast bullet}
							{bone show	"glass_shard_door_r_16"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_17" enable contact blast bullet}
							{bone show	"glass_shard_door_r_17"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_18" enable contact blast bullet}
							{bone show	"glass_shard_door_r_18"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_19" enable contact blast bullet}
							{bone show	"glass_shard_door_r_19"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_20" enable contact blast bullet}
							{bone show	"glass_shard_door_r_20"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_21" enable contact blast bullet}
							{bone show	"glass_shard_door_r_21"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_22" enable contact blast bullet}
							{bone show	"glass_shard_door_r_22"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_23" enable contact blast bullet}
							{bone show	"glass_shard_door_r_23"}
						}
						{if rand 0.5
							{volumes "glass_shard_door_r_24" enable contact blast bullet}
							{bone show	"glass_shard_door_r_24"}
						}
					}
				}
				{if volume "shard"
					{spawn	"glass_hit_sm_bullet"}
					{if rand 0.5
						{spawn	"glass_hit_small" }
						{tear "piece_small_glass" bone from_volume
							{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
			}
		}
	}
	{on pierce
		{if volume "glass_front_00"
			{spawn	"glass_hit_sm_bullet"}
			{if rand 0.3
				{spawn	"glass_hit2" "fx_break_f_l_00" x}
				{spawn	"glass_hit3" "fx_break_f_l_01" x}
				{spawn	"glass_hit3" "fx_break_f_l_02" x}
				{spawn	"break_glass_01" "fx_break_f_l_01" x}
				{spawn	"break_glass_02" "fx_break_f_l_02" x}
				{spawn	"break_glass_03" "fx_break_f_l_03" x}
				{spawn	"break_glass_04" "fx_break_f_l_04" x}
				{bone hide "glass_front_00"}
				{volumes "glass_front_00" disable all}
				{if rand 0.8
					{bone show	"glass_shard_l_00"}
					{volumes "glass_shard_l_00" enable contact blast bullet}
				}
				{if rand 0.8
					{bone show	"glass_shard_l_01"}
					{volumes "glass_shard_l_01" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_l_02" enable contact blast bullet}
					{bone show	"glass_shard_l_02"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_03" enable contact blast bullet}
					{bone show	"glass_shard_l_03"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_04" enable contact blast bullet}
					{bone show	"glass_shard_l_04"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_05" enable contact blast bullet}
					{bone show	"glass_shard_l_05"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_06" enable contact blast bullet}
					{bone show	"glass_shard_l_06"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_07" enable contact blast bullet}
					{bone show	"glass_shard_l_07"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_08" enable contact blast bullet}
					{bone show	"glass_shard_l_08"}
				}
				{if rand 0.8
					{bone show	"glass_shard_l_09"}
					{volumes "glass_shard_l_09" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_l_10" enable contact blast bullet}
					{bone show	"glass_shard_l_10"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_11" enable contact blast bullet}
					{bone show	"glass_shard_l_11"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_12" enable contact blast bullet}
					{bone show	"glass_shard_l_12"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_13" enable contact blast bullet}
					{bone show	"glass_shard_l_13"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_14" enable contact blast bullet}
					{bone show	"glass_shard_l_14"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_15" enable contact blast bullet}
					{bone show	"glass_shard_l_15"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_16" enable contact blast bullet}
					{bone show	"glass_shard_l_16"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_17" enable contact blast bullet}
					{bone show	"glass_shard_l_17"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_18" enable contact blast bullet}
					{bone show	"glass_shard_l_18"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_19" enable contact blast bullet}
					{bone show	"glass_shard_l_19"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_20" enable contact blast bullet}
					{bone show	"glass_shard_l_20"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_21" enable contact blast bullet}
					{bone show	"glass_shard_l_21"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_22" enable contact blast bullet}
					{bone show	"glass_shard_l_22"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_23" enable contact blast bullet}
					{bone show	"glass_shard_l_23"}
				}
				{if rand 0.8
					{volumes "glass_shard_l_24" enable contact blast bullet}
					{bone show	"glass_shard_l_24"}
				}
			}
		}
		{if volume "glass_front_01"
			{spawn	"glass_hit_sm_bullet"}
			{if rand 0.3
				{volumes "glass_front_01" disable all}
				{spawn	"glass_hit2" "fx_break_f_r_00" x}
				{spawn	"glass_hit3" "fx_break_f_r_01" x}
				{spawn	"glass_hit3" "fx_break_f_r_02" x}
				{spawn	"break_glass_01" "fx_break_f_r_01" x}
				{spawn	"break_glass_02" "fx_break_f_r_02" x}
				{spawn	"break_glass_03" "fx_break_f_r_03" x}
				{spawn	"break_glass_04" "fx_break_f_r_04" x}
				{bone hide	"glass_front_01"}
				{if rand 0.8
					{bone show	"glass_shard_r_00"}
					{volumes "glass_shard_r_00" enable contact blast bullet}
				}
				{if rand 0.8
					{bone show	"glass_shard_r_01"}
					{volumes "glass_shard_r_01" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_r_02" enable contact blast bullet}
					{bone show	"glass_shard_r_02"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_03" enable contact blast bullet}
					{bone show	"glass_shard_r_03"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_04" enable contact blast bullet}
					{bone show	"glass_shard_r_04"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_05" enable contact blast bullet}
					{bone show	"glass_shard_r_05"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_06" enable contact blast bullet}
					{bone show	"glass_shard_r_06"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_07" enable contact blast bullet}
					{bone show	"glass_shard_r_07"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_08" enable contact blast bullet}
					{bone show	"glass_shard_r_08"}
				}
				{if rand 0.8
					{bone show	"glass_shard_r_09"}
					{volumes "glass_shard_r_09" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_r_10" enable contact blast bullet}
					{bone show	"glass_shard_r_10"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_11" enable contact blast bullet}
					{bone show	"glass_shard_r_11"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_12" enable contact blast bullet}
					{bone show	"glass_shard_r_12"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_13" enable contact blast bullet}
					{bone show	"glass_shard_r_13"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_14" enable contact blast bullet}
					{bone show	"glass_shard_r_14"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_15" enable contact blast bullet}
					{bone show	"glass_shard_r_15"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_16" enable contact blast bullet}
					{bone show	"glass_shard_r_16"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_17" enable contact blast bullet}
					{bone show	"glass_shard_r_17"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_18" enable contact blast bullet}
					{bone show	"glass_shard_r_18"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_19" enable contact blast bullet}
					{bone show	"glass_shard_r_19"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_20" enable contact blast bullet}
					{bone show	"glass_shard_r_20"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_21" enable contact blast bullet}
					{bone show	"glass_shard_r_21"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_22" enable contact blast bullet}
					{bone show	"glass_shard_r_22"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_23" enable contact blast bullet}
					{bone show	"glass_shard_r_23"}
				}
				{if rand 0.8
					{volumes "glass_shard_r_24" enable contact blast bullet}
					{bone show	"glass_shard_r_24"}
				}
			}
		}
		{if volume "glass_l"
			{spawn	"glass_hit_sm_bullet"}
			{if rand 0.3
				{volumes "glass_l" disable all}
				{spawn	"glass_hit2" "fx_break_l_00" x}
				{spawn	"glass_hit3" "fx_break_l_01" x}
				{spawn	"glass_hit3" "fx_break_l_02" x}
				{spawn	"break_glass_01" "fx_break_l_01" x}
				{spawn	"break_glass_02" "fx_break_l_02" x}
				{spawn	"break_glass_03" "fx_break_l_03" x}
				{spawn	"break_glass_04" "fx_break_l_04" x}
				{bone hide	"glass_l"}
				{if rand 0.8
					{bone show	"glass_shard_door_l_00"}
					{volumes "glass_shard_door_l_00" enable contact blast bullet}
				}
				{if rand 0.8
					{bone show	"glass_shard_door_l_01"}
					{volumes "glass_shard_door_l_01" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_02" enable contact blast bullet}
					{bone show	"glass_shard_door_l_02"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_03" enable contact blast bullet}
					{bone show	"glass_shard_door_l_03"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_04" enable contact blast bullet}
					{bone show	"glass_shard_door_l_04"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_05" enable contact blast bullet}
					{bone show	"glass_shard_door_l_05"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_06" enable contact blast bullet}
					{bone show	"glass_shard_door_l_06"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_07" enable contact blast bullet}
					{bone show	"glass_shard_door_l_07"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_08" enable contact blast bullet}
					{bone show	"glass_shard_door_l_08"}
				}
				{if rand 0.8
					{bone show	"glass_shard_door_l_09"}
					{volumes "glass_shard_door_l_09" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_10" enable contact blast bullet}
					{bone show	"glass_shard_door_l_10"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_11" enable contact blast bullet}
					{bone show	"glass_shard_door_l_11"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_12" enable contact blast bullet}
					{bone show	"glass_shard_door_l_12"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_13" enable contact blast bullet}
					{bone show	"glass_shard_door_l_13"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_14" enable contact blast bullet}
					{bone show	"glass_shard_door_l_14"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_15" enable contact blast bullet}
					{bone show	"glass_shard_door_l_15"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_16" enable contact blast bullet}
					{bone show	"glass_shard_door_l_16"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_17" enable contact blast bullet}
					{bone show	"glass_shard_door_l_17"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_18" enable contact blast bullet}
					{bone show	"glass_shard_door_l_18"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_19" enable contact blast bullet}
					{bone show	"glass_shard_door_l_19"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_20" enable contact blast bullet}
					{bone show	"glass_shard_door_l_20"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_21" enable contact blast bullet}
					{bone show	"glass_shard_door_l_21"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_22" enable contact blast bullet}
					{bone show	"glass_shard_door_l_22"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_23" enable contact blast bullet}
					{bone show	"glass_shard_door_l_23"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_l_24" enable contact blast bullet}
					{bone show	"glass_shard_door_l_24"}
				}
			}
		}
		{if volume "glass_r"
			{spawn	"glass_hit_sm_bullet"}
			{if rand 0.3
				{volumes "glass_r" disable all}
				{spawn	"glass_hit2" "fx_break_r_00" x}
				{spawn	"glass_hit3" "fx_break_r_01" x}
				{spawn	"glass_hit3" "fx_break_r_02" x}
				{spawn	"break_glass_01" "fx_break_r_01" x}
				{spawn	"break_glass_02" "fx_break_r_02" x}
				{spawn	"break_glass_03" "fx_break_r_03" x}
				{spawn	"break_glass_04" "fx_break_r_04" x}
				{bone hide	"glass_r"}
				{if rand 0.8
					{bone show	"glass_shard_door_r_00"}
					{volumes "glass_shard_door_r_00" enable contact blast bullet}
				}
				{if rand 0.8
					{bone show	"glass_shard_door_r_01"}
					{volumes "glass_shard_door_r_01" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_02" enable contact blast bullet}
					{bone show	"glass_shard_door_r_02"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_03" enable contact blast bullet}
					{bone show	"glass_shard_door_r_03"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_04" enable contact blast bullet}
					{bone show	"glass_shard_door_r_04"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_05" enable contact blast bullet}
					{bone show	"glass_shard_door_r_05"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_06" enable contact blast bullet}
					{bone show	"glass_shard_door_r_06"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_07" enable contact blast bullet}
					{bone show	"glass_shard_door_r_07"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_08" enable contact blast bullet}
					{bone show	"glass_shard_door_r_08"}
				}
				{if rand 0.8
					{bone show	"glass_shard_door_r_09"}
					{volumes "glass_shard_door_r_09" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_10" enable contact blast bullet}
					{bone show	"glass_shard_door_r_10"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_11" enable contact blast bullet}
					{bone show	"glass_shard_door_r_11"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_12" enable contact blast bullet}
					{bone show	"glass_shard_door_r_12"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_13" enable contact blast bullet}
					{bone show	"glass_shard_door_r_13"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_14" enable contact blast bullet}
					{bone show	"glass_shard_door_r_14"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_15" enable contact blast bullet}
					{bone show	"glass_shard_door_r_15"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_16" enable contact blast bullet}
					{bone show	"glass_shard_door_r_16"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_17" enable contact blast bullet}
					{bone show	"glass_shard_door_r_17"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_18" enable contact blast bullet}
					{bone show	"glass_shard_door_r_18"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_19" enable contact blast bullet}
					{bone show	"glass_shard_door_r_19"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_20" enable contact blast bullet}
					{bone show	"glass_shard_door_r_20"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_21" enable contact blast bullet}
					{bone show	"glass_shard_door_r_21"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_22" enable contact blast bullet}
					{bone show	"glass_shard_door_r_22"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_23" enable contact blast bullet}
					{bone show	"glass_shard_door_r_23"}
				}
				{if rand 0.8
					{volumes "glass_shard_door_r_24" enable contact blast bullet}
					{bone show	"glass_shard_door_r_24"}
				}
			}
		}
		{if volume "shard"
			{spawn	"glass_hit_sm_bullet"}
			{if rand 0.5
				{spawn	"glass_hit_small" }
				{tear "piece_small_glass" bone from_volume
					{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
				}
			}
		}
	}
	{on "break_all_glass_expl"
		{delay 0.2
			(define "break_glass"
				{if rand 0.3
					{spawn "glass_hit_car" %0}
				}
				{delay 0.1
					{bone hide %0}
					{bone cut %0}
				}
			)
	;		("break_glass" args "front_glass" )
	;		("break_glass" args "glass_doorl" )
	;		("break_glass" args "glass_doorl1" )
	;		("break_glass" args "glass_doorr" )
	;		("break_glass" args "glass_doorr1" )
	;		("break_glass" args "back_glass" )
	;		("break_glass" args "glass_upper" )	
			("break_glass" args "front_glass_r_1" )
			("break_glass" args "front_glass_r_2" )
			("break_glass" args "front_glass_l_1" )
			("break_glass" args "front_glass_l_2" )
			("break_glass" args "glass_lamp_l" )
			("break_glass" args "glass_lamp_l2" )
			("break_glass" args "glass_lamp_r" )
			("break_glass" args "glass_lamp_r2" )
			("break_glass" args "back_glass_l_1" )
			("break_glass" args "back_glass_l_2" )
			("break_glass" args "back_glass_r_1" )
			("break_glass" args "back_glass_r_2" )
			{spawn	"glass_hit2" "fx_break_f_l_00"}
			{spawn	"glass_hit3" "fx_break_f_l_01"}
			{spawn	"glass_hit3" "fx_break_f_l_02"}
			{spawn	"break_glass_01" "fx_break_f_l_01"}
			{spawn	"break_glass_02" "fx_break_f_l_02"}
			{spawn	"break_glass_03" "fx_break_f_l_03"}
			{spawn	"break_glass_04" "fx_break_f_l_04"}
			{bone cut	"glass_front_00"}
			{spawn	"glass_hit2" "fx_break_f_r_00"}
			{spawn	"glass_hit3" "fx_break_f_r_01"}
			{spawn	"glass_hit3" "fx_break_f_r_02"}
			{spawn	"break_glass_01" "fx_break_f_r_01"}
			{spawn	"break_glass_02" "fx_break_f_r_02"}
			{spawn	"break_glass_03" "fx_break_f_r_03"}
			{spawn	"break_glass_04" "fx_break_f_r_04"}
			{bone cut	"glass_front_01"}
			{spawn	"glass_hit2" "fx_break_l_00"}
			{spawn	"glass_hit3" "fx_break_l_01"}
			{spawn	"glass_hit3" "fx_break_l_02"}
			{spawn	"break_glass_01" "fx_break_l_01"}
			{spawn	"break_glass_02" "fx_break_l_02"}
			{spawn	"break_glass_03" "fx_break_l_03"}
			{spawn	"break_glass_04" "fx_break_l_04"}
			{bone cut	"glass_l"}
			{bone cut	"glass_l_damage"}
			{bone show	"glass_l_broken"}		
			{spawn	"glass_hit2" "fx_break_r_00"}
			{spawn	"glass_hit3" "fx_break_r_01"}
			{spawn	"glass_hit3" "fx_break_r_02"}
			{spawn	"break_glass_01" "fx_break_r_01"}
			{spawn	"break_glass_02" "fx_break_r_02"}
			{spawn	"break_glass_03" "fx_break_r_03"}
			{spawn	"break_glass_04" "fx_break_r_04"}
			{bone cut	"glass_r"}
			{bone cut	"glass_r_damage"}
			{bone show	"glass_r_broken"}				
			{spawn	"glass_hit3" "fx_break_r_02"}
			{bone cut	"glass_r1"}
			{bone cut	"glass_r1_damage"}
			{spawn		"glass_hit3" "glass_r1_broken"}
			{bone show	"glass_r1_broken"}
			{bone cut	"glass_l1"}
			{bone cut	"glass_l1_damage"}
			{bone show	"glass_l1_broken"}
			{bone cut	"glass_r2"}
			{bone cut	"glass_r2_damage"}
			{spawn		"glass_hit3" "glass_r2_broken"}
			{bone show	"glass_r2_broken"}
			{bone cut	"glass_l2"}
			{bone cut	"glass_l2_damage"}
			{bone show	"glass_l2_broken"}
		}
	}
	{on blast
		{if min_energy 0.5
			{if volume "glass_front_00"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.3
					{volumes "glass_front_00" disable all}
					{spawn	"glass_hit2" "fx_break_f_l_00"}
					{spawn	"glass_hit3" "fx_break_f_l_01"}
					{spawn	"glass_hit3" "fx_break_f_l_02"}
					{spawn	"break_glass_01" "fx_break_f_l_01"}
					{spawn	"break_glass_02" "fx_break_f_l_02"}
					{spawn	"break_glass_03" "fx_break_f_l_03"}
					{spawn	"break_glass_04" "fx_break_f_l_04"}
					{bone hide	"glass_front_00"}
					{if rand 0.8
						{bone show	"glass_shard_l_00"}
						{volumes "glass_shard_l_00" enable contact blast bullet}
					}
					{if rand 0.8
						{bone show	"glass_shard_l_01"}
						{volumes "glass_shard_l_01" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_l_02" enable contact blast bullet}
						{bone show	"glass_shard_l_02"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_03" enable contact blast bullet}
						{bone show	"glass_shard_l_03"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_04" enable contact blast bullet}
						{bone show	"glass_shard_l_04"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_05" enable contact blast bullet}
						{bone show	"glass_shard_l_05"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_06" enable contact blast bullet}
						{bone show	"glass_shard_l_06"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_07" enable contact blast bullet}
						{bone show	"glass_shard_l_07"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_08" enable contact blast bullet}
						{bone show	"glass_shard_l_08"}
					}
					{if rand 0.8
						{bone show	"glass_shard_l_09"}
						{volumes "glass_shard_l_09" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_l_10" enable contact blast bullet}
						{bone show	"glass_shard_l_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_11" enable contact blast bullet}
						{bone show	"glass_shard_l_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_12" enable contact blast bullet}
						{bone show	"glass_shard_l_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_13" enable contact blast bullet}
						{bone show	"glass_shard_l_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_14" enable contact blast bullet}
						{bone show	"glass_shard_l_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_15" enable contact blast bullet}
						{bone show	"glass_shard_l_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_16" enable contact blast bullet}
						{bone show	"glass_shard_l_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_17" enable contact blast bullet}
						{bone show	"glass_shard_l_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_18" enable contact blast bullet}
						{bone show	"glass_shard_l_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_19" enable contact blast bullet}
						{bone show	"glass_shard_l_19"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_20" enable contact blast bullet}
						{bone show	"glass_shard_l_20"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_21" enable contact blast bullet}
						{bone show	"glass_shard_l_21"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_22" enable contact blast bullet}
						{bone show	"glass_shard_l_22"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_23" enable contact blast bullet}
						{bone show	"glass_shard_l_23"}
					}
					{if rand 0.8
						{volumes "glass_shard_l_24" enable contact blast bullet}
						{bone show	"glass_shard_l_24"}
					}
				}
			}
			{if volume "glass_front_01"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.3
					{volumes "glass_front_01" disable all}
					{spawn	"glass_hit2" "fx_break_f_r_00"}
					{spawn	"glass_hit3" "fx_break_f_r_01"}
					{spawn	"glass_hit3" "fx_break_f_r_02"}
					{spawn	"break_glass_01" "fx_break_f_r_01"}
					{spawn	"break_glass_02" "fx_break_f_r_02"}
					{spawn	"break_glass_03" "fx_break_f_r_03"}
					{spawn	"break_glass_04" "fx_break_f_r_04"}
					{bone hide	"glass_front_01"}
					{if rand 0.8
						{bone show	"glass_shard_r_00"}
						{volumes "glass_shard_r_00" enable contact blast bullet}
					}
					{if rand 0.8
						{bone show	"glass_shard_r_01"}
						{volumes "glass_shard_r_01" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_r_02" enable contact blast bullet}
						{bone show	"glass_shard_r_02"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_03" enable contact blast bullet}
						{bone show	"glass_shard_r_03"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_04" enable contact blast bullet}
						{bone show	"glass_shard_r_04"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_05" enable contact blast bullet}
						{bone show	"glass_shard_r_05"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_06" enable contact blast bullet}
						{bone show	"glass_shard_r_06"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_07" enable contact blast bullet}
						{bone show	"glass_shard_r_07"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_08" enable contact blast bullet}
						{bone show	"glass_shard_r_08"}
					}
					{if rand 0.8
						{bone show	"glass_shard_r_09"}
						{volumes "glass_shard_r_09" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_r_10" enable contact blast bullet}
						{bone show	"glass_shard_r_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_11" enable contact blast bullet}
						{bone show	"glass_shard_r_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_12" enable contact blast bullet}
						{bone show	"glass_shard_r_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_13" enable contact blast bullet}
						{bone show	"glass_shard_r_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_14" enable contact blast bullet}
						{bone show	"glass_shard_r_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_15" enable contact blast bullet}
						{bone show	"glass_shard_r_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_16" enable contact blast bullet}
						{bone show	"glass_shard_r_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_17" enable contact blast bullet}
						{bone show	"glass_shard_r_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_18" enable contact blast bullet}
						{bone show	"glass_shard_r_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_19" enable contact blast bullet}
						{bone show	"glass_shard_r_19"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_20" enable contact blast bullet}
						{bone show	"glass_shard_r_20"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_21" enable contact blast bullet}
						{bone show	"glass_shard_r_21"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_22" enable contact blast bullet}
						{bone show	"glass_shard_r_22"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_23" enable contact blast bullet}
						{bone show	"glass_shard_r_23"}
					}
					{if rand 0.8
						{volumes "glass_shard_r_24" enable contact blast bullet}
						{bone show	"glass_shard_r_24"}
					}
				}
			}
			{if volume "glass_l"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.3
					{volumes "glass_l" disable all}
					{spawn	"glass_hit2" "fx_break_l_00"}
					{spawn	"glass_hit3" "fx_break_l_01"}
					{spawn	"glass_hit3" "fx_break_l_02"}
					{spawn	"break_glass_01" "fx_break_l_01"}
					{spawn	"break_glass_02" "fx_break_l_02"}
					{spawn	"break_glass_03" "fx_break_l_03"}
					{spawn	"break_glass_04" "fx_break_l_04"}
					{bone hide	"glass_l"}
					{if rand 0.8
						{bone show	"glass_shard_door_l_00"}
						{volumes "glass_shard_door_l_00" enable contact blast bullet}
					}
					{if rand 0.8
						{bone show	"glass_shard_door_l_01"}
						{volumes "glass_shard_door_l_01" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_02" enable contact blast bullet}
						{bone show	"glass_shard_door_l_02"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_03" enable contact blast bullet}
						{bone show	"glass_shard_door_l_03"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_04" enable contact blast bullet}
						{bone show	"glass_shard_door_l_04"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_05" enable contact blast bullet}
						{bone show	"glass_shard_door_l_05"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_06" enable contact blast bullet}
						{bone show	"glass_shard_door_l_06"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_07" enable contact blast bullet}
						{bone show	"glass_shard_door_l_07"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_08" enable contact blast bullet}
						{bone show	"glass_shard_door_l_08"}
					}
					{if rand 0.8
						{bone show	"glass_shard_door_l_09"}
						{volumes "glass_shard_door_l_09" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_10" enable contact blast bullet}
						{bone show	"glass_shard_door_l_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_11" enable contact blast bullet}
						{bone show	"glass_shard_door_l_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_12" enable contact blast bullet}
						{bone show	"glass_shard_door_l_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_13" enable contact blast bullet}
						{bone show	"glass_shard_door_l_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_14" enable contact blast bullet}
						{bone show	"glass_shard_door_l_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_15" enable contact blast bullet}
						{bone show	"glass_shard_door_l_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_16" enable contact blast bullet}
						{bone show	"glass_shard_door_l_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_17" enable contact blast bullet}
						{bone show	"glass_shard_door_l_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_18" enable contact blast bullet}
						{bone show	"glass_shard_door_l_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_19" enable contact blast bullet}
						{bone show	"glass_shard_door_l_19"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_20" enable contact blast bullet}
						{bone show	"glass_shard_door_l_20"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_21" enable contact blast bullet}
						{bone show	"glass_shard_door_l_21"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_22" enable contact blast bullet}
						{bone show	"glass_shard_door_l_22"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_23" enable contact blast bullet}
						{bone show	"glass_shard_door_l_23"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_l_24" enable contact blast bullet}
						{bone show	"glass_shard_door_l_24"}
					}
				}
			}
			{if volume "glass_r"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.3
					{volumes "glass_r" disable all}
					{spawn	"glass_hit2" "fx_break_r_00"}
					{spawn	"glass_hit3" "fx_break_r_01"}
					{spawn	"glass_hit3" "fx_break_r_02"}
					{spawn	"break_glass_01" "fx_break_r_01"}
					{spawn	"break_glass_02" "fx_break_r_02"}
					{spawn	"break_glass_03" "fx_break_r_03"}
					{spawn	"break_glass_04" "fx_break_r_04"}
					{bone hide	"glass_r"}
					{if rand 0.8
						{bone show	"glass_shard_door_r_00"}
						{volumes "glass_shard_door_r_00" enable contact blast bullet}
					}
					{if rand 0.8
						{bone show	"glass_shard_door_r_01"}
						{volumes "glass_shard_door_r_01" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_02" enable contact blast bullet}
						{bone show	"glass_shard_door_r_02"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_03" enable contact blast bullet}
						{bone show	"glass_shard_door_r_03"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_04" enable contact blast bullet}
						{bone show	"glass_shard_door_r_04"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_05" enable contact blast bullet}
						{bone show	"glass_shard_door_r_05"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_06" enable contact blast bullet}
						{bone show	"glass_shard_door_r_06"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_07" enable contact blast bullet}
						{bone show	"glass_shard_door_r_07"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_08" enable contact blast bullet}
						{bone show	"glass_shard_door_r_08"}
					}
					{if rand 0.8
						{bone show	"glass_shard_door_r_09"}
						{volumes "glass_shard_door_r_09" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_10" enable contact blast bullet}
						{bone show	"glass_shard_door_r_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_11" enable contact blast bullet}
						{bone show	"glass_shard_door_r_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_12" enable contact blast bullet}
						{bone show	"glass_shard_door_r_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_13" enable contact blast bullet}
						{bone show	"glass_shard_door_r_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_14" enable contact blast bullet}
						{bone show	"glass_shard_door_r_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_15" enable contact blast bullet}
						{bone show	"glass_shard_door_r_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_16" enable contact blast bullet}
						{bone show	"glass_shard_door_r_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_17" enable contact blast bullet}
						{bone show	"glass_shard_door_r_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_18" enable contact blast bullet}
						{bone show	"glass_shard_door_r_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_19" enable contact blast bullet}
						{bone show	"glass_shard_door_r_19"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_20" enable contact blast bullet}
						{bone show	"glass_shard_door_r_20"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_21" enable contact blast bullet}
						{bone show	"glass_shard_door_r_21"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_22" enable contact blast bullet}
						{bone show	"glass_shard_door_r_22"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_23" enable contact blast bullet}
						{bone show	"glass_shard_door_r_23"}
					}
					{if rand 0.8
						{volumes "glass_shard_door_r_24" enable contact blast bullet}
						{bone show	"glass_shard_door_r_24"}
					}
				}
			}
			{if volume "shard"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.7
					{spawn	"glass_hit_small" }
					{tear "piece_small_glass" bone from_volume
						{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}
			}
		}
	}
}



{"glass_frame"
	{on spawn
		{bone hide	"glass_shard_1"}
		{bone hide	"glass_shard_2"}
		{bone hide	"glass_shard_3"}
		{bone hide	"glass_shard_4"}
		{bone hide	"glass_shard_5"}
		{bone hide	"glass_shard_6"}
		{bone hide	"glass_shard_7"}
		{bone hide	"glass_shard_8"}
		{bone hide	"glass_shard_9"}
		{bone hide	"glass_shard_10"}
		{bone hide	"glass_shard_11"}
		{bone hide	"glass_shard_12"}
		{bone hide	"glass_shard_13"}
		{bone hide	"glass_shard_14"}
		{bone hide	"glass_shard_15"}
		{bone hide	"glass_shard_16"}
		{bone hide	"glass_shard_17"}
		{bone hide	"glass_shard_18"}
		{bone hide	"glass_shard_19"}
		{volumes "glass_shard_1" disable all}
		{volumes "glass_shard_2" disable all}
		{volumes "glass_shard_3" disable all}
		{volumes "glass_shard_4" disable all}
		{volumes "glass_shard_5" disable all}
		{volumes "glass_shard_6" disable all}
		{volumes "glass_shard_7" disable all}
		{volumes "glass_shard_8" disable all}
		{volumes "glass_shard_9" disable all}
		{volumes "glass_shard_10" disable all}
		{volumes "glass_shard_11" disable all}
		{volumes "glass_shard_12" disable all}
		{volumes "glass_shard_13" disable all}
		{volumes "glass_shard_14" disable all}
		{volumes "glass_shard_15" disable all}
		{volumes "glass_shard_16" disable all}
		{volumes "glass_shard_17" disable all}
		{volumes "glass_shard_18" disable all}
		{volumes "glass_shard_19" disable all}
	}
	{on bullet_hit
		{if stuff "fx_40"
			{bullet_detonate}
		}
		{if volume "shard"
			{spawn	"glass_hit_sm_bullet"}
			{if stuff "bullet big"
				{spawn	"glass_hit_small" }			
				{tear "piece_delete" bone from_volume
					{delete}
				}
			else
				{if rand 0.7
					{spawn	"glass_sm_hit" }
					{tear "piece_small_glass" bone from_volume
						{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}
			}
		}
		{if volume "glass"
			(define "bullet_hit"
				{spawn	"glass_hit_sm_bullet"}
				{if stuff %0
					{if rand %1
						{volumes "glass" disable all}
						{spawn	"glass_hit2" "fx_break_01"}
						{spawn	"glass_hit3" "fx_break_03"}
						{spawn	"glass_hit3" "fx_break_04"}
						{spawn	"break_glass_01" "fx_break_01"}
						{spawn	"break_glass_02" "fx_break_02"}
						{spawn	"break_glass_03" "fx_break_03"}
						{spawn	"break_glass_04" "fx_break_04"}
						{spawn	"break_glass_03" "fx_break_05"}
						{bone hide	"glass"}
						{if rand 0.8
							{bone show	"glass_shard_1"}
							{volumes "glass_shard_1" enable contact blast bullet}
						}
						{if rand 0.8
							{volumes "glass_shard_2" enable contact blast bullet}
							{bone show	"glass_shard_2"}
						}
						{if rand 0.8
							{volumes "glass_shard_3" enable contact blast bullet}
							{bone show	"glass_shard_3"}
						}
						{if rand 0.8
							{volumes "glass_shard_4" enable contact blast bullet}
							{bone show	"glass_shard_4"}
						}
						{if rand 0.8
							{volumes "glass_shard_5" enable contact blast bullet}
							{bone show	"glass_shard_5"}
						}
						{if rand 0.8
							{volumes "glass_shard_6" enable contact blast bullet}
							{bone show	"glass_shard_6"}
						}
						{if rand 0.8
							{volumes "glass_shard_7" enable contact blast bullet}
							{bone show	"glass_shard_7"}
						}
						{if rand 0.8
							{volumes "glass_shard_8" enable contact blast bullet}
							{bone show	"glass_shard_8"}
						}
						{if rand 0.8
							{bone show	"glass_shard_9"}
							{volumes "glass_shard_9" enable contact blast bullet}
						}
						{if rand 0.8
							{volumes "glass_shard_10" enable contact blast bullet}
							{bone show	"glass_shard_10"}
						}
						{if rand 0.8
							{volumes "glass_shard_11" enable contact blast bullet}
							{bone show	"glass_shard_11"}
						}
						{if rand 0.8
							{volumes "glass_shard_12" enable contact blast bullet}
							{bone show	"glass_shard_12"}
						}
						{if rand 0.8
							{volumes "glass_shard_13" enable contact blast bullet}
							{bone show	"glass_shard_13"}
						}
						{if rand 0.8
							{volumes "glass_shard_14" enable contact blast bullet}
							{bone show	"glass_shard_14"}
						}
						{if rand 0.8
							{volumes "glass_shard_15" enable contact blast bullet}
							{bone show	"glass_shard_15"}
						}
						{if rand 0.8
							{volumes "glass_shard_16" enable contact blast bullet}
							{bone show	"glass_shard_16"}
						}
						{if rand 0.8
							{volumes "glass_shard_17" enable contact blast bullet}
							{bone show	"glass_shard_17"}
						}
						{if rand 0.8
							{volumes "glass_shard_18" enable contact blast bullet}
							{bone show	"glass_shard_18"}
						}
						{if rand 0.8
							{volumes "glass_shard_19" enable contact blast bullet}
							{bone show	"glass_shard_19"}
						}
					}
				}
			)
			("bullet_hit" args "bullet big"			0.4)
			("bullet_hit" args "bullet sp"			0.1)
			("bullet_hit" args "bullet ap"			0.3)
			("bullet_hit" args "shell"				0.9)			
			("bullet_hit" args "zenite"				0.9)			
		}
	}
	{on contact
		{if not effector "obstacle"	
			{if volume "shard"
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.7
					{spawn	"glass_hit_small" }
					{tear "piece_small_glass" bone from_volume
						{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				else rand 0.3
					{spawn	"glass_hit_small" }			
					{tear "piece_delete" bone from_volume
						{delete}
					}			
				}
			}
			{if volume "glass"
				{if effector "stuff"
					{spawn	"glass_hit_small" "glass"}
					{spawn	"break_glass_01" "fx_break_01"}
					{spawn	"break_glass_02" "fx_break_02"}
					{spawn	"break_glass_03" "fx_break_03"}
					{spawn	"break_glass_04" "fx_break_04"}
					{spawn	"break_glass_03" "fx_break_05"}
					{bone hide	"glass"}
					{volumes "glass" disable all}
					{if rand 0.8
						{bone show	"glass_shard_1"}
						{volumes "glass_shard_1" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_2" enable contact blast bullet}
						{bone show	"glass_shard_2"}
					}
					{if rand 0.8
						{volumes "glass_shard_3" enable contact blast bullet}
						{bone show	"glass_shard_3"}
					}
					{if rand 0.8
						{volumes "glass_shard_4" enable contact blast bullet}
						{bone show	"glass_shard_4"}
					}
					{if rand 0.8
						{volumes "glass_shard_5" enable contact blast bullet}
						{bone show	"glass_shard_5"}
					}
					{if rand 0.8
						{volumes "glass_shard_6" enable contact blast bullet}
						{bone show	"glass_shard_6"}
					}
					{if rand 0.8
						{volumes "glass_shard_7" enable contact blast bullet}
						{bone show	"glass_shard_7"}
					}
					{if rand 0.8
						{volumes "glass_shard_8" enable contact blast bullet}
						{bone show	"glass_shard_8"}
					}
					{if rand 0.8
						{bone show	"glass_shard_9"}
						{volumes "glass_shard_9" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_10" enable contact blast bullet}
						{bone show	"glass_shard_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_11" enable contact blast bullet}
						{bone show	"glass_shard_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_12" enable contact blast bullet}
						{bone show	"glass_shard_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_13" enable contact blast bullet}
						{bone show	"glass_shard_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_14" enable contact blast bullet}
						{bone show	"glass_shard_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_15" enable contact blast bullet}
						{bone show	"glass_shard_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_16" enable contact blast bullet}
						{bone show	"glass_shard_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_17" enable contact blast bullet}
						{bone show	"glass_shard_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_18" enable contact blast bullet}
						{bone show	"glass_shard_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_19" enable contact blast bullet}
						{bone show	"glass_shard_19"}
					}
				else effector "fraction"
					{spawn	"glass_hit_small" "glass"}
					{spawn	"break_glass_01" "fx_break_01"}
					{spawn	"break_glass_02" "fx_break_02"}
					{spawn	"break_glass_03" "fx_break_03"}
					{spawn	"break_glass_04" "fx_break_04"}
					{spawn	"break_glass_03" "fx_break_05"}
					{bone hide	"glass"}
					{volumes "glass" disable all}
					{if rand 0.8
						{bone show	"glass_shard_1"}
						{volumes "glass_shard_1" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_2" enable contact blast bullet}
						{bone show	"glass_shard_2"}
					}
					{if rand 0.8
						{volumes "glass_shard_3" enable contact blast bullet}
						{bone show	"glass_shard_3"}
					}
					{if rand 0.8
						{volumes "glass_shard_4" enable contact blast bullet}
						{bone show	"glass_shard_4"}
					}
					{if rand 0.8
						{volumes "glass_shard_5" enable contact blast bullet}
						{bone show	"glass_shard_5"}
					}
					{if rand 0.8
						{volumes "glass_shard_6" enable contact blast bullet}
						{bone show	"glass_shard_6"}
					}
					{if rand 0.8
						{volumes "glass_shard_7" enable contact blast bullet}
						{bone show	"glass_shard_7"}
					}
					{if rand 0.8
						{volumes "glass_shard_8" enable contact blast bullet}
						{bone show	"glass_shard_8"}
					}
					{if rand 0.8
						{bone show	"glass_shard_9"}
						{volumes "glass_shard_9" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_10" enable contact blast bullet}
						{bone show	"glass_shard_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_11" enable contact blast bullet}
						{bone show	"glass_shard_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_12" enable contact blast bullet}
						{bone show	"glass_shard_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_13" enable contact blast bullet}
						{bone show	"glass_shard_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_14" enable contact blast bullet}
						{bone show	"glass_shard_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_15" enable contact blast bullet}
						{bone show	"glass_shard_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_16" enable contact blast bullet}
						{bone show	"glass_shard_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_17" enable contact blast bullet}
						{bone show	"glass_shard_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_18" enable contact blast bullet}
						{bone show	"glass_shard_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_19" enable contact blast bullet}
						{bone show	"glass_shard_19"}
					}
				else 
					{spawn	"glass_hit_small" "glass"}
					{spawn	"break_glass_01" "fx_break_01"}
					{spawn	"break_glass_02" "fx_break_02"}
					{spawn	"break_glass_03" "fx_break_03"}
					{spawn	"break_glass_04" "fx_break_04"}
					{spawn	"break_glass_03" "fx_break_05"}
					{bone hide	"glass"}
					{volumes "glass" disable all}
					{if rand 0.8
						{bone show	"glass_shard_1"}
						{volumes "glass_shard_1" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_2" enable contact blast bullet}
						{bone show	"glass_shard_2"}
					}
					{if rand 0.8
						{volumes "glass_shard_3" enable contact blast bullet}
						{bone show	"glass_shard_3"}
					}
					{if rand 0.8
						{volumes "glass_shard_4" enable contact blast bullet}
						{bone show	"glass_shard_4"}
					}
					{if rand 0.8
						{volumes "glass_shard_5" enable contact blast bullet}
						{bone show	"glass_shard_5"}
					}
					{if rand 0.8
						{volumes "glass_shard_6" enable contact blast bullet}
						{bone show	"glass_shard_6"}
					}
					{if rand 0.8
						{volumes "glass_shard_7" enable contact blast bullet}
						{bone show	"glass_shard_7"}
					}
					{if rand 0.8
						{volumes "glass_shard_8" enable contact blast bullet}
						{bone show	"glass_shard_8"}
					}
					{if rand 0.8
						{bone show	"glass_shard_9"}
						{volumes "glass_shard_9" enable contact blast bullet}
					}
					{if rand 0.8
						{volumes "glass_shard_10" enable contact blast bullet}
						{bone show	"glass_shard_10"}
					}
					{if rand 0.8
						{volumes "glass_shard_11" enable contact blast bullet}
						{bone show	"glass_shard_11"}
					}
					{if rand 0.8
						{volumes "glass_shard_12" enable contact blast bullet}
						{bone show	"glass_shard_12"}
					}
					{if rand 0.8
						{volumes "glass_shard_13" enable contact blast bullet}
						{bone show	"glass_shard_13"}
					}
					{if rand 0.8
						{volumes "glass_shard_14" enable contact blast bullet}
						{bone show	"glass_shard_14"}
					}
					{if rand 0.8
						{volumes "glass_shard_15" enable contact blast bullet}
						{bone show	"glass_shard_15"}
					}
					{if rand 0.8
						{volumes "glass_shard_16" enable contact blast bullet}
						{bone show	"glass_shard_16"}
					}
					{if rand 0.8
						{volumes "glass_shard_17" enable contact blast bullet}
						{bone show	"glass_shard_17"}
					}
					{if rand 0.8
						{volumes "glass_shard_18" enable contact blast bullet}
						{bone show	"glass_shard_18"}
					}
					{if rand 0.8
						{volumes "glass_shard_19" enable contact blast bullet}
						{bone show	"glass_shard_19"}
					}
				}
			}
		}
	}
	{on blast
		;{if min_energy 0.1
			{if volume "glass"
				{spawn	"glass_hit_sm_bullet"}
				{spawn	"glass_hit" "fx_break_01"}
				{spawn	"glass_hit2" "fx_break_03"}
				{spawn	"glass_hit" "fx_break_04"}
				{spawn	"break_glass_01" "fx_break_01"}
				{spawn	"break_glass_02" "fx_break_02"}
				{spawn	"break_glass_03" "fx_break_03"}
				{spawn	"break_glass_04" "fx_break_04"}
				{spawn	"break_glass_03" "fx_break_05"}
				{bone hide	"glass"}
				{volumes "glass" disable all}
				{if rand 0.8
					{bone show	"glass_shard_1"}
					{volumes "glass_shard_1" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_2" enable contact blast bullet}
					{bone show	"glass_shard_2"}
				}
				{if rand 0.8
					{volumes "glass_shard_3" enable contact blast bullet}
					{bone show	"glass_shard_3"}
				}
				{if rand 0.8
					{volumes "glass_shard_4" enable contact blast bullet}
					{bone show	"glass_shard_4"}
				}
				{if rand 0.8
					{volumes "glass_shard_5" enable contact blast bullet}
					{bone show	"glass_shard_5"}
				}
				{if rand 0.8
					{volumes "glass_shard_6" enable contact blast bullet}
					{bone show	"glass_shard_6"}
				}
				{if rand 0.8
					{volumes "glass_shard_7" enable contact blast bullet}
					{bone show	"glass_shard_7"}
				}
				{if rand 0.8
					{volumes "glass_shard_8" enable contact blast bullet}
					{bone show	"glass_shard_8"}
				}
				{if rand 0.8
					{bone show	"glass_shard_9"}
					{volumes "glass_shard_9" enable contact blast bullet}
				}
				{if rand 0.8
					{volumes "glass_shard_10" enable contact blast bullet}
					{bone show	"glass_shard_10"}
				}
				{if rand 0.8
					{volumes "glass_shard_11" enable contact blast bullet}
					{bone show	"glass_shard_11"}
				}
				{if rand 0.8
					{volumes "glass_shard_12" enable contact blast bullet}
					{bone show	"glass_shard_12"}
				}
				{if rand 0.8
					{volumes "glass_shard_13" enable contact blast bullet}
					{bone show	"glass_shard_13"}
				}
				{if rand 0.8
					{volumes "glass_shard_14" enable contact blast bullet}
					{bone show	"glass_shard_14"}
				}
				{if rand 0.8
					{volumes "glass_shard_15" enable contact blast bullet}
					{bone show	"glass_shard_15"}
				}
				{if rand 0.8
					{volumes "glass_shard_16" enable contact blast bullet}
					{bone show	"glass_shard_16"}
				}
				{if rand 0.8
					{volumes "glass_shard_17" enable contact blast bullet}
					{bone show	"glass_shard_17"}
				}
				{if rand 0.8
					{volumes "glass_shard_18" enable contact blast bullet}
					{bone show	"glass_shard_18"}
				}
				{if rand 0.8
					{volumes "glass_shard_19" enable contact blast bullet}
					{bone show	"glass_shard_19"}
				}
			}
		;}
		{if volume "shard"
			{if min_energy 0.5
				{spawn	"glass_hit_sm_bullet"}
				{if rand 0.7
					{spawn	"glass_hit_small" }
					{tear "piece_small_glass" bone from_volume
						{impulse up 1.5 0.2 dir 1.5 cx 3 1 cy 3 1 rnd_dir 2 no_position}
					}
				}
			}
		}
	}
}






{"marble_frame"
;	(define "volume"
;		{volumes %0 disable all}
;		{volumes %1 enable contact_ground contact blast bullet}
;	)
	; {on spawn
		; {if not tagged "instal"
			; {tags add "instal"}
			; (define "hide_bone"
				; {volumes "broken_%0"  disable all}
			; )
			; ("hide_bone" args 00)
			; ("hide_bone" args 01)
			; ("hide_bone" args 02)
			; ("hide_bone" args 03)
			; ("hide_bone" args 04)
			; ("hide_bone" args 05)
			; ("hide_bone" args 06)
			; ("hide_bone" args 07)
			; ("hide_bone" args 08)
			; ("hide_bone" args 09)
			; ("hide_bone" args 10)
			; ("hide_bone" args 11)
			; ("hide_bone" args 12)
			; ("hide_bone" args 13)
			; ("hide_bone" args 14)
			; ("hide_bone" args 15)
			; ("hide_bone" args 16)
			; ("hide_bone" args 17)
			; ("hide_bone" args 18)
			; ("hide_bone" args 19)
			; ("hide_bone" args 20)
		; }
	; }
	
	{on pierce
		{if rand 0.1
			{if not linked
				{impulse dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
			else
				{unlink}
				{impulse up 0.1}
			}
		}
		(define "bullet_hit"
			{if stuff %stuff
				{if rand %rand
					{if volume "shard"
						{tear "piece_small_glass_nodelete" bone from_volume
							%impact
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  stuff   		   
		("bullet_hit" stuff("shell")			rand(1) 		impact({impulse up 1 0.5  	dir 7 4		cx 4 2 cy 4 2  	no_position}))
		("bullet_hit" stuff("heavy_zenite")		rand(1) 		impact({impulse up 3 1 		dir 5 2 	cx 7 3 cy 7 3  	no_position}))
		("bullet_hit" stuff("zenite")			rand(0.9) 		impact({impulse up 2 1 		dir 4 2 	cx 4 1 cy 4 1 	no_position}))
		("bullet_hit" stuff("bullet big")		rand(0.6) 		impact({impulse up 2 1 		dir 2 1 	cx 2 1 cy 2 1 	no_position}))
		("bullet_hit" stuff("bullet normal")	rand(0.3) 		impact({impulse up 1 0.5    dir 1 0.5 	cx 0.5 cy 0.5  	no_position}))
		("bullet_hit" stuff("bullet small")		rand(0.15) 		impact({impulse up 0.2 0.1 	dir 0.5 	cx 0.5 cy 0.5  	no_position}))
	}
	{on contact 		
		{if effector "semtex"	
			{impulse up 2 1 dir 2 1 cx 5 1 cy 5 1 rnd_dir 1 no_position}
		}
		{if not effector "obstacle"	
			(define "contact_hit"
				{if effector %0
					; {if rand %1
						; {if contact_velocity 2
							; {if volume "body"
								; {if not tagged "broken_glass"
									; {unlink}
									; {tags add "broken_glass"}
									; {bone hide "normal" }
									; {spawn "glass_hit_shrap_small2" "normal" } ; - marble_dust
									; {call "marble_set"}
									; {bone cut "normal"}
								; }
							; }				
						; }
					; }				
					{if contact_velocity 2
						{if volume "shard"
							{if rand %2
								{unlink}
								{tear "piece_small_glass_nodelete" bone from_volume
									{impulse dir 1.5 0.7 cx 2 1 cy 2 1 rnd_dir 2 no_position}
								}
							}
						}
					}
				}
			)
			;                  ------   первичный вторичный финальный
			("contact_hit" args "fraction"	1 0.7 1	)
			("contact_hit" args "vehicle"	1 1 1	)
			("contact_hit" args "grenade"	0.3 0.2 0.2	)
			("contact_hit" args "weight"	1 0.9 0.8	)
			("contact_hit" args "stuff"		0.6 0.3 0.1	)
		}
	}
	{on blast
		(define "blast_hit"
			{if min_energy %blast
				; {if rand %first
					; {if volume "body"
						; {unlink}
						; {if not tagged "broken_glass"
							; {tags add "broken_glass"}
							; {bone hide "normal" }
							; {spawn "glass_hit_shrap_small2" "normal" } ; - marble_dust
							; {call "marble_set"}
							; {bone cut "normal"}
						; }
					; }				
				; }				
				{if volume "shard"
					{if rand %end
						(define "blast"
							{tear "piece_small_glass_nodelete" bone "%bone"
								{spawn	"glass_hit_shrap_small" }
								{impulse dir 2 1 cx 2 1 cy 2 1 no_position}
							}
						)
						("blast"  bone(broken_00))
						("blast"  bone(broken_01))
						("blast"  bone(broken_02))
						("blast"  bone(broken_03))
						("blast"  bone(broken_04))
						("blast"  bone(broken_05))
						("blast"  bone(broken_06))
						("blast"  bone(broken_07))
						("blast"  bone(broken_08))
						("blast"  bone(broken_09))
						("blast"  bone(broken_10))
						("blast"  bone(broken_11))
						("blast"  bone(broken_12))
						("blast"  bone(broken_13))
						("blast"  bone(broken_14))
						("blast"  bone(broken_15))
						("blast"  bone(broken_16))
						("blast"  bone(broken_17))
						("blast"  bone(broken_18))
						("blast"  bone(broken_19))
						("blast"  bone(broken_20))
						("blast"  bone(broken_21))
						("blast"  bone(broken_22))
						("blast"  bone(broken_23))
						("blast"  bone(broken_24))
						("blast"  bone(broken_25))
						("blast"  bone(broken_26))
						("blast"  bone(broken_27))
						("blast"  bone(broken_28))
						("blast"  bone(broken_29))
					}
					{if rand %shard
						{unlink}
						{tear "piece_small_glass_nodelete" bone from_volume
							{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("blast_hit" blast(6) first(1)     second(1)     end(0.5)     shard(1))
		("blast_hit" blast(4)  first(0.8)   second(0.7)   end(0.25)   shard(1))
		("blast_hit" blast(2)  first(0.8)   second(0.5)   end(0.2)     shard(1))
		("blast_hit" blast(0.1)  first(0.7)   second(0.1)   end(0.1)   shard(1))
	}
	{on ground_hit 
		(define "ground_hit"
			{if contact_velocity %hit
				; {if volume "body"
					; {if rand %first
						; {unlink}
						; {if not tagged "broken_glass"
							; {tags add "broken_glass"}
							; {bone hide "normal" }
							; {spawn "glass_hit_shrap_small2" "normal" } ; - marble_dust
							; {call "marble_set"}
							; {bone cut "normal"}
						; }
					; }
				; }
				{if volume "shard"
					{if rand %shard
						{unlink}
						{tear "piece_small_glass_nodelete" bone from_volume
							{impulse up 0.5 0.2 dir 1.5 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
				{if volume "holded_sharp"
					{if rand 0.1
						{spawn	"glass_hit_small" }
						{bone hide}
					}
				}
			}
		)
		;                  ------   первичный вторичный финальный
		("ground_hit" hit(10) first(1)     second(1)       end(1)       shard(1))
		("ground_hit" hit(5) first(0.5)   second(0.4)     end(0.2)     shard(0.7))
		("ground_hit" hit(1) first(0.1)    second(0.1)     end(0.1)     shard(0.5))
	}	
}

{"gypsum_frame"
	{on pierce
		(define "bullet_hit"
			{if stuff %stuff
				{if volume "shard_upper"
					{if rand %rand_upper
						{spawn "gypsum_crush_small"}
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{delete}
						}
					}
				}
				{if volume "shard_down"
					{if rand %rand_down
						{spawn "gypsum_crush_small"}
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{delete}
						}
					}
				}
			}
		)
		;                  stuff   		   
		("bullet_hit" stuff("shell")			rand_upper(1) 		rand_down(1)		impact({impulse up 1 0.5  	dir 7 4		cx 4 2 cy 4 2  	no_position}))
		("bullet_hit" stuff("heavy_zenite")		rand_upper(1) 		rand_down(1)		impact({impulse up 3 1 		dir 5 2 	cx 7 3 cy 7 3  	no_position}))
		("bullet_hit" stuff("zenite")			rand_upper(0.5) 	rand_down(0.2)		impact({impulse up 2 1 		dir 4 2 	cx 4 1 cy 4 1 	no_position}))
		("bullet_hit" stuff("bullet big")		rand_upper(0.5) 	rand_down(0.1)		impact({impulse up 2 1 		dir 2 1 	cx 2 1 cy 2 1 	no_position}))
		("bullet_hit" stuff("bullet normal")	rand_upper(0.2) 	rand_down(0.05)		impact({impulse up 1 0.5    dir 1 0.5 	cx 0.5 cy 0.5  	no_position}))
		("bullet_hit" stuff("bullet small")		rand_upper(0.05) 	rand_down(0.01)		impact({impulse up 0.2 0.1 	dir 0.5 	cx 0.5 cy 0.5  	no_position}))
	}
	{on contact 	
		{with_effector
			{if not "link_weapon"
				{with_effector
					{if not effector "obstacle"	
						(define "contact_hit"
							{if effector "%effector"
								{if contact_velocity 10
									{if rand %end
										(define "blast"
											{tear "piece_medium_gypsum_crushed" bone "%bone"
												{spawn "gypsum_crush_small"}
												{delete}
											}
										)
										("blast"  bone(broken_29))
										("blast"  bone(broken_28))
										("blast"  bone(broken_27))
										("blast"  bone(broken_26))
										("blast"  bone(broken_25))
										("blast"  bone(broken_24))
										("blast"  bone(broken_23))
										("blast"  bone(broken_22))
										("blast"  bone(broken_21))
										("blast"  bone(broken_20))
										("blast"  bone(broken_19))
										("blast"  bone(broken_18))
										("blast"  bone(broken_17))
										("blast"  bone(broken_16))
										("blast"  bone(broken_15))
										("blast"  bone(broken_14))
										("blast"  bone(broken_13))
										("blast"  bone(broken_12))
										("blast"  bone(broken_11))
										("blast"  bone(broken_10))
										("blast"  bone(broken_09))
										("blast"  bone(broken_08))
										("blast"  bone(broken_07))
										("blast"  bone(broken_06))
										("blast"  bone(broken_05))
										("blast"  bone(broken_04))
										("blast"  bone(broken_03))
										("blast"  bone(broken_02))
										("blast"  bone(broken_01))
										("blast"  bone(broken_00))
									}
									{if volume "shard_upper"
										{if rand %rand_upper
											{spawn "gypsum_crush_small"}
											{tear "piece_medium_gypsum_crushed" bone from_volume
												{delete}
											}
										}
									}
									{if volume "shard_down"
										{if rand %rand_down
											{spawn "gypsum_crush_small"}
											{tear "piece_medium_gypsum_crushed" bone from_volume
												{delete}
												;%impact
											}
										}
									}
								else contact_velocity 3
									{if volume "shard_upper"
										{if rand %rand_upper
											{spawn "gypsum_crush_small"}
											{tear "piece_medium_gypsum_crushed" bone from_volume
												{delete}
												;%impact_slow
											}
										}
									}
									{if volume "shard_down"
										{if rand %rand_down
											{spawn "gypsum_crush_small"}
											{tear "piece_medium_gypsum_crushed" bone from_volume
												{delete}
												;%impact_slow
											}
										}
									}
								}
							}
						)
						;                  ------   первичный 
						("contact_hit" effector(fraction) 		rand_upper(0.3) rand_down(0.1) 	end(0.02) 	impact({impulse 				dir 2 1		cx 2 1 		cy 2 1   }) impact_slow({impulse 				dir 0.5		cx 0.5 		cy 0.5 	}))
						("contact_hit" effector(vehicle)  		rand_upper(1) 	rand_down(1) 	end(0.3)	impact({impulse 			 	dir 0.5							 })	impact_slow({impulse 				dir 0.1 						}))
						("contact_hit" effector(grenade)  		rand_upper(0.1) rand_down(0.01) end(0)		impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 1 0.5 	cx 0.5  	cy 0.5 	}))
						("contact_hit" effector(local_physics)  rand_upper(0.2) rand_down(0.1) 	end(0.0)	impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 0.2 	cx 0.5  	cy 0.5 	}))
						;("contact_hit" effector(stuff)  	rand_upper(0.2) rand_down(0.1) 	end(0.02)	impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 0.2 	cx 0.5  	cy 0.5 	}))
					}
				}
			}
		}
	}
	{on blast
		(define "blast_hit"
			{if min_energy %blast
				{if volume "shard_upper"
					{if rand %upper
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{delete}
							;%impact
						}
					}
				}
				{if volume "shard_down"
					{if rand %down
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{delete}
							;%impact
						}
					}
				}
			}
		)
		;                  ------   
		("blast_hit" blast(6) 		down(0.25)     	upper(1)	 	impact({impulse dir 7 4		cx 4 2 cy 4 2  	no_position}))
		("blast_hit" blast(4)  		down(0.2)   	upper(0.6) 		impact({impulse dir 5 2		cx 4 2 cy 4 2  	no_position}))
		("blast_hit" blast(2)  		down(0.1)     	upper(0.3) 		impact({impulse dir 2 1		cx 2 1 cy 2 1  	no_position}))
		("blast_hit" blast(0.1)  	down(0)   		upper(0.05) 	impact({impulse dir 0.1 	cx 0.1 cy 0.1  	no_position}))
	}
	{on ground_hit 
		(define "ground_hit"
			{if contact_velocity %hit
				{if volume "shard_upper"
					{if rand %shard
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{impulse dir 0.5}
						}
					}
				}
				{if volume "shard_down"
					{if rand %shard
						{tear "piece_medium_gypsum_crushed" bone from_volume
							{impulse dir 0.5}
						}
					}
				}
			}
		)
		;                  ------  
		("ground_hit" hit(10) shard(1))
		("ground_hit" hit(3)  shard(0.7))
		("ground_hit" hit(1)  shard(0.5))
	}	
}

{"big_glass_frame"
	{on "room_blast"	
		{tex_mod "broken"}
		(define "blast"
			{spawn "glass_hit4" "%bone" x}
			{if rand 0.5
				{tear "piece_small_glass" bone "%bone"
					%impact
				}
			else
				{tear "piece_delete" bone "%bone"
					{impulse up 0.1}
				}
			}
		)
		("blast" bone(broken_29) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position 		}))	
		("blast" bone(broken_28) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_27) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_26) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_25) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_24) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_23) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_22) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_21) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_20) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_19) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_18) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_17) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_16) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_15) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_14) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_13) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_12) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_11) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_10) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_09) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_08) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_07) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_06) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_05) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_04) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_03) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_02) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_01) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		("blast" bone(broken_00) impact({impulse forward 7 3 cx 1 0.5 cy 1 0.5 no_position  	}))	
		{spawn "glass_hit" "basis" x}
		{delete}
	}
	{on pierce
		(define "bullet_hit"
			{if stuff %stuff
				{tex_mod "broken"}
				{if volume "shard_upper"
					{if rand %rand_upper
						{tear "piece_small_glass_crushed" bone from_volume
							%impact
						}
					}
				}
				{if volume "shard_down"
					{if rand %rand_down
						{tear "piece_small_glass_crushed" bone from_volume
							%impact
						}
					}
				}
			}
		)
		;                  stuff   		   
		("bullet_hit" stuff("shell")			rand_upper(1) 		rand_down(1)		impact({impulse up 1 0.5  	dir 7 4		cx 4 2 cy 4 2  	no_position}))
		("bullet_hit" stuff("heavy_zenite")		rand_upper(1) 		rand_down(1)		impact({impulse up 3 1 		dir 5 2 	cx 7 3 cy 7 3  	no_position}))
		("bullet_hit" stuff("zenite")			rand_upper(0.8) 	rand_down(0.5)		impact({impulse up 2 1 		dir 4 2 	cx 4 1 cy 4 1 	no_position}))
		("bullet_hit" stuff("bullet big")		rand_upper(0.6) 	rand_down(0.4)		impact({impulse up 2 1 		dir 2 1 	cx 2 1 cy 2 1 	no_position}))
		("bullet_hit" stuff("bullet normal")	rand_upper(0.5) 	rand_down(0.1)		impact({impulse up 1 0.5    dir 1 0.5 	cx 0.5 cy 0.5  	no_position}))
		("bullet_hit" stuff("bullet small")		rand_upper(0.2) 	rand_down(0.04)		impact({impulse up 0.2 0.1 	dir 0.5 	cx 0.5 cy 0.5  	no_position}))
	}
	{on contact 		
		{if not effector "obstacle"	
			(define "contact_hit"
				{if effector "%effector"
					{if contact_velocity 6
						{if rand %end
							{tex_mod "broken"}
							{spawn	"glass_hit_small" }
							(define "blast"
								{tear "piece_small_glass_crushed" bone "%bone"
									{impulse up 1 0.5   }
								}
							)
							("blast"  bone(broken_29))
							("blast"  bone(broken_28))
							("blast"  bone(broken_27))
							("blast"  bone(broken_26))
							("blast"  bone(broken_25))
							("blast"  bone(broken_24))
							("blast"  bone(broken_23))
							("blast"  bone(broken_22))
							("blast"  bone(broken_21))
							("blast"  bone(broken_20))
							("blast"  bone(broken_19))
							("blast"  bone(broken_18))
							("blast"  bone(broken_17))
							("blast"  bone(broken_16))
							("blast"  bone(broken_15))
							("blast"  bone(broken_14))
							("blast"  bone(broken_13))
							("blast"  bone(broken_12))
							("blast"  bone(broken_11))
							("blast"  bone(broken_10))
							("blast"  bone(broken_09))
							("blast"  bone(broken_08))
							("blast"  bone(broken_07))
							("blast"  bone(broken_06))
							("blast"  bone(broken_05))
							("blast"  bone(broken_04))
							("blast"  bone(broken_03))
							("blast"  bone(broken_02))
							("blast"  bone(broken_01))
							("blast"  bone(broken_00))
						}
						{if volume "shard_upper"
							{if rand %rand_upper
								{tex_mod "broken"}
								{spawn	"glass_hit_small" }
								{tear "piece_small_glass_crushed" bone from_volume
									%impact
								}
							}
						}
						{if volume "shard_down"
							{if rand %rand_down
								{tex_mod "broken"}
								{spawn "glass_hit_small"}
								{tear "piece_small_glass_crushed" bone from_volume
									%impact
								}
							}
						}
					else contact_velocity 1
						{volumes disable contact }
						{delay 0.01
							{volumes enable contact }
						}
						{if volume "shard_upper"
							{tex_mod "broken"}
							{if rand %rand_upper
								{spawn "glass_hit_small"}
								{tear "piece_small_glass_crushed" bone from_volume
									%impact_slow
								}
							}
						}
						{if volume "shard_down"
							{tex_mod "broken"}
							{if rand %rand_down
								{spawn "glass_hit_small"}
								{tear "piece_small_glass_crushed" bone from_volume
									%impact_slow
								}
							}
						}
					}
				}
			)
			;                  ------   первичный 
			("contact_hit" effector(fraction) 	rand_upper(0.8) rand_down(0.7) 	end(0.02) 	impact({impulse 				dir 2 1		cx 2 1 		cy 2 1   }) impact_slow({impulse 				dir 0.5		cx 0.5 		cy 0.5 	}))
			("contact_hit" effector(vehicle)  	rand_upper(1) 	rand_down(1) 	end(0.3)	impact({impulse 			 	dir 0.5							 })	impact_slow({impulse 				dir 0.1 						}))
			("contact_hit" effector(baze_machinery)  	rand_upper(1) 	rand_down(1) 	end(0.3)	impact({impulse 			 	dir 0.5							 })	impact_slow({impulse 				dir 0.1 						}))
			("contact_hit" effector(grenade)  	rand_upper(1)	 rand_down(1) end(0)		impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 1 0.5 	cx 0.5  	cy 0.5 	}))
			("contact_hit" effector(weight)  	rand_upper(0.8) rand_down(0.4) 	end(0.02)	impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 0.2 	cx 0.5  	cy 0.5 	}))
			("contact_hit" effector(stuff)  	rand_upper(0.4) rand_down(0.3) 	end(0.02)	impact({impulse 				dir 1 0.5 	cx 1 0.5  	cy 1 0.5 })	impact_slow({impulse 				dir 0.2 	cx 0.5  	cy 0.5 	}))
		}
	}
	{on blast
		(define "blast_hit"
			{if min_energy %blast
				{if volume "shard_upper"
					{if rand %upper
						{tex_mod "broken"}
						{tear "piece_small_glass_crushed" bone from_volume
								%impact
						}
					}
				}
				{if volume "shard_down"
					{if rand %down
						{tex_mod "broken"}
						{tear "piece_small_glass_crushed" bone from_volume
								%impact
						}
					}
				}
			}
		)
		;                  ------   
		("blast_hit" blast(6) 		down(0.6)     	upper(1)	 	impact({impulse dir 7 4		cx 4 2 cy 4 2  	no_position}))
		("blast_hit" blast(2.5)  	down(0.4)   	upper(0.8) 		impact({impulse dir 5 2		cx 4 2 cy 4 2  	no_position}))
		("blast_hit" blast(1)  		down(0.25)     	upper(0.5) 		impact({impulse dir 2 1		cx 2 1 cy 2 1  	no_position}))
		("blast_hit" blast(0.1)  	down(0)   		upper(0.08) 	impact({impulse dir 0.1 	cx 0.1 cy 0.1  	no_position}))
	}
	{on ground_hit 
		(define "ground_hit"
			{if contact_velocity %hit
				{if volume "shard_upper"
					{if rand %shard
						{tex_mod "broken"}
						{tear "piece_small_glass_crushed" bone from_volume
							{impulse dir 0.5}
						}
					}
				}
				{if volume "shard_down"
					{if rand %shard
						{tex_mod "broken"}
						{tear "piece_small_glass_crushed" bone from_volume
							{impulse dir 0.5}
						}
					}
				}
			}
		)
		;                  ------  
		("ground_hit" hit(6)  shard(1))
		("ground_hit" hit(3)  shard(0.7))
		("ground_hit" hit(1)  shard(0.5))
	}	
}
{"small_windows"
	{on blast 
		{spawn "glass_hit_sm"}
		{delete}
	}
	{on bullet_hit 
		{tex_mod "broken"}
		{if rand 0.5
			{spawn "glass_hit_sm"}
			{delete}
		}
	}
	{on contact
		{volumes disable contact }
		{delay 0.01
			{volumes enable contact }
		}
		{if min_speed 10
			{delete}
			{spawn "glass_hit_sm" }
		}
	}
	{on ground_hit
		{delete}
		{if min_speed 1
			{if rand 0.2
				{spawn "glass_hit_sm" }
			}
		}
	}
}
