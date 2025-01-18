	(define "pierce_impulse" ;	
		("bullet_hit" args "all_ap"				1 	{impulse forward 0.1 dir 7 4} )			
		("bullet_hit" args "atgm_launcher"		1 	{impulse forward 0.1 dir 7 4} )			
		("bullet_hit" args "rocketlauncher fg"	1 	{impulse forward 0.1 dir 7 4} )			
		("bullet_hit" args "rocketlauncher"		1 	{impulse forward 0.1 dir 5 2} )			
		("bullet_hit" args "shell_minimum"		1 	{impulse forward 0.1 dir 5 2} )				
		("bullet_hit" args "shell"				1 	{impulse forward 0.1 dir 5 2} )				
		("bullet_hit" args "heavy_zenite"		0.9 {impulse forward 0.2 dir 4 2} )				
		("bullet_hit" args "bullet grenade"		0.6 {impulse forward 0.1 dir 4 2} )				
		("bullet_hit" args "zenite"				0.9 {impulse forward 0.1 dir 4 2} )				
		("bullet_hit" args "bullet big sniper"	0.7 {impulse forward 0.1 dir 2 1.2} )		
		("bullet_hit" args "bullet big ap"		0.6 {impulse forward 0.1 dir 1.2 0.8} )		
		("bullet_hit" args "bullet big"			0.4 {impulse forward 0.1 dir 1 0.6} )		
		("bullet_hit" args "bullet med"			0.5 {impulse forward 0.1 dir 1 0.5} )		
		("bullet_hit" args "bullet normal ap"	0.35 {impulse forward 0.1 dir 1} )		
		("bullet_hit" args "bullet normal"		0.3 {impulse forward 0.06 dir 1} )		
		("bullet_hit" args "bullet small ap"	0.2 {impulse forward 0.1 dir 0.5} )		
		("bullet_hit" args "bullet small"		0.15 {impulse forward 0.1 dir 0.5} )		
		("bullet_hit" args "bullet"				0.1 {impulse forward 0.1 dir 0.3} )		
	)		
	{call "stop_idle"}
	{call "check_work_organ"}
	{if volume "damaged_component"	
		{burn volume fx "component_break_fx" time 1 fake even_law}								
	}
	{if not able "exploded"			
		{if volume "armor_composite_back_right"	
			{if not tagged "move"
				{if not tagged "replace_position"
					{ani_play "hit_reel_135ccw" 0.5}
				}					
			}
		}		
		{if volume "armor_composite_back_left"	
			{if not tagged "move"
				{if not tagged "replace_position"
					{ani_play "hit_reel_135cw" 0.5}
				}					
			}
		}		
		{if volume "armor_composite_front_right"	
			{if not tagged "move"
				{if not tagged "replace_position"
					{ani_play "hit_reel_45cw" 0.5}
				}					
			}
		}		
		{if volume "armor_composite_front_left"	
			{if not tagged "move"
				{if not tagged "replace_position"
					{ani_play "hit_reel_45ccw" 0.5}
				}					
			}
		}
	}
	{if volume "armor_composite"		
		{bullet_detonate}
		{spawn "composite_destroy" volume x}				
		{tear "piece_delete" bone from_volume}	
	}	
	{if volume "armor_composite_rus"		
		{bullet_detonate}
		{spawn "composite_destroy_rus" volume x}				
		{tear "piece_delete" bone from_volume}	
	}	
	(define "glass_damaged" ;
		{if rand 0.2
			{if volume "%component"
				{if not work "%component"
					{components "%component" destroy}
					{spawn "glass_hit_car" volume x}
				}
			}
		}
		{if volume "%component"
			{if rand %rand
				{if work "%component"
					{components "%component" break}
				}
			}
		}
	)
	("glass_damaged" component(head_light_00)  			rand(0.5)    )
	("glass_damaged" component(head_light_small_00)  	rand(0.5)    )
	("glass_damaged" component(head_light_small_01)  	rand(0.5)    )
	("glass_damaged" component(head_light_small_02)  	rand(0.5)    )		
	{if volume "frontplate" 
		{components "frontplate" break}	
		{if not "blocked"
			{call "move_hit"}
		}			
	else volume "fueltank"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "fueltank"							
						{spawn "ex_molot_fire_impact" "fueltank"}
						{spawn "ex_molot_fire_impact" "fueltank"}
						{spawn "ex_molot_fire_impact" "fueltank"}
						{spawn "open_gas_ph" "fueltank"}
						{spawn "open_gas_ph" "fueltank"}
						{spawn "ex_molot_contact" "fueltank"}
						{burn fx "hit_fuel_tritium" time 3 }
						{components "fueltank" break}
					else
						{if rand %1
							{components "fueltank" destroy}
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "fuel"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "fuel"
						{burn fx "hit_fuel_tritium" time 3 }
						{components "fuel" break}
					else
						{if rand %1
							{components "fuel" destroy}
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "fuel_small"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "fuel"
						{components "fuel_small" break}
					else
						{if rand %1
							{components "fuel_small" destroy}
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "guided_missile"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "missile"
						{components "missile" break}
					else
						{if rand %1
							{components "missile" destroy}
						}
					}
				}
				{if tagged "destroy_missile"
					{if rand 0.1
						{tear "piece_big_steel" bone from_volume
							{burn volume fx "smoke_bats" time 5 fake even_law}					
							%2
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "Missile_r"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "Missile_r"
						{components "Missile_r" break}
					else
						{if rand %1
							{components "Missile_r" destroy}
						}
					}
				}
				{if tagged "destroy_missile_r"
					{if rand 0.3
						{tear "piece_big_steel" bone from_volume
							{burn volume fx "smoke_bats" time 5 fake even_law}					
							%2
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "Missile_l"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "Missile_l"
						{components "Missile_l" break}
					else
						{if rand %1
							{components "Missile_l" destroy}
						}
					}
				}
				{if tagged "destroy_missile_r"
					{if rand %1
						{tear "piece_big_steel" bone from_volume
							{burn volume fx "smoke_bats" time 5 fake even_law}					
							%2
						}
					}
				}
			}
		)
		("pierce_impulse")	
	else volume "shotgun"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "shotgun"
						{components "shotgun" break}
					else
						{if rand 0.3
							{components "shotgun" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	else volume "sniper"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "sniper"
						{components "sniper" break}
					else
						{if rand 0.3
							{components "sniper" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	else volume "mgun"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "mgun"
						{components "mgun" break}
					else
						{if rand 0.3
							{components "mgun" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	else volume "rocket_cluster"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "rocket_cluster"
						{components "rocket_cluster" break}
					else
						{if rand 0.3
							{components "rocket_cluster" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	else volume "rocket"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "rocket"
						{components "rocket" break}
					else
						{if rand 0.3
							{components "rocket" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	else volume "Flamethrower"
		(define "bullet_hit"
			{if stuff %0
				{if rand %1
					{if work "Flamethrower"
						{components "Flamethrower" break}
					else
						{if rand 0.3
							{components "Flamethrower" destroy}
						}
					}
				}
			}
		)		
		("pierce_impulse")	
	}
	{if volume "armor_crushed"
		{if stuff "shell"
			{tear "piece_medium_steel" bone from_volume
				(define "disable_contact_blast_0")
				{impulse forward 3 dir 5 2}
			}
		else stuff "shell_minimum"
			{tear "piece_medium_steel" bone from_volume
				(define "disable_contact_blast_0")
				{impulse forward 1 dir 2 1}
			}			
		}
	}
	;organ
	(define "bullet_hit" 
		{if stuff %0
			{if rand %1
				{if volume "head_arm"
					{if not work "head_arm"
						{components "head_arm" destroy}
						{ik_enable "Head_ik_v2" 0}
						{ik_enable "head_ik_v_damage" 0}													
						{spawn "electric_spark_hit_pierce" }
					else
						{components "head_arm" break}
						{ik_enable "head_ik_v" 0}
						{ik_enable "head_ik_v_damage" 1}							
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "neck"
					{if not work "neck"
						{components "neck" destroy}
						{ik_enable "eyes_ik_h" 0}						
						{spawn "electric_spark_hit_pierce" }
					else
						{components "neck" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "neck1"
					{if not work "neck1"
						{components "neck1" destroy}
						{ik_enable "eyes_ik_h" 0}						
						{spawn "electric_spark_hit_pierce" }
					else
						{components "neck1" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "head_joint"
					{if not work "head_joint"
						{components "head_joint" destroy}
						{spawn "electric_spark_hit_pierce" }
					else
						{components "head_joint" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "battery"
					{if not work "battery"
						{components "battery" destroy}
						{spawn "break_small_body_robot" "battery" } ;destroy_component
					else
						{components "battery" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "battery_r"
					{if not work "battery_r"
						{components "battery_r" destroy}
					else
						{components "battery_r" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "battery_l"
					{if not work "battery_l"
						{components "battery_l" destroy}
					else
						{components "battery_l" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "cooling_systems"
					{if not work "cooling_systems"
						{components "cooling_systems" destroy}
						{spawn "destroy_component" "cooling_systems" } 
					else
						{burn volume "cooling_systems" fx "brake_component" time 2 fake even_law}	
						{components "cooling_systems" break} ;
					}
				else volume "leg_regulator_large_right"
					{if not work "leg_regulator_large_right"
						{components "leg_regulator_large_right" destroy}
					else
						{components "leg_regulator_large_right" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "leg_regulator_large_left"
					{if not work "leg_regulator_large_left"
						{components "leg_regulator_large_left" destroy}
					else
						{components "leg_regulator_large_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "leg_motor_left"
					{if not work "leg_motor_left"
						{components "leg_motor_left" destroy}
					else
						{components "leg_motor_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "leg_motor_right"
					{if not work "leg_motor_right"
						{components "leg_motor_right" destroy}
					else
						{components "leg_motor_right" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_engine_drive_left"
					{if not work "organs_engine_drive_left"
						{components "organs_engine_drive_left" destroy}
					else
						{components "organs_engine_drive_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_engine_drive_right"
					{if not work "organs_engine_drive_right"
						{components "organs_engine_drive_right" destroy}
					else
						{components "organs_engine_drive_right" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_hip_right"
					{if not work "organs_hip_right"
						{components "organs_hip_right" destroy}
					else
						{components "organs_hip_right" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_hip_left"
					{if not work "organs_hip_left"
						{components "organs_hip_left" destroy}
					else
						{components "organs_hip_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "hydraulic_knee_right"
					{if not work "hydraulic_knee_right"
						{components "hydraulic_knee_right" destroy}
					else
						{components "organs_hip_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "hydraulic_knee_left"
					{if not work "hydraulic_knee_left"
						{components "hydraulic_knee_left" destroy}
					else
						{components "hydraulic_knee_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "hydraulic" ;lynx
					{if not work "hydraulic"
						{components "hydraulic" destroy}
						{spawn "electric_spark_hit_pierce" }
					else
						{components "hydraulic" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_leg_right"
					{if not work "organs_leg_right"
						{components "organs_leg_right" destroy}
					else
						{components "organs_hip_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "organs_leg_left"
					{if not work "organs_leg_left"
						{components "organs_leg_left" destroy}
					else
						{components "organs_leg_left" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "right_engine"
					{if not work "right_engine"
						{components "right_engine" destroy}
					else
						{burn volume "burn_component_break_small" fx "right_engine" time 20 fake even_law}	
						{components "right_engine" break}
						{spawn "break_small_body_robot" "right_engine"}
					}
				else volume "left_engine"
					{if not work "left_engine"
						{components "left_engine" destroy}
					else
						{components "left_engine" break}
						{burn volume "burn_component_break_small" fx "left_engine" time 20 fake even_law}	
						{spawn "break_small_body_robot" "left_engine"}
					}
				else volume "right_engine2"
					{if not work "right_engine2"
						{components "right_engine2" destroy}
					else
						{burn volume "burn_component_break_small" fx "right_engine2" time 20 fake even_law}	
						{components "right_engine2" break}
						{spawn "break_small_body_robot" "right_engine2"}
					}
				else volume "left_engine2"
					{if not work "left_engine2"
						{components "left_engine2" destroy}
					else
						{components "left_engine2" break}
						{burn volume "burn_component_break_small" fx "left_engine2" time 20 fake even_law}	
						{spawn "break_small_body_robot" "left_engine2"}
					}
				else volume "horn"
					{if not work "horn"
						{components "horn" destroy}
					else
						{components "horn" break}
						{burn volume "burn_component_break_small" fx "horn" time 20 fake even_law}	
						{spawn "break_small_body_robot" "horn"}
					}
				else volume "left_jetengine"
					{if not work "jetengine_l"
						{components "jetengine_l" destroy}
					else
						{components "jetengine_l" break}
						{spawn "break_small_body_robot" "jetengine_l"}
					}
				else volume "right_jetengine"
					{if not work "jetengine_r"
						{components "jetengine_r" destroy}
					else
						{components "jetengine_r" break}
						{spawn "break_small_body_robot" "jetengine_r"}
					}
				else volume "body_organ"
					{if not work "body_organ"
						{components "body_organ" destroy}
					else
						{components "body_organ" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "head_organ"
					{if not work "head_organ"
						{components "head_organ" destroy}
					else
						{call "power_drop"}
						{components "head_organ" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "head_wire"
					{if not work "head_wire"
						{components "head_wire" destroy}
						{spawn "electric_spark_hit_pierce" }
					else
						{call "power_drop"}
						{components "head_wire" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "visor_head"
					{if tagged "destroy_visor"
						{tear "piece_small_steel" bone "scanner"
							{impulse dir 2 1	cx 2 1 	cy 2 1 no_position}
							{spawn "electric_spark_hit_pierce" volume x}				
						}	
					}
					{if not work "visor_head"
						{components "visor_head" destroy}
						{spawn "electric_spark_hit_pierce" }
					else
						{components "visor_head" break}
						{spawn "electric_spark_hit_pierce" }
					}
				else volume "visor_body"
					{if not work "visor_body"
						{components "visor_body" destroy}
						{spawn "electric_spark_hit_pierce" }
					else
						{components "visor_body" break}
						{spawn "electric_spark_hit_pierce" }
					}
				}
			}
		}
	)
	("pierce_impulse")	
	{if volume "wire" 
		{burn volume fx "electric_spark_hit_pierce" time 2 fake even_law}
		{burn volume "wire" fx "electric_spark_micro_hit" time 2 1 fake}	
		{if rand 0.2
			{call "power_drop"}	
			{components "wire" break}	
		}
	else volume "wire_small" 
		{burn volume "wire" fx "electric_spark_micro_hit" time 2 1 fake}	
		{if rand 0.5
			{call "power_drop"}	
			{components "wire_small" break}	
		}
	}
