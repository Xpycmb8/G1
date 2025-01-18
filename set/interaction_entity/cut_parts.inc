

{"cut_parts_volume"
	{on bullet_hit
		{if stuff "fx_40"
			{if rand 0.6		
				{bullet_detonate}
			}
		}
	}
	{on blast_hit  
		{if stuff "zenite fg"
			{if volume "part"
				{burn volume fx "smoke_dead_small3" time 5 fake even_law}
				{fire radius 1 time 1 heating 1 effector}
				{tear "piece_medium_steel_crushed" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
			{if volume "part_wood"
				{burn volume fx "smoke_dead_small3" time 5 fake even_law}
				{fire radius 1 time 1 heating 1 effector}
				{tear "piece_small_wood" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}
			}
		}
	}	
	{on blast
		{if volume "part"
			{if min_energy 10
				{tear "piece_medium_steel_crushed" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}	
			{if min_energy 5
				{if rand 0.6		
					{tear "piece_medium_steel_crushed" bone from_volume
						(define "disable_contact_0")
						{impulse up 5 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			}
			{if min_energy 1
				{if rand 0.6		
					{tear "piece_medium_steel_crushed" bone from_volume
						(define "disable_contact_0")
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
		{if volume "part_misc"
			{if min_energy 10
				{tear "piece_small_misc" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}	
			{if min_energy 5
				{if rand 0.6		
					{tear "piece_small_misc" bone from_volume
						(define "disable_contact_0")
						{impulse up 5 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			}
			{if min_energy 1
				{if rand 0.6		
					{tear "piece_small_misc" bone from_volume
						(define "disable_contact_0")
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
		{if volume "part_wood"
			{if min_energy 10
				{tear "piece_small_wood" bone from_volume
					(define "disable_contact_0")
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}	
			{if min_energy 5
				{if rand 0.6		
					{tear "piece_small_wood" bone from_volume
						(define "disable_contact_0")
						{impulse up 5 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			}
			{if min_energy 1
				{if rand 0.6		
					{tear "piece_small_wood" bone from_volume
						(define "disable_contact_0")
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
	}
	{on contact 
		{if effector "fraction" 
			{if volume "part_wood"
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						(define "disable_contact_0")
						{impulse up 1.2 dir 1 0.4}
					}
				}	
			}	
			{if volume "part_misc"
				{if rand 0.8		
					{tear "piece_small_misc" bone from_volume
						(define "disable_contact_0")
						{impulse up 1.2 dir 1 0.4}
					}
				}	
			}	
			{if volume "part"
				{if rand 0.6		
					{tear "piece_medium_steel" bone from_volume
						(define "disable_contact_0")
						{impulse up 1.2 dir 1 0.4}
					}
				}	
			}	
		}	
		{if effector_velocity 30
			{if effector "tank" 
				{if volume "part"
					{if rand 0.7		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 1.6 dir 0.3 0.1}
						}
					}	
				}	
				{if volume "part_wood"
					{tear "piece_small_wood" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
				{if volume "part_misc"
					{tear "piece_small_misc" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
			else effector "small_vehicle" 
				{if volume "part"
					{if rand 0.3		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_wood"
					{if rand 0.7		
						{tear "piece_small_wood" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_misc"
					{tear "piece_small_misc" bone from_volume
						{impulse up 0.5 dir 0.6 0.1}
					}
				}	
			else effector "car" 
				{if volume "part"
					{if rand 0.5		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 1 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_misc"
					{tear "piece_small_misc" bone from_volume
							{impulse up 1 dir 0.6 0.1}
					}
				}	
				{if volume "part_wood"
					{if rand 0.7		
						{tear "piece_small_wood" bone from_volume
							{impulse up 1 dir 0.6 0.1}
						}
					}	
				}	
			}
		else effector_velocity 10
			{if effector "tank" 
				{if volume "part"
					{if rand 0.4		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 1.6 dir 0.3 0.1}
						}
					}	
				}	
				{if volume "part_wood"
					{tear "piece_small_wood" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
				{if volume "part_misc"
					{tear "piece_small_misc" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
			else effector "small_vehicle" 
				{if volume "part"
					{if rand 0.1		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_wood"
					{if rand 0.7		
						{tear "piece_small_wood" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_misc"
					{if rand 0.7		
						{tear "piece_small_misc" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
					}	
				}	
			else effector "car" 
				{if volume "part"
					{if rand 0.2		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 1 dir 0.6 0.1}
						}
					}	
				}	
				{if volume "part_wood"
					{tear "piece_small_wood" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
				{if volume "part_misc"
					{tear "piece_small_misc" bone from_volume
						{impulse up 1.6 dir 0.3 0.1}
					}
				}	
			}
		else effector_velocity 5
		}
	}
	{on ground_hit
		{if contact_velocity 20
			{if volume "tear"
				{if rand 0.7
					{tear "piece_medium_steel_crushed" bone from_volume
						{spawn "spheredust_small_short_arm" }
						{impulse up 0.5 }
					}	
				}	
			}	
			{if volume "part"
				{if rand 0.7
					{tear "piece_medium_steel_crushed" bone from_volume
						{spawn "spheredust_small_short_arm" }
						{impulse up 0.5 }
					}	
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 0.5 }
				}	
			}	
			{if volume "part_wood"
				{if rand 0.7
					{tear "piece_small_wood" bone from_volume
						{impulse up 0.5 }
					}	
				}	
			}	
		}	
	}	
	{on "crush_all_part"
		(define "cut_wall"
			{tear "piece_medium_steel_crushed" bone "part%0"
				{impulse up 5 2 dir 5 2 cx 12 2 cy 12 2 rnd_dir 4 no_position}
			}
		)
		("cut_wall" args 00	)	("cut_wall" args 01	)
		("cut_wall" args 02	)	("cut_wall" args 03	)
		("cut_wall" args 04	)	("cut_wall" args 05	)
		("cut_wall" args 06	)	("cut_wall" args 07	)
		("cut_wall" args 08	)	("cut_wall" args 09	)
		("cut_wall" args 10	)	("cut_wall" args 11	)
		("cut_wall" args 12	)	("cut_wall" args 13	)
		("cut_wall" args 14	)	("cut_wall" args 15	)
		("cut_wall" args 16	)	("cut_wall" args 17	)
		("cut_wall" args 18	)	("cut_wall" args 19	)
		("cut_wall" args 20	)	("cut_wall" args 21	)
		("cut_wall" args 22	)	("cut_wall" args 23	)
		("cut_wall" args 24	)	("cut_wall" args 25	)
		("cut_wall" args 26	)	("cut_wall" args 27	)
		("cut_wall" args 28	)	("cut_wall" args 29	)
		("cut_wall" args 30	)	("cut_wall" args 31	)
		("cut_wall" args 32	)	("cut_wall" args 33	)
		("cut_wall" args 34	)	("cut_wall" args 35	)
		("cut_wall" args 36	)	("cut_wall" args 37	)
		("cut_wall" args 38	)	("cut_wall" args 39	)
	}
	{on "crush_all_parts"
		(define "cut_wall"
			{tear "piece_medium_steel_crushed" bone "parts%0"
				{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
			}
		)
		("cut_wall" args 00	)	("cut_wall" args 01	)
		("cut_wall" args 02	)	("cut_wall" args 03	)
		("cut_wall" args 04	)	("cut_wall" args 05	)
		("cut_wall" args 06	)	("cut_wall" args 07	)
		("cut_wall" args 08	)	("cut_wall" args 09	)
		("cut_wall" args 10	)	("cut_wall" args 11	)
		("cut_wall" args 12	)	("cut_wall" args 13	)
		("cut_wall" args 14	)	("cut_wall" args 15	)
		("cut_wall" args 16	)	("cut_wall" args 17	)
		("cut_wall" args 18	)	("cut_wall" args 19	)
		("cut_wall" args 20	)	("cut_wall" args 21	)
		("cut_wall" args 22	)	("cut_wall" args 23	)
		("cut_wall" args 24	)	("cut_wall" args 25	)
		("cut_wall" args 26	)	("cut_wall" args 27	)
		("cut_wall" args 28	)	("cut_wall" args 29	)
		("cut_wall" args 30	)	("cut_wall" args 31	)
		("cut_wall" args 32	)	("cut_wall" args 33	)
		("cut_wall" args 34	)	("cut_wall" args 35	)
		("cut_wall" args 36	)	("cut_wall" args 37	)
		("cut_wall" args 38	)	("cut_wall" args 39	)
	}
	{on pierce
		{if stuff "atgm_launcher"
			{if volume "part"
				{call "crush_all_part"}
				{call "crush_all_parts"}
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{call "crush_all_part"}
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 6 2 dir 6 2 cx 5 1 cy 5 1 rnd_dir 3 no_position}
				}
			}
		}
		{if stuff "shell_big"
			{if volume "part"
				{call "crush_all_part"}
				{call "crush_all_parts"}
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{call "crush_all_part"}
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 6 2 dir 6 2 cx 5 1 cy 5 1 rnd_dir 3 no_position}
				}
			}
		}
		{if stuff "shell_minimum"
			{if volume "part"
				{call "crush_all_part"}
				{call "crush_all_parts"}
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.8		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 6 2 dir 6 2 cx 5 1 cy 5 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "shell"
			{if volume "part"
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.4		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 6 2 dir 6 2 cx 5 1 cy 5 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "zenite ap"
			{if volume "part"
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.4		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 4 2 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "zenite fg"
			{if volume "part"
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 12 5 dir 12 5 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.4		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 6 2 dir 6 2 cx 5 1 cy 5 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "zenite"
			{if volume "part"
				{tear "piece_medium_steel_crushed" bone from_volume
					{impulse up 8 1 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.2		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
	
		{if stuff "bullet hmgun"
			{if volume "parts"
				{if rand 0.8		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 5 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
					}
				}	
			}	
			{if volume "part"
				{if rand 0.8		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 5 1 dir 5 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
					}
				}	
			}	
			{if volume "part_wood"
				{tear "piece_small_wood" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "part_misc"
				{tear "piece_small_misc" bone from_volume
					{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.03		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "bullet sp"
			{if volume "part"
				{if rand 0.1		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
					}
				}	
			}	
			{if volume "part_wood"
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}	
				}	
			}	
			{if volume "part_misc"
				{if rand 0.4		
					{tear "piece_small_misc" bone from_volume
						{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}	
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.01		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "bullet normal ap"
			{if volume "part_wood"
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}	
				}	
			}	
			{if volume "part_misc"
				{if rand 0.2		
					{tear "piece_small_misc" bone from_volume
						{impulse up 5 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}
				}	
			}	
			{if volume "part"
				{if rand 0.2		
					{tear "piece_medium_steel_crushed" bone from_volume
						{spawn "metal_hit_wire" }
						{impulse up 4 1 dir 4 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
					}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.07		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 3 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
		{if stuff "bullet"
			{if volume "part_wood"
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}	
				}	
			}	
			{if volume "part_misc"
				{if rand 0.7		
					{tear "piece_small_misc" bone from_volume
						{impulse up 9 2 dir 8 1 cx 12 2 cy 12 2 rnd_dir 4 no_position}
					}	
				}	
			}	
			{if volume "part"
				{if rand 0.2		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
					}
				}	
			}	
			{if volume "heavy_part"
				{if rand 0.03		
					{tear "piece_medium_steel_crushed" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 3 no_position}
					}
				}	
			}
		}
	}	
}


{"cut_parts_volume_wood"
	{inflammation_time 15}
	{on blast_hit  
		{if volume "parts"
			{if stuff "zenite fg"
				{burn volume fx "smoke_dead_small3" time 5 fake even_law}
				{fire radius 1 time 1 heating 1 effector}
				{tear "piece_small_wood" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
		}
		{if volume "part"
			{if stuff "zenite fg"
				{burn volume fx "smoke_dead_small3" time 5 fake even_law}
				{fire radius 1 time 1 heating 1 effector}
				{tear "piece_small_wood" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
		}
	}	
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burns"}
			}
		}
	}
	{on "_burns"
		{start_sound "fire/small"}
		{link_sound 	"burn"			"fire/big/big_fire1"}
		{link_sound 	"small"			"fire/small_stuff/fire_small"}
		{fire volume "body" radius 0.4 heating 1  time 20 follow}
		{burn fx "smoke_dead_small" time 37 fake even_law}
		{play_sound "small" 1}
		{delay 8 2 "burn_die1"
			{tex_morph "burn1" 5}
			{call "_burn_crash"}
			{delay 6 "_burn_crash_end"
				{call "_burn_crash_end"}
			}
			{delay 12 3 "burn_die2"
				{stop_sound "small" }
				{play_sound "big" 1}
				{call "_burn_crash"}
				{delay 16 2 "burn_die3"
					{tex_morph "burn2" 12}
					{call "_burn_crash"}
					{stop_sound "burn" 1}
					{play_sound "small" 1}
					{delay 5 
						{stop_sound "small" }
					}
				}
			}
		}
	}
	{on "_burn_crash"
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{tex_morph "burned" 5}
					{burn fx "smoke_dead_small3" time 10 fake even_law}
					{fire volume %0 radius 0.8 heating 3  time 20 follow}
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "part1"			0.1)
		("_burn_crash" args "part2"			0.1)
		("_burn_crash" args "part3"			0.1)
		("_burn_crash" args "part4"			0.1)
		("_burn_crash" args "part5"			0.1)
		("_burn_crash" args "part6"			0.1)
		("_burn_crash" args "part7"			0.1)
		("_burn_crash" args "part8"			0.1)
		("_burn_crash" args "part9"			0.1)
		("_burn_crash" args "part01"			0.1)
		("_burn_crash" args "part02"			0.1)
		("_burn_crash" args "part03"			0.1)
		("_burn_crash" args "part04"			0.1)
		("_burn_crash" args "part05"			0.1)
		("_burn_crash" args "part06"			0.1)
		("_burn_crash" args "part07"			0.1)
		("_burn_crash" args "part08"			0.1)
		("_burn_crash" args "part09"			0.1)
		("_burn_crash" args "part10"		0.1)
		("_burn_crash" args "part11"		0.1)
		("_burn_crash" args "part12"		0.1)
		("_burn_crash" args "part13"		0.1)
		("_burn_crash" args "part14"		0.1)
		("_burn_crash" args "part15"		0.1)
		("_burn_crash" args "part16"		0.1)
		("_burn_crash" args "part17"		0.1)
		("_burn_crash" args "part18"		0.1)
		("_burn_crash" args "part19"		0.1)
		("_burn_crash" args "part20"			0.1)
		("_burn_crash" args "part21"			0.1)
		("_burn_crash" args "part22"			0.1)
		("_burn_crash" args "part23"			0.1)
		("_burn_crash" args "part24"			0.1)
		("_burn_crash" args "part25"			0.1)
		("_burn_crash" args "part26"			0.1)
		("_burn_crash" args "part27"			0.1)
		("_burn_crash" args "part28"			0.1)
		("_burn_crash" args "part29"			0.1)
		("_burn_crash" args "part30"			0.1)
		("_burn_crash" args "part31"			0.1)
		("_burn_crash" args "part32"			0.1)
		("_burn_crash" args "part33"			0.1)
		("_burn_crash" args "part34"			0.1)
		("_burn_crash" args "part35"			0.1)
		("_burn_crash" args "part36"			0.1)
		("_burn_crash" args "part37"			0.1)
		("_burn_crash" args "part38"			0.1)
		("_burn_crash" args "part39"			0.1)
		("_burn_crash" args "part40"			0.1)
		("_burn_crash" args "part41"			0.1)
		("_burn_crash" args "part42"			0.1)
		("_burn_crash" args "part43"			0.1)
		("_burn_crash" args "part44"			0.1)
		("_burn_crash" args "part45"			0.1)
		("_burn_crash" args "part46"			0.1)
		("_burn_crash" args "part47"			0.1)
		("_burn_crash" args "part48"			0.1)
		("_burn_crash" args "part49"			0.1)
		("_burn_crash" args "part50"			0.1)
		("_burn_crash" args "part51"			0.1)
		("_burn_crash" args "part52"			0.1)
		("_burn_crash" args "part53"			0.1)
		("_burn_crash" args "part54"			0.1)
		("_burn_crash" args "part55"			0.1)
		("_burn_crash" args "part56"			0.1)
		("_burn_crash" args "part57"			0.1)
		("_burn_crash" args "part58"			0.1)
		("_burn_crash" args "part59"			0.1)
		("_burn_crash" args "part60"			0.1)
		("_burn_crash" args "part61"			0.1)
		("_burn_crash" args "part62"			0.1)
		("_burn_crash" args "part63"			0.1)
		("_burn_crash" args "part64"			0.1)
		("_burn_crash" args "part65"			0.1)
		("_burn_crash" args "part66"			0.1)
		("_burn_crash" args "part67"			0.1)
		("_burn_crash" args "part68"			0.1)
		("_burn_crash" args "part69"			0.1)
		("_burn_crash" args "part70"			0.1)
		("_burn_crash" args "part71"			0.1)
		("_burn_crash" args "part72"			0.1)
		("_burn_crash" args "part73"			0.1)
		("_burn_crash" args "part74"			0.1)
		("_burn_crash" args "part75"			0.1)
		("_burn_crash" args "part76"			0.1)
		("_burn_crash" args "part77"			0.1)
		("_burn_crash" args "part78"			0.1)
		("_burn_crash" args "part79"			0.1)
	}
	{on "_burn_crash_end"
		{delay 18
			{start_sound "crush/small/wood/"}
			{tex_morph "burned" 5}
			(define "_burn_crash"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{burn volume fx "smoke_dead_small3" time 10 fake even_law}
						{fire volume %0 radius 0.8 heating 3  time 20 follow}
						{impulse up 0.3 dir 0.3}
					}
				}
			)	
			("_burn_crash" args "part1"			0.1)
			("_burn_crash" args "part2"			0.1)
			("_burn_crash" args "part3"			0.1)
			("_burn_crash" args "part4"			0.1)
			("_burn_crash" args "part5"			0.1)
			("_burn_crash" args "part6"			0.1)
			("_burn_crash" args "part7"			0.1)
			("_burn_crash" args "part8"			0.1)
			("_burn_crash" args "part9"			0.1)
			("_burn_crash" args "part01"			0.1)
			("_burn_crash" args "part02"			0.1)
			("_burn_crash" args "part03"			0.1)
			("_burn_crash" args "part04"			0.1)
			("_burn_crash" args "part05"			0.1)
			("_burn_crash" args "part06"			0.1)
			("_burn_crash" args "part07"			0.1)
			("_burn_crash" args "part08"			0.1)
			("_burn_crash" args "part09"			0.1)
			("_burn_crash" args "part10"		0.1)
			("_burn_crash" args "part11"		0.1)
			("_burn_crash" args "part12"		0.1)
			("_burn_crash" args "part13"		0.1)
			("_burn_crash" args "part14"		0.1)
			("_burn_crash" args "part15"		0.1)
			("_burn_crash" args "part16"		0.1)
			("_burn_crash" args "part17"		0.1)
			("_burn_crash" args "part18"		0.1)
			("_burn_crash" args "part19"		0.1)
			("_burn_crash" args "part20"			0.1)
			("_burn_crash" args "part21"			0.1)
			("_burn_crash" args "part22"			0.1)
			("_burn_crash" args "part23"			0.1)
			("_burn_crash" args "part24"			0.1)
			("_burn_crash" args "part25"			0.1)
			("_burn_crash" args "part26"			0.1)
			("_burn_crash" args "part27"			0.1)
			("_burn_crash" args "part28"			0.1)
			("_burn_crash" args "part29"			0.1)
			("_burn_crash" args "part30"			0.1)
			("_burn_crash" args "part31"			0.1)
			("_burn_crash" args "part32"			0.1)
			("_burn_crash" args "part33"			0.1)
			("_burn_crash" args "part34"			0.1)
			("_burn_crash" args "part35"			0.1)
			("_burn_crash" args "part36"			0.1)
			("_burn_crash" args "part37"			0.1)
			("_burn_crash" args "part38"			0.1)
			("_burn_crash" args "part39"			0.1)
			("_burn_crash" args "part40"			0.1)
			("_burn_crash" args "part41"			0.1)
			("_burn_crash" args "part42"			0.1)
			("_burn_crash" args "part43"			0.1)
			("_burn_crash" args "part44"			0.1)
			("_burn_crash" args "part45"			0.1)
			("_burn_crash" args "part46"			0.1)
			("_burn_crash" args "part47"			0.1)
			("_burn_crash" args "part48"			0.1)
			("_burn_crash" args "part49"			0.1)
			("_burn_crash" args "part50"			0.1)
			("_burn_crash" args "part51"			0.1)
			("_burn_crash" args "part52"			0.1)
			("_burn_crash" args "part53"			0.1)
			("_burn_crash" args "part54"			0.1)
			("_burn_crash" args "part55"			0.1)
			("_burn_crash" args "part56"			0.1)
			("_burn_crash" args "part57"			0.1)
			("_burn_crash" args "part58"			0.1)
			("_burn_crash" args "part59"			0.1)
			("_burn_crash" args "part60"			0.1)
			("_burn_crash" args "part61"			0.1)
			("_burn_crash" args "part62"			0.1)
			("_burn_crash" args "part63"			0.1)
			("_burn_crash" args "part64"			0.1)
			("_burn_crash" args "part65"			0.1)
			("_burn_crash" args "part66"			0.1)
			("_burn_crash" args "part67"			0.1)
			("_burn_crash" args "part68"			0.1)
			("_burn_crash" args "part69"			0.1)
			("_burn_crash" args "part70"			0.1)
			("_burn_crash" args "part71"			0.1)
			("_burn_crash" args "part72"			0.1)
			("_burn_crash" args "part73"			0.1)
			("_burn_crash" args "part74"			0.1)
			("_burn_crash" args "part75"			0.1)
			("_burn_crash" args "part76"			0.1)
			("_burn_crash" args "part77"			0.1)
			("_burn_crash" args "part78"			0.1)
			("_burn_crash" args "part79"			0.1)
		}
	}
	{on "end_stage_b"
		{if effector "helicopter"
			{if min_speed 25
				{start_sound "crush/small/wood/"}
				{spawn "wood_crush_small" "basis"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 12 4 dir 12 2 cx 7 2 cy 7 2 rnd_dir 8 no_position}
					}	
				}	
			else min_speed 12
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 2 1 dir 4 2 cx 4 2 cy 4 2 rnd_dir 3 no_position}
					}	
				}	
			else 
				{impulse up 2 1 }
			}
		}
	}		
	{on "end_stage_r"
		{start_sound "crush/small/wood/"}
		{spawn "wood_crush_small" "basis"}
		(define "contact_hit"
			{tear "piece_small_wood" bone %0
				{add_view "smoke_cover-up_small_fast" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 2 1 "pause"}
				{impulse up 5 1 dir 12 4 cx 12 cy 12 rnd_dir 5 no_position}
			}
		)	
		("contact_hit" args "part1"		)
		("contact_hit" args "part2"		)
		("contact_hit" args "part3"		)
		("contact_hit" args "part4"		)
		("contact_hit" args "part5"		)
		("contact_hit" args "part6"		)
		("contact_hit" args "part7"		)
		("contact_hit" args "part8"		)
		("contact_hit" args "part9"		)
		("contact_hit" args "part01"		)
		("contact_hit" args "part02"		)
		("contact_hit" args "part03"		)
		("contact_hit" args "part04"		)
		("contact_hit" args "part05"		)
		("contact_hit" args "part06"		)
		("contact_hit" args "part07"		)
		("contact_hit" args "part08"		)
		("contact_hit" args "part09"		)
		("contact_hit" args "part10"		)
		("contact_hit" args "part11"		)
		("contact_hit" args "part12"		)
		("contact_hit" args "part13"		)
		("contact_hit" args "part14"		)
		("contact_hit" args "part15"		)
		("contact_hit" args "part16"		)
		("contact_hit" args "part17"		)
		("contact_hit" args "part18"		)
		("contact_hit" args "part19"		)
		("contact_hit" args "part20"		)
	}
	{on contact
		{if effector "fraction"
			{start_sound "crush/small/wood/"}
			{with_effector
				{delete}
			}
			{spawn "wood_hit_bul"}
			{if volume "parts"
				{if rand 0.01
					{call "end_stage_r"}	
				}
				{if rand 0.2
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "wood_hit_bul"}
						{impulse up 0.5 dir 1 0.5 cx 1 cy 1 rnd_dir 0.5 no_position}
					}
				}
			}		
		else effector "big_build"
			{if min_speed 15
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.2
						{start_sound "crush/small/wood/"}
						{tear "piece_small_wood" bone from_volume
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}					
		else effector "concrete"
			{if min_speed 10
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.7
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}					
		else effector "hit_small"
			{if min_speed 20
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.3
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}			
		else effector "vehicle"
			{if min_speed 40
				{impulse up 0.5 dir 2 cx 0.5 cy 0.5}
				{start_sound "crush/small/wood/"}
				{spawn "wood_crush_small" "basis"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 12 4 dir 12 2 cx 7 2 cy 7 2 rnd_dir 8 no_position}
					}	
				}	
			else min_speed 25
				{start_sound "crush/small/wood/"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 5 1 dir 4 2 cx 4 2 cy 4 2 rnd_dir 3 no_position}
					}	
				}	
			}
		else effector "steel"
			{if min_speed 20
				{start_sound "hit/small/wood_steel/"}
				{start_sound "hit/small/wood_solid/"}
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.3
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			}					
		else min_speed 5
			{spawn "hay_hit_small3" }
		}
	}		
	{on ground_hit sync
		{if volume "parts"
			{if min_speed 70
				{if rand 0.5
					{call "end_stage_r"}	
				}
				;{tags add "70"}
				{spawn "wood_hit_bul" }
				(define "ground_hit"
					{if rand %1
						{start_sound "crush/small/wood/"}
						{spawn "wood_crush_small" "basis"}
						{tear "piece_small_wood" bone %0
							{impulse up 5 1 dir 4 2 cx 4 2 cy 4 2 rnd_dir 3 no_position}
						}
					}
				)	
				("ground_hit" args "part1"		0.8)
				("ground_hit" args "part2"		0.8)
				("ground_hit" args "part3"		0.8)
				("ground_hit" args "part4"		0.8)
				("ground_hit" args "part5"		0.8)
				("ground_hit" args "part6"		0.8)
				("ground_hit" args "part7"		0.8)
				("ground_hit" args "part8"		0.8)
				("ground_hit" args "part9"		0.8)
				("ground_hit" args "part01"		0.8)
				("ground_hit" args "part02"		0.8)
				("ground_hit" args "part03"		0.8)
				("ground_hit" args "part04"		0.8)
				("ground_hit" args "part05"		0.8)
				("ground_hit" args "part06"		0.8)
				("ground_hit" args "part07"		0.8)
				("ground_hit" args "part08"		0.8)
				("ground_hit" args "part09"		0.8)
				("ground_hit" args "part10"		0.8)
				("ground_hit" args "part11"		0.8)
				("ground_hit" args "part12"		0.8)
				("ground_hit" args "part13"		0.8)
				("ground_hit" args "part14"		0.8)
				("ground_hit" args "part15"		0.8)
				("ground_hit" args "part16"		0.8)
				("ground_hit" args "part17"		0.8)
				("ground_hit" args "part18"		0.8)
				("ground_hit" args "part19"		0.8)
				("ground_hit" args "part20"		0.8)
			else min_speed 35
				(define "ground_hit"
					;{tags add "35"}
					{spawn "wood_hit_bul" }
					{if rand %1
						{start_sound "crush/small/wood/"}
						{tear "piece_small_wood" bone %0
							{impulse up 1.3 0.5 dir 0.3}
						}
					}
				)	
				("ground_hit" args "part1"		0.6)
				("ground_hit" args "part2"		0.6)
				("ground_hit" args "part3"		0.6)
				("ground_hit" args "part4"		0.6)
				("ground_hit" args "part5"		0.6)
				("ground_hit" args "part6"		0.6)
				("ground_hit" args "part7"		0.6)
				("ground_hit" args "part8"		0.6)
				("ground_hit" args "part9"		0.6)
				("ground_hit" args "part01"		0.6)
				("ground_hit" args "part02"		0.6)
				("ground_hit" args "part03"		0.6)
				("ground_hit" args "part04"		0.6)
				("ground_hit" args "part05"		0.6)
				("ground_hit" args "part06"		0.6)
				("ground_hit" args "part07"		0.6)
				("ground_hit" args "part08"		0.6)
				("ground_hit" args "part09"		0.6)
				("ground_hit" args "part10"		0.6)
				("ground_hit" args "part11"		0.6)
				("ground_hit" args "part12"		0.6)
				("ground_hit" args "part13"		0.6)
				("ground_hit" args "part14"		0.6)
				("ground_hit" args "part15"		0.6)
				("ground_hit" args "part16"		0.6)
				("ground_hit" args "part17"		0.6)
				("ground_hit" args "part18"		0.6)
				("ground_hit" args "part19"		0.6)
				("ground_hit" args "part20"		0.6)
			else min_speed 20
				(define "ground_hit"
					;{tags add "20"}
					{spawn "spheredust_small_short_wood" }
					{if rand %1
						{start_sound "crush/small/wood/"}
						{tear "piece_small_wood" bone %0
							{impulse up 0.1 dir 0.1}
						}
					}
				)	
				("ground_hit" args "part1"		0.01)
				("ground_hit" args "part2"		0.01)
				("ground_hit" args "part3"		0.01)
				("ground_hit" args "part4"		0.01)
				("ground_hit" args "part5"		0.01)
				("ground_hit" args "part6"		0.01)
				("ground_hit" args "part7"		0.01)
				("ground_hit" args "part8"		0.01)
				("ground_hit" args "part9"		0.01)
				("ground_hit" args "part01"		0.01)
				("ground_hit" args "part02"		0.01)
				("ground_hit" args "part03"		0.01)
				("ground_hit" args "part04"		0.01)
				("ground_hit" args "part05"		0.01)
				("ground_hit" args "part06"		0.01)
				("ground_hit" args "part07"		0.01)
				("ground_hit" args "part08"		0.01)
				("ground_hit" args "part09"		0.01)
				("ground_hit" args "part10"		0.01)
				("ground_hit" args "part11"		0.01)
				("ground_hit" args "part12"		0.01)
				("ground_hit" args "part13"		0.01)
				("ground_hit" args "part14"		0.01)
				("ground_hit" args "part15"		0.01)
				("ground_hit" args "part16"		0.01)
				("ground_hit" args "part17"		0.01)
				("ground_hit" args "part18"		0.01)
				("ground_hit" args "part19"		0.01)
				("ground_hit" args "part20"		0.01)
			}
		}		
	}		
	{on bullet_hit
		{if stuff "fx_40"
			{spawn "wood_crush_small" "basis"}
			{bullet_detonate}
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 4 3 dir 14 3 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				}
			)	
			("cut_part" args "part1")
			("cut_part" args "part2")
			("cut_part" args "part3")
			("cut_part" args "part4")
			("cut_part" args "part5")
			("cut_part" args "part6")
			("cut_part" args "part7")
			("cut_part" args "part8")
			("cut_part" args "part9")
			("cut_part" args "part01")
			("cut_part" args "part02")
			("cut_part" args "part03")
			("cut_part" args "part04")
			("cut_part" args "part05")
			("cut_part" args "part06")
			("cut_part" args "part07")
			("cut_part" args "part08")
			("cut_part" args "part09")
			("cut_part" args "part10")
			("cut_part" args "part11")
			("cut_part" args "part12")
			("cut_part" args "part13")
			("cut_part" args "part14")
			("cut_part" args "part15")
			("cut_part" args "part16")
			("cut_part" args "part17")
			("cut_part" args "part18")
			("cut_part" args "part19")
		else stuff "shell"
			{if rand 0.4
				{delay 4
					{fire volume "box" radius 1 time 5}
				}
			}
			{burn fx "smoke_aero_small" time 4 fake}				
			{burn fx "smoke_aero_2_small" time 9 fake}				
			{burn fx "smoke_aero_3_small" time 14 fake}				
			{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
			{spawn "wood_crush_small" "basis"}
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 8 3 dir 8 4}
				}
			)	
			("cut_part" args "part1")
			("cut_part" args "part2")
			("cut_part" args "part3")
			("cut_part" args "part4")
			("cut_part" args "part5")
			("cut_part" args "part6")
			("cut_part" args "part7")
			("cut_part" args "part8")
			("cut_part" args "part9")
			("cut_part" args "part01")
			("cut_part" args "part02")
			("cut_part" args "part03")
			("cut_part" args "part04")
			("cut_part" args "part05")
			("cut_part" args "part06")
			("cut_part" args "part07")
			("cut_part" args "part08")
			("cut_part" args "part09")
			("cut_part" args "part10")
			("cut_part" args "part11")
			("cut_part" args "part12")
			("cut_part" args "part13")
			("cut_part" args "part14")
			("cut_part" args "part15")
			("cut_part" args "part16")
			("cut_part" args "part17")
			("cut_part" args "part18")
			("cut_part" args "part19")
		else stuff "zenite"
			{burn fx "smoke_aero_small" time 4 fake}				
			{burn fx "smoke_aero_2_small" time 9 fake}				
			{burn fx "smoke_aero_3_small" time 14 fake}				
			{impulse dir 5 1 up 5 1 dir 7 2 cx 0 0.5 cy 0 0.5}
			{spawn "wood_crush_small" "basis"}
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 8 3 dir 8 4}
				}
			)	
			("cut_part" args "part1")
			("cut_part" args "part2")
			("cut_part" args "part3")
			("cut_part" args "part4")
			("cut_part" args "part5")
			("cut_part" args "part6")
			("cut_part" args "part7")
			("cut_part" args "part8")
			("cut_part" args "part9")
			("cut_part" args "part01")
			("cut_part" args "part02")
			("cut_part" args "part03")
			("cut_part" args "part04")
			("cut_part" args "part05")
			("cut_part" args "part06")
			("cut_part" args "part07")
			("cut_part" args "part08")
			("cut_part" args "part09")
			("cut_part" args "part10")
			("cut_part" args "part11")
			("cut_part" args "part12")
			("cut_part" args "part13")
			("cut_part" args "part14")
			("cut_part" args "part15")
			("cut_part" args "part16")
			("cut_part" args "part17")
			("cut_part" args "part18")
			("cut_part" args "part19")
		}
	}
	{on blast
		{if volume "parts"
			{if min_energy 10
				{start_sound "crush/small/wood/"}
				{tear "piece_small_wood" bone from_volume
					{impulse up 21 2 dir 12 2 cx 8 2 cy 8 2  }
				}	
			}	
			{if min_energy 5
				{start_sound "crush/small/wood/"}
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						{impulse up 14 1 dir 5 1 cx 2 1 cy 2 1  }
					}
				}	
			}
			{if min_energy 3
				{start_sound "crush/small/wood/"}
				{if rand 0.6		
					{tear "piece_small_wood" bone from_volume
						{impulse up 10 1 dir 5 1 cx 2 1 cy 2 1 }
					}
				}	
			}
			{if min_energy 1
				{impulse up 0.1}
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 6 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
	}
	{on pierce
		{if stuff "bullet hmgun"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.7		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.09		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet sp"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.1		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 1 0.5 dir 1 0.5 cx 2 1 cy 2 1 rnd_dir 3 no_position}
						}
					}
					{if "burned"
						{if rand 0.6		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 2 0.5 dir 2 0.5 cx 2 1 cy 2 1 rnd_dir 3 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.01		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.2 dir 1 cx 1 cy 1 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.2		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet normal ap"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 3 1 dir 4 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.09		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet normal"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.3		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 3 1 dir 4 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.05		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
	}	
}

{"cut_parts_volume_wood_build"
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burns"}
			}
		}
	}
	{on "_burns"
		{start_sound "fire/small"}
		{fire radius 0.3 time 40 heating 3}
		{burn volume fx "smoke_dead_norm" time 37 fake even_law}
		{delay 8 2 "burn_die1"
			{tex_morph "burn1" 5}
			{call "_burn_crash"}
			{delay 6 "_burn_crash_end"
				{call "_burn_crash_end"}
			}
			{delay 12 3 "burn_die2"
				{call "_burn_crash"}
				{delay 16 2 "burn_die3"
					{tex_morph "burn2" 12}
					{call "_burn_crash"}
				}
			}
		}
	}
	{on "_burn_crash"
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "part01"			0.1)
		("_burn_crash" args "part02"			0.1)
		("_burn_crash" args "part03"			0.1)
		("_burn_crash" args "part04"			0.1)
		("_burn_crash" args "part05"			0.1)
		("_burn_crash" args "part06"			0.1)
		("_burn_crash" args "part07"			0.1)
		("_burn_crash" args "part08"			0.1)
		("_burn_crash" args "part09"			0.1)
		("_burn_crash" args "part10"		0.1)
		("_burn_crash" args "part11"		0.1)
		("_burn_crash" args "part12"		0.1)
		("_burn_crash" args "part13"		0.1)
		("_burn_crash" args "part14"		0.1)
		("_burn_crash" args "part15"		0.1)
		("_burn_crash" args "part16"		0.1)
		("_burn_crash" args "part17"		0.1)
		("_burn_crash" args "part18"		0.1)
		("_burn_crash" args "part19"		0.1)
		("_burn_crash" args "part20"			0.1)
		("_burn_crash" args "part21"			0.1)
		("_burn_crash" args "part22"			0.1)
		("_burn_crash" args "part23"			0.1)
		("_burn_crash" args "part24"			0.1)
		("_burn_crash" args "part25"			0.1)
		("_burn_crash" args "part26"			0.1)
		("_burn_crash" args "part27"			0.1)
		("_burn_crash" args "part28"			0.1)
		("_burn_crash" args "part29"			0.1)
		("_burn_crash" args "part30"			0.1)
		("_burn_crash" args "part31"			0.1)
		("_burn_crash" args "part32"			0.1)
		("_burn_crash" args "part33"			0.1)
		("_burn_crash" args "part34"			0.1)
		("_burn_crash" args "part35"			0.1)
		("_burn_crash" args "part36"			0.1)
		("_burn_crash" args "part37"			0.1)
		("_burn_crash" args "part38"			0.1)
		("_burn_crash" args "part39"			0.1)
		("_burn_crash" args "part40"			0.1)
		("_burn_crash" args "part41"			0.1)
		("_burn_crash" args "part42"			0.1)
		("_burn_crash" args "part43"			0.1)
		("_burn_crash" args "part44"			0.1)
		("_burn_crash" args "part45"			0.1)
		("_burn_crash" args "part46"			0.1)
		("_burn_crash" args "part47"			0.1)
		("_burn_crash" args "part48"			0.1)
		("_burn_crash" args "part49"			0.1)
		("_burn_crash" args "part50"			0.1)
		("_burn_crash" args "part51"			0.1)
		("_burn_crash" args "part52"			0.1)
		("_burn_crash" args "part53"			0.1)
		("_burn_crash" args "part54"			0.1)
		("_burn_crash" args "part55"			0.1)
		("_burn_crash" args "part56"			0.1)
		("_burn_crash" args "part57"			0.1)
		("_burn_crash" args "part58"			0.1)
		("_burn_crash" args "part59"			0.1)
		("_burn_crash" args "part60"			0.1)
		("_burn_crash" args "part61"			0.1)
		("_burn_crash" args "part62"			0.1)
		("_burn_crash" args "part63"			0.1)
		("_burn_crash" args "part64"			0.1)
		("_burn_crash" args "part65"			0.1)
		("_burn_crash" args "part66"			0.1)
		("_burn_crash" args "part67"			0.1)
		("_burn_crash" args "part68"			0.1)
		("_burn_crash" args "part69"			0.1)
		("_burn_crash" args "part70"			0.1)
		("_burn_crash" args "part71"			0.1)
		("_burn_crash" args "part72"			0.1)
		("_burn_crash" args "part73"			0.1)
		("_burn_crash" args "part74"			0.1)
		("_burn_crash" args "part75"			0.1)
		("_burn_crash" args "part76"			0.1)
		("_burn_crash" args "part77"			0.1)
		("_burn_crash" args "part78"			0.1)
		("_burn_crash" args "part79"			0.1)
	}
	{on "_burn_crash_end"
		{delay 18
			{start_sound "crush/small/wood/"}
			(define "_burn_crash"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{impulse up 0.3 dir 0.3}
					}
				}
			)	
			("_burn_crash" args "part01"			0.1)
			("_burn_crash" args "part02"			0.1)
			("_burn_crash" args "part03"			0.1)
			("_burn_crash" args "part04"			0.1)
			("_burn_crash" args "part05"			0.1)
			("_burn_crash" args "part06"			0.1)
			("_burn_crash" args "part07"			0.1)
			("_burn_crash" args "part08"			0.1)
			("_burn_crash" args "part09"			0.1)
			("_burn_crash" args "part10"		0.1)
			("_burn_crash" args "part11"		0.1)
			("_burn_crash" args "part12"		0.1)
			("_burn_crash" args "part13"		0.1)
			("_burn_crash" args "part14"		0.1)
			("_burn_crash" args "part15"		0.1)
			("_burn_crash" args "part16"		0.1)
			("_burn_crash" args "part17"		0.1)
			("_burn_crash" args "part18"		0.1)
			("_burn_crash" args "part19"		0.1)
			("_burn_crash" args "part20"			0.1)
			("_burn_crash" args "part21"			0.1)
			("_burn_crash" args "part22"			0.1)
			("_burn_crash" args "part23"			0.1)
			("_burn_crash" args "part24"			0.1)
			("_burn_crash" args "part25"			0.1)
			("_burn_crash" args "part26"			0.1)
			("_burn_crash" args "part27"			0.1)
			("_burn_crash" args "part28"			0.1)
			("_burn_crash" args "part29"			0.1)
			("_burn_crash" args "part30"			0.1)
			("_burn_crash" args "part31"			0.1)
			("_burn_crash" args "part32"			0.1)
			("_burn_crash" args "part33"			0.1)
			("_burn_crash" args "part34"			0.1)
			("_burn_crash" args "part35"			0.1)
			("_burn_crash" args "part36"			0.1)
			("_burn_crash" args "part37"			0.1)
			("_burn_crash" args "part38"			0.1)
			("_burn_crash" args "part39"			0.1)
			("_burn_crash" args "part40"			0.1)
			("_burn_crash" args "part41"			0.1)
			("_burn_crash" args "part42"			0.1)
			("_burn_crash" args "part43"			0.1)
			("_burn_crash" args "part44"			0.1)
			("_burn_crash" args "part45"			0.1)
			("_burn_crash" args "part46"			0.1)
			("_burn_crash" args "part47"			0.1)
			("_burn_crash" args "part48"			0.1)
			("_burn_crash" args "part49"			0.1)
			("_burn_crash" args "part50"			0.1)
			("_burn_crash" args "part51"			0.1)
			("_burn_crash" args "part52"			0.1)
			("_burn_crash" args "part53"			0.1)
			("_burn_crash" args "part54"			0.1)
			("_burn_crash" args "part55"			0.1)
			("_burn_crash" args "part56"			0.1)
			("_burn_crash" args "part57"			0.1)
			("_burn_crash" args "part58"			0.1)
			("_burn_crash" args "part59"			0.1)
			("_burn_crash" args "part60"			0.1)
			("_burn_crash" args "part61"			0.1)
			("_burn_crash" args "part62"			0.1)
			("_burn_crash" args "part63"			0.1)
			("_burn_crash" args "part64"			0.1)
			("_burn_crash" args "part65"			0.1)
			("_burn_crash" args "part66"			0.1)
			("_burn_crash" args "part67"			0.1)
			("_burn_crash" args "part68"			0.1)
			("_burn_crash" args "part69"			0.1)
			("_burn_crash" args "part70"			0.1)
			("_burn_crash" args "part71"			0.1)
			("_burn_crash" args "part72"			0.1)
			("_burn_crash" args "part73"			0.1)
			("_burn_crash" args "part74"			0.1)
			("_burn_crash" args "part75"			0.1)
			("_burn_crash" args "part76"			0.1)
			("_burn_crash" args "part77"			0.1)
			("_burn_crash" args "part78"			0.1)
			("_burn_crash" args "part79"			0.1)
		}
	}
	{on "end_stage_b"
		{if effector "helicopter"
			{if min_speed 25
				{start_sound "crush/small/wood/"}
				{spawn "wood_crush_small" "basis"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 12 4 dir 12 2 cx 7 2 cy 7 2 rnd_dir 8 no_position}
					}	
				}	
			else min_speed 12
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 2 1 dir 4 2 cx 4 2 cy 4 2 rnd_dir 3 no_position}
					}	
				}	
			else 
				{impulse up 2 1 }
			}
		}
	}		
	{on "end_stage_r"
		{start_sound "crush/small/wood/"}
		{spawn "wood_crush_small" "basis"}
		(define "contact_hit"
			{tear "piece_small_wood" bone %0
				{add_view "smoke_cover-up_small_fast" "smoke" "basis"}
				{view start "smoke"}
				{delay_effect 2 1 "pause"}
				{impulse up 5 1 dir 12 4 cx 12 cy 12 rnd_dir 5 no_position}
			}
		)	
		("contact_hit" args "part01"		)
		("contact_hit" args "part02"		)
		("contact_hit" args "part03"		)
		("contact_hit" args "part04"		)
		("contact_hit" args "part05"		)
		("contact_hit" args "part06"		)
		("contact_hit" args "part07"		)
		("contact_hit" args "part08"		)
		("contact_hit" args "part09"		)
		("contact_hit" args "part10"		)
		("contact_hit" args "part11"		)
		("contact_hit" args "part12"		)
		("contact_hit" args "part13"		)
		("contact_hit" args "part14"		)
		("contact_hit" args "part15"		)
		("contact_hit" args "part16"		)
		("contact_hit" args "part17"		)
		("contact_hit" args "part18"		)
		("contact_hit" args "part19"		)
		("contact_hit" args "part20"		)
	}
	{on contact
		{if effector "fraction"
			{start_sound "crush/small/wood/"}
			{with_effector
				{delete}
			}
			{spawn "wood_hit_bul"}
			{if volume "parts"
				{if rand 0.01
					{call "end_stage_r"}	
				}
				{if rand 0.2
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "wood_hit_bul"}
						{impulse up 0.5 dir 1 0.5 cx 1 cy 1 rnd_dir 0.5 no_position}
					}
				}
			}		
		else effector "big_build"
			{if min_speed 15
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.2
						{start_sound "crush/small/wood/"}
						{tear "piece_small_wood" bone from_volume
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}					
		else effector "concrete"
			{if min_speed 10
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.7
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}					
		else effector "hit_small"
			{if min_speed 20
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.3
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			else min_speed 5
				{spawn "hay_hit_small3" }
			}			
		else effector "vehicle"
			{if min_speed 40
				{impulse up 0.5 dir 2 cx 0.5 cy 0.5}
				{start_sound "crush/small/wood/"}
				{spawn "wood_crush_small" "basis"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 12 4 dir 12 2 cx 7 2 cy 7 2 rnd_dir 8 no_position}
					}	
				}	
			else min_speed 25
				{start_sound "crush/small/wood/"}
				{if volume "parts"
					{tear "piece_small_wood" bone from_volume
						{impulse up 5 1 dir 4 2 cx 4 2 cy 4 2 rnd_dir 3 no_position}
					}	
				}	
			}
		else effector "steel"
			{if min_speed 20
				{start_sound "hit/small/wood_steel/"}
				{start_sound "hit/small/wood_solid/"}
				{spawn "hay_hit_small3" }
				{if volume "parts"
					{if rand 0.3
						{tear "piece_small_wood" bone from_volume
							{impulse up 5 1 dir 3 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}	
					}
				}
			}					
		else min_speed 5
			{spawn "hay_hit_small3" }
		}
	}		
	{on bullet_hit
		{if stuff "shell_minimum fg"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.9		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.9		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "fx_40"
			{spawn "wood_crush_small" "basis"}
			{bullet_detonate}
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 4 3 dir 14 3 cx 5 2 cy 5 2 rnd_dir 6 no_position}
				}
			)	
			("cut_part" args "part01")
			("cut_part" args "part02")
			("cut_part" args "part03")
			("cut_part" args "part04")
			("cut_part" args "part05")
			("cut_part" args "part06")
			("cut_part" args "part07")
			("cut_part" args "part08")
			("cut_part" args "part09")
			("cut_part" args "part10")
			("cut_part" args "part11")
			("cut_part" args "part12")
			("cut_part" args "part13")
			("cut_part" args "part14")
			("cut_part" args "part15")
			("cut_part" args "part16")
			("cut_part" args "part17")
			("cut_part" args "part18")
			("cut_part" args "part19")
		else stuff "shell"
			{burn fx "smoke_aero_small" time 4 fake}				
			{burn fx "smoke_aero_2_small" time 9 fake}				
			{burn fx "smoke_aero_3_small" time 14 fake}				
			{spawn "wood_crush_small" "basis"}
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 8 3 dir 8 4}
				}
			)	
			("cut_part" args "part01")
			("cut_part" args "part02")
			("cut_part" args "part03")
			("cut_part" args "part04")
			("cut_part" args "part05")
			("cut_part" args "part06")
			("cut_part" args "part07")
			("cut_part" args "part08")
			("cut_part" args "part09")
			("cut_part" args "part10")
			("cut_part" args "part11")
			("cut_part" args "part12")
			("cut_part" args "part13")
			("cut_part" args "part14")
			("cut_part" args "part15")
			("cut_part" args "part16")
			("cut_part" args "part17")
			("cut_part" args "part18")
			("cut_part" args "part19")
		}
	}
	{on "break_all_expl"
		{start_sound "crush/small/wood/"}
		(define "break_all_expl"
			{tear "piece_small_wood" bone %0
				{impulse up 5 2 dir 20 5 cx 8 2 cy 8 2 rnd_dir 8 no_position}
			}
		)	
		("break_all_expl" args "part01"			)
		("break_all_expl" args "part02"			)
		("break_all_expl" args "part03"			)
		("break_all_expl" args "part04"			)
		("break_all_expl" args "part05"			)
		("break_all_expl" args "part06"			)
		("break_all_expl" args "part07"			)
		("break_all_expl" args "part08"			)
		("break_all_expl" args "part09"			)
		("break_all_expl" args "part10"		)
		("break_all_expl" args "part11"		)
		("break_all_expl" args "part12"		)
		("break_all_expl" args "part13"		)
		("break_all_expl" args "part14"		)
		("break_all_expl" args "part15"		)
		("break_all_expl" args "part16"		)
		("break_all_expl" args "part17"		)
		("break_all_expl" args "part18"		)
		("break_all_expl" args "part19"		)
		("break_all_expl" args "part20"			)
		("break_all_expl" args "part21"			)
		("break_all_expl" args "part22"			)
		("break_all_expl" args "part23"			)
		("break_all_expl" args "part24"			)
		("break_all_expl" args "part25"			)
		("break_all_expl" args "part26"			)
		("break_all_expl" args "part27"			)
		("break_all_expl" args "part28"			)
		("break_all_expl" args "part29"			)
		("break_all_expl" args "part30"			)
		("break_all_expl" args "part31"			)
		("break_all_expl" args "part32"			)
		("break_all_expl" args "part33"			)
		("break_all_expl" args "part34"			)
		("break_all_expl" args "part35"			)
		("break_all_expl" args "part36"			)
		("break_all_expl" args "part37"			)
		("break_all_expl" args "part38"			)
		("break_all_expl" args "part39"			)
		("break_all_expl" args "part40"			)
		("break_all_expl" args "part41"			)
		("break_all_expl" args "part42"			)
		("break_all_expl" args "part43"			)
		("break_all_expl" args "part44"			)
		("break_all_expl" args "part45"			)
		("break_all_expl" args "part46"			)
		("break_all_expl" args "part47"			)
		("break_all_expl" args "part48"			)
		("break_all_expl" args "part49"			)
		("break_all_expl" args "part50"			)
		("break_all_expl" args "part51"			)
		("break_all_expl" args "part52"			)
		("break_all_expl" args "part53"			)
		("break_all_expl" args "part54"			)
		("break_all_expl" args "part55"			)
		("break_all_expl" args "part56"			)
		("break_all_expl" args "part57"			)
		("break_all_expl" args "part58"			)
		("break_all_expl" args "part59"			)
		("break_all_expl" args "part60"			)
		("break_all_expl" args "part61"			)
		("break_all_expl" args "part62"			)
		("break_all_expl" args "part63"			)
		("break_all_expl" args "part64"			)
		("break_all_expl" args "part65"			)
		("break_all_expl" args "part66"			)
		("break_all_expl" args "part67"			)
		("break_all_expl" args "part68"			)
		("break_all_expl" args "part69"			)
		("break_all_expl" args "part70"			)
		("break_all_expl" args "part71"			)
		("break_all_expl" args "part72"			)
		("break_all_expl" args "part73"			)
		("break_all_expl" args "part74"			)
		("break_all_expl" args "part75"			)
		("break_all_expl" args "part76"			)
		("break_all_expl" args "part77"			)
		("break_all_expl" args "part78"			)
		("break_all_expl" args "part79"			)
	}
	{on blast
		{if volume "parts"
			{if min_energy 8
				{start_sound "crush/small/wood/"}
				{call "break_all_expl"}
			else min_energy 6
				{start_sound "crush/small/wood/"}
				{tear "piece_small_wood" bone from_volume
					{impulse up 21 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			else min_energy 4
				{start_sound "crush/small/wood/"}
				{if rand 0.8		
					{tear "piece_small_wood" bone from_volume
						{impulse up 14 1 dir 5 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			else min_energy 2
				{start_sound "crush/small/wood/"}
				{if rand 0.6		
					{tear "piece_small_wood" bone from_volume
						{impulse up 10 1 dir 5 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}	
			else min_energy 1
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{impulse up 6 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
					}
				}					
			}
		}
	}
	{on pierce
		{if stuff "zenite"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.9		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.4		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet hmgun"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.7		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 5 2 dir 3 2 cx 7 2 cy 7 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.09		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet sp"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.1		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 1 0.5 dir 1 0.5 cx 2 1 cy 2 1 rnd_dir 3 no_position}
						}
					}
					{if "burned"
						{if rand 0.6		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 2 0.5 dir 2 0.5 cx 2 1 cy 2 1 rnd_dir 3 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.01		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.2 dir 1 cx 1 cy 1 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.2		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet normal ap"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 3 1 dir 4 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.09		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
		{if stuff "bullet normal"
			{if volume "parts"
				{if not volume "hard"
					{if rand 0.3		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 2 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
						}
					}
					{if "burned"
						{if rand 0.9		
							{tear "piece_small_wood" bone from_volume
								{start_sound "crush/small/wood/"}
								{spawn "hay_hit_wood" }
								{impulse up 3 1 dir 4 1 cx 5 2 cy 5 2 rnd_dir 6 no_position}
							}
						}
					}	
				}
			else
				{if rand 0.05		
					{tear "piece_small_wood" bone from_volume
						{start_sound "crush/small/wood/"}
						{spawn "hay_hit_wood" }
						{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
					}
				}
				{if "burned"
					{if rand 0.5		
						{tear "piece_small_wood" bone from_volume
							{start_sound "crush/small/wood/"}
							{spawn "hay_hit_wood" }
							{impulse up 0.4 dir 1 cx 2 cy 2 rnd_dir 1 no_position}
						}
					}
				}	
			}		
		}
	}	
}
