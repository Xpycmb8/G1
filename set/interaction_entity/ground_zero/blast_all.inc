{call "check_work_organ"}
{if able "exploded"
	{tags remove "electric_spark_loop"}
}		
{if not stuff "damage_overlap"
	{tags add "blast_hit"}
	{delay 2
		{tags remove "blast_hit"}
	}
	{if min_energy 6
		{if volume "frontplate"
			{if work "frontplate"
				{if not "blocked"
					{call "move_hit"}
				}
			else
				{components "frontplate" break}
			}
		}
	}
	(define "prop_hit" 
		{if tagged "%prop"
			{if min_energy %impact
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
				{if volume "fuel_small" 
					{components "fuel_small" break}
				}
				{if volume "visor_head" 
					{if tagged "destroy_visor"
						{spawn "electric_spark_hit_pierce" volume x}				
						{tear "piece_delete" bone from_volume}	
					}
				}
				(define "arm" ;части ног если сломан
					{if min_mass 200
						{if volume "%component"
							{if able "exploded"
								{if rand 0.6
									{tear "piece_small_steel_forward" bone "%component"
										{impulse dir 1 0.5 	cx 1 0.5 cy 1 0.5 no_position}
									}				
								}
							}
						}
					}
				)
				("arm" component(RightToeBase)  		rand(0.5)    )
				("arm" component(RightFoot)  			rand(0.5)    )
				("arm" component(RightLeg)  			rand(0.5)    )
				("arm" component(rightupperleg)  		rand(0.5)    )
				("arm" component(leftToeBase)  			rand(0.5)    )
				("arm" component(leftFoot)  			rand(0.5)    )
				("arm" component(leftLeg)  				rand(0.5)    )
				("arm" component(leftupperleg)  		rand(0.5)    )
				("arm" component(centralToeBase)  		rand(0.5)    )
				("arm" component(centralFoot)  			rand(0.5)    )
				("arm" component(centralLeg)  			rand(0.5)    )
				("arm" component(centralupperleg)  		rand(0.5)    )	
				{if rand %rand_impact
					(define "glass_damaged" ;
						{if volume "%component"
							{if work "%component"
								{components "%component" break}
							else
								{if rand 0.4
									{components "%component" destroy}
									{spawn "glass_hit_car" volume x}
								}
							}
						}
					)
					("glass_damaged" component(head_light_00)  			)
					("glass_damaged" component(head_light_small_00)  	)
					("glass_damaged" component(head_light_small_01)  	)
					("glass_damaged" component(head_light_small_02)  	)
				}
				(define "mesh_break" ;
					{if component "%component"
						{if not work "%component"
							{if rand %d_rand
								{components "%component" destroy}
							}
						else
							{if rand %rand
								{components "%component" break}
							}
						}
					}
				)
				("mesh_break" component(bridge)  								rand(0.3) d_rand(0.3)      )
				("mesh_break" component(hips)  									rand(0.3) d_rand(0.3)      )
				("mesh_break" component(gasdrop_l)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(gasdrop_r)  							rand(0.3) d_rand(0.3)    )
				("mesh_break" component(Concussion_Pulse_r)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Concussion_Pulse_l)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Drillmount)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backlegs_mount)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(frontlegs_mount)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_core_panel)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(structure_plate_right)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(structure_plate_left)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(back_hatch_l)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(back_hatch_r)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch)  							rand(0.3) d_rand(0.5)    ) ;lynx
				("mesh_break" component(front_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(drill_hatch_l)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(Drill)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(pestcontainer)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(engine_move)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_01)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_02)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(backfan_03)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(sideplate_left)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(sideplate_right)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_front_r)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_front_l)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_back_r)  				rand(0.3) d_rand(0.5)    )
				("mesh_break" component(head_sideplate_back_l)  				rand(0.3) d_rand(0.5)    )
				;all armor
				("mesh_break" component(front_armor)  							rand(0.3) d_rand(0.5)	 )
				("mesh_break" component(down_armor)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(armour_head)  							rand(0.5) d_rand(0.5)    )
				("mesh_break" component(armour_knee_left)  						rand(0.5) d_rand(0.5)    )
				("mesh_break" component(armour_knee_right)  					rand(0.5) d_rand(0.5)    )
				("mesh_break" component(armour_shoulder_left)  					rand(0.5) d_rand(0.5)    )
				("mesh_break" component(armour_shoulder_right)  				rand(0.5) d_rand(0.5)    )
				("mesh_break" component(kneepad_r)  							rand(0.5) d_rand(0.5)    )
				("mesh_break" component(kneepad_l)  							rand(0.5) d_rand(0.5)    )
				("mesh_break" component(head_top)  								rand(0.5) d_rand(0.5)    )
				("mesh_break" component(back_armor)  							rand(0.5) d_rand(0.5)    )
				("mesh_break" component(upper_armor_raid)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_armor_raid)  						rand(0.2) d_rand(0.5)    )
				("mesh_break" component(armor_head_wire)  						rand(0.5) d_rand(0.5)    )
				("mesh_break" component(knee_plate_l)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(knee_plate_r)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_plate_r)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(front_plate_l)  						rand(0.3) d_rand(0.5)    )
				
				("mesh_break" component(armour_prot_right)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(armour_prot_left)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(cyl_prot_plate_right)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(cyl_prot_plate_left)  					rand(0.3) d_rand(0.5)    )

				("mesh_break" component(armour_head_upper)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(armour_head_lower)  					rand(0.3) d_rand(0.5)    )
				
				("mesh_break" component(armor_ballistic_left_hand)  			rand(0.7) d_rand(0.5)    )
				("mesh_break" component(armor_ballistic_right_hand)  			rand(0.7) d_rand(0.5)    )
				("mesh_break" component(armor_left_engine_wire)  				rand(0.7) d_rand(0.5)    ) ;hunter
				("mesh_break" component(armor_right_engine_wire)  				rand(0.7) d_rand(0.5)    )	;hunter
				("mesh_break" component(armor_cpu_wire)  						rand(0.7) d_rand(0.5)    )	;hunter

				("mesh_break" component(trackLeft)  						rand(0.7) d_rand(0.5)    )	;lynx
				("mesh_break" component(trackRight)  						rand(0.7) d_rand(0.5)    )	;lynx
				
				;all leg
				("mesh_break" component(leftupleg_knee)  						rand(0.5) d_rand(0.5) 	 )
				("mesh_break" component(leftarm)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftfoot)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftforearm)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(lefthand)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(lefthandtoe)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftleg)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(lefttoebase)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftupleg)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftShoulder)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftUpLeg_spring)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftUpLeg1)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftArmorPlate_Knee)  					rand(0.5) d_rand(0.5)    )
				("mesh_break" component(leftToe1)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftToe2)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftToe3)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(leftToe4)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightupleg_knee)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightarm)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightfoot)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightforearm)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(righthand)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(righthandtoe)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightleg)  								rand(0.3) d_rand(0.5)    )
				("mesh_break" component(righttoebase)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightupleg)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightShoulder)  						rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightUpLeg_spring)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightUpLeg1)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightArmorPlate_Knee)  					rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightToe1)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightToe2)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightToe3)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(rightToe4)  							rand(0.3) d_rand(0.5)    )
				("mesh_break" component(armor)  								rand(0.3) d_rand(0.5)    )
				(define "organ_break" ;
					{if volume "%volume"
						{if not work "%component"
							{if rand %rand_destroy
								{components "%component" destroy}
							}
						}
						{if rand %rand
							{components "%component" break}
						}
					}
				)
				("organ_break" volume(head) 							component(head) 				 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(neck) 							component(neck) 				 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(head_arm)							component(head_arm) 				 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(head_joint)						component(head_joint) 			 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(battery)							component(battery) 				 		rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(battery_r)						component(battery_r) 			 		rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(battery_l)						component(battery_l) 					rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(cooling_systems)					component(cooling_systems) 				rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(leg_regulator_large_right)		component(leg_regulator_large_right) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(leg_regulator_large_left)			component(leg_regulator_large_left) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_leg_motor_left)			component(organs_leg_motor_left) 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_leg_motor_right)			component(organs_leg_motor_right) 		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_engine_drive_left)			component(organs_engine_drive_left) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_engine_drive_right)		component(organs_engine_drive_right) 	rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_hip_right)					component(organs_hip_right)  			rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_hip_left)					component(organs_hip_left)  			rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(hydraulic_knee_right)				component(hydraulic_knee_right)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(hydraulic)						component(hydraulic)  					rand(0.5) rand_destroy(0.5)  ) ;lynx
				("organ_break" volume(hydraulic_knee_left)				component(hydraulic_knee_left)  		rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_leg_right)					component(organs_leg_right)  			rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(organs_leg_left)					component(organs_leg_left)  			rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(right_engine)						component(right_engine)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(left_engine)						component(left_engine)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(right_engine2)					component(right_engine2)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(left_engine2)						component(left_engine2)  				rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(body_organ)						component(body_organ)  					rand(0.1) rand_destroy(0.1)  )
				("organ_break" volume(head_organ)						component(head_organ)  					rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(head_wire)						component(head_wire)  					rand(0.5) rand_destroy(0.5)  )
				("organ_break" volume(visor_head)						component(visor_head)  					rand(0.3) rand_destroy(0.3)  )
				("organ_break" volume(visor_body)						component(visor_body) 					rand(0.3) rand_destroy(0.3)  )
				("organ_break" volume(LeftPiston_UpperLegToShoulder)	component(LeftPiston_UpperLegToShoulder) 	rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightPiston_UpperLegToShoulder)	component(RightPiston_UpperLegToShoulder) 	rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftUpLeg_cylplate_01)			component(leftUpLeg_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftUpLeg_cylplate_02)			component(leftUpLeg_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftUpLeg1_cylplate_01)			component(leftUpLeg1_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftUpLeg1_cylplate_02)			component(leftUpLeg1_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftFoot_cylplate_01)				component(leftFoot_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(leftFoot_cylplate_02)				component(leftFoot_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightUpLeg_cylplate_01)			component(RightUpLeg_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightUpLeg_cylplate_02)			component(RightUpLeg_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightUpLeg1_cylplate_01)			component(RightUpLeg1_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightUpLeg1_cylplate_02)			component(RightUpLeg1_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightFoot_cylplate_01)			component(RightFoot_cylplate_01) 		rand(0.5) rand_destroy(0.2)  )
				("organ_break" volume(RightFoot_cylplate_02)			component(RightFoot_cylplate_02) 		rand(0.5) rand_destroy(0.2)  )				
				("organ_break" volume(fuel)								component(fuel) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(legplate_right)					component(legplate_right) 				rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(legplate_left)					component(legplate_left)  				rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(shoulder_plate_left)				component(shoulder_plate_left) 			rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(shoulder_plate_right)				component(shoulder_plate_right)  		rand(0.3) rand_destroy(0.2)  )
				("organ_break" volume(missile_l)						component(missile_l) 					rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(missile_r)						component(missile_r) 					rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(guided_missile)					component(missilelauncher) 				rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(flamethrower)						component(flamethrower) 				rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(fuel_rods_l)						component(fuel_rods_l) 					rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(fuel_rods_r)						component(fuel_rods_r) 					rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(rocket)							component(rocket) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(mgun)	 							component(mgun) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(sniper)	 						component(sniper) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(missile)	 						component(missile) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(missilelauncher)	 				component(missilelauncher) 				rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(ammo)	 							component(ammo) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(shotgun)	 						component(shotgun) 						rand(0.2) rand_destroy(0.2)  )
				("organ_break" volume(rocket_cluster)	 				component(rocket_cluster) 				rand(0.2) rand_destroy(0.2)  )				
			}
		}
	)
	("prop_hit" prop(drone_base)  			impact(1) rand_impact(0.5) )
	("prop_hit" prop(pest_base)  			impact(2) rand_impact(0.5) )
	("prop_hit" prop(scout_base)  			impact(2) rand_impact(0.3) )
	("prop_hit" prop(lynx_base)  			impact(2) rand_impact(0.2) )
	("prop_hit" prop(skirmisher_base)  		impact(2) rand_impact(0.2) )
	("prop_hit" prop(hunter_base)  			impact(3) rand_impact(0.2) )
	("prop_hit" prop(dreadnought_base) 		impact(4) rand_impact(0.2) )
	("prop_hit" prop(harvester_base)  		impact(4) rand_impact(0.2) )
}
