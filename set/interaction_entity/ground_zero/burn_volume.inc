{on "burn_volume"
	{call "check_work_organ"}
	{burn volume fx "smoke_heat" time 4 fake even_law}
	{if not burned
		{if component "wire_small"
			{delay 4
				{call "power_drop_permanent"}
			}
		}
		{if component "fuel_small"
			{burn volume fx "smoke_dead_body_fast" time 8 fake even_law}
			{delay 6
				{call "_explosion_pest"}	
			}
		}
	}
	{if component "mgun"
		{burn volume "mgun" fx "smoke_dead_body_fast" time 8 fake even_law}
		{delay 4
			{if not work "mgun"
				{if rand 0.2
					{components "mgun" destroy}
				}
			}
			{if rand 0.3
				{delay 6
					{burn volume "mgun" fx "smoke_dead_body_fast" time 8 fake even_law}
					{components "mgun" break}
					{fire volume "mgun" radius 0.2 heating 0.2  time 5 follow}
				}
			}
		}
	}
	{if component "cpu"
		{burn volume "cpu" fx "smoke_dead_small_robo" time 8 fake even_law}
		{delay 4
			{if not work "cpu"
				{if rand 0.3
					{components "cpu" destroy}
				}
			}
			{if rand 0.3
				{delay 6
					{burn volume "cpu" fx "smoke_dead_body_fast" time 8 fake even_law}
					{components "cpu" break}
					{fire volume "cpu" radius 0.3 heating 0.2  time 5 follow}
					;{if rand 0.1
					;	{call "explosion_skir"}							
					;}
				}
			}
		}
	}
	(define "burn_volume" ;
		{if component "%component"
			{burn volume "%volume" fx "smoke_dead_body_fast" time 8 fake even_law}
			{delay 4
				{if not work "%component"
					{if rand %rand
						{components "%component" destroy}
					}
				}
				{if rand %rand
					{delay 6
						{burn volume "%volume" fx "smoke_dead_body_fast" time 8 fake even_law}
						{components "%component" break}
						{fire volume "%volume" radius 0.3 heating 0.2  time 5 follow}
					}
				}
			}
		}
	)
	("burn_volume" volume(body)							component(main_body)  					rand(0.3)    )
	("burn_volume" volume(body_r)						component(main_body)  					rand(0.3)    )
	("burn_volume" volume(body_l)						component(main_body)  					rand(0.3)    )
	("burn_volume" volume(body_c)						component(main_body)  					rand(0.3)    )
	("burn_volume" volume(head)							component(head)  						rand(0.4)    )
	("burn_volume" volume(hips)							component(hips)  						rand(0.2)    )
	;all armor

	("burn_volume" volume(armour_prot_right)				component(armour_prot_right)  			rand(0.9)    )
	("burn_volume" volume(armour_prot_left)					component(armour_prot_left)  			rand(0.9)    )
	("burn_volume" volume(cyl_prot_plate_left)				component(cyl_prot_plate_left)  		rand(0.9)    )
	("burn_volume" volume(cyl_prot_plate_right)				component(cyl_prot_plate_right)  		rand(0.9)    )
	("burn_volume" volume(head_sideplate_front_l)			component(head_sideplate_front_l)  		rand(0.9)    )
	("burn_volume" volume(head_sideplate_front_r)			component(head_sideplate_front_r)  		rand(0.9)    )
	("burn_volume" volume(head_sideplate_back_l)			component(head_sideplate_back_l)  		rand(0.9)    )
	("burn_volume" volume(head_sideplate_back_r)			component(head_sideplate_back_r)  		rand(0.9)    )
	
	("burn_volume" volume(armor_ballistic_left_hand)		component(cyl_prot_plate_right)  		rand(0.9)    )
	("burn_volume" volume(armor_ballistic_right_hand)		component(head_sideplate_front_l)  		rand(0.9)    )
	("burn_volume" volume(armor_left_engine_wire)			component(head_sideplate_front_r)  		rand(0.9)    )
	("burn_volume" volume(armor_right_engine_wire)			component(head_sideplate_back_l)  		rand(0.9)    )
	("burn_volume" volume(armor_cpu_wire)					component(head_sideplate_back_r)  		rand(0.9)    )
	

	

	("burn_volume" volume(front_armor)					component(front_armor)  			rand(0.9)    )
	("burn_volume" volume(down_armor)					component(down_armor)  				rand(0.9)    )
	("burn_volume" volume(armour_head_upper)			component(armour_head_upper)  		rand(0.9)    )
	("burn_volume" volume(armour_head)					component(armour_head)  			rand(0.9)    )
	("burn_volume" volume(armour_knee_left)				component(armour_knee_left)  		rand(0.9)    )
	("burn_volume" volume(armour_knee_right)			component(armour_knee_right)  		rand(0.9)    )
	("burn_volume" volume(armour_shoulder_left)			component(armour_shoulder_left)  	rand(0.9)    )
	("burn_volume" volume(armour_shoulder_right)		component(armour_shoulder_right)  	rand(0.9)    )
	("burn_volume" volume(kneepad_r)					component(kneepad_r)  				rand(0.9)    )
	("burn_volume" volume(kneepad_l)					component(kneepad_l)  				rand(0.9)    )
	("burn_volume" volume(head_top)						component(head_top)  				rand(0.9)    )
	("burn_volume" volume(back_armor)					component(back_armor)  				rand(0.9)    )
	("burn_volume" volume(upper_armor_raid)				component(upper_armor_raid)  		rand(0.9)    )
	("burn_volume" volume(front_armor_raid)				component(front_armor_raid)  		rand(0.9)    )
	("burn_volume" volume(armor_head_wire)				component(armor_head_wire)  		rand(0.9)    )
	;all leg
	("burn_volume" volume(leftupleg_knee)				component(leftupleg_knee)  			rand(0.9)    )
	("burn_volume" volume(leftarm)						component(leftarm)  				rand(0.9)    )
	("burn_volume" volume(leftfoot)						component(leftfoot)  				rand(0.9)    )
	("burn_volume" volume(leftforearm)					component(leftforearm)  			rand(0.9)    )
	("burn_volume" volume(lefthand)						component(lefthand)  				rand(0.9)    )
	("burn_volume" volume(lefthandtoe)					component(lefthandtoe)  			rand(0.9)    )
	("burn_volume" volume(leftleg)						component(leftleg)  				rand(0.9)    )
	("burn_volume" volume(lefttoebase)					component(lefttoebase)  			rand(0.9)    )
	("burn_volume" volume(leftupleg)					component(leftupleg)  				rand(0.9)    )
	("burn_volume" volume(leftShoulder)					component(leftShoulder)  			rand(0.9)    )
	("burn_volume" volume(leftUpLeg_spring)				component(leftUpLeg_spring)  		rand(0.9)    )
	("burn_volume" volume(leftUpLeg1)					component(leftUpLeg1)  				rand(0.9)    )
	("burn_volume" volume(leftArmorPlate_Knee)			component(leftArmorPlate_Knee)  	rand(0.9)    )
	("burn_volume" volume(leftToe1)						component(leftToe1)  				rand(0.9)    )
	("burn_volume" volume(leftToe2)						component(leftToe2)  				rand(0.9)    )
	("burn_volume" volume(leftToe3)						component(leftToe3)  				rand(0.9)    )
	("burn_volume" volume(leftToe4)						component(leftToe4)  				rand(0.9)    )
	("burn_volume" volume(rightupleg_knee)				component(rightupleg_knee)  		rand(0.9)    )
	("burn_volume" volume(rightarm)						component(rightarm)  				rand(0.9)    )
	("burn_volume" volume(rightfoot)					component(rightfoot)  				rand(0.9)    )
	("burn_volume" volume(rightforearm)					component(rightforearm)  			rand(0.9)    )
	("burn_volume" volume(righthand)					component(righthand)  				rand(0.9)    )
	("burn_volume" volume(righthandtoe)					component(righthandtoe)  			rand(0.9)    )
	("burn_volume" volume(rightleg)						component(rightleg)  				rand(0.9)    )
	("burn_volume" volume(righttoebase)					component(righttoebase)  			rand(0.9)    )
	("burn_volume" volume(rightupleg)					component(rightupleg)  				rand(0.9)    )
	("burn_volume" volume(rightShoulder)				component(rightShoulder)  			rand(0.9)    )
	("burn_volume" volume(rightUpLeg_spring)			component(rightUpLeg_spring)  		rand(0.9)    )
	("burn_volume" volume(rightUpLeg1)					component(rightUpLeg1)  			rand(0.9)    )
	("burn_volume" volume(rightArmorPlate_Knee) 		component(rightArmorPlate_Knee)  	rand(0.9)    )
	("burn_volume" volume(rightToe1) 					component(rightToe1)  				rand(0.9)    )
	("burn_volume" volume(rightToe2) 					component(rightToe2)  				rand(0.9)    )
	("burn_volume" volume(rightToe3) 					component(rightToe3)  				rand(0.9)    )
	("burn_volume" volume(rightToe4) 					component(rightToe4)  				rand(0.9)    )		
	("burn_volume" volume(head_arm)   					component(head_arm)  				rand(0.9)    )
	("burn_volume" volume(neck1)   						component(head_arm)  				rand(0.9)    )
	("burn_volume" volume(horn)  						component(horn)  					rand(0.9)    )
	("burn_volume" volume(left_jetengine)  				component(jetengine_l)				rand(0.9)    )
	("burn_volume" volume(right_jetengine)  			component(jetengine_r)   			rand(0.9)    )

	("burn_volume" component(legplate_right)  			component(legplate_right)  				rand(0.5)    )
	("burn_volume" component(legplate_left)  			component(legplate_left)  				rand(0.5)    )

	("burn_volume" component(shoulder_plate_left)  		component(shoulder_plate_left)  				rand(0.5)    )
	("burn_volume" component(shoulder_plate_right)  	component(shoulder_plate_right)  				rand(0.5)    )


	("burn_volume" volume(fuel)  						component(fuel)   					rand(0.6)    )
	("burn_volume" volume(fuel_small)  					component(fuel_small)   			rand(0.6)    )

	("burn_volume" volume(wire)  						component(wire)   					rand(0.6)    )
	("burn_volume" volume(wire_small)  					component(wire_small)   			rand(0.6)    )
	("burn_volume" volume(head_wire)  					component(head_joint)   					rand(0.6)    )
	

	("burn_volume" volume(scanner)  					component(visor_head)   			rand(0.9)    )
	("burn_volume" volume(body_organ)  					component(body_organ)   			rand(0.9)    )
	("burn_volume" volume(back_engine_organ)  			component(back_engine_organ)   		rand(0.9)    )
	("burn_volume" volume(head_organ)  					component(head_organ)   			rand(0.9)    )
	("burn_volume" volume(flamethrower)  				component(flamethrower)   			rand(0.6)    )
	("burn_volume" volume(fuel_rods_l)  				component(fuel_rods_l)   			rand(0.6)    )
	("burn_volume" volume(fuel_rods_r)  				component(fuel_rods_r)   			rand(0.6)    )
	("burn_volume" volume(armor_ballistic_left_hand)  		component(armor_ballistic_left_hand)   			rand(0.6)    )
	("burn_volume" volume(armor_ballistic_right_hand)  		component(armor_ballistic_right_hand)   		rand(0.6)    )
	("burn_volume" volume(armor_left_engine_wire)  			component(armor_left_engine_wire)   			rand(0.6)    )
	("burn_volume" volume(armor_right_engine_wire)  		component(armor_right_engine_wire)   			rand(0.6)    )
	("burn_volume" volume(armor_cpu_wire)  					component(armor_cpu_wire)   					rand(0.6)    )
	
	("burn_volume" volume(front_hatch_l)  			component(front_hatch_l)   					rand(0.2)    )
	("burn_volume" volume(front_hatch_r)  			component(front_hatch_r)   					rand(0.2)    )
	("burn_volume" volume(bridge)  					component(bridge)   					rand(0.2)    )
	("burn_volume" volume(visor_body)  				component(visor_body)   					rand(0.2)    )
	("burn_volume" volume(pestcontainer)  			component(pestcontainer)   					rand(0.2)    )
	("burn_volume" volume(shotgun)  				component(shotgun)   					rand(0.2)    )
	("burn_volume" volume(rocket_cluster)  			component(rocket_cluster)   					rand(0.2)    )
	("burn_volume" volume(ammo)  					component(ammo)   					rand(0.2)    )
	("burn_volume" volume(missilelauncher)  		component(missilelauncher)   					rand(0.2)    )
	("burn_volume" volume(missile)  				component(missile)   					rand(0.2)    )
	("burn_volume" volume(sniper)  					component(sniper)   					rand(0.2)    )
	("burn_volume" volume(rocket)  					component(rocket)   					rand(0.2)    )
	("burn_volume" volume(fuel_rods_r)  			component(fuel_rods_r)   					rand(0.2)    )
	("burn_volume" volume(fuel_rods_l)  			component(fuel_rods_l)   					rand(0.2)    )
	("burn_volume" volume(flamethrower)  			component(flamethrower)   					rand(0.2)    )

	("burn_volume" volume(hydraulic)  				component(hydraulic)   					rand(0.2)    ) ;lynx
	
	
	;("burn_volume" volume(cpu)  						component(cpu)   					rand(0.9)    )
	{if not burned
		{if component "engine"
			{burn volume fx "smoke_dead_body_fast" time 8 fake even_law}
			{delay 6
				{if work "engine"
					{components "engine" break}	
					{spawn "electric_spark_hit_pierce" }
					{call "power_drop_permanent"}	
				}
			}
		}
	}
}	
{on "check_work_organ" 
	{if broken "main_organ" 6
		{tags add "broken_6"}
		{spawn "electric_spark_hit_pierce" "head"}
		{call "power_drop_permanent"}	
		{delay 5
			{call "explosion_harv"}							
			{call "explosion_dread"}							
			{call "explosion_hunter"}							
		}
	else broken "main_organ" 5
		{tags add "broken_5"}
		{spawn "electric_spark_hit_pierce" "head"}
		{if prop "skirmisher_base"
			{call "power_drop_permanent"}	
;			else
;				{call "power_drop"}	
		}
		{delay 5
			{call "explosion_skir"}							
		}
	else broken "hydraulic" 4
		{movement_limit slow}
		{tags add "hydraulic_4"}
	else broken "main_organ" 3
		{tags add "broken_3"}
		{delay 2
			{spawn "electric_spark_hit_pierce" "head"}
			;{call "power_drop"}	
		}
	else broken "gasdrop" 2
		{weapon_work "attack_gas" 0}		
	else broken "hydraulic" 2
		{tags add "hydraulic_2"}
	}
}
