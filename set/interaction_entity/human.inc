{"human"
	{inflammation_time 2}
	{on spawn
		{ani_play "move_human_spawn" 0.5}
		{set "operatable_human" 1}
		{if not tagged "veterancy_load"
			{tags add "veterancy_empty"}
		}
		{if not user_control
			{tags add "ai"}			
		}
		{if tagged "synth"
			{call "synth_sistem"}
		}
		{add_view	"veterancy_view"			"fxt_veterancy"	 "basis"}
		{add_view	"cigarettesmoke"			"smoke"			"head"}
		{add_view	"drops_water_small2"		"on_water"		"foot3r"}
		{add_view	"drops_water_small2"		"on_water"		"foot3l"}
		{add_view	"drops_water_small3"		"swim"			"foot3r"}
		{add_view	"drops_water_small3"		"swim"			"foot3l"}
		{add_view	"drops_water_small3"		"swim"			"hand2r"}
		{add_view	"drops_water_small3"		"swim"			"hand2l"}
		{add_view	"synth_tail"				"fly"			"body"}
		{add_view	"spark_electro03e"			"fly"			"body"}
		{add_view	"spark_electro03e"			"blast"			"foot3r"}
		{add_view	"spark_electro03e"			"blast"			"foot3l"}
		{add_view	"spark_electro03e"			"blast"			"hand2r"}
		{add_view	"spark_electro03e"			"blast"			"hand2l"}
		{add_view	"wash_human_small"			"swim_move"		"head"}
		{add_view	"drops_puddle_small"		"on_puddle"		"foot3r"}
		{add_view	"drops_puddle_small"		"on_puddle"		"foot3l"}
		{add_view	"drops_puddle_small"		"die_in_swamp"	"foot3r"}
		{add_view	"drops_puddle_small"		"die_in_swamp"	"foot3l"}
		{add_view	"marker_bleeding"			"marker_bleeding"			"head" not_manual}
		{add_view	"marker_kill_neutral"		"marker_kill_neutral"		"head" not_manual}
		{add_view	"marker_healing"			"marker_healing"			"head" not_manual}
		{add_view	"marker_repair"				"marker_repair"				"head" not_manual}
		{add_view	"marker_ammo_out"			"marker_ammo_out"			"head" not_manual}
		{add_view	"marker_ammo_refill"		"marker_ammo_refill"		"head" not_manual}
		{add_view	"marker_personage"			"marker_personage"			"head" not_manual}
		{add_view	"marker_personage_acute"	"marker_personage_acute"	"head" not_manual}
		;--------------------------------------
		{add_view	"marker_veterancy_1"		"marker_veterancy_1"			"head" not_manual}
		{add_view	"marker_veterancy_2"		"marker_veterancy_2"			"head" not_manual}
		{add_view	"marker_veterancy_3"		"marker_veterancy_3"			"head" not_manual}
		{add_view	"marker_veterancy_4"		"marker_veterancy_4"			"head" not_manual}
		{add_view	"marker_veterancy_5"		"marker_veterancy_5"			"head" not_manual}
		{add_view	"marker_veterancy_6"		"marker_veterancy_6"			"head" not_manual}
		{add_view	"marker_veterancy_7"		"marker_veterancy_7"			"head" not_manual}
		{add_view	"marker_veterancy_8"		"marker_veterancy_8"			"head" not_manual}
		;--------------------------------------
		{add_view	"marker_blinded"			"marker_blinded"			"head" not_manual}
		{add_view	"marker_rad"				"marker_rad"				"head" not_manual}
		{add_view	"marker_broken"				"marker_broken"				"head" not_manual}
		{link_sound "screw_twist"		"human/anim/repair/screw_twist/"}
		{link_sound "wrench_turn"		"human/anim/repair/wrench_turn/"}
		{link_sound "toolbox_open"		"human/anim/repair/toolbox_open/"}
		{link_sound "toolbox_close"		"human/anim/repair/toolbox_close/"}
		{link_sound "tool_equip"		"human/anim/repair/tool_equip/"}

		{link_sound "open_bolt"			"weapon/reload/open_bolt/"}
		{link_sound "close_bolt"		"weapon/reload/close_bolt/"}

		{link_sound "pick_up_small"		"human/anim/pickup/small/"}
		{link_sound "crouch"		    "human/anim/crouch/"}
		{link_sound "drink_canteen"		"human/anim/drink_canteen/can_drink"}
		{link_sound "prone_to_stand"	"human/anim/prone_to_stand/"}
		{link_sound "stand_to_prone"	"human/anim/stand_to_prone/"}
		{link_sound "rest_gun"	        "human/anim/rest_gun/"}
		{link_sound "stand_at_attention"	        "human/anim/stand_at_attention/"}
		{link_sound "swim" "human/move/swim"}
		{link_sound "death_breathe"		"human/death_breathe/"}
		{link_sound "death_choke"		"human/death_choke/"}
		{link_sound "tinnitus_small_start"			"human/tinnitus/tinnitus_start"}
		{link_sound "tinnitus_small_loop"			"human/tinnitus/tinnitus_loop"}
		{link_sound "tinnitus_small_end"			"human/tinnitus/tinnitus_end"}

		{link_sound "metal_footstep"	"human/move/normal/metal"}
		{link_sound "metal_hand"		"human/anims/metal_hand"}

		{link_sound "shovel_ground"	"human/anims/dig/shovel/ground"}
		{link_sound "shovel_snow"	"human/anims/dig/shovel/snow"}
		{link_sound "pickaxe_ground"	"human/anims/dig/pickaxe/ground"}
		{link_sound "construct_mine"	"human/anims/construct_mine"}
		{link_sound "construct_sandbag"	"human/anims/construct_sandbag"}
		
		{link_sound "critical_health_loop"			"human/critical_health/critical_health_lp"}
		{link_sound "critical_health_end"			"human/critical_health/critical_health_exit"}
		
		
		
;		{link_sound "tinnitus_shock"				"human/tinnitus/shock/tinnitus_shock"}
		{call "breath_nose"}
		{call "starvation"}
		{call "idle"}
		{if able "burning"
			{call "add_burn_fx"}
			{view start "burn_fire"}
		}
	}
	(define "health_damage"
		{health_damage_count %c
			{effects "" "hit" "damage" "die" "die"}
		}
	)
	(define "human_health"
		{health_damage_count (* 1.429 %c)
			{effects "" "hit" "damage" "die" "die"}
		}
	)
	(define "contact_settings"
		{if not tagged "common_%a"
			{tags add "common_%a"}
			{delay %t {tags remove "common_%a"}}
			{spawn "blood_medium"}				
			("health_damage" c(%c))
		}
	)
	(define "contact_part"
		{if not tagged "crew"
			{if not volume "foot" 
				{delay 0
					{volumes disable contact }	
					{delay 0.1
						 {volumes enable contact}	
					}
				}
				{with_effector
					{if contact_velocity %velocity
						{if min_mass 900
							{with_effector
								{health_damage_count %damage_count_big
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}				
								{spawn "bloodsparks_big"}
							}
						else min_mass 350
							{with_effector
								{health_damage_count %damage_count_med
									{effects "" "hit" "damage" "die" "die"}
								}				
								{spawn "bloodsparks_small"}
							}
						else min_mass 80
							{with_effector
								{health_damage_count %damage_count_small
									{effects "" "hit" "hit" "hit" "die"}
								}				
								{spawn "bloodsparks_small"}
							}
						}
					}
				}
			}
		}
	)
	(define "thermite_fx"
		{link_sound "loop"	 "detonation/thermite/loop/"				}
		{if volume "%0"
			{fire volume "%0" radius 0.05 heating 35  time 1 follow}
			{fire volume "%0" radius 0.05 heating 10  time 18 follow}
			{add_view 	"thermite_hit2" 						"fx_fire_%0" "%0"}
			{spawn "fraction_thermite" "%0"}
			{spawn "fraction_thermite" "%0"}
			{start_sound "detonation/thermite/flash/"}	
			{view start	"fx_fire_%0"}
			{view show	"fx_fire_%0"}	
			{play_sound "flash" }
			{delay 1.5
				{play_sound "loop" 1}
				{burn volume "%0" fx "thermite_hit2" time 10 fake even_law}
				{delay 20
					{stop_sound "loop" }
					{play_sound "end" }
					{start_sound "detonation/thermite/end/"}	
					{view stop	"fx_fire%0"}
					{view hide	"fx_fire%0"}	
					{delay 3 ;24.5
					}
				}
			}
		}
	)
	(define "fx_rad"
		{if volume "%0"
			;{start_sound "generation_zero/hits/electricity_explo_small/"}	
			{burn volume "%0" fx "smoke_gas_tail" time 6 fake even_law}
		}
	)
	(define "electra_fx"
		{link_sound "loop"	 "generation_zero/electric_spark/" }
		{if volume "%0"
			;{add_view 	"electra_hit" 						"fx_fire_%0" "%0"}
			{start_sound "generation_zero/hits/electricity_explo_small/"}	
			;{view start	"fx_fire_%0"}
			;{view show	"fx_fire_%0"}	
			{burn volume "%0" fx "electra_hit" time 6 fake even_law}
			{delay 1.5
				{play_sound "loop" 1}
				{delay 5
					{stop_sound "loop" }
					;{start_sound "///"}	
					{view stop	"fx_fire%0"}
					{view hide	"fx_fire%0"}	
				}
			}
		}
	)
	{on contact
		{if dead
			{volumes disable contact }	
			{delay 1
				 {volumes enable contact}	
			}
		}
		{if not tagged "crew"
			{if not impregnable
				{if not volume "ram"
					{kill_flags reset}
					{if effector "ex_molot_fire"
						("human_health" c(10))
						(define "burn_volume"
							{if volume %0
								{if not tagged %1
									{burn volume %0 fx "smoke_dead_body" time 5 fake even_law}
									{burn volume %0 fx "smoke_dead_body_fast" time 2 fake even_law}
									{link_sound 	"small"			"fire/small_stuff/fire_small"}
									{play_sound "small" 1}
									{fire volume %0 radius 1 heating 4  time 5 follow}
									{tags add %1}
									{delay 5.5 
										{stop_sound "small" }
									}
								}
							}
						)
						("burn_volume" args "head" "burn_head")
						("burn_volume" args "body" "burn_body")
						("burn_volume" args "hand1l" "burn_hand1l")
						("burn_volume" args "hand1r" "burn_hand1r")
						("burn_volume" args "hand2l" "burn_hand2l")
						("burn_volume" args "hand2r" "burn_hand2r")
						("burn_volume" args "foot1l" "burn_foot1l")
						("burn_volume" args "foot1r" "burn_foot1r")
						("burn_volume" args "foot2l" "burn_foot2l")
						("burn_volume" args "foot2r" "burn_foot2r")
					}
					{if effector "melee_contact"
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{if tagged "juggernog_perk"		
							("contact_settings" a(hit_zombie) t(0.5) c(80))
						else
							("contact_settings" a(hit_zombie) t(0.5) c(260))			
						}
					else effector "melee_dog-common"		
						{spawn "fx_piece_blood_fx" }	
						{if tagged "juggernog_perk"
							("contact_settings" a(hit_zombie) t(0.5) c(80))
						else
							("contact_settings" a(hit_zombie) t(0.5) c(260))			
						}			
					else effector "nazi_zombie"
						{tags add "blast_hit_human"}
						{delay 0.1
							{spawn "damage_shock" "basis" x}
						}
						{start_sound "human/tinnitus/shock"}
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{chassis_work 0} {delay 0.2 {chassis_work 1}}
						{if not tagged "dead" 
							{if not tagged "delay_z"
								{tags add "delay_z"}
								{delay 0.1 {tags remove "delay_z"}}
								{with_effector	{if not tagged "traversing"	{call "attack_it"}}}
							}
						}
					else effector "hell_hound"
						{tags add "blast_hit_human"}
						{delay 0.1
							{spawn "damage_shock" "basis" x}
						}
						{start_sound "human/tinnitus/shock"}
						{spawn "fx_piece_blood_fx" }	
						{chassis_work 0} {delay 0.2 {chassis_work 1}}
						{if not tagged "dead" 
							{if not tagged "delay_h"
								{tags add "delay_h"}
								{delay 0.1 {tags remove "delay_h"}}
								{with_effector {call "attack_it"}}
							}
						}
					}			
					{if effector "fraction_small" ;дробь
						; {if tagged "lie_wounded_enter"		
							; {tags remove "lie_wounded_enter"}
							; {tags add "lie_wounded_exit"}
							; {ani_play "squat_die_front" }
							; {ani_stop "lie_wounded" }
							; {ani_stop "lie_wounded_1" }
							; {ani_stop "lie_wounded_2" }		
						; }
						{health_damage_count 75
							{effects "" "hit" "damage" "die" "die"}
						}
						{if rand 0.5 
							{tags add "bleeding_small"}
							{call "bleeding_small"}
							{delay 25 5 "tags"
								{tags remove "bleeding_small"}
							}
						}
					else effector "melee_detect"		
						{drop_orders}
					else effector "tank"
						{if not dead
							{spawn "blood_after_hit"}
							{talk "death_cry"}
							{call "die"}
							{if volume "head" 
								{spawn "fx_piece_blood_fx" "head" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "body" 
								{spawn "fx_piece_blood_fx" "body" x}
								{spawn "fx_piece_blood_fx" "body" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "foot1l" 
								{spawn "fx_piece_blood_fx" "foot1l" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "foot1r" 
								{spawn "fx_piece_blood_fx" "foot1r" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "foot21" 
								{spawn "fx_piece_blood_fx" "foot2l" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "foot2r" 
								{spawn "fx_piece_blood_fx" "foot2r" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "hand1r" 
								{spawn "fx_piece_blood_fx" "hand1r" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "hand1l" 
								{spawn "fx_piece_blood_fx" "hand1l" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "hand2r" 
								{spawn "fx_piece_blood_fx" "hand2r" x}
								{spawn "bloodsparks_small"}
							}
							{if volume "hand2l" 
								{spawn "fx_piece_blood_fx" "hand2l" x}
								{spawn "bloodsparks_small"}
							}
						}
					else effector "drone_scout"
						{if not dead
							{if not user_control
								{if contact_velocity 5
									{health_damage_count 30
										{effects "" "hit" "damage" "die" "die"}
									}
								else contact_velocity 40
									{health_damage_count 200
										{effects "" "hit" "damage" "die" "die"}
									}
								}
							}
						}
					else effector "knife_armed"
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{start_sound "hit/small/human/"}
						{tags add "bleeding_small"}
						{call "bleeding_small"}
						{delay 20 6 "tags"
							{tags remove "bleeding_small"}
						}
						{if volume "head" 
							{spawn "fx_piece_blood_fx" "head" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 300
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "body" 
							{spawn "fx_piece_blood_fx" "body" x}
							{spawn "fx_piece_blood_fx" "body" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 300
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "foot1l" 
							{spawn "fx_piece_blood_fx" "foot1l" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 120
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "foot1r" 
							{spawn "fx_piece_blood_fx" "foot1r" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 120
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "foot21" 
							{spawn "fx_piece_blood_fx" "foot2l" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 120
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "foot2r" 
							{spawn "fx_piece_blood_fx" "foot2r" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 120
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "hand1r" 
							{spawn "fx_piece_blood_fx" "hand1r" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 150
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "hand1l" 
							{spawn "fx_piece_blood_fx" "hand1l" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 150
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "hand2r" 
							{spawn "fx_piece_blood_fx" "hand2r" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 150
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
						{if volume "hand2l" 
							{spawn "fx_piece_blood_fx" "hand2l" x}
							{spawn "bloodsparks_small"}
							{health_damage_count 150
								{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
							}
						}
					else effector "vehicle"
						{if not dead
							{if contact_velocity 50
								{spawn "fx_piece_blood_fx" "head" x}	
								{spawn "fx_piece_blood_fx" "head" x}	
								{spawn "fx_piece_blood_fx" "head" x}	
								{delay 3
									{call "die"}
								}
								{if volume "head" 
									{if rand 0.4
										{spawn "fx_piece_blood_fx" "head" x}	
									}
									{if not user_control	
										{if rand 0.6
											{tags add "bleeding_small_head"}
											{call "hit_head"}
											{call "bleeding_small_head"}
											{view start ally neutral "marker_bleeding"}
											{delay 5.0 "marks"
												{view pause "marker_bleeding"}
											}			
											{delay 35 5 "tags"
												{tags remove "bleeding_small_head"}
											}
										else rand 0.12
											{if not tagged "head_cut"
												{able "personage" 0}
												{tags add "head_cut" }
												{spawn "bloodsparks_big_head" "head" x}
												{add_view "blood_droper_head" "blood_b" 	"IK_UpDown"}
												{view start "blood_b"}
												{add_view "head_cut" 		"head_cut" 	"IK_UpDown"}
												{view stop "head_cut"}
												{delay 15.5 {view stop "blood_b"}}
												{call "die"}						
												{spawn "head_parts" "head" x}
												; {if tagged "lie_wounded_enter"		
													; {tags remove "lie_wounded_enter"}
													; {tags add "lie_wounded_exit"}
													; {ani_play "squat_die_front" }
													; {ani_stop "lie_wounded" }
													; {ani_stop "lie_wounded_1" }
													; {ani_stop "lie_wounded_2" }		
												; }
												{bone hide "head"}
												{delay 0.3 {spawn "bloodsparks_big" "IK_UpDown" x}}
												{delay 0.6 {spawn "bloodsparks_big" "IK_UpDown" x}}
												{delay 0.9 {spawn "bloodsparks_big" "IK_UpDown" x}}
												{delay 1.2 {spawn "bloodsparks_big" "IK_UpDown" x}}
												{health_damage_count 400
													{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
												}
											}
										}
									}
								}
							}
							{if contact_velocity 20
								;{if not user_control
									{throw_off up 5 2 dir 17 5 forward 16 turn 0 360 die force}
									{tags add "bleeding_small_body_random"}
									{call "bleeding_small_body_random"}
									{delay 4 2 "tags_random"
										{tags remove "bleeding_small_body_random"}
									}
									{if volume "head" 
										{if rand 0.4
											{spawn "fx_piece_blood_fx" "head" x}	
										}
										{if not user_control	
											{if rand 0.6
												{tags add "bleeding_small_head"}
												{call "hit_head"}
												{call "bleeding_small_head"}
												{view start ally neutral "marker_bleeding"}
												{delay 5.0 "marks"
													{view pause "marker_bleeding"}
												}			
												{delay 35 5 "tags"
													{tags remove "bleeding_small_head"}
												}
											else rand 0.12
												{if not tagged "head_cut"
													{able "personage" 0}
													{tags add "head_cut" }
													{spawn "bloodsparks_big_head" "head" x}
													{add_view "blood_droper_head" "blood_b" 	"IK_UpDown"}
													{view start "blood_b"}
													{add_view "head_cut" 		"head_cut" 	"IK_UpDown"}
													{view stop "head_cut"}
													{delay 15.5 {view stop "blood_b"}}
													{call "die"}						
													{spawn "head_parts" "head" x}
													{bone hide "head"}
													{delay 0.3 {spawn "bloodsparks_big" "IK_UpDown" x}}
													{delay 0.6 {spawn "bloodsparks_big" "IK_UpDown" x}}
													{delay 0.9 {spawn "bloodsparks_big" "IK_UpDown" x}}
													{delay 1.2 {spawn "bloodsparks_big" "IK_UpDown" x}}
													{health_damage_count 400
														{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
													}
												}
											}
										}
									else volume "body" 
										{if rand 0.6
											{if not "talk"
												{set "talk" 1}
												{talk "hit"}
												{delay 2 
													{set "talk" 0}
												}
											}
										}
										{if rand 0.7
											{if not "talk"
												{set "talk" 1}
												{talk "bleeding"}
												{delay 2 
													{set "talk" 0}
												}
											}
											{tags add "bleeding_small_body"}
											{call "bleeding_small_body"}
											{delay 17 4 
												{tags remove "bleeding_small_body"}
											}
										}
									else volume "foot1r" 
										{if rand 0.7
											{if "fast_move_mode"
												{call "knockdown"}
											}
											{tags add "bleeding_small_foot1r"}
											{talk "hit_legs"}
											{call "bleeding_small_foot1r"}
											{delay 14 4
												{tags remove "bleeding_small_foot1r"}
											}
										}
									else volume "foot2r" 
										{if rand 0.7
											{talk "hit_legs"}
											{if "fast_move_mode"
												{call "knockdown"}
											}
											{tags add "bleeding_small_foot2r"}
											{call "bleeding_small_foot2r"}
											{delay 14 4
												{tags remove "bleeding_small_foot2r"}
											}
										}
									else volume "foot1l" 
										{if rand 0.7
											{if "fast_move_mode"
												{call "knockdown"}
											}
											{talk "hit_legs"}
											{tags add "bleeding_small_foot1l"}
											{call "bleeding_small_foot1l"}
											{delay 14 4
												{tags remove "bleeding_small_foot1l"}
											}
										}
									else volume "foot2l" 	
										{if rand 0.7
											{talk "hit_legs"}
											{if "fast_move_mode"
												{call "knockdown"}
											}
											{tags add "bleeding_small_foot2l"}
											{call "bleeding_small_foot2l"}
											{delay 14 4
												{tags remove "bleeding_small_foot2l"}
											}
										}
									else volume "hand1r" 
										{if rand 0.7
											{talk "hit_hand"}
											{tags add "bleeding_small_hand1r"}
											{call "bleeding_small_hand1r"}
											{delay 14 4
												{tags remove "bleeding_small_hand1r"}
											}
										}
									else volume "hand1l" 
										{if rand 0.7
											{talk "hit_hand"}
											{tags add "bleeding_small_hand1l"}
											{call "bleeding_small_hand1l"}
											{delay 14 4
												{tags remove "bleeding_small_hand1l"}
											}
										}
									else volume "hand2r" 
										{if rand 0.7
											{talk "hit_hand"}
											{tags add "bleeding_small_hand2r"}
											{call "bleeding_small_hand2r"}
											{delay 14 4
												{tags remove "bleeding_small_hand2r"}
											}
										}
									else volume "hand2l" 
										{if rand 0.7
											{talk "hit_hand"}
											{tags add "bleeding_small_hand2l"}
											{call "bleeding_small_hand2l"}
											{delay 14 4
												{tags remove "bleeding_small_hand2l"}
											}
										}
									}
								 else
									{call "die"}
								;}
							}
						else
							{spawn "bloodsparks_small"}
						}
					else effector "helicopter"
						{if not dead
							{if contact_velocity 4
								{if not user_control
									{call "die"}
								 else
									{call "die"}
								}
							}
						}
					else effector "electra15"
						{spawn "bloodsparks_small"}
					else effector "s5_rocket"
						{spawn "fx_piece_blood_fx_fast" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx_fast" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
						{spawn "fx_piece_blood_fx" }	
					else effector "thermite"
						{if contact_velocity 1
							("thermite_fx" args head 	)
							("thermite_fx" args body 	)
							("thermite_fx" args foot1l 	)
							("thermite_fx" args foot1r 	)
							("thermite_fx" args foot21 	)
							("thermite_fx" args foot2r 	)
							("thermite_fx" args hand1r 	)
							("thermite_fx" args hand1l 	)
							("thermite_fx" args hand2r 	)
							("thermite_fx" args hand2l 	)
						}
					else effector "knife"
						{if contact_velocity 1
							{tags add "bleeding_small"}
							{call "bleeding_small"}
							{delay 25 5 "tags"
								{tags remove "bleeding_small"}
							}
							{if volume "head" 
								{spawn "fx_piece_blood_fx" "head" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 500
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "body" 
								{spawn "fx_piece_blood_fx" "body" x}
								{spawn "fx_piece_blood_fx" "body" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 400
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "foot1l" 
								{spawn "fx_piece_blood_fx" "foot1l" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 200
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "foot1r" 
								{spawn "fx_piece_blood_fx" "foot1r" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 200
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "foot21" 
								{spawn "fx_piece_blood_fx" "foot2l" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 200
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "foot2r" 
								{spawn "fx_piece_blood_fx" "foot2r" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 200
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "hand1r" 
								{spawn "fx_piece_blood_fx" "hand1r" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 150
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "hand1l" 
								{spawn "fx_piece_blood_fx" "hand1l" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 150
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "hand2r" 
								{spawn "fx_piece_blood_fx" "hand2r" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 150
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "hand2l" 
								{spawn "fx_piece_blood_fx" "hand2l" x}
								{spawn "bloodsparks_small"}
								{health_damage_count 150
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
						}
					else effector "big_props"
						{if contact_velocity 70
							{call "knockdown_body"}
							{if volume "head" 
								{health_damage_count 250
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "body" 
								{health_damage_count 300
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{tags add "bleeding_small"}
							{call "bleeding_small"}
							{delay 15 "tags"
								{tags remove "bleeding_small"}
							}
						}
						{if contact_velocity 45
							{if volume "head" 
								{health_damage_count 70
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{if volume "body" 
								{health_damage_count 50
									{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
								}
							}
							{tags add "bleeding_small"}
							{call "bleeding_small"}
							{delay 5 "tags"
								{tags remove "bleeding_small"}
							}
						}
					else effector "blade"
						{health_damage_count 120
							{effects "" "hit" "damage" "die" "die"}
						}
						{tags add "bleeding_small"}
						{call "bleeding_small"}
						{delay 15 "tags"
							{tags remove "bleeding_small"}
						}
					else effector "knife_s"
						{if contact_velocity 5
							{health_damage_count 24
								{effects "" "hit" "damage" "die" "die"}
							}
						}
					else effector "glass"
						{spawn "bloodsparks_small2"}
						{health_damage_count 12
							{effects "" "hit" }
						}
					else effector "axe"
						{if contact_velocity 5
							("health_damage" c(500))
						}
					else effector "grenade"
						{if contact_velocity 5
							{if rand 0.5
								{spawn "bloodsparks_small"}
							}
							{health_damage_count 75
								{effects "" "hit" "damage" "die" "die"}
							}
						}
					else effector "chicken"
						{health_damage_count 0
							{effects "" "hit" "hit" "hit" "hit"}
						}
					else effector "emp"
						{view start "blast"}
						{talk "hit"}
						{spawn "electra_blast_sound" "body"}
						{tags add "bleeding_small_e"}
						{call "bleeding_small_e"}
						{delay 8 "tags"
							{tags remove "bleeding_small_e"}
						}
						{delay 2
							{talk "hit"}
							{view pause "blast"}
						}
						{health_damage_count 150
							{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
						}
					else effector "wire"
						{if not dead
							("human_health" c(15))
						}
					else effector "fx_piece_flame"
						{if not dead
							("human_health" c(10))
						}
					else effector "flame_piece"
						{if not dead
							("human_health" c(10))
						}						
					else effector "radio_signal"
						{tags add "radio_signal"}
;--------------------------------------------Generation_zero_hits						
					else effector "pest_class_d"
						; {if tagged "lie_wounded_enter"		
							; {tags remove "lie_wounded_enter"}
							; {tags add "lie_wounded_exit"}
							; {ani_play "squat_die_front" }
							; {ani_stop "lie_wounded" }
							; {ani_stop "lie_wounded_1" }
							; {ani_stop "lie_wounded_2" }		
						; }
						("fx_rad" args head 	)
						("fx_rad" args body 	)
						("fx_rad" args foot1l 	)
						("fx_rad" args foot1r 	)
						("fx_rad" args foot21 	)
						("fx_rad" args foot2r 	)
						("fx_rad" args hand1r 	)
						("fx_rad" args hand1l 	)
						("fx_rad" args hand2r 	)
						("fx_rad" args hand2l 	)
						{health_damage_count 25
							{effects "hit" }
						}
						{if rand 0.5 
							{tags add "bleeding_small"}
							{call "bleeding_small"}
							{delay 7 2 "tags"
								{tags remove "bleeding_small"}
							}
						}
					else effector "pest_classic"
						; {if tagged "lie_wounded_enter"		
							; {tags remove "lie_wounded_enter"}
							; {tags add "lie_wounded_exit"}
							; {ani_play "squat_die_front" }
							; {ani_stop "lie_wounded" }
							; {ani_stop "lie_wounded_1" }
							; {ani_stop "lie_wounded_2" }		
						; }
						{health_damage_count 25
							{effects "hit" }
						}
						; {if rand 0.5 
							; {tags add "bleeding_small"}
							; {call "bleeding_small"}
							; {delay 7 2 "tags"
								; {tags remove "bleeding_small"}
							; }
						; }
					else effector "skirmisher_base"
						{if not dead
							{if not user_control
								{if contact_velocity 14
									{if rand 0.5
										("electra_fx" args head 	)
										("electra_fx" args body 	)
										("electra_fx" args foot1l 	)
										("electra_fx" args foot1r 	)
										("electra_fx" args foot21 	)
										("electra_fx" args foot2r 	)
										("electra_fx" args hand1r 	)
										("electra_fx" args hand1l 	)
										("electra_fx" args hand2r 	)
										("electra_fx" args hand2l 	)
									}
									{health_damage_count 200
										{effects "" "hit" "damage" "die" "die"}
									}
								else contact_velocity 5
									{health_damage_count 30
										{effects "" "hit" "damage" "die" "die"}
									}								
								}
							}
						}
					else effector "hunter_base"
						{if not dead
							{if not user_control
								{if contact_velocity 14
									{if rand 0.5
										("electra_fx" args head 	)
										("electra_fx" args body 	)
										("electra_fx" args foot1l 	)
										("electra_fx" args foot1r 	)
										("electra_fx" args foot21 	)
										("electra_fx" args foot2r 	)
										("electra_fx" args hand1r 	)
										("electra_fx" args hand1l 	)
										("electra_fx" args hand2r 	)
										("electra_fx" args hand2l 	)
									}
									{health_damage_count 75
										{effects "" "hit" "damage" "die" "die"}
									}
								else contact_velocity 5
									{health_damage_count 30
										{effects "" "hit" "damage" "die" "die"}
									}								
								}
							}
						}
					}
					("contact_part" velocity(10)  damage_count_big(45) 	damage_count_med(30)  	damage_count_small(5)   )
					("contact_part" velocity(15)  damage_count_big(55)  damage_count_med(40)  	damage_count_small(10)	)
					("contact_part" velocity(17)  damage_count_big(70)  damage_count_med(50) 	damage_count_small(25)	)
					("contact_part" velocity(20) damage_count_big(90)  damage_count_med(60) 	damage_count_small(45)	)
					("contact_part" velocity(23) damage_count_big(110)  damage_count_med(80) 	damage_count_small(70)	)
					("contact_part" velocity(30) damage_count_big(210)  damage_count_med(120) 	damage_count_small(90)	)
				}
			}
		}
	}
	{on pierce 
		{if stuff "shell fg"
			{call "die"}						
			{bullet_detonate}
		else stuff "bazooka"
			{call "die"}						
			{bullet_detonate}
		else stuff "bullet zenite fg"
			{bullet_detonate}
			{if volume "head" 
				{if not user_control	
					{if rand 0.8
						{if not linked
							{if not dead
								{if not lying
									{if hit_side front
										{if not tagged "fast" 
											{if not tagged "normal" 
												{chassis_work 0}
												;{weapon_work "hand_right" 0}
												{if not tagged "bleeding" 
													{ani_play "stand_after_straight_hit"}	
												}
												;{spawn "blind" "basis"}
												{delay 1.0 "hit_side"
													{chassis_work 1}
													;{weapon_work "hand_right" 1}
													{ani_stop "stand_after_straight_hit"}	
													;{ani_play "pose_step_aside_right_gun"}	
												}
											}
										}
									}			
								}			
							}
						}
						;{talk ""}						
						{call "hit_head"}
						{view start ally neutral "marker_bleeding"}
						{delay 5.0 "marks"
							{view pause "marker_bleeding"}
						}			
					}
				}
			}
		}
		{if stuff "bullet emp"
			{view start "blast"}
			{talk "hit"}
			{spawn "electra_blast_sound" "body"}
			{tags add "bleeding_small_e"}
			{call "bleeding_small_e"}
			{delay 35 "tags"
				{tags remove "bleeding_small_e"}
			}
			{delay 4 1
				{talk "hit"}
				{view pause "blast"}
			}
			{health_damage_count 100
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{if stuff "pierce"
			{if not tagged "transform"
				; {if tagged "lie_wounded_enter"		
					; {tags remove "lie_wounded_enter"}
					; {tags add "lie_wounded_exit"}
					; {ani_play "squat_die_front" }
					; {ani_stop "lie_wounded" }
					; {ani_stop "lie_wounded_1" }
					; {ani_stop "lie_wounded_2" }		
				; }
				{kill_delay "fast_hit"}
				{tags add "fast_hit"}
				{delay 0.3 "fast_hit"
					{tags remove "fast_hit"}
				}	
				{kill_flags reset}
				{signal shot 500}
				{tags remove "armorplate_pierce"}
				{if active 							
					{if rand 0.3 				
						{spawn "damage_shock_micro" }
						{call "critical_health"}
					}
				}
				{kill_flags reset}
				(define "hit_system"
					{if stuff %0
						{tags add "bleeding_small_body_random"}
						{call "bleeding_small_body_random"}
						{delay %1 "tags_random" ;delay_bleeding_tags_random
							{tags remove "bleeding_small_body_random"}
						}
						{if volume "heart" 
							;{call_synced "unhealable"}
							{spawn "fx_piece_blood_fx" "IK_UpDown" }	
						}
						{if volume "head" 
							{if rand %2  ;rand_hit
								;{call_synced "unhealable"}
								{if not tagged "wound_head" 
									{tex_mod "wound_head"}
								}
								{spawn "fx_piece_blood_fx" "head" x}	
								{if user_control
									{start_sound "hit/small/flesh/"}
								}
							}
							{if rand %2  ;rand_hit
								{if not linked
									{if not dead
										{if not lying
											{if hit_side front
												{if not tagged "fast" 
													{if not tagged "normal" 
														{chassis_work 0}
														;{weapon_work "hand_right" 0}
														{if not tagged "bleeding" 
															{ani_play "stand_after_straight_hit"}	
														}
														;{spawn "blind" "basis"}
														{delay 1.0 "hit_side"
															{chassis_work 1}
															;{weapon_work "hand_right" 1}
															{ani_stop "stand_after_straight_hit"}	
															;{ani_play "pose_step_aside_right_gun"}	
														}
													}
												}
											}			
										}			
									}
								}
								;{talk ""}						
								{tags add "bleeding_small_head"}
								{call "hit_head"}
								{call "bleeding_small_head"}
								{view start ally neutral "marker_bleeding"}
								{delay 5.0 "marks"
									{view pause "marker_bleeding"}
								}			
								{delay %4 "tags" ;delay_bleeding_tags_body
									{tags remove "bleeding_small_head"}
								}
							else rand %3;head_cut
								{if not user_control	
									{if not tagged "head_cut"
										{able "personage" 0}
										{tags add "head_cut" }
										{spawn "bloodsparks_big_head" "head" x}
										{add_view "blood_droper_head" "blood_b" 	"head"}
										{view start "blood_b"}
										{add_view "head_cut" 		"head_cut" 	"head"}
										{view stop "head_cut"}
										{delay 15.5 {view stop "blood_b"}}
										{call "die"}						
										{spawn "head_parts" "head" x}
										{bone hide "head"}
										{delay 0.3 {spawn "bloodsparks_big" "head" }}
										{delay 0.6 {spawn "bloodsparks_big" "head" }}
										{delay 0.9 {spawn "bloodsparks_big" "head" }}
										{delay 1.2 {spawn "bloodsparks_big" "head" }}
										; {if tagged "lie_wounded_enter"		
											; {tags remove "lie_wounded_enter"}
											; {tags add "lie_wounded_exit"}
											; {ani_play "squat_die_front" }
											; {ani_stop "lie_wounded" }
											; {ani_stop "lie_wounded_1" }
											; {ani_stop "lie_wounded_2" }		
										; }
										{health_damage_count 400
											{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
										}
									}
								}
							}
						else volume "body" 
							{if rand 0.7
								{if not "talk"
									{set "talk" 1}
									{talk "bleeding"}
									{delay 2 
										{set "talk" 0}
									}
								}
								{tags add "bleeding_small_body"}
								{call "bleeding_small_body"}
								{delay %4 ;delay_bleeding_tags_body(4)
									{tags remove "bleeding_small_body"}
								}
							}
						else volume "foot1r" 
							{if rand 0.4
								{if "fast_move_mode"
									{call "knockdown_foot"}					
								}
								{tags add "bleeding_small_foot1r"}
								{talk "hit_legs"}
								{call "bleeding_small_foot1r"}
								{delay %6 ;delay_bleeding_tags_other(6)
									{tags remove "bleeding_small_foot1r"}
								}
							}
						else volume "foot2r" 
							{if rand 0.4
								{talk "hit_legs"}
								{if "fast_move_mode"
									{call "knockdown_foot"}					
								}
								{tags add "bleeding_small_foot2r"}
								{call "bleeding_small_foot2r"}
								{delay %6 ;delay_bleeding_tags_other(6)
									{tags remove "bleeding_small_foot2r"}
								}
							}
						else volume "foot1l" 
							{if rand 0.4
								{if "fast_move_mode"
									{call "knockdown_foot"}					
								}
								{talk "hit_legs"}
								{tags add "bleeding_small_foot1l"}
								{call "bleeding_small_foot1l"}
								{delay %6 ;delay_bleeding_tags_other(6)
									{tags remove "bleeding_small_foot1l"}
								}
							}
						else volume "foot2l" 	
							{if rand 0.4
								{talk "hit_legs"}
								{if "fast_move_mode"
									{call "knockdown_foot"}					
								}
								{tags add "bleeding_small_foot2l"}
								{call "bleeding_small_foot2l"}
								{delay %6 ;delay_bleeding_tags_other(6)
									{tags remove "bleeding_small_foot2l"}
								}
							}
						else volume "hand1r" 
							{if rand 0.4
								{talk "hit_hand"}
								{tags add "bleeding_small_hand1r"}
								{call "bleeding_small_hand1r"}
								{delay %7 ;delay_bleeding_tags_hand(7)
									{tags remove "bleeding_small_hand1r"}
								}
							}
						else volume "hand1l" 
							{if rand 0.4
								{talk "hit_hand"}
								{tags add "bleeding_small_hand1l"}
								{call "bleeding_small_hand1l"}
								{delay %7 ;delay_bleeding_tags_hand(7)
									{tags remove "bleeding_small_hand1l"}
								}
							}
						else volume "hand2r" 
							{if rand 0.4
								{talk "hit_hand"}
								{tags add "bleeding_small_hand2r"}
								{call "bleeding_small_hand2r"}
								{delay %7 ;delay_bleeding_tags_hand(7)
									{tags remove "bleeding_small_hand2r"}
								}
							}
						else volume "hand2l" 
							{if rand 0.4
								{talk "hit_hand"}
								{tags add "bleeding_small_hand2l"}
								{call "bleeding_small_hand2l"}
								{delay %7 ;delay_bleeding_tags_hand(7)
									{tags remove "bleeding_small_hand2l"}
								}
							}
						}
						{call "process_bullet_hit"}
					}
				)
				;					tags (0)              		delay_bleeding_tags_random(1)  	rand_hit(2)  head_cut(3)   delay_bleeding_tags_body(4)  delay_bleeding_tags_head(5)  delay_bleeding_tags_other(6)  delay_bleeding_tags_other(7)
				("hit_system" args "bullet stackable small sp"   3	    							0.2          0.03           15				        	20				         		10                       	6   )
				("hit_system" args "bullet stackable small exp"  5	    							0.4          0.07           22				        	30				         		20                        	12  )
				("hit_system" args "bullet stackable small ap"   7	    							0.6          0.08           25				        	40				         		30                        	15  )
				("hit_system" args "bullet stackable small fg"   10	    							0.8          0.03           25				        	40				         		30                        	15  )
				("hit_system" args "bullet stackable normal sp"  4	    							0.3          0.07           20				        	25				         		15                       	12   )
				("hit_system" args "bullet stackable normal fg"  7	    							0.7          0.07           20				        	25				         		15                       	12   )
				("hit_system" args "bullet stackable normal ap"  9	    							0.8          0.1           	30				        	55				         		45                        	30  )
				("hit_system" args "bullet big ap"  	  		18	    							1          	 0.3            40				        	70				         		50                        	27  )
				("hit_system" args "bullet big fg"  	  		15	    							0.8          0.3            55				        	55				         		40                        	24  )
				("hit_system" args "bullet big sp"  	  		12	    							0.8          0.1            35				        	55				         		40                        	24  )
				("hit_system" args "zenite fg"  	  			25	    							0.8          0.7            35				        	55				         		40                        	24  )
				("hit_system" args "zenite ap"  	  			25	    							0.9          0.6            35				        	55				         		40                        	24  )
				("hit_system" args "zenite"  	  				25	    							0.8          0.4            35				        	55				         		40                        	24  )
				("hit_system" args "shell"  	  				25	    							1          	   1            35				        	55				         		40                        	24  )
				("hit_system" args "bullet small_arms"  		7	    							0.7          0.07           20				        	25				         		15                       	12   ) ;goh
			}
		}
	}
	{on bullet_hit
		{kill_flags reset}
		{signal hit 5}
		{if stuff "non_lethal"
			{if rand 0.2
				{call "knockdown_body_blow"}
			}
			{if volume "head" 
				{call "knockdown_head_nonlethal"}
			else volume "body"
				{call "knockdown_body_nonlethal"}
			else volume "foot1r"
				{call "knockdown_foot_nonlethal"}
			else volume "foot1l"
				{call "knockdown_foot_nonlethal"}
			else volume "foot2r"
				{call "knockdown_foot_nonlethal"}
			else volume "foot2l"
				{call "knockdown_foot_nonlethal"}
			else volume "hand1l"
				{call "knockdown_foot_nonlethal"}
			else volume "hand2l"
				{call "knockdown_foot_nonlethal"}
			else volume "hand1r"
				{call "knockdown_foot_nonlethal"}
			else volume "hand2r"
				{call "knockdown_foot_nonlethal"}
			}	
		else stuff "shell fg"
			{bullet_detonate}
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "rocketlauncher"
			{bullet_detonate}
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "rifle_grenade_at"
			{bullet_detonate}
			{call "process_bullet_hit"}
		else stuff "shell"
			{call "process_bullet_hit"}
			{call "unhealable"}
		else stuff "bullet pierce"
			{if volume_armored
				{bullet_detonate}
				{spawn "helmet_hit_bul"}
			}
			{call "process_bullet_hit"}
			{if tagged "start_personage"
				{if rand 0.5
					{call_synced "unhealable"}
				}
			}
		else
			{call "process_bullet_hit"}
		}
	}
	{on blow
		{if not name "knife"
			{start_sound "human/blow"}
		}
	}
	{on blow opponent sync
		{if name "knife"
			{health_damage_blow
				{effects "" "hit" "hit" "die_from_knife" "die_from_knife"}
			}
		else
			{call "knockdown_body_blow"}
		}
	}
	{on "blow_opponent_effect"
		{if name "head"
			{spawn "bloodsparks_small2" "head"}
		}
	}
	{on "process_bullet_hit" sync
		{if hit_side front
			{kill_flags front}
		else hit_side back
			{kill_flags back}
		else
			{kill_flags front back}
		}

		{if velocity 7
			{kill_flags run}
		else velocity 0.1
			{kill_flags go}
		}
		{kill_flags piercing}
		{if	stuff "rifle"
			{kill_flags rifle}
		}
		{if	stuff "mgun"
			{kill_flags mgun}
		}
		{if	stuff "smg"
			{kill_flags smg}
		}
		{if	stuff "pistol"
			{kill_flags pistol}
		}

		{health_damage_pierce
			{effects
				"hit-scream"
				"hit-light"
				"hit-heavy"
				"die"
				"hit-explosion"
				"throw-off"
				"throw-off-and-die"
			}
			{explosive_treshold 70} ;// value = amount of damage done to human
			{table	;// table for "throw_off" impluse
			;//{ , impulse}
				{30 	1	}
				{200	2.5	}
				{500	3	}
				{5000	5	}
			}
		}
	}
	{on blast_hit overload
		{volumes disable blast }	
		{delay 0.1
			 {volumes enable blast}	
		}		
		{tags add "blast_hit_human"}
		{if not dead
			{if min_energy 2.6
				("human_health" c(350))
			else min_energy 1.9
				("human_health" c(225))
			else min_energy 1.25
				("human_health" c(85))
			else min_energy 0.3
				("human_health" c(10))
			}
			{if stuff "damage_impact"
				{throw_off up 0.2 dir 5.5 2 forward 4 turn 0 360 force}
			}
			{if stuff "damage_overlap"
				{start_sound "hit/small/human/"}
				{if volume "head" 
					{spawn "fx_piece_blood_fx" "head"}	
					{spawn "fx_piece_blood_fx" "head"}	
					{spawn "fx_piece_blood_fx" "head"}	
					{if not tagged "wound_head" 
						{tex_mod "wound_head"}
					}
					{talk "bleeding"}			
					{tags add "bleeding_small_head"}
					{call "bleeding_small_head"}
					{delay 12 7 "tags_blast"
						{tags remove "bleeding_small_head"}
					}
				else
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{spawn "fx_piece_blood_fx" }	
					{talk "bleeding"}
					{tags add "bleeding_small_body"}
					{call "bleeding_small_body"}
					{delay 10 7 "tags_blast"
						{tags remove "bleeding_small_body"}
					}
				}
				("health_damage" c(100))
			}
		}
		{if rand 0.2
			{if min_energy 2
				{if not dead
					{if not user_control
						{if not tagged "hit_side front"
							{if hit_side front
								{tags add "hit_side"}
								{chassis_work 0}
								{weapon_work "hand_right" 0}
								{talk "hit"}
								{reset_manual_control}
								{if not tagged "bleeding" 
									{ani_play "stand_die_back_1"  1.2}	
								}
								{delay 2.8 "hit_side"
									{if not dead
										{if not tagged "bleeding" 
											{ani_play "stand_from_lie_back"  0.8}	
										}
									}
								}			
								{delay 2  "workes"
									{if dead
										{ani_stop "stand_from_lie_back" }	
									}	
								}	
								{delay 4.1  "workes"
									{if not dead
										{chassis_work 1}
										{weapon_work "hand_right" 1}
									}
								}
								{delay 20
									{tags remove "hit_side"}	
								}
							}
						}
					}	
				}	
			}			
		}		
		{if not dead
			{if min_energy 2
				{call "unhealable"}
			else min_energy 1.25
				(mod "mp" {call "unhealable"})
			}
		}
		{if min_energy 0.2
			{kill_flags reset}
			{if hit_side front
				{kill_flags front}
			else hit_side back
				{kill_flags back}
			else
				{kill_flags front back}
			}
			{kill_flags blast}
			{health_damage_blast
				{effects
					"hit-scream"
					"hit-light"
					"hit-heavy"
					"die"
					"hit-explosion"
					"throw-off"
					"throw-off-and-die"
				}
				{table	;// table for "throw_off" impluse
				;//{blast energy, impulse}
					{0.95	0.05}
					{1.1	0.15}
					{2.0	0.5 }
					{10		2	}
					{50		3	}
				}
			}
			{if stuff "damage_shock"
				{call "tinnitus_micro"}
			}
			{if not dead
				{if active ;возможная причина живучести после удара гранатомёта
					{delay 0.1
						{spawn "damage_shock" "basis" x}
					}
					{delay 0.4 
						{start_sound "human/tinnitus/shock"}
					}
				}
				{if volume "head" 
					{if not tagged "wound_head" 
						{tex_mod "wound_head"}
					}
					{if hit_side front
						{if min_energy 8
							{spawn "fx_piece_blood_fx" }	
							{spawn "fx_piece_blood_fx" }	
						else min_energy 2
							{spawn "fx_piece_blood_fx" }	
							{if rand 0.5
								{spawn "fx_piece_blood_fx" }	
							}
						}
					}
					{if rand 0.4	
						{talk "bleeding"}			
						{tags add "bleeding_small_head"}
						{call "bleeding_small_head"}
						{delay 12 7 "tags_blast"
							{tags remove "bleeding_small_head"}
						}
					}
				else volume "body" 
					{if hit_side front
						{if rand 0.5
							{spawn "fx_piece_blood_fx" }	
						}
					}
					{if rand 0.2 
						{talk "bleeding"}
						{tags add "bleeding_small_body"}
						{call "bleeding_small_body"}
						{delay 10 7 "tags_blast"
							{tags remove "bleeding_small_body"}
						}
					}
				else volume "foot1r" 
					{if rand 0.1 
						{talk "bleeding"}
						{tags add "bleeding_small_foot1r"}
						{call "bleeding_small_foot1r"}
						{delay 10 7 "tags"
							{tags remove "bleeding_small_foot1r"}
						}
					}
				else volume "foot2r" 
					{if rand 0.1 
						{talk "bleeding"}
						{tags add "bleeding_small_foot2r"}
						{call "bleeding_small_foot2r"}
						{delay 10 7 "tags_blast"
							{tags remove "bleeding_small_foot2r"}
						}
					}
				else volume "foot1l" 
					{if rand 0.1 
						{talk "bleeding"}
						{tags add "bleeding_small_foot1l"}
						{call "bleeding_small_foot1l"}
						{delay 10 7 "tags_blast"
							{tags remove "bleeding_small_foot1l"}
						}
					}
				else volume "foot2l" 	
					{if rand 0.1 
						{talk "bleeding"}
						{tags add "bleeding_small_foot2l"}
						{call "bleeding_small_foot2l"}
						{delay 10 7 "tags_blast"
							{tags remove "bleeding_small_foot2l"}
						}
					}
				}
				{call "tinnitus_small_expl"}	
				("health_damage" c(100))
			}
		}
		{delay 3 
			{tags remove "blast_hit_human"}
		}
	}
	{on "critical_health"	
		{if not tagged "critical_health"
			{tags add "critical_health"}
            {start_sound "human/critical_health/enter"}
 			{delay 1 "critical_health"
				{call "check_active"}
			}
            {delay 7 4 "critical_health"
 				{if active
                    {play_sound "critical_health_end" }
                }
				{stop_sound "critical_health_loop" }
 				{tags remove "critical_health"}
				{tags remove "start_sound"}
				{kill_delay "check_active"}	
 				{tags remove "play_sound"}
           }
        }
	}
	{on "tinnitus_micro"	
	;	{kill_delay "tinnitus" }
		{if not tagged "tinnitus_micro"
			{tags add "tinnitus_micro"}
            {if active
                {play_sound "tinnitus_small_start" }
            }
			{delay 1.3 "tinnitus"
				{call "check_active"}
			}
            {delay 3 "tinnitus"
 				{if active
                    {play_sound "tinnitus_small_end" }
                }
				{stop_sound "tinnitus_small_loop" }
 				{tags remove "tinnitus_micro"}
				{tags remove "start_sound"}
				{kill_delay "check_active"}	
 				{tags remove "play_sound"}
           }
        }
	}
	{on "tinnitus_small_expl"	
	;	{kill_delay "tinnitus" }
		{if not tagged "tinnitus_small"
			{tags add "tinnitus_small"}
            {if active
                {play_sound "tinnitus_small_start" }
            }
			{delay 1.3 "tinnitus"
				{call "check_active"}
			}
            {delay 7 4 "tinnitus"
 				{if active
                    {play_sound "tinnitus_small_end" }
                }
				{stop_sound "tinnitus_small_loop" }
 				{tags remove "tinnitus_small"}
				{tags remove "start_sound"}
				{kill_delay "check_active"}	
 				{tags remove "play_sound"}
           }
        }
	}
	{on "check_active"
		{if tagged "critical_health"
            {if active
				{if not tagged "start_sound"
					{play_sound "critical_health_loop" 1}
					{tags add "start_sound"}
				}
			else
				{tags remove "start_sound"}
				{stop_sound "critical_health_start" }
				{stop_sound "critical_health_loop" }
				{stop_sound "critical_health_end" }
			}
		}
		{if tagged "tinnitus_small"
            {if active
				{if not tagged "start_sound"
					{play_sound "tinnitus_small_loop" 1}
					{tags add "start_sound"}
				}
			else
				{tags remove "start_sound"}
				{stop_sound "tinnitus_small_start" }
				{stop_sound "tinnitus_small_loop" }
				{stop_sound "tinnitus_small_end" }
			}
		}
		{delay_effect 0.3
			"check_active"
		}
	}
	{on "unhealable"
		{tags add "no_revive"}
		{delay 0.2							;// removes tag incase blastwave doesn't kill human
			{tags remove "no_revive"}
		}
		{if tagged "start_personage"
			{if personage
				{able "personage" 0}		;// stops human from being revivable if in revive state
				{call "die_with_blood"}
			}
		}
	}
	{on "die_throw_high"
		{set "die_after_throw" 1}
		{spawn "bloodsparks_small2"}
		{call "die_scream"}
		{call "throw_high"}
	}

	{on "hit-scream"
		{if not "talk"
			{set "talk" 1}
			{talk "injuring"}
			{delay 10 2
				{set "talk" 0}
			}
		}
	}

	{on "hit-light"
		{if not tagged "synth"
			{spawn "bloodsparks_small2"}
		}
	}

	{on "hit-heavy"
		{if not tagged "synth"
			{spawn "bloodsparks_big"}
		}
	}
	{on "hit-explosion"
		{if tagged "no_explosion"
			{call "die"}
		else
			{call "die_scream"}
			{call "explosion"}
		}
	}
	{on "throw-off"
		{set "die_after_throw" 0}
		{call "throw_high"}
	}
	{on "throw-off-and-die"
		{set "die_after_throw" 1}
		{call "die_scream"}
		{call "throw_high"}
	}
	{on "hit"
		{call "hit-scream"}
	}
	{on "damage"
		{if not tagged "synth"
			{spawn "bloodsparks_small2"}
		}
		{call "hit"}
	}
	{on "throw_high"
		{if senseless
			{if not dead
				{if not user_control
					{call "die"}
				}
			}
		else
			{if not dead
				{if linked "vehicle"
					{if "die_after_throw"
						{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 die force}
					else
						{if "knock_out"
							{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
						}
					}
				else
					{if "die_after_throw"
						{throw_off up 4 0.8 dir 3.5 0.5 forward 0 0 die}
					else
						{if "knock_out"
							{throw_off up 4 0.8 dir 3.5 0.5 forward 0 0}
						}
					}
				}
			else
				{call "explosion"}
			}
		}
	}
	{on "throw_off_end"
		{if not user_control
			{health_damage_count 50
				{effects "" "hit" "damage" "die" "die"}
			}
		}
		{call "knock_down"}
	}
	{on "throw_off_end_die"
		{call "die"}
	}
	{on "throw_off_from_tower"
		{throw_off up 1 forward 2 die force}
	}
	{on "throw_off_from_ladder"
		{throw_off up 1 forward -2 die force}
	}
	{on "throw_off_from_ship"
		{throw_off up 4 dir 3 1 die force}
	}
	{on "throw_off_from_vehicle"
		{if difficulty "multiplayer"
			{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force die}
		else
			{if user_control
				{throw_off up 1.3 0.5 dir 5.5 2 forward 4 turn 0 360 force}
			else
				{throw_off up 1.3 0.5 dir 5 1 forward 4 turn 0 360 rnd_die 0.7 force}
			}
		}
	}
	{on "linker_simulation"
		{if effector "airborne"
		 else effector "cannon"
			;{throw_off up 2.25 0.75 forward 2.25 0.75 turn 0 360 force}
		 else altitude 3
			{throw_off up 1 forward 2 die force}
		}
	}

	{on "knock_down"
		{if not water_level -0.1
			{knockdown 12 3}
		}
	}
	;{on "kill_log"
	;}
	{on "die"
		;{call "kill_log"}
		{delay 35 10
			{tags add "die_end"}	
		}
		{set "idle" 0}
		{tags remove "detect"}	
		{view pause "detect"}	
		{view stop "detect"}	
		{tags add "killed"}
		{delay 1 {tags remove "killed"}}
		;{call "bodyfalls"}
		{set "blocked" 1}
		{set "operatable_human" 0}
		{delay 2 "blood"
			{stop_sound "small" }
			{if tagged "bleeding_small_body"			
				{spawn "blood_after_hit" "body"}
			else tagged "bleeding_small_body_random"	
				{spawn "blood_after_hit" "body"}
			else tagged "bleeding_small_body_random_ap"	
				{spawn "blood_after_hit" "body"}
			else tagged "bleeding_small_foot2r"	
				{spawn "blood_after_hit" "foot2r"}
			else tagged "bleeding_small_foot1l"
				{spawn "blood_after_hit" "foot1l"}
			else tagged "bleeding_small_foot1r"
				{spawn "blood_after_hit" "foot1r"}
			else tagged "bleeding_small_foot2l"
				{spawn "blood_after_hit" "foot2l"}
			else tagged "bleeding_small_hand2r"	
				{spawn "blood_after_hit" "hand2r"}
			else tagged "bleeding_small_hand1l"
				{spawn "blood_after_hit" "hand1l"}
			else tagged "bleeding_small_hand1r"
				{spawn "blood_after_hit" "hand1r"}
			else tagged "bleeding_small_hand2l"
				{spawn "blood_after_hit" "hand2l"}
			else tagged "bleeding_small"
				{spawn "blood_after_hit" "body"}
			else tagged "bleeding_small_body_sm_ic"
				{spawn "blood_after_hit" "body"}
			}
		}
		{delay 5 "blood"
			{tags remove "bleeding_small_gas"}	
			{tags remove "contact_gases"}	
			{tags remove "bleeding_small_body_random_ap"}	
			{tags remove "bleeding_small_body_sm_ic"}	
			{tags remove "bleeding_small_head"}	
			{tags remove "bleeding_small"}	
			{tags remove "bleeding_small_body"}	
			{tags remove "bleeding_small_foot2r"}	
			{tags remove "bleeding_small_foot1l"}	
			{tags remove "bleeding_small_foot1r"}	
			{tags remove "bleeding_small_foot2l"}	
			{tags remove "bleeding_small_hand2r"}	
			{tags remove "bleeding_small_hand1l"}	
			{tags remove "bleeding_small_hand1r"}	
			{tags remove "bleeding_small_hand2l"}	
		}
		{delay 0
			{if not dead
				{call "radio_signal"}
				{spawn "bloodsparks_small"}
				; {if not tagged "lying"
					; {if not burned
						; {if rand 0.5
							; {delay 2 1
								; {call "lie_wounded"}
							; }
						; }
					; }
				; }
				{if linked
					{if linked "shipflak"
						{call "throw_off_from_ship"}
					else linked "doublecolt"
						{call "throw_off_from_ship"}
					else linked "car"
						{if place "driver"
							{throw_off up 1.6 forward 2 turn -90 die force rotate_to_dir}
						else place "commander"
							{throw_off up 1.6 forward 2 turn +90 die force rotate_to_dir}
						else
							{call "die_with_blood"}
						}
					else altitude 2
						{if boarding
							{call "throw_off_from_ladder"}
						else
							{call "throw_off_from_tower"}
						}
					else linked "cannon"
						{call "die_with_blood"}
					else
						{call "throw_off_from_vehicle"}
					}
				else
					{call "die_with_blood"}
				}
			}
		}
	}
	{on "die_with_blood"
		; {if not tagged "lying"
			; {if not burned
				; {if rand 0.5
					; {delay 2 1
						; {call "lie_wounded"}
					; }
				; }
			; }
		; }
		; {if not senseless
			; {spawn "blood"}
		; }
		{call "die_without_blood"}
	}
	{on "lie_wounded"
		{if not tagged "die_end"
			{if not tagged "lie_wounded_enter"
				{if rand 0.4
					{ani_play "lie_wounded" }
				else rand 0.3
					{ani_play "lie_wounded_1" }
				else
					{ani_play "lie_wounded_2" }		
				}
			}
		}
	}
	{on animation_event "lie_wounded_enter"	
		{tags remove "lie_wounded_exit"}
		{tags add "lie_wounded_enter"}
	}
	{on animation_event "lie_wounded_exit"	
		{tags add "lie_wounded_exit"}
		{tags remove "lie_wounded_enter"}
		{if not tagged "die_end"
			{call "lie_wounded"}
		else not tagged "lie_wounded_end"
			{tags add "lie_wounded_end"}		
			{ani_play "lie_wounded" }			
		}
	}
	{on animation_event "body_hit"	
		{call "body_hit_health"}
	}
	{on "body_hit_health"
		{if not active
			{if not tagged "move"
				{if not tagged "fire_hold"
					{call "fast_health"}			
				}
			}
		}
	}
	{on "fast_health"
		{if not tagged "fast_health"
			{tags add "fast_health"}
			{delay 0.5
				{if not able "burning"
					{if not "blocked"
						{if not linked
							{if not tagged "stim"
								{tags add "stim"}
								{if not dead
									{if not tagged "check_move"
										{if not tagged "fire_hold"
											{if tagged "link_weapon"											
												{weapon_work "hand_right" 0}
												{ani_play "stand_take_gun_up" -1}
											}
											{add_view 	"stim" 		"stim" "right_hand"}
											{view start "stim"}
											{reset_manual_control}
											{delay 0.4 
												{if not able "burning"
													{if not dead
														{call "heal_bleeding"}
														{if not "blocked"
															{ani_play "squat_self-treatment_hand_begin" 2}
														}
													}
												}
											}
											{delay 1.1
												{if not dead
													{if not able "burning"
														{spawn "stim" "palm3r" x {impulse up 0.1}}
														{view hide	"stim"}
														{view pause	"stim"}
														{if not "blocked"
															{if tagged "link_weapon"											
																{weapon_work "hand_right" 1}
																{ani_play "stand_take_gun_up" 1.2}
															}
														}
													}
												}
											}
										}
									}
								}
							}
							{delay 25
								{tags remove "stim"}
							}
						}
					}
				}
			}
		}
	}
	{on "die_without_blood"
		;{con "die"}
		{view pause "swim"}
		{call "die_scream"}
		{if not kill_flags blast
			{kill_flags piercing}
		}
		{die}
		;{able collect 1}
		{delay 3
			{volumes enable contact}
		}
		;{delay 30 {delete}}
	}
	{on "die_scream"
		{if not "die_sound"
			{set "die_sound" 1}
			{talk "death_cry"}
			{signal mandie 50}
		}
	}
	{on "die_from_knife"
		{set "die_from_knife" 1}
		{call "die"}
	}

	{on ground_hit sync
		{if not tagged "non_lethal"
			{spawn "blood"}
		}
	}
	(define "imp"
		{spawn %0 %1
			{impulse	up 1 0.5 dir 8 4
						cx 0 12 cy 0 12
						fx 0 60 fy 0 60 fz 80 40
			}
		}
	)
	{on "explosion"
		{call "die"}
	}
	{on "crush"
		{if personage
			{call "die"}
		else
			{spawn "bloodsparks_dead"}
			{call "delete"}
		}
	}
	{on "delete"
		{if not dead
			{stat_notify die}
		}
		{delete}
	}
	{on animation_event "end_burn"
		{if not dead
			{delay 1
				{die}
			}
		}			
	}
	{on "burn_volume"
		{if linked
			{if linked "tank"
				{if rand 0.05
					{able "burning" 1}
					{set_heater}
					{call "_burn"}
				}
			else linked "car"
				{if rand 0.3
					{call "_burn"}
				}
			}
		else
			{if not dead
				{if not tagged "blast_hit_human"				
					{if rand 0.5
						{ani_play "stand_die_burn"}
					else
						{ani_play "stand_die_burn_2"}
					}
					{chassis_work 0}
					{weapon_work "hand_right" 0}
				}
			}
			{able "burning" 1}			;// causes unit to act uncontrolable
			{able select 0}
			{drop_orders}
			{call "_burn"}
			(define "burn_volume"
				{if volume %0
					{if not tagged %1
						{burn volume %0 fx "smoke_dead_body" time 35 fake even_law}
						{burn volume %0 fx "smoke_dead_body_fast" time 10 fake even_law}
						{link_sound 	"small"			"fire/small_stuff/fire_small"}
						{play_sound "small" 1}
						{fire volume %0 radius 0.2 heating 1  time 35 follow}
						{tags add %1}
						{delay 35 
							{stop_sound "small" }
						}
					}
				}
			)
			("burn_volume" args "head" "burn_head")
			("burn_volume" args "body" "burn_body")
			("burn_volume" args "hand1l" "burn_hand1l")
			("burn_volume" args "hand1r" "burn_hand1r")
			("burn_volume" args "hand2l" "burn_hand2l")
			("burn_volume" args "hand2r" "burn_hand2r")
			("burn_volume" args "foot1l" "burn_foot1l")
			("burn_volume" args "foot1r" "burn_foot1r")
			("burn_volume" args "foot2l" "burn_foot2l")
			("burn_volume" args "foot2r" "burn_foot2r")
		}
	}
	{on "_burn"
		{if not burned
			{able "burning" 1}			;// causes unit to act uncontrollable
			(define "try_get_off"		;// unlinks unit from vehicles
				{delay %0
					{if not tagged "can_die"
						{unlink}
					}
				}
			)

			("try_get_off" args 0.5)
			("try_get_off" args 2.0)
			("try_get_off" args 3.0)
			("try_get_off" args 4.0)
			("try_get_off" args 5.0)

			{call "add_burn_fx"}
			{delay_effect 0.5 "burn_scream"}	;// calls burn_scream event below and loops

			{if not dead
				{call_synced "start_burn_damage"}
			}

			{delay 20
				{call_synced "stop_burn_damage"}
			}
			{burn time 20}					;// Required! Without it, humans die instantly when on fire
		}
	}
	{on "start_burn_damage"
		{able select 0}
		{drop_orders}
		{weapon_work "hand_right" 0}
		{call "unhealable"}
		(define "burn_damage"					;// causes increasing damage to human health over time
			{delay %t "burn_damage"
				{if not dead
					{if able "burning"
						("human_health" c(%c))
						{fire radius 1 time 1 heating 0.25 follow}	;// adds heating to unit (potential to set other items on fire due to proximity)
						{if not tagged "no_revive"
							{if not tagged "hero_unit"	;// exception for unit to be revive-able in missions
								{tags add "no_revive"}
							}
						}
					else
						{kill_delay "burn_damage"}
						{tags remove "no_revive"}
					}
				else
					{if not "burn_tex"
						{set "burn_tex" 1}
						{tex_mod "burned"}
						;{tex_morph "burned" 5}
					}
				}
			}
		)
		("burn_damage" t(0.0) c(10))
		("burn_damage" t(0.3) c(10))
		("burn_damage" t(0.6) c(15))
		("burn_damage" t(0.9) c(20))
		("burn_damage" t(1.2) c(25))
		("burn_damage" t(1.5) c(30))
		("burn_damage" t(1.8) c(35))
		("burn_damage" t(2.1) c(40))
		("burn_damage" t(2.4) c(45))
		("burn_damage" t(2.7) c(50))
		("burn_damage" t(3) c(100))
		("burn_damage" t(4) c(200))
		("burn_damage" t(5) c(300))
	}
	{on "add_burn_fx"
		{play_sound "burn" 1}
		{view start "burn_fire"}
	}

	{on "burn_scream"
		{if not dead
			{if not senseless
				{if not "quench"
					{if not tagged "death_cry_talk"
						{tags add "death_cry_talk"}
						{talk "death_cry"}
						{delay 4 {tags remove "death_cry_talk"}}
					}
					{delay_effect 1.25 "burn_scream"}		;// calls own event again (loops)
				else
					{call "stop_burn_damage"}
					{set "quench" 0}							;// allows unit to be able to burn again
					{able "burning" 0}							;// stops uncontrollable actions
				}
			}
		}
	}

	{on "stop_burn"
		{stop_sound "breath"}
		{if burned
			{burn stop_retry}
			{set "quench" 1}			;// stops "burn_scream" loop
			{delay 2					;// quench 0 in "burn_scream" not working. Backup code.
				{set "quench" 0}
			}
		}
	}
	{on "smoke"
		{if not tagged "synth"
			{smoke}
		}
		{ani_stop "stand_smoke_1"}
		{ani_stop "stand_smoke_2"}
		{ani_stop "stand_smoke_3"}
	}
	{on "smoking"
		{if not tagged "synth"
			{view start "smoke"}
			{delay 0.3 0.1
				{view pause "smoke"}
			}
		}
		{ani_stop "stand_smoke_1"}
		{ani_stop "stand_smoke_2"}
		{ani_stop "stand_smoke_3"}
	}
	(include "link_weapon_human.inc")
	(include "unlink_weapon_human.inc")
	(include "armed_weapon_human.inc")
	(include "hand_right_human.inc")
	(define "cut_shells"
		{tear "shell_drop_12_55" bone "shells0%0" copy 
			{impulse up 0.2 0.1 cx 1 com}
		}
	)
	(define "hide_shells"
		{view hide "shells0%0"}						
	)
	(define "view_shells"
		{view show "shells0%0"}						
	)
	{on "reload"
		{signal shot 80 }
		{tags add "reload"}
		{delay 3
			{tags remove "reload"}	
		}
		{call "rand_sm"}
		{call "rand_ph"}
		{call "rand_art"}
		{call "reload_s"}
		(define "add_tags_reload"
			{if effector "stuff weapon %tag"
				(include "reset_shoot.inc")
				{delay 1 
					{tags add "%tag"}
				}
				{with_effector
					(include "reset_shoot.inc")
					{delay 1 
						{ani_play "%reset" -1}
						{tags add "%tag"}
					}			
				}
			}
		)
		("add_tags_reload" 	tag(100_bullet) reset(shot_small100) )
		("add_tags_reload" 	tag(96_bullet) reset(shot_small96) )
		("add_tags_reload" 	tag(75_bullet) reset(shot_small75) )
		("add_tags_reload" 	tag(70_bullet) reset(shot_small70) )
		("add_tags_reload" 	tag(53_bullet) reset(shot_small53) )
		("add_tags_reload" 	tag(50_bullet) reset(shot_small48))
		("add_tags_reload" 	tag(45_bullet) reset(shot_small45) )
		("add_tags_reload" 	tag(40_bullet) reset(shot_small40) )
		("add_tags_reload" 	tag(35_bullet) reset(shot_small35) )
		("add_tags_reload" 	tag(32_bullet) reset(shot_small32) )
		("add_tags_reload" 	tag(30_bullet) reset(shot_small30) )
		("add_tags_reload" 	tag(25_bullet) reset(shot_small25) )
		("add_tags_reload" 	tag(20_bullet) reset(shot_small20) )
		("add_tags_reload" 	tag(18_bullet) reset(shot_small18) )
		("add_tags_reload" 	tag(15_bullet) reset(shot_small15) )
		("add_tags_reload" 	tag(12_bullet) reset(shot_small12) )
		("add_tags_reload" 	tag(10_bullet) reset(shot_small10) )
		("add_tags_reload" 	tag(8_bullet) reset(shot_small8) )
		("add_tags_reload" 	tag(7_bullet) reset(shot_small7) )
		("add_tags_reload" 	tag(5_bullet) reset(shot_small5) )
		("add_tags_reload" 	tag(6_bullet) reset(shot_small6) )
		("add_tags_reload" 	tag(1_bullet) reset(shot_small1) )
		{if "broken"
			{spawn "ex_air_sm" "foresight3" }
			{spawn "sparks01" "fxshell" x}
			{call "broken_weapon"}
			{delay 0.1 
				{delete}
			}
		}
		{if effector "stuff weapon m37"
			{with_effector 
				{delay 4.2
					{ani_play "charge" 1.2 }
				}
			}
			{delay 4.2
				{if tagged "squat"
					{ani_play "squat_charge_m37" 1.2 }
				}
				{if tagged "lying"
					{ani_play "lying_charge_m37" 1.2 }
				else tagged "stand"
					{ani_play "squat_charge_m37" 1.2 }
				}
			}
		}
		{if effector "stuff weapon autoshot"
			{tags add "0_auto"}
			{tags remove "1_auto"}
			{tags remove "2_auto"}
			{tags remove "3_auto"}
		}
		{if effector "stuff cross_break_40m"
;			{if not "blocked"
;				{ani_play "stand_reload_guns" 1}
;			}
			;{set "delete_parts" 1}
			{with_effector
				{tags add "reload" }
				{call "cross_break_40m"}			
				{delay 0 
					{delay 0.3
						{tear "shell_drop_12_55" bone "shotgunshell" copy 
							{impulse up 0 dir -1 1 forward 3 1 com  fx -2 4}
							{add_view "smoke_zenit" "smoke_shell" "fx_smoke"}
							{view start "smoke_shell"}
							{delay 2
								{view stop "smoke_shell"}
							}
							{delay 9 2
								{hide 3}
							}
						}
						{delay 0
							{view hide "shotgunshell"}	
						}
						{tags remove "empty" }
					}
					{delay 1.5 "check"
						{tags remove "reload" }
						{view show "shotgunshell"}
					}
				}
			}		
		else effector "stuff weapon pistol"
			;{set "delete_parts" 1}
			{with_effector
				{add_view	"smoke_heat_barrel"		"smoke_heat_barrel"		"fxshell"}
				{ani_play "clip_magazine_out" 1}
				{ani_play "reload" 1}
				{tags add "empty" }
				{tags add "reload" }
				{delay 0.3
					{if tagged "fire_hold"
						{view start	"smoke_heat_barrel"}
					}
					{tear "smg_metal_drop" bone "magazine" copy ;slicer_tail
						{impulse up 0 com}
					}
					{delay 0
						{view hide "magazine"}	
					}
				}
				{delay 0 ; for hiding magazine bone only after copying it ot new entity
					{view hide "bullets"}
					{view hide "bullet"}
					{view hide "bullet0"}
					{view hide "bullet1"}
					{view hide "bullet2"}
					{view hide "bullet3"}
					{view hide "bullet4"}
					{view hide "bullet5"}
					{view hide "bullet6"}
					{delay 0.7
						{tear "shell_drop_9_19" bone "eject_bullet" copy 
						}
						{view hide "shells0%0"}						
						("cut_shells" args 0)
						("cut_shells" args 1)
						("cut_shells" args 2)
						("cut_shells" args 3)
						("cut_shells" args 4)
						("cut_shells" args 5)
						("cut_shells" args 6)
						{delay 0
							("hide_shells" args 0)
							("hide_shells" args 1)
							("hide_shells" args 2)
							("hide_shells" args 3)
							("hide_shells" args 4)
							("hide_shells" args 5)
							("hide_shells" args 6)
							{view hide "eject_bullet"}
							{delay 0.4
								("view_shells" args 0)
								("view_shells" args 1)
								("view_shells" args 2)
								("view_shells" args 3)
								("view_shells" args 4)
								("view_shells" args 5)
								("view_shells" args 6)
								{view show "bullet"}
								{view show "bullet1"}
								{view show "bullet2"}
								{view show "bullet3"}
								{view show "bullet4"}
								{view show "bullet5"}
								{view show "bullet6"}
							}
						}
						{tags add "empty" }
					}
					{delay 1.5 "check"
						{view stop	"smoke_heat_barrel"}
						{if tagged "empty"
							{delay 0.1 
								{start_sound "weapon/mag_clip/pistol_series/in"}
								{ani_play "close" 0.5}
							}
						}
						{view show "eject_bullet"}
						{view show "magazine"}
						{view show "bullets"}
						{ani_play "clip_magazine_out" -1}
						{tags remove "reload" }
					}
				}
			}
		else effector "stuff weapon mgun"
			{if not effector "counter"
				{call "armed_weapon"}
			}			
			;{set "delete_parts" 1}
			{with_effector
				{bone hide "j_mag_box"}	
				{bone hide "bullet_base"}	
				{if tagged "100_heat_stage"
					{start_sound "weapon/heat/"}
				}
				{add_view	"smoke_heat_barrel"		"smoke_heat_barrel"			"fxshell"}
				(define "clip_out"
					{if prop "%0"				
						{start_sound "weapon/mag_clip/%0/out/"}
					}
				)
				("clip_out" args mg_series)
				("clip_out" args rpd_series)
				{tags add "empty" }
				{tags add "reload" }
				{delay 1
					{ani_play "clip_magazine_out_mg" 0.2}
					{if tagged "fire_hold"
						{view start	"smoke_heat_barrel"}
					}
					{tear "large_drum_drop" bone "magazine" copy ;slicer_tail
						{impulse up 0}
					}
					{delay 0
						{bone hide "magazine"}	
					}
				}
				{delay 0 ; for hiding magazine bone only after copying it ot new entity			
					{delay 0.6
						{tags remove "empty" }
					}
					{delay 4 "check"
						{tags remove "reload" }
						{bone show "magazine"}	
						{bone show "j_mag_box"}	
						{bone show "bullet_base"}	
						{view stop	"smoke_heat_barrel"}
						{ani_play "clip_magazine_out_mg" -0.2}
						{delay 0.3 "sound"
							(define "clip_in"
								{if prop "%0"				
									{start_sound "weapon/mag_clip/%0/in/"}
								}
								{delay 0.4
									{start_sound "weapon/mag_clip/%0/belt/"}
								}
							)
							("clip_in" args mg_series)
							("clip_in" args rpd_series)
						}
						{if tagged "empty" 
							{delay 0.7 "close"
								(define "close"
									{if prop "%0"				
										{start_sound "weapon/close/%0/"}
									}
								)
								("close" args mg_series)
								("close" args rpd_series)
								{ani_play "close" 1}
							}						
						}
					}
				}
			}
		else effector "stuff weapon riflehand"
			;{set "delete_parts" 1}
			{delay 6			
				{if tagged "squat"										
					 {ani_play "squat_bolt_rifle_close" 1.1 }					
				}					
				{if tagged "lying"										
					 {if not tagged "move"									
						{ani_play "lie_bolt_rifle_close" 1.1 }					
					}					
				 else					
					 {ani_play "stand_bolt_rifle_close_up" 1.1 }					
				}
			}
			{with_effector
				{tags add "reload"}
				{delay 0.4
					{ani_play "charge" 1.8 }
					{delay 0.3
						{ani_stop "charge" }
						{delay 5.3			
							{ani_play "charge" -1 resume}
						}
					}
					{call "reload"}
					{delay 1.4
						{ani_play "clip_magazine_out" 1}
						{start_sound "weapon/mag_clip/sniper_series_riflehand/out/"}
						{tags add "empty" }
						{tags add "reload" }
						{if tagged "fire_hold"
							{view start	"smoke_heat_barrel"}
						}
						{if tagged "transform"
							{tear "ak_metal_drop" bone "magazine_inv" copy ;slicer_tail
								{burn volume "magazine" fx "smoke_mist_run" time 7 fake even_law}
								{impulse up 0.1 com}
							}
							{delay 0
								{bone hide "magazine_inv"}	
							}
						else
							(define "mag_copy"
								{if prop "%tags"							
									{tear "%tear" bone "magazine" copy 
										{impulse dir 0.01}
									}
								}
							)
							("mag_copy"  tags(rifle270_metal_drop) 	tear(rifle270_metal_drop))						
							("mag_copy"  tags(ak_metal_magazine) 	tear(ak_metal_drop))						
							("mag_copy"  tags(ak_poly_magazine) 	tear(ak_poly_drop))						
							("mag_copy"  tags(ar_metal_magazine) 	tear(ar_metal_drop))						
							("mag_copy"  tags(ar_poly_magazine) 	tear(ar_poly_drop))						
							("mag_copy"  tags(smg_metal_magazine) 	tear(smg_metal_drop))						
							("mag_copy"  tags(smg_poly_magazine) 	tear(smg_poly_drop))						
							("mag_copy"  tags(large_drum_magazine) 	tear(large_drum_drop))						
							{delay 0
								{bone hide "magazine"}	
							}
						}
					}
				}
				{delay 3.8 "check"
					{tags remove "reload" }
					{bone show "magazine"}	
					{bone show "bullet"}	
					{ani_play "clip_magazine_out" -1}
					{delay 0.1 "sound"
						{start_sound "weapon/mag_clip/sniper_series_riflehand/in/"}
					}
				}
			}
		else effector "stuff weapon riflehand_auto"
			;{set "delete_parts" 1}
			{with_effector
				{delay 1
					{call "reload"}
					{ani_play "clip_magazine_out" 1}
					{start_sound "weapon/mag_clip/sniper_series/out/"}
					{tags add "empty" }
					{tags add "reload" }
					{if tagged "fire_hold"
						{view start	"smoke_heat_barrel"}
					}
					{tear "ar_metal_drop" bone "magazine" copy ;slicer_tail
						{impulse up 0.1 com}
					}
					{delay 0
						{view hide "magazine"}	
						{view hide "bullet"}	
					}
				}
				{delay 1.5 "check"
					{tags remove "reload" }
					{view show "magazine"}	
					{view show "bullet"}	
					{with_effector
						{talk "reload"}
					}
					{view stop	"smoke_heat_barrel"}
					{ani_play "clip_magazine_out" -1}
					{delay 0.1 "sound"
						{start_sound "weapon/mag_clip/sniper_series/in/"}
					}
					{if tagged "empty" 
						{delay 0.7 "close"
							{start_sound "weapon/close/sniper_series/"}
							{ani_play "close" 1}
						}						
					}
				}
			}
		else effector "stuff weapon"
			{if not effector "counter"
				{call "armed_weapon"}
			}			
			;{set "delete_parts" 1}
			{with_effector
				{call "weapon_reload"}			;// defined in stuff.inc goh
				{call "reload"}
				{if tagged "100_heat_stage"
					{start_sound "weapon/heat/"}
				}
				{add_view	"smoke_heat_barrel"		"smoke_heat_barrel"			"fxshell"}
				{ani_play "clip_magazine_out" 1.5}
				{ani_play "reload" 0.3}
				(define "clip_out"
					{if prop "%0"				
						{start_sound "weapon/mag_clip/%0/out/"}
					}
				)
				("clip_out" args aa12_series)
				("clip_out" args lynx_series)
				("clip_out" args xm109_series)
				("clip_out" args sniper_series)
				("clip_out" args smg_series)
				("clip_out" args pp_series)
				("clip_out" args mp7_series)
				("clip_out" args mp5_series)
				("clip_out" args mg_series)
				("clip_out" args pistol_series)
				("clip_out" args aug_series)
				("clip_out" args aug_9mm_series)
				("clip_out" args bizon_series)
				("clip_out" args g3sg1_series)
				("clip_out" args m4a1_series)
				("clip_out" args galil_series)
				("clip_out" args p90_series)
				("clip_out" args ash_series)
				("clip_out" args ump_series)
				{tags add "empty" }
				{tags add "reload" }
				{delay 0.3
					{if tagged "fire_hold"
						{view start	"smoke_heat_barrel"}
					}
					{ani_play "latch" 1}
					(define "mag_copy"
						{if prop "%tags"							
							{tear "%tear" bone "magazine" copy 
								{impulse dir 0.01}
							}
						}
					)
					("mag_copy"  tags(rifle270_metal_drop) 	tear(rifle270_metal_drop))						
					("mag_copy"  tags(ak_metal_magazine) 	tear(ak_metal_drop))						
					("mag_copy"  tags(ak_poly_magazine) 	tear(ak_poly_drop))						
					("mag_copy"  tags(ar_metal_magazine) 	tear(ar_metal_drop))						
					("mag_copy"  tags(ar_poly_magazine) 	tear(ar_poly_drop))						
					("mag_copy"  tags(smg_metal_magazine) 	tear(smg_metal_drop))						
					("mag_copy"  tags(smg_poly_magazine) 	tear(smg_poly_drop))						
					("mag_copy"  tags(large_drum_magazine) 	tear(large_drum_drop))						
					{delay 0
						{view hide "shell_empty"}
						{view hide "shell_magazine"}
						{view hide "mag_handle"}
						{bone hide "sort"}
						{bone hide "spin"}
						{bone hide "magazine"}	
					}
				}
				{delay 0 ; for hiding magazine bone only after copying it ot new entity			
					{bone hide "j_magazine_r"}
					{view hide "shell00_n"}
					{view hide "shell01_n"}
					{view hide "shell"}
					{view hide "bullets"}
					{view hide "bullet"}
					{view hide "bullet_view"}
					{view hide "bullet0"}
					{view hide "bullet1"}
					{view hide "bullet2"}
					{view hide "bullet3"}
					{view hide "bullet4"}
					{view hide "bullet5"}
					{view hide "bullet6"}
					{delay 0.6
						{tear "shell_drop_762_39" bone "eject_bullet" copy 
							{impulse up 0.1 com}
						}
						{tear "shell_drop_12_55" bone "shell00_sc" copy ;slicer_tail
							{impulse forward -1.7 -2 com  }
							{add_view "smoke_shell_gauge" "smoke" "root"}
							{view start "smoke"}
							{delay_effect 3 1 "stop"}
						}
						{tear "shell_drop_12_55" bone "shell01_sc" copy ;slicer_tail
							{impulse forward -1.7 -2 com  }
							{add_view "smoke_shell_gauge" "smoke" "root"}
							{view start "smoke"}
							{delay_effect 3 1 "stop"}
						}
						("cut_shells" args 1)
						("cut_shells" args 2)
						("cut_shells" args 3)
						("cut_shells" args 4)
						("cut_shells" args 5)
						("cut_shells" args 6)
						{delay 0
							{view hide "shell00_sc"}
							{view hide "shell01_sc"}
							("hide_shells" args 1)
							("hide_shells" args 2)
							("hide_shells" args 3)
							("hide_shells" args 4)
							("hide_shells" args 5)
							("hide_shells" args 6)
							{view hide "eject_bullet"}
						}
						{tags remove "empty" }
					}
					{delay 1.5 "check"
						{ani_play "shot_small00" -1}
						{ani_play "shot22" -5}
						{tags remove "reload" }
						{bone show "shell_magazine"}
						{view show "shell_magazine"}
						{view show "shell00_n"}
						{view show "shell01_n"}
						{view show "shell00_sc"}
						{view show "shell01_sc"}
						{bone show "j_magazine_r"}
						{bone show "spin"}
						{view show "shell02"}
						{view show "shell03"}
						{bone show "sort"}
						{view show "eject_bullet"}
						{view show "mag_handle"}
						{bone show "magazine"}
						{view show "shell"}
						{view show "bullets"}
						{view show "bullet1"}
						{view show "bullet2"}
						{view show "bullet3"}
						{view show "bullet4"}
						{view show "bullet5"}
						{view show "bullet6"}
						{bone show "bullet_06"}
						{bone show "bullet_05"}
						{bone show "bullet_04"}
						{bone show "bullet_03"}
						{bone show "bullet_02"}
						{bone show "bullet_01"}
						{view show "bullet_view"}
						{view stop	"smoke_heat_barrel"}
						{ani_play "clip_magazine_out" -0.7}
						{view show "bullet"}
						(define "clip_in"
							{if prop "%prop"				
								{delay %delay
									("view_shells" args 1)
									("view_shells" args 2)
									("view_shells" args 3)
									("view_shells" args 4)
									("view_shells" args 5)
									("view_shells" args 6)
									{start_sound "weapon/mag_clip/%prop/in/"}
								}
							}
						)						
						("clip_in"  prop(g36_series)  		delay(0.6)	)
						("clip_in"  prop(aa12_series)  		delay(0.3)	)
						("clip_in" 	prop(lynx_series)  		delay(1)	)
						("clip_in"  prop(xm109_series)  	delay(1)	)
						("clip_in"  prop(sniper_series)  	delay(0.3)  )
						("clip_in"  prop(smg_series)  		delay(0.3)  )
						("clip_in"  prop(pp_series)  		delay(0.3)  )
						("clip_in"  prop(mp7_series)  		delay(0.3)  )
						("clip_in"  prop(mp5_series)  		delay(0.3)  )
						("clip_in"  prop(mg_series)  		delay(0.3)  )
						("clip_in"  prop(pistol_series)  	delay(0.3)  )
						("clip_in"  prop(aug_series)  		delay(0.3)  )
						("clip_in"  prop(aug_9mm_series)  	delay(0.3)  )
						("clip_in"  prop(bizon_series)  	delay(0.3)  )
						("clip_in"  prop(g3sg1_series)  	delay(0.3)  )
						("clip_in"  prop(m4a1_series)  		delay(0.3)  )
						("clip_in"  prop(galil_series)  	delay(0.3)  )
						("clip_in"  prop(p90_series)  		delay(0.1)  )
						("clip_in"  prop(ump_series)  		delay(0.3)  )
						("clip_in"  prop(ash_series)  		delay(0.3)  )
						{if tagged "empty" 
							{delay 0.7 "close"
								(define "close"
									{if prop "%0"				
										{start_sound "weapon/close/%0/"}
									}
								)
								("close" args aa12_series)
								("close" args sniper_series)
								("close" args smg_series)
								("close" args pp_series)
								("close" args mp7_series)
								("close" args mp5_series)
								("close" args mg_series)
								("close" args pistol_series)
								("close" args aug_series)
								("close" args aug_9mm_series)
								("close" args bizon_series)
								("close" args g3sg1_series)
								("close" args m4a1_series)
								("close" args galil_series)
								("close" args p90_series)
								("close" args ash_series)
								{ani_play "close" 1}
							}						
						}
					}
				}
			}
		}
	}

	(define "terrain_fx_human"
		{on terrain_fx %0 enter
			{if not swimming
				{view start "on_%1"}
				{view start "on_%1_time_short"}
				{delay 0.1
					{view pause "on_%1_time_short"}
				}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx_human" args "water"			water)
	("terrain_fx_human" args "puddle"			puddle)
	("terrain_fx_human" args "shallow_water"	puddle)
	("terrain_fx_human" args "mud"				mud)
	(define "terrain_fx_check_exterior"
		{on terrain_fx %0 enter
			{tags remove "interior"}
			{tags add 	"exterior"}
		}
	)
	("terrain_fx_check_exterior" args "ground" )
	("terrain_fx_check_exterior" args "bridge" )
	("terrain_fx_check_exterior" args "bridge_wood" )
	("terrain_fx_check_exterior" args "road" )
	("terrain_fx_check_exterior" args "country_road" )
	("terrain_fx_check_exterior" args "rock" )
	("terrain_fx_check_exterior" args "sand" )
	("terrain_fx_check_exterior" args "grass" )
	("terrain_fx_check_exterior" args "metal" )
	("terrain_fx_check_exterior" args "land" )
	("terrain_fx_check_exterior" args "snow" )
	(define "terrain_fx_check_interior"
		{on terrain_fx %0 enter
			{tags remove "exterior"}
			{tags add 	"interior"}
		}
	)
	("terrain_fx_check_interior" args "shoot_emit_int_wood" )
	("terrain_fx_check_interior" args "shoot_emit_int" )
	("terrain_fx_check_interior" args "shoot_emit_mtl" )
	("terrain_fx_check_interior" args "shoot_emit_mtl_int" )
	("terrain_fx_check_interior" args "floor" )
	("terrain_fx_check_interior" args "volume" )
	{on terrain_pp "swamp" enter
		{delay 0							; without delay will crash in Die()
			{call "die_without_blood"}
			{view start "die_in_swamp"}
			{delay 10
				{view stop "die_in_swamp"}
				{delete}
			}
		}
	}
	{on "diving"
		{delay 0.3
			{spawn "spherewater_big"}
		}
	}
	{on swim on
		{view pause "on_water"}
		{view start "swim"}
		{call "stop_burn"}
		{kill_delay "after_swim"}
	}
	{on swim off
		{delay 1.5 "after_swim"
			{view pause "swim"}
		}
	}
	{on move on
		{call "stop_idle"}
;		{if not active
;			{if rand 0.2
;				{delay 8
;					{player 4}
;				}
;			else rand 0.2
;				{delay 8
;					{player 5}
;				}
;			else rand 0.2
;				{delay 8
;					{player 6}
;				}
;			else rand 0.2
;				{delay 8
;					{player 7}
;				}
;			else rand 0.2
;				{delay 8
;					{player 8}
;				}
;			else rand 0.2
;				{delay 8
;					{player 9}
;				}
;			else rand 0.2
;				{delay 8
;					{player 10}
;				}
;			else
;				{delay 8
;					{player 11}
;				}
;			}
;		}
;		{ani_stop "squat_bolt_rifle"     } ;edited from goh
;		{ani_stop "lie_bolt_rifle"  	 };edited from goh
;		{ani_stop "stand_bolt_rifle_up"  };edited from goh
		{tags remove "idle"}
		{tags add "check_move"}
		{kill_delay "check_move"}	
		{if user_control
			{tags remove "ai"}			
		}
		{tags remove "stop"}
		{tags add "move"}
		{if swimming
			{view start "swim_move"}
		}
	}
	{on move off
		{tags remove "fast"}
		{tags remove "normal"}
		{tags remove "walk"}
		{tags remove "slow"}
		{tags remove "sneak"}
		{tags remove "spot"}
		{tags remove "bow"}
		{tags remove "assault"}
		{tags add "stop"}		
		{tags remove "move"}
		{call "start-idle"}
		{if tagged "quiet"
			{if tagged "transform"
				{delay 8
					{spawn "queit_change" "body"}
					{volumes enable contact bullet }	
					{talk "reload"}
					{spawn "orientation_gun_end"   "check_weapon_move" }
					{delay 0.5
						{tags remove "transform"}
					}
					{bone show "torso"}
					{bone show "skin"}
					{bone show "loadout"}
					{bone show "hair"}
					{bone show "head_skin"}
					{bone hide "torso_inv"}
					{bone hide "skin_inv"}
					{bone hide "loadout_inv"}
					{bone hide "hair_inv"}
					{bone hide "head_skin_inv"}
				}
			}
		}
		{delay 1 "check_move" 
			{tags remove "check_move"}
		}
		{view pause "swim_move"}
		{call "stop_move_sounds"}
	}
	(define "play_move_sound"
		{if terrain_fx "road"
			{start_sound "human/move/%0/road_%1"}
		else terrain_fx "country_road"
			{start_sound "human/move/%0/road_%1"}
		else terrain_fx "ice"
			{start_sound "human/move/%0/snow_%1"}
		else terrain_fx "snow"
			{start_sound "human/move/%0/snow_%1"}
		else terrain_fx "sand"
			{start_sound "human/move/%0/sand_%1"}
		else terrain_fx "grass"
			{start_sound "human/move/%0/grass_%1"}
		else terrain_fx "metal"
			{start_sound "human/move/%0/metal_%1"}
		else terrain_fx "shoot_emit_mtl_int"
			{start_sound "human/move/%0/metal_%1"}
		else
			{start_sound "human/move/%0/ground_%1"}
		}
	)

	{on "stop_move_sounds"
		{stop_sound "swim"}
		{set "fast_move_mode" 0}
	}
	{on movement_mode_changed
		(define "terrain_fx_check"
			{if terrain_fx %0 
				{tags add %0}
			else
				{tags remove %0}
			}
		)
		("terrain_fx_check" args "shoot_emit_ext_sand" )
		("terrain_fx_check" args "shoot_emit_int_wood" )
		("terrain_fx_check" args "shoot_emit_ext" )
		("terrain_fx_check" args "shoot_emit_int" )
		("terrain_fx_check" args "shoot_emit_mtl" )
		("terrain_fx_check" args "shoot_emit_mtl_int" )
		("terrain_fx_check" args "floor" )
		("terrain_fx_check" args "volume" )
		("terrain_fx_check" args "snow" )
		("terrain_fx_check" args "land" )
		("terrain_fx_check" args "metal" )
		("terrain_fx_check" args "ground" )
		("terrain_fx_check" args "bridge" )
		("terrain_fx_check" args "bridge_wood" )
		("terrain_fx_check" args "road" )
		("terrain_fx_check" args "country_road" )
		("terrain_fx_check" args "rock" )
		("terrain_fx_check" args "sand" )
		("terrain_fx_check" args "grass" )
		{if tagged "m37_link"
			{delay 0.2
				{if not tagged "move"
					{if tagged "squat"
						{ani_play "squat_link_m37" }
					}
					{if tagged "lying"
						{ani_play "lying_link_m37" }
					else tagged "stand"
						{ani_play "stand_link_m37" }
					}
				}
			}
		}
		{if lying
			{tags remove "squat"}
			{tags add "lying"}
			{set "lying" 1}
		else 
			{if not tagged "squat"
				{tags add "stand"}
			else
				{tags remove "stand"}
			}
			{tags remove "lying"}
			{set "lying" 0}
		}
		{call "stop_move_sounds"}
		{if name "fast"
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags remove "assault"}
			{if tagged "quiet"
				(define "terrain_fx"
					{if tagged %0 
						{start_sound "body_slide/%1/"}	
					}
				)
				("terrain_fx" args "ground" 		dirt 			 	)
				("terrain_fx" args "grass" 			dirt 		 	)
				("terrain_fx" args "road" 			concrete 	 	)
				("terrain_fx" args "country_road" 	concrete 		 	)
				("terrain_fx" args "sand" 			sand 		 	)
				("terrain_fx" args "snow"  			mud 		 	)
				("terrain_fx" args "water" 			water 		 	)
				("terrain_fx" args "bridge" 		wood 		   )
				("terrain_fx" args "bridge_wood" 	wood	   )
				("terrain_fx" args "floor" 			carpet 		   )
				("terrain_fx" args "rock" 			gravel 		   )
				("terrain_fx" args "metal" 			metal_thin 		   )
				("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
				("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
				("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
				("terrain_fx" args "shoot_emit_ext" 				grass 		 )
				("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
				{if tagged "transform"
					{if rand 0.4 
						{if not tagged "deploy"
							{spawn "queit_change" "body"}
							;{ani_play "fast_run"}
							{tags add "deploy"}
							(define "burn_volume"
								{burn volume %0 fx "smoke_mist_run" time 4 fake even_law}
							)
							("burn_volume" args "head" "burn_head")
							("burn_volume" args "body" "burn_body")
							("burn_volume" args "hand1l" "burn_hand1l")
							("burn_volume" args "hand1r" "burn_hand1r")
							("burn_volume" args "hand2l" "burn_hand2l")
							("burn_volume" args "hand2r" "burn_hand2r")
							("burn_volume" args "foot1l" "burn_foot1l")
							("burn_volume" args "foot1r" "burn_foot1r")
							("burn_volume" args "foot2l" "burn_foot2l")
							("burn_volume" args "foot2r" "burn_foot2r")
							{delay 4
								{tags remove "deploy"}	
							}
						}
					}
				}
				{if not tagged "transform"
					{spawn "orientation_gun_start"   "check_weapon_move" x}
					{delay 0.5
						{volumes disable contact bullet}	
					}
					{tags add "transform"}
					{spawn "queit_change" "body"}
					(define "burn_volume"
						{burn volume %0 fx "smoke_mist" time 7 fake even_law}
					)
					("burn_volume" args "head" "burn_head")
					("burn_volume" args "body" "burn_body")
					("burn_volume" args "hand1l" "burn_hand1l")
					("burn_volume" args "hand1r" "burn_hand1r")
					("burn_volume" args "hand2l" "burn_hand2l")
					("burn_volume" args "hand2r" "burn_hand2r")
					("burn_volume" args "foot1l" "burn_foot1l")
					("burn_volume" args "foot1r" "burn_foot1r")
					("burn_volume" args "foot2l" "burn_foot2l")
					("burn_volume" args "foot2r" "burn_foot2r")
					{bone hide "torso"}
					{bone hide "skin"}
					{bone hide "loadout"}
					{bone hide "hair"}
					{bone hide "head_skin"}
					{bone hide "head_skin_butterfly"}
					
					
					{bone show "torso_inv"}
					{bone show "skin_inv"}
					{bone show "loadout_inv"}
					{bone show "hair_inv"}
					{bone show "head_skin_inv"}
				}
			}	
			{if swimming
				{play_sound "swim" 1}
			else not lying
				("play_move_sound" args fast start)
				{set "fast_move_mode" 1}
			}
		else name "normal"
			{tags remove "fast"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags remove "assault"}
			{if tagged "quiet"
				{if tagged "transform"
					{delay 2
						(define "terrain_fx"
							{if tagged %0 
								{start_sound "body_slide/%1/"}	
							}
						)
						("terrain_fx" args "ground" 		dirt 			 	)
						("terrain_fx" args "grass" 			dirt 		 	)
						("terrain_fx" args "road" 			concrete 	 	)
						("terrain_fx" args "country_road" 	concrete 		 	)
						("terrain_fx" args "sand" 			sand 		 	)
						("terrain_fx" args "snow"  			mud 		 	)
						("terrain_fx" args "water" 			water 		 	)
						("terrain_fx" args "bridge" 		wood 		   )
						("terrain_fx" args "bridge_wood" 	wood	   )
						("terrain_fx" args "floor" 			carpet 		   )
						("terrain_fx" args "rock" 			gravel 		   )
						("terrain_fx" args "metal" 			metal_thin 		   )
						("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
						("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
						("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
						("terrain_fx" args "shoot_emit_ext" 				grass 		 )
						("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
						{spawn "queit_change" "body"}
						{volumes enable contact bullet }	
						{if rand 0.5
							{talk "reload"}
						}
						{tags remove "transform"}
						{spawn "orientation_gun_end"   "check_weapon_move" x}
						{bone show "torso"}
						{bone show "skin"}
						{bone show "loadout"}
						{bone show "hair"}
						{bone show "head_skin"}
						{bone hide "skin_inv"}
						{bone hide "loadout_inv"}
						{bone hide "hair_inv"}
						{bone hide "head_skin_inv"}
						{bone hide "torso_inv"}
					}
				}
			}
			{tags add "normal"}		
			{set "fast_move_mode" 0}
		else name "walk"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags remove "assault"}
			{if tagged "quiet"
				{if tagged "transform"
					{delay 1.2
						(define "terrain_fx"
							{if tagged %0 
								{start_sound "body_slide/%1/"}	
							}
						)
						("terrain_fx" args "ground" 		dirt 			 	)
						("terrain_fx" args "grass" 			dirt 		 	)
						("terrain_fx" args "road" 			concrete 	 	)
						("terrain_fx" args "country_road" 	concrete 		 	)
						("terrain_fx" args "sand" 			sand 		 	)
						("terrain_fx" args "snow"  			mud 		 	)
						("terrain_fx" args "water" 			water 		 	)
						("terrain_fx" args "bridge" 		wood 		   )
						("terrain_fx" args "bridge_wood" 	wood	   )
						("terrain_fx" args "floor" 			carpet 		   )
						("terrain_fx" args "rock" 			gravel 		   )
						("terrain_fx" args "metal" 			metal_thin 		   )
						("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
						("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
						("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
						("terrain_fx" args "shoot_emit_ext" 				grass 		 )
						("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
						{spawn "queit_change" "body"}
						{volumes enable contact bullet }	
						{if rand 0.5
							{talk "reload"}
						}
						{tags remove "transform"}
						{spawn "orientation_gun_end"   "check_weapon_move" x}
						{bone show "torso"}
						{bone show "skin"}
						{bone show "loadout"}
						{bone show "hair"}
						{bone show "head_skin"}
						{bone hide "skin_inv"}
						{bone hide "loadout_inv"}
						{bone hide "hair_inv"}
						{bone hide "head_skin_inv"}
						{bone hide "torso_inv"}
					}
				}
			}
			{tags add "walk"}		
			{set "fast_move_mode" 0}
		else name "slow"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags remove "assault"}
			{if tagged "quiet"
				{if tagged "transform"
					{delay 1.2 0.5
						(define "terrain_fx"
							{if tagged %0 
								{start_sound "body_slide/%1/"}	
							}
						)
						("terrain_fx" args "ground" 		dirt 			 	)
						("terrain_fx" args "grass" 			dirt 		 	)
						("terrain_fx" args "road" 			concrete 	 	)
						("terrain_fx" args "country_road" 	concrete 		 	)
						("terrain_fx" args "sand" 			sand 		 	)
						("terrain_fx" args "snow"  			mud 		 	)
						("terrain_fx" args "water" 			water 		 	)
						("terrain_fx" args "bridge" 		wood 		   )
						("terrain_fx" args "bridge_wood" 	wood	   )
						("terrain_fx" args "floor" 			carpet 		   )
						("terrain_fx" args "rock" 			gravel 		   )
						("terrain_fx" args "metal" 			metal_thin 		   )
						("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
						("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
						("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
						("terrain_fx" args "shoot_emit_ext" 				grass 		 )
						("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
						{spawn "queit_change" "body"}
						{volumes enable contact bullet }	
						{if rand 0.5
							{talk "reload"}
						}
						{tags remove "transform"}
						{spawn "orientation_gun_end"   "check_weapon_move" x}
						{bone show "torso"}
						{bone show "skin"}
						{bone show "loadout"}
						{bone show "hair"}
						{bone show "head_skin"}
						{bone hide "skin_inv"}
						{bone hide "loadout_inv"}
						{bone hide "hair_inv"}
						{bone hide "head_skin_inv"}
						{bone hide "torso_inv"}
					}
				}
			}
			{tags add "slow"}		
			{set "fast_move_mode" 0}
		else name "sneak"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags remove "assault"}
			{tags add "sneak"}		
		else name "spot"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "bow"}
			{tags remove "assault"}
			{tags add "spot"}		
		else name "bow"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "assault"}
			{tags add "bow"}		
		else name "assault"
			{tags remove "fast"}
			{tags remove "normal"}
			{tags remove "walk"}
			{tags remove "slow"}
			{tags remove "sneak"}
			{tags remove "spot"}
			{tags remove "bow"}
			{tags add "assault"}		
		else name "stop"
			{if tagged "quiet"
				{if tagged "transform"
					{delay 15 4
						(define "terrain_fx"
							{if tagged %0 
								{start_sound "body_slide/%1/"}	
							}
						)
						("terrain_fx" args "ground" 		dirt 			 	)
						("terrain_fx" args "grass" 			dirt 		 	)
						("terrain_fx" args "road" 			concrete 	 	)
						("terrain_fx" args "country_road" 	concrete 		 	)
						("terrain_fx" args "sand" 			sand 		 	)
						("terrain_fx" args "snow"  			mud 		 	)
						("terrain_fx" args "water" 			water 		 	)
						("terrain_fx" args "bridge" 		wood 		   )
						("terrain_fx" args "bridge_wood" 	wood	   )
						("terrain_fx" args "floor" 			carpet 		   )
						("terrain_fx" args "rock" 			gravel 		   )
						("terrain_fx" args "metal" 			metal_thin 		   )
						("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
						("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
						("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
						("terrain_fx" args "shoot_emit_ext" 				grass 		 )
						("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
						{spawn "queit_change" "body"}
						{volumes enable contact bullet }	
						{talk "reload"}
						{spawn "orientation_gun_end"   "check_weapon_move" x}
						{delay 0.5
							{tags remove "transform"}
						}
						{bone show "torso"}
						{bone show "skin"}
						{bone show "loadout"}
						{bone show "hair"}
						{bone show "head_skin"}
						{bone hide "skin_inv"}
						{bone hide "loadout_inv"}
						{bone hide "hair_inv"}
						{bone hide "head_skin_inv"}
						{bone hide "torso_inv"}
					}
				}
			}
		}
	}




	{on "move_signal"
		{if tagged "fast"
			{signal shot 520}
		else tagged "assault"
			{signal shot 570}
		else tagged "bow"
			{signal shot 550}
		else tagged "normal"
			{signal shot 515}
		else tagged "walk"
			{signal shot 56}
		else tagged "spot"
			{signal shot 50}
		else tagged "slow"
			{signal shot 52}
		else tagged "sneak"
			{signal shot 50}
		}
	}
	{on "check_bleeding_legs"
		{if tagged "bleeding_small_foot2l"
			{movement_limit slow}
			{if rand 0.4
				{talk "hit_legs"}
				{call "knockdown"}
			}
		else tagged "bleeding_small_foot2r"
			{movement_limit slow}
			{if rand 0.4
				{talk "hit_legs"}
				{call "knockdown"}
			}
		else tagged "bleeding_small_foot1l"
			{movement_limit slow}
			{if rand 0.2
				{talk "hit_legs"}
				{call "knockdown"}
			}
		else tagged "bleeding_small_foot1r"
			{movement_limit slow}
			{if rand 0.2
				{talk "hit_legs"}
				{call "knockdown"}
			}
		else 
			{movement_limit fast}			
		}
	}
	{on "falldown"
		{if altitude 3
			{throw_off up 1 forward 0.01 die force}
		else altitude 1
			{throw_off up 1 forward 0.01 force}
		else
			{throw_on_ground}
		}
	}


	{on board in
		(define "board_in"
			{if effector "%board"			
				{start_sound "doors/%board/in/"}	
			}
			{view pause "swim"}
		)	
		("board_in" board(civilian)		)
		("board_in" board(arm_car)			)
		("board_in" board(armored)			)
		("board_in" board(heavy)			)
	}
	{on board out
		(define "board_out"
			{if effector "%board"			
				{start_sound "doors/%board/out/"}	
			else effector "mtb_d3"
				{if name "emit1" "emit2" "emit3" "emit4"
					{delay 0.7
						{spawn "spherewater_big"}
					}
				}
			}
		)	
		("board_out" board(civilian)		)
		("board_out" board(arm_car)			)
		("board_out" board(armored)			)
		("board_out" board(heavy)			)
	}
	{on "idle"
		{set "idle" 1}
		{if not "blocked"
			{if rand 0.5
				{if bone "j_cosmetic_hair_front_le1_ciri_recoil" visible
					{ani_play "idle_prop_ciri" 0.3 callback}
				else bone "j_cosmetic_hair_back_1_quiet_link" visible 
					{ani_play "idle_prop" 0.3 callback}
				}
			 else
				{if bone "j_cosmetic_hair_front_le1_ciri_recoil" visible
					{ani_play "idle_prop2_ciri" 0.3 callback}
				else bone "j_cosmetic_hair_back_1_quiet_link" visible 
					{ani_play "idle_prop2" 0.3 callback}
				}
			}
		}
	}
	
	
	{on "safe-idle"
		{if "idle"
			{call "idle"}
		}
	}
	{on "start-idle"
		{set "idle" 1}
		{delay_effect 1 "safe-idle"}
	}
	{on animation_end "idle_prop"
		{delay_effect 4 1.5 "safe-idle"}
	}
	{on animation_end "idle_prop2"
		{delay_effect 4 1.5 "safe-idle"}
	}
	{on "stop_idle"
		{set "idle" 0}
		{ani_stop "idle_prop"}
		{ani_stop "idle_prop2"}
	}	
	{on "kill_neutral"
		{view start ally neutral "marker_kill_neutral"}
		{delay 5.0
			{view pause "marker_kill_neutral"}
		}
	}
	{on "disable_physics"					;// stops sliding after landing on ground. forces soldier to ground
		{delay 1.3
			{physics_work 0}
			{delay 0
				{physics_work 1}
				{throw_off up 0.5 0.2 forward 1 0.5}
			}
		}
	}
	{on "start_healing"
		{tags add "healing"}
		{tags remove "repair"}
		{link_sound "healing" "human/action/healing/"}
		{play_sound "healing" 1}
		{view start ally neutral "marker_healing"}
		{delay 1	
			{tags remove "bleeding_small_head"}	
			{tags remove "bleeding_small_body_random"}	
			{tags remove "bleeding_small"}	
			{tags remove "bleeding_small_body"}	
			{tags remove "bleeding_small_foot2r"}	
			{tags remove "bleeding_small_foot1l"}	
			{tags remove "bleeding_small_foot1r"}	
			{tags remove "bleeding_small_foot2l"}	
			{tags remove "bleeding_small_hand2r"}	
			{tags remove "bleeding_small_hand1l"}	
			{tags remove "bleeding_small_hand1r"}	
			{tags remove "bleeding_small_hand2l"}	
		}
		{delay 2	
			{if rand 0.8
				{call "armorplate_ai"}
			}
		}
	}
	{on "stop_healing"
		{tags remove "healing"}
		{stop_sound "healing"}
		{view pause "marker_healing"}
	}
	{on "start_repair"
		{tags remove "healing"}
		{tags add "repair"}
		{view start ally neutral "marker_repair"}
	}
	{on "stop_repair"
		{view hide "wrench2"}
		{view hide "wrench1"}
		{tags remove "repair"}
		{view pause "marker_repair"}
	}
	{on "attach_clear"
		{if effector "smallitemin1hand"
			{with_effector
				{delay 1 
					{hide 0.1}
				}
			}
		}
	}	
	{on "broken_weapon"
		{reset_manual_control}
		{tags add "click_jammed"}
		{tags add "broken_weapon"}
		{call "click_jammed"}
		;{weapon_work "hand_right" 0}
		{tags add "click_jammed"}
		{with_effector
			{view start "shell"}
			{delay 0.1 "shell"
				{view pause "shell"}
				{tear "piece_small_steel" bone "part"
					{impulse up 2 1 dir 2 1}
				}
				{delay 1.4
					{call "broken_drop"}
				}
			}
			{start_sound "weapon/attach/"}
		}
		{delay 1 "broken"
			{tags remove "click_jammed"}
			{start_sound "weapon/boltopen"}
			{if not dead
				{ani_play "stand_pick_small_begin" 1.2}
			}
			{delay 0.7 "stand_pick_small_end"
				{if not dead
					{ani_play "stand_pick_small_end" 1.2}
				}
				{delay 0.8 "stand_pick_small_end"
					{tags remove "click_jammed"}
					{chassis_work 1}
					{tags remove "broken_weapon"}
					;{weapon_work "hand_right" 1}
					{if not dead
						{ani_play "stand_idle_empty_1" 2}
					}
				}
			}
		}
	}
	{on "rand_jammed"
		{if not active	
			{if rand 0.0001
				{tags add "click_jammed"}
				{call "click_jammed"}
				{chassis_work 0}
				{weapon_work "hand_right" 0}
				{with_effector
					{view start "shell"}
					{delay 0.1 "shell"
						{view pause "shell"}
					}
					{start_sound "weapon/attach/"}
					{view start "jammed"}
					{delay 2
						{view stop "jammed"}
					}
				}
				{delay 2 "click_jammed"
					{start_sound "weapon/boltopen"}
					{ani_play "stand_reload_gun" 0.3}
					{tags remove "click_jammed"}
				}
				{delay 4 "chassis_work"
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
			}
		}
	}
	{on "click_jammed"
		{if tagged "click_jammed"
			{delay 0.3 0.1
				{start_sound "weapon/click/empty_gun_shot"}
				{call "click_jammed"}
			}
		}
	}


	{on "rand_art"
		{if not user_control	
			{if not lying
				{if not tagged "rand_art"	
					{if rand 0.0001
						{ani_play "squat_take_gun" 1}
						{tags add "rand_art"}	
						{ani_play "squat_take_small" 1}
						{chassis_work 0}
						{weapon_work "hand_right" 0}
						{delay 0.6 "chassis_work"
							{ani_play "squat_throw_grenade_1_begin" 1}
							{start_sound "weapon/attach/"}
							{delay 0.8 "chassis_work"
								{spawn "target_grenade_art" "foot1l" x}
								{ani_play "squat_throw_grenade_1_end" 1}
								{delay 1 
									{ani_play "squat_fire_gun" }
									{chassis_work 1}
									{weapon_work "hand_right" 1}
								}
							}
							{delay 600 
								{tags remove "rand_art"}	
							}							
						}							
					}
				}
			}
		}
	}
	{on "rand_ph"
		{if not user_control	
			{if not lying
				{if not tagged "rand_ph"	
					{if rand 0.0001
						{ani_play "squat_take_gun" 1}
						{tags add "rand_ph"}	
						{ani_play "squat_take_small" 1}
						{chassis_work 0}
						{weapon_work "hand_right" 0}
						{delay 0.6 "chassis_work"
							{ani_play "squat_throw_grenade_1_begin" 1}
							{start_sound "weapon/attach/"}
							{delay 0.8 "chassis_work"
								{spawn "target_grenade" "foot1l" x}
								{ani_play "squat_throw_grenade_1_end" 1}
								{delay 1 
									{ani_play "squat_fire_gun" }
									{chassis_work 1}
									{weapon_work "hand_right" 1}
								}
							}
							;{delay 600 
							;	{tags remove "rand_ph"}	
							;}							
						}							
					}
				}
			}
		}
	}
	{on "rand_sm"
		{if not user_control	
			{if not lying
				{if not tagged "rand_sm"	
					{if rand 0.001
						{delay 1.6 "chassis_work"
							{if not dead
								{ani_play "squat_take_small" 1}
							}
							{chassis_work 0}
							{weapon_work "hand_right" 0}
							{delay 0.6 "chassis_work"
								{talk "throwing_a_grenade_smoke"}
								{if not dead
									{ani_play "squat_throw_grenade_1_begin" 1}
								}
								{start_sound "weapon/attach/"}
								{tags add "rand_sm" }
								{delay 0.8 "chassis_work"
									{spawn "grenade_smoke_ai" "foot1l" x}
									{if not dead
										{ani_play "squat_throw_grenade_1_end" 1}
									}
									{delay 1 
										{if not dead
											{ani_play "squat_fire_gun" }
										}
										{chassis_work 1}
										{weapon_work "hand_right" 1}
									}
								}
								{delay 120.0 "set"
									{tags remove "rand_sm" }
								}							
							}							
						}							
					}
				}
			}
		}
	}
	{on "jump"
		{if not dead
			{if not tagged "jump"
				{tags add "jump"}
				{ani_play "getover_middle_1" callback}
				{delay 5 
					{tags remove "jump"}
				}
			}
		}
	}	
	{on "falls"
		{if not dead
			{if not tagged "falls"
				{ani_play "010_bm_arm-bayonets_2" callback}
				{tags add "falls"}
				{delay 4 
					{tags remove "falls"}
				}
			}
		}
	}	
;	{on ik begin "aim_ref_h"
;				{tags add "aim_ref_h"}
;	}
;	{on ik begin "aim_ref_v"
;				{tags add "aim_ref_v"}
;	}
;	{on ik end "aim_ref_h"
;		{tags remove "aim_ref_h"}
;	}
;	{on ik end "aim_ref_v"
;		{tags remove "aim_ref_v"}
;	}
	{on "stim_ai"
		{if not able "burning"
			{if not "blocked"
				{if not linked
					{if not tagged "stim"
						{tags add "stim"}
						{delay 1.5
							{if not dead
								{if not tagged "check_move"
									{if not tagged "fire_hold"
										{if not able "burning"
											{if not "blocked"
												;{chassis_work 0}
												{if tagged "link_weapon"											
													{weapon_work "hand_right" 0}
													{ani_play "stand_take_gun_up" -1}
												}
											}
										}
										{add_view 	"stim" 		"stim" "right_hand"}
										{view start "stim"}
										{reset_manual_control}
										{delay 0.2 
											{if not dead
												{start_sound "human/medic/Human_Stimpak"}
											;{ani_play "squat_put_small" 1}
											}
										}
										{delay 0.4 
											{if not able "burning"
												{if not dead
													{call "heal_bleeding"}
													{if not "blocked"
														{ani_play "squat_self-treatment_hand_begin" 2}
													}
												}
											}
										}
									}
								}
								{delay 1.1
									{if not dead
										{if not able "burning"
											{view hide	"stim"}
											{view pause	"stim"}
											;{chassis_work 1}
											;{weapon_work "hand_right" 1}								
											{if not "blocked"
												{if tagged "link_weapon"											
													{weapon_work "hand_right" 1}
													{ani_play "stand_take_gun_up" 1.2}
												}
											}
										}
									}
								}
							}
						}
					}			
					{delay 25
						{tags remove "stim"}
					}
				}
			}
		}
	}
	{on "stim"
		{if not dead
			{if not tagged "stim"
				{chassis_work 0}
				{weapon_work "hand_right" 0}
				{ani_stop "stand_idle_empty_1" }
				{ani_stop "stand_idle_strap_1" }
				{ani_stop "stand_idle_1hand" }
				{if not "blocked"							
					{ani_play "squat_from_stand_empty" 0.5}
				}
				{add_view 	"stim" 		"stim" "right_hand"}
				{view start "stim"}
				{reset_manual_control}
				{delay 0.3 
					{start_sound "human/medic/Human_Stimpak"}
					{ani_play "squat_put_small" 0.7}
				}
				{delay 0.5 
					{call "heal_bleeding"}
					{ani_play "squat_self-treatment_hand_end" 0.5}
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 1
					{view hide	"stim"}
					{view pause	"stim"}
				
				}
				{delay 5
					{tags remove "stim"}
				}
			}
		}
	}
	{on "heal_bleeding"
		{health_damage_count -80
			{effects "" }
		}
		{tags remove "bleeding_small_body_random_ap"}	
		{tags remove "bleeding_small_body_sm_ic"}	
		{tags remove "bleeding_small_head"}	
		{tags remove "bleeding_small"}	
		{tags remove "bleeding_small_body"}	
		{tags remove "bleeding_small_foot2r"}	
		{tags remove "bleeding_small_foot1l"}	
		{tags remove "bleeding_small_foot1r"}	
		{tags remove "bleeding_small_foot2l"}	
		{tags remove "bleeding_small_hand2r"}	
		{tags remove "bleeding_small_hand1l"}	
		{tags remove "bleeding_small_hand1r"}	
		{tags remove "bleeding_small_hand2l"}	
	
	}
	{on "armorplate"
		{if not "blocked"
			{if not dead
				{if not tagged "armorplate_pierce"
					{add_view 	"armorplate" 		"armorplate" "right_hand"}
					{view start "armorplate"}
					{ani_stop "stand_idle_empty_1" }
					{ani_stop "stand_idle_strap_1" }
					{ani_stop "stand_idle_1hand" }
					{ani_play "armorplate" 0.5}
					{reset_manual_control}
					{chassis_work 0}
					{weapon_work "hand_right" 0}
					{delay 0.3 
						{start_sound "push/armor/armor_pickup"}
					}
					{delay 1 
						{if not dead
							{start_sound "push/armor/armor_use"}
							{tags add "armorplate_pierce"}
							{health_damage_count -150
								{effects "" }
							}
							{chassis_work 1}
							{weapon_work "hand_right" 1}
						}
					}
					{delay 1.5 
						{view hide	"armorplate"}
						{view pause	"armorplate"}
					
					}
				}
			}
		}	
	}	
	{on "armorplate_ai"
		{if not tagged "lying" 
			{if not "blocked"
				{if not dead
					{if not tagged "armorplate_pierce"
						{add_view 	"armorplate" 		"armorplate" "right_hand"}
						{view start "armorplate"}
						{ani_stop "stand_idle_empty_1" }
						{ani_stop "stand_idle_strap_1" }
						{ani_stop "stand_idle_1hand" }
						{ani_play "armorplate" 0.8}
						{reset_manual_control}
						{chassis_work 0}
						{weapon_work "hand_right" 0}
						{delay 0.2 
							{start_sound "push/armor/armor_pickup"}
						}
						{delay 0.8 
							{if not dead
								{start_sound "push/armor/armor_use"}
								{tags add "armorplate_pierce"}
								{health_damage_count -150
									{effects "" }
								}
								{chassis_work 1}
								{weapon_work "hand_right" 1}
							}
						}
						{delay 1.2 
							{view hide	"armorplate"}
							{view pause	"armorplate"}
						
						}
					}
				}
			}	
		}	
	}	

	{on "stimpack"
		{if not dead
			{if not tagged "stimpack"
				{ani_play "squat_from_stand_empty" 0.5}
				{chassis_work 0}
				{weapon_work "hand_right" 0}
				{delay 0.3 
					{start_sound "human/medic/Human_Stimpak"}
					{ani_play "squat_put_small" 0.7}
				}
				{delay 0.5 
					{tags add "stimpack"}
					{call "heal_stimpack"}
					{ani_play "squat_self-treatment_hand_end" 0.5}
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 5
					{tags remove "stimpack"}
				}
			}
		}
	}	

	{on "heal_stimpack"
		{if tagged "stimpack"
			{health_damage_count -5
				{effects "" }
			}
			{delay 0.5
				{call "heal_stimpack"}
			}
		}
	}


	{on "nukacola"
		{if not dead
			{if not tagged "nukacola"
				{ani_play "102_drink" callback}
				{tags add "nukacola"}
				{call "heal_nukacola"}
				{delay 3 
					{spawn "nukacola_empty" "Hand3R"}
				}
				{delay 15 
					{tags remove "nukacola"}
				}
			}
		}
	}	
	{on "heal_nukacola"
		{if tagged "nukacola"
			{health_damage_count -1
				{effects "" }
			}
			{delay 0.3
				{call "heal_nukacola"}
			}
		}
	}
	{on "nukacola_victory"
		{if not dead
			{if not tagged "nukacola_victory"
				{ani_play "102_drink" callback}
				{tags add "nukacola_victory"}
				{call "heal_nukacola_victory"}
				{delay 3 
					{spawn "nukacola_empty" "Hand3R"}
				}
				{delay 15 
					{tags remove "nukacola_victory"}
				}
			}
		}
	}	
	{on "heal_nukacola_victory"
		{if tagged "nukacola_victory"
			{health_damage_count -15
				{effects "" }
			}
			{delay 0.3
				{call "heal_nukacola_victory"}
			}
		}
	}	
	
	{on "hit_head"
		{if not tagged "hit_head"
			{talk "hit_head"}
			{tags add "hit_head" }
			{delay 5.0 "hit_head"
				{tags remove "hit_head" }
			}			
		}
	}
	{on "mine_planted"
		{if not "mine_planted"
			{talk "mine_planted"}
			{set "mine_planted" 1}
			{delay 1.0 "mine_planted"
				{set "mine_planted" 0}
			}			
		}
	}
	{on "reload_s"
		{delay 0.5
			{if not "talk"
				{talk "reload"}
				{set "talk" 1}
				{delay 3 "reload_s"
					{set "talk" 0}
				}			
			}			
		}
	}
	{on "texmods_s"
		{if not "texmods"
			{set "texmods" 1}
			{if rand 0.3
				{tex_mod "1"}
			else rand 0.3
				{tex_mod "2"}
			else rand 0.3
				{tex_mod "3"}
			else rand 0.3
				{tex_mod "4"}
			else rand 0.3
				{tex_mod "5"}
			else rand 0.3
				{tex_mod "6"}
			}
		}
	}
	{on "radio_signal"
		{if rand 0.1
			{if not tagged "radio_signal"
				{talk "radio_signal"}
				{tags add "radio_signal" }
				{delay 60 "radio_signal"
					{tags remove "radio_signal" }
				}			
			}
		}
	}
	{on "autofire"
		{tags add "0_auto"}
		{if not tagged "auto_fire_3" 
			{if not tagged "auto_fire"
				{start_sound "weapon/armed/fire_change"}				
				{tags add "auto_fire"}
			else not tagged "auto_fire_3"
				{start_sound "weapon/armed/fire_change"}				
				{delay 0.05 
					{start_sound "weapon/armed/fire_change"}				
					{delay 0.05
						{start_sound "weapon/armed/fire_change"}	
					}
				}
				{tags remove "auto_fire"}
				{tags add "auto_fire_3"}
			}
		else 
			{tags remove "auto_fire"}
			{tags remove "auto_fire_3"}
		}
	}
	{on "shoot_m203"
		{start_sound "weapon/armed/fire_change"}				
		{tags add "ready_shot"}	
	}
	{on "shoot_masterkey"
		{if not tagged "empty_key"
			{tags add "0_auto"}
		}		
		{start_sound "weapon/armed/fire_change"}				
		{tags add "ready_shot"}	
	}
	{on "change_ammo_thermite"
		{if tagged "empty_m203" 
			{drop_orders}
			{if not dead
				{delay 0.3 
					{chassis_work 0}
					{weapon_work "hand_right" 0}
					{if not tagged "lying" 
						{ani_play "squat_put_small" 0.7}
					}
				}
				{delay 0.7 
					{start_sound "weapon/reload/small_arms/m203/m203"}				
					{if tagged "lying" 
						{ani_play "lie_reload_piat" 0.5}
					else					
						{ani_play "squat_reload_piat" 0.5}
					}
					{bone show "m203"}
					{bone hide "m203_empty"}
				}
				{delay 3 
					{start_sound "weapon/mag_clip/sniper_series/out"}				
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 4
					{tags remove "empty_m203"}
					{tags add "ready_m203_thermite"}	
				}
			}	
		}			
	}			
	{on "change_ammo_flash"
		{if tagged "empty_m203" 
			{drop_orders}
			{if not dead
				{delay 0.3 
					{chassis_work 0}
					{weapon_work "hand_right" 0}
					{if not tagged "lying" 
						{ani_play "squat_put_small" 0.7}
					}
				}
				{delay 0.7 
					{start_sound "weapon/reload/small_arms/m203/m203"}				
					{if tagged "lying" 
						{ani_play "lie_reload_piat" 0.5}
					else					
						{ani_play "squat_reload_piat" 0.5}
					}
					{bone show "m203"}
					{bone hide "m203_empty"}
				}
				{delay 3 
					{start_sound "weapon/mag_clip/sniper_series/out"}				
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 4
					{tags remove "empty_m203"}
					{tags add "ready_m203_flash"}	
				}
			}	
		}			
	}			
	{on "change_ammo"
		{if tagged "empty_m203" 
			{drop_orders}
			{if not dead
				{delay 0.3 
					{chassis_work 0}
					{weapon_work "hand_right" 0}
					{if not tagged "lying" 
						{ani_play "squat_put_small" 0.7}
					}
				}
				{delay 0.7 
					{start_sound "weapon/reload/small_arms/m203/m203"}				
					{if tagged "lying" 
						{ani_play "lie_reload_piat" 0.5}
					else					
						{ani_play "squat_reload_piat" 0.5}
					}
					{bone show "m203"}
					{bone hide "m203_empty"}
				}
				{delay 3 
					{start_sound "weapon/mag_clip/sniper_series/out"}				
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 4
					{tags remove "empty_m203"}
					{tags add "ready_m203_fg"}	
				}
			}	
		}			
	}	

	{on "reload_masterkey"
		{if tagged "empty_key" 
			{drop_orders}
			{if not dead
				{delay 0.3 
					{chassis_work 0}
					{weapon_work "hand_right" 0}
					{if not tagged "lying" 
						{ani_play "squat_put_small" 0.7}
					}
				}
				{delay 0.7 
					{if tagged "lying" 
						{ani_play "lie_reload_piat" 0.7}
					else					
						{ani_play "squat_reload_piat" 0.7}
					}
				}
				{delay 1.2 
					{start_sound "weapon/bolt_move/ithaca/forward/"}				
					{chassis_work 1}
					{weapon_work "hand_right" 1}
				}
				{delay 2.4
					{start_sound "weapon/bolt_move/ithaca/back/"}				
					{tags remove "empty_auto"}
					{tags remove "empty_key"}
					{tags add "0_auto"}	
				}
			}	
		}			
	}	



	{on "bolt_anim"
		{if not tagged "reload"
			{if tagged "quiet"
				{spawn "queit_change" "body"}
				(define "burn_volume"
					{burn volume %0 fx "smoke_mist" time 2 fake even_law}
					{delay 2 
						{stop_sound "small" }
					}
				)
				("burn_volume" args "head" )
				("burn_volume" args "body" )
				("burn_volume" args "hand1l")
				("burn_volume" args "hand1r")
				("burn_volume" args "hand2l")
				("burn_volume" args "hand2r")
				("burn_volume" args "foot1l" )
				("burn_volume" args "foot1r" )
				("burn_volume" args "foot2l" )
				("burn_volume" args "foot2r" )
				{if not tagged "transform"
					{bone show "head_skin_butterfly"}
					{bone hide "head_skin"}
				}
				{delay 5 3.5
					{if not tagged "transform"
						{bone hide "head_skin_butterfly"}
						{bone show "head_skin"}
					}
				}
				;{if rand 0.3
					{talk "reload"}
				;}
			}
			{if tagged "squat"										;edited from goh
				 {ani_play "squat_bolt_rifle" 0.9 }					;edited from goh
			 }					;edited from goh
			{if tagged "lying"										;edited from goh
				 {if not tagged "move"									;edited from goh
					; {ani_play "lie_bolt_rifle" 0.9 }					;edited from goh
				 }					;edited from goh
			 else					;edited from goh
				 {ani_play "stand_bolt_rifle_up" 0.9 }					;edited from goh
			 }					;edited from goh
		}
	}
	{on "start_ammo_out"
		;{if rand 0.8
			{talk "ill_take_ammo"}
		;}
		{view start ally neutral "marker_ammo_out"}
	}
	{on "stop_ammo_out"
		{view pause "marker_ammo_out"}
	}
	{on "start_ammo_refill"
		{view start ally neutral "marker_ammo_refill"}
		{delay 2.5
			{view pause "marker_ammo_refill"}
		}
	}
	{on "start_rad"
		{view start "marker_rad"}
		{delay 2.5
			{view pause "marker_rad"}
		}
	}
	{on "start_personage"
		{view pause "marker_repair"}
		{view pause "marker_personage_acute"}
		{view start ally neutral "marker_personage"}
		{tags add "start_personage"}
	}

	{on "stop_personage"
		{set "die_sound" 0}
		{view pause "marker_personage"}
		{view pause "marker_personage_acute"}
		{if tagged "start_personage"
			{delay 1
				{if dead
					{tags remove "lie_wounded_enter"}
					{tags add "lie_wounded_exit"}
					{ani_stop "lie_wounded" }
					{ani_stop "lie_wounded_1" }
					{ani_stop "lie_wounded_2" }		
					;{spawn "bloodstain" "basis" x}		;// spawns a pool of blood that spreads
					{tags add "_bleedout_"}
				}
			}
		}
		{tags remove "start_personage"}
	}

	{on "start_personage_acute"
		{view pause "marker_personage"}
		{view start ally neutral "marker_personage_acute"}
	}
	{on "fx_veterancy"
		{view start "fxt_veterancy"}
		{delay 1
			{view pause "fxt_veterancy"}
		}
		{start_sound "gui/veterancy/start"}	
	}
	{on "start_veterancy"
		{call "fx_veterancy"}
		{if tagged "veterancy_empty"
			{view start ally neutral "marker_veterancy_1"}
			{delay 2
				{view pause "marker_veterancy_1"}
			}
			{tags add "veterancy_load"}
			{tags add "veterancy_1"}
			{tags remove "veterancy_empty"}
		else tagged "veterancy_1"
			{view start ally neutral "marker_veterancy_2"}
			{delay 2
				{view pause "marker_veterancy_2"}
			}
			{tags remove "veterancy_1"}
			{tags add "veterancy_2"}
		else tagged "veterancy_2"
			{view start ally neutral "marker_veterancy_3"}
			{delay 2
				{view pause "marker_veterancy_3"}
			}
			{tags remove "veterancy_2"}
			{tags add "veterancy_3"}
		else tagged "veterancy_3"
			{view start ally neutral "marker_veterancy_4"}
			{delay 2
				{view pause "marker_veterancy_4"}
			}
			{tags remove "veterancy_3"}
			{tags add "veterancy_4"}
		else tagged "veterancy_4"
			{view start ally neutral "marker_veterancy_5"}
			{delay 2
				{view pause "marker_veterancy_5"}
			}
			{tags remove "veterancy_4"}
			{tags add "veterancy_5"}
		else tagged "veterancy_5"
			{view start ally neutral "marker_veterancy_6"}
			{delay 2
				{view pause "marker_veterancy_6"}
			}
			{tags remove "veterancy_5"}
			{tags add "veterancy_6"}
		else tagged "veterancy_6"
			{view start ally neutral "marker_veterancy_7"}
			{delay 2
				{view pause "marker_veterancy_7"}
			}
			{tags remove "veterancy_6"}
			{tags add "veterancy_7"}
		else tagged "veterancy_7"
			{view start ally neutral "marker_veterancy_8"}
			{delay 2
				{view pause "marker_veterancy_8"}
			}
			{tags remove "veterancy_7"}
			{tags add "veterancy_8"}
		}
	}
	{on "stop_veterancy"
		{view pause "marker_veterancy"}
	}
	{on "hide_veterancy"
		{view hide "marker_veterancy"}
	}
	{on "start_blinded"
		{tags add "bleeding_marker"}
		{view start ally neutral "marker_blinded"}
	}
	{on "stop_blinded"
		{tags remove "lie_wounded_enter"}
		{tags add "lie_wounded_exit"}
		{tags remove "bleeding_marker"}
		{view pause "marker_blinded"}
	}
	{on "capture"
		{tags add "capturer"}
	}
	{on animation_end "stand_smoke_3"
	}
	{on terrain_fx "irradiation" enter
		{call "start_rad"}	
		{call "radio-hit-small"}
	}
	
	{on terrain_fx "electra" enter
		{view start "blast"}
		{talk "hit"}
		{spawn "electra_blast_sound" "body"}
		{tags add "bleeding_small_e"}
		{call "bleeding_small_e"}
		{delay 8 "tags"
			{tags remove "bleeding_small_e"}
		}
		{delay 2
			{talk "hit"}
			{view pause "blast"}
		}
		{health_damage_count 150
			{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
		}
		{volumes disable overlap}
		{delay 1
			{volumes enable overlap}
		}
	}
	{on overlap begin	
		{if effector "rad10"
			{call "radio-hit-big"}
			{call "start_rad"}	
			{health_damage_count 300
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
			{volumes disable overlap}
			{delay 3 {volumes enable overlap}}
		else effector "s5_rocket"
			{talk "hit"}
			{spawn "explosion_flash" }
		else effector "posion_gas"
			{call "contact_gases"}
		else effector "open_doors_human"
			{if active	
				{if tagged "stop"	
					{if tagged "stand"	
						{if not tagged "anim_script"	
							{ani_play "stand_take_small"}
							{delay 2 {tags remove "anim_script"}}
						}	
					}	
				}
			}
		else effector "bush"	
			{if active	
				{if tagged "fast"	
					{signal shot 50}
				}
			}
		else effector "gravi_01"
			{health_damage_count 1300
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
	}
	{on overlap end ; not work	
	}
	{on "radio-hit-big"
		{delay 0.1
			{health_damage_count 50
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 1	
			{health_damage_count 50
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 2	
			{health_damage_count 45
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 3	
			{health_damage_count 45
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 4	
			{health_damage_count 40
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 5	
			{health_damage_count 35
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 6	
			{health_damage_count 30
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
	}
	{on "radio-hit-medium"
		{delay 0.1
			{health_damage_count 30
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 1	
			{health_damage_count 30
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 2	
			{health_damage_count 30
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 3	
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 4	
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 5	
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 6	
			{health_damage_count 15
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
	}
	{on "radio-hit-small"
		{delay 0.1
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 1	
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 2	
			{health_damage_count 20
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 3	
			{health_damage_count 15
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 4	
			{health_damage_count 15
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 5	
			{health_damage_count 10
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
		{delay 6	
			{health_damage_count 10
				{effects "" "hit" "damage" "die_without_blood" "die_without_blood"}
			}
		}
	}
	{on "bleeding"
		{add_view 	"blood_s_hit" "blood" "ik_updown"}
		{view start	"blood"}
		{delay 12
			{view pause	"blood"}
		}
		{health_damage_count 54		
			{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
		}
		{delay 2			
			{health_damage_count 43
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{delay 4			
			{health_damage_count 32
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{delay 6 			
			{health_damage_count 31
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{delay 8 			
			{health_damage_count 23
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{delay 10 			
			{health_damage_count 22
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
		{delay 12 			
			{health_damage_count 21
				{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
			}
		}
	}
	{on "bleeding_small_body_random"
		{if tagged "bleeding_small_body_random"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{if rand 0.005
				{if not tagged "no_talks"
					{talk "hit"}
				}
			}
			{spawn "blood_small_hit" "body"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_body_random"}
		else
			{kill_delay "bleeding_small_body_random"}
		}
	}
	{on "bleeding_small_body_random_ap"
		{if tagged "bleeding_small_body_random_ap"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{if rand 0.005
				{if not tagged "no_talks"
					{talk "hit"}
				}
			}
			{spawn "blood_small_hit" "body"}				
			{health_damage_count 1.2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_body_random_ap"}
		else
			{kill_delay "bleeding_small_body_random_ap"}
		}
	}
	{on "bleeding_small_head"
		{if tagged "bleeding_small_head"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "head"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_head"}
		else
			{kill_delay "bleeding_small_head"}
		}
	}
	{on "bleeding_small_body_sm_ic"
		{if tagged "bleeding_small_body_sm_ic"
			{spawn "blood_small_hit" "body"}				
			{health_damage_count 1.5
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_body_sm_ic"}
		else
			{kill_delay "bleeding_small_body_sm_ic"}
		}
	}
	{on "bleeding_small_body"
		{if tagged "bleeding_small_body"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "body"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_body"}
		else
			{kill_delay "bleeding_small_body"}
		}
	}
	{on "bleeding_small_foot1l"
		{if tagged "bleeding_small_foot1l"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1l"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_small_foot1l"}
		else
			{kill_delay "bleeding_small_foot1l"}
		}
	}
	{on "bleeding_small_foot1r"
		{if tagged "bleeding_small_foot1r"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1r"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_foot1r"}
		else
			{kill_delay "bleeding_small_foot1r"}
		}
	}
	{on "bleeding_small_foot2l"
		{if tagged "bleeding_small_foot12"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2l"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_foot2l"}
		else
			{kill_delay "bleeding_small_foot2l"}
		}
	}
	{on "bleeding_small_foot2r"
		{if tagged "bleeding_small_foot2r"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2r"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_foot2r"}
		else
			{kill_delay "bleeding_small_foot2r"}
		}
	}
	{on "bleeding_small_hand1l"
		{if tagged "bleeding_small_hand1l"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1l"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_hand1l"}
		else
			{kill_delay "bleeding_small_hand1l"}
		}
	}
	{on "bleeding_small_hand1r"
		{if tagged "bleeding_small_hand1r"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1r"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_hand1r"}
		else
			{kill_delay "bleeding_small_hand1r"}
		}
	}
	{on "bleeding_small_hand2l"
		{if tagged "bleeding_small_hand12"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2l"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_hand2l"}
		else
			{kill_delay "bleeding_small_hand2l"}
		}
	}
	{on "bleeding_small_hand2r"
		{if tagged "bleeding_small_hand2r"
			{if rand 0.02
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2r"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.2 "bleeding_small_hand2r"}
		else
			{kill_delay "bleeding_small_hand2r"}
		}
	}
	{on "bleeding_big_head"
		{if tagged "bleeding_big_head"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "head"}				
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_big_head"}
		else
			{kill_delay "bleeding_big_head"}
		}
	}
	{on "bleeding_big_body"
		{if tagged "bleeding_big_body"
			{if rand 0.05
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "body"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_big_body"}
		else
			{kill_delay "bleeding_big_body"}
		}
	}
	{on "bleeding_big_foot1l"
		{if tagged "bleeding_big_foot1l"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1l"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_big_foot1l"}
		else
			{kill_delay "bleeding_big_foot1l"}
		}
	}
	{on "bleeding_big_foot1r"
		{if tagged "bleeding_big_foot1r"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1r"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.1 "bleeding_big_foot1r"}
		else
			{kill_delay "bleeding_big_foot1r"}
		}
	}
	{on "bleeding_big_foot2l"
		{if tagged "bleeding_big_foot2l"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2l"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_foot2l"}
		else
			{kill_delay "bleeding_big_foot2l"}
		}
	}
	{on "bleeding_big_foot2r"
		{if tagged "bleeding_big_foot2r"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2r"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_foot2r"}
		else
			{kill_delay "bleeding_big_foot2r"}
		}
	}
	{on "bleeding_big_hand1l"
		{if tagged "bleeding_big_hand1l"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1l"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_hand1l"}
		else
			{kill_delay "bleeding_big_hand1l"}
		}
	}
	{on "bleeding_big_hand1r"
		{if tagged "bleeding_big_hand1r"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot1r"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_hand1r"}
		else
			{kill_delay "bleeding_big_hand1r"}
		}
	}
	{on "bleeding_big_hand2l"
		{if tagged "bleeding_big_hand12"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2l"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_hand2l"}
		else
			{kill_delay "bleeding_big_hand2l"}
		}
	}
	{on "bleeding_big_hand2r"
		{if tagged "bleeding_big_hand2r"
			{if rand 0.03
				{if not user_control
					{call "stim_ai"}
				}
			}
			{spawn "blood_small_hit" "foot2r"}				
			{health_damage_count 2
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_big_hand2r"}
		else
			{kill_delay "bleeding_big_hand2r"}
		}
	}
	{on "bleeding_small_e"
		{if tagged "bleeding_small_e"
			{start_sound "anomaly/electra/hit"}
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
			{delay_effect 0.15 "bleeding_small_e"}
		else
			{kill_delay "bleeding_small_e"}
		}
	}
	{on "blood_step"
		{kill_delay "blood_step"}
		{delay 10 "blood_step"
			{tags remove "blood_step"}
		}
	}
	{on "personage_check"
		{if not user_control
			{able "personage" 0}
		else swimming
			{able "personage" 0}
		else burned
			{able "personage" 0}
		else tagged "crush"
			{able "personage" 0}
		else tagged "no_revive"
			{able "personage" 0}
			{tags remove "no_revive"}
		else 
			{if rand 0.5
				{call_synced "mp_personage_0"}
			}
		}
	}
	{on "mp_personage_0"
		(mod "mp"
			{able "personage" 0}
		)
	}
	
	{on "danger_grenade"
		{if not "talk"
			{if not tagged "danger_grenade"
				{talk "danger_grenade"}
				{tags add "danger_grenade" }
				{delay 3.0 "danger_grenade"
					{tags remove "danger_grenade" }
				}			
			}
		}
	}
	{on "open_gas"
		{if not tagged "gasmask"
			{delay 2
				{tags add "bleeding_small_gas2"}
				{call "small_gases"}
				{delay 5 "tags"
					{tags remove "bleeding_small_gas2"}
				}
			}
		}
	}
	;gen_zero
 	{on "open_trit"
		{if not tagged "gasmask"
			{delay 0.6
				{tags add "bleeding_small_trit"}
				{call "small_gases_inh"}
				{delay 15 "tags"
					{tags remove "bleeding_small_trit"}
				}
			}
		}
	}
	{on "small_gases_inh"
		{if tagged "bleeding_small_trit"
			{if rand 0.2
				{if not tagged "talk"
					{tags add "talk"}
					{talk "exh"}
					{delay 1.5 	
						{tags remove "talk"}
						{talk "inh"}
					}
				}
			}
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
		else
			{kill_delay "bleeding_small_trit"}		
		}
		{delay_effect 15 "bleeding_small_trit"}
	}
	;-----------------------------
	{on "clear_hands_repair"
		{if tagged "clear_hands_repair"
			{tags remove "clear_hands_repair"}
			{view hide "repair_kit"}
		else
			{tags add "clear_hands_repair"}
			{add_view "repair_kit" "repair_kit" 		"repair_bone"}
			{view show "repair_kit"}
			{delay 12
				{view hide "repair_kit"}
			}
		}
	}
	{on "knockdown"
 		{if not dead
			{if not tagged "knockdown_foot"
				{tags add "knockdown_foot"}
				{knockdown 0.1}
			}
			{delay 2
				{tags remove "knockdown_foot"}
			}
		}
	}
	{on "knockdown_head_nonlethal"
 		{if not dead
			{if not tagged "knockdown_head"			
				{tags add "non_lethal"}
				{tags add "knockdown_head"}
				{if not tagged "talk"
					{tags add "talk"}
					{talk "exh"}
					{delay 1.5 	
						{tags remove "talk"}
						{talk "inh"}
					}
				}
				{knockdown 360}
				{auto_operatable 0}
			}
			{delay 355 "auto_operatable"
				{call "wake_up"}
			}
			{delay 5
				{tags remove "non_lethal"}
				{tags remove "knockdown_head"}
			}
		}
	}
	{on "knockdown_foot_nonlethal"
 		{if not dead
			{if not tagged "knockdown_foot"
				{tags add "non_lethal"}
				{tags add "knockdown_foot"}
			}
			{delay 10 5
				{auto_operatable 0}
				{knockdown 240}
				{delay 235 "auto_operatable"
					{call "wake_up"}
				}
			}
			{delay 2
				{tags remove "non_lethal"}
				{tags remove "knockdown_foot"}
			}
		}
	}
	{on "knockdown_body_nonlethal"
 		{if not dead
			{if not tagged "knockdown_body"
				{tags add "non_lethal"}
				{tags add "knockdown_body"}
			}
			{delay 5
				{tags remove "knockdown_body"}
				{tags remove "non_lethal"}
			}
			{delay 10 5
				{if not tagged "talk"
					{tags add "talk"}
					{talk "exh"}
					{delay 1.5 	
						{tags remove "talk"}
						{talk "inh"}
					}
				}
				{auto_operatable 0}
				{knockdown 300}
				{delay 295 "auto_operatable"
					{call "wake_up"}
				}
			}
		}
	}
	{on "knockdown_foot"
 		{if not dead
			{if not tagged "knockdown_foot"
				{tags add "knockdown_foot"}
				{knockdown 0.1}
			}
			{delay 2
				{tags remove "knockdown_foot"}
			}
		}
	}
	{on "knockdown_body_blow"
 		{if not dead
			{tags add "non_lethal"}
			{knockdown 240}
			{auto_operatable 0}
			{delay 240 "auto_operatable"
			}
		}
		{delay 5
			{auto_operatable 1}
			{tags remove "knockdown_foot"}
		}
	}
	{on "knockdown_body"
 		{if not dead
			{if not tagged "knockdown_body"
				{tags add "knockdown_body"}
				{knockdown 0.5}
			}
			{delay 1
				{tags remove "knockdown_body"}
			}
		}
	}
	{on "wake_up"
		{if not dead
			{if rand 0.4
				{ani_play "lie_wounded" }
			else rand 0.3
				{ani_play "lie_wounded_1" }
			else
				{ani_play "lie_wounded_2" }		
			}
			{talk "inh"}
			{delay 5
				{ani_stop "lie_wounded" }		
				{ani_stop "lie_wounded_1" }		
				{ani_stop "lie_wounded_2" }		
				{auto_operatable 1}		
				{if rand 0.2
					{delay 0.3
						{player 4}
					}
				else rand 0.2
					{delay 0.3
						{player 5}
					}
				else rand 0.2
					{delay 0.3
						{player 6}
					}
				else rand 0.2
					{delay 0.3
						{player 7}
					}
				else rand 0.2
					{delay 0.3
						{player 12}
					}
				else rand 0.2
					{delay 0.3
						{player 9}
					}
				else rand 0.2
					{delay 0.3
						{player 10}
					}
				else
					{delay 0.3
						{player 11}
					}
				}
			}
		}
	}
	{on "lighter_zippo_fire"
		{spawn "lighter_zippo_fire" "Palm2L"}
	}		
	{on "detect"
		{if not tagged "detect"
			{start_sound "vehicle/whotel/alarm/marked"}
			{tags add "detect"}
			{add_view "mp_watchout"	"detect"	"basis"	}
			{view start "detect"}
			{delay 8
				{view pause "detect"}	
			}
		}
		{delay 12 "tags"
			{tags remove "detect"}
		}
	}
	{on "contact_gases"
		{if not tagged "gasmask"
			{delay 5 3 
				{tags add "bleeding_small_gas"}
				{tags add "killed_gas"}
				{call "gases"}
				{delay 5 3 "tagsgas"
					{talk "hit_gases"}
					{knockdown 10}
				}
				{delay 25 "tags"
					{tags remove "bleeding_small_gas"}
				}
				{health_damage_count 10
					{effects "" "hit" "damage" "die_from_knife" "die_from_knife"}
				}
			}
		}
	}
	{on "small_gases"
		{if tagged "bleeding_small_gas2"
			{view start "smoke"}
			{if rand 0.2
				{if not tagged "talk"
					{tags add "talk"}
					{talk "exh"}
					{delay 1.5 	
						{tags remove "talk"}
						{talk "inh"}
					}
				}
			}
			{health_damage_count 1
				{effects "" "hit" "hit" "die" "die"}
			}
		}
		{delay 1 	
			{call "small_gases"}
			{view pause "smoke"}
		}
	}
	{on "gases"
		{if tagged "bleeding_small_gas"
			{view start "smoke"}
			{if rand 0.8
				{if not tagged "talk"
					{tags add "talk"}
					{talk "exh"}
					{delay 2 	
						{tags remove "talk"}
						{talk "inh"}
					}
				}
			}
			{health_damage_count 5
				{effects "" "hit" "hit" "die" "die"}
			}
		}
		{delay 0.2	
			{call "gases"}
			{view pause "smoke"}
		}
	}
	{on "breath_nose"
 		{if not dead
			{if rand 0.03
				{call "cough"}
			}
			{delay 3
				{start_sound "human/breath_nose_in/"}
				{delay 3
					{start_sound "human/breath_nose_out/"}
				}		
			}		
		}		
		{delay_effect 9 "breath_nose"}
	}
	{on "cough"
 		{if not dead
			{if tagged "idle"				
				{start_sound "human/cough"}
			}
		}
	}
	{on "starvation"
		{if not tagged "starvation"				
			{tags add "starvation"}
			{ani_play "life" +0.02 resume}
		}
	}
	{on "food_ration"
		{if not dead
			{kill_delay "food_ration"}
			{kill_delay "starvation_health"}
			{tags remove "full_starvation"}
			{ani_play "life" -0.8 resume}
			{delay 15 "food_ration"
				{ani_play "life" +0.02 resume}
			}		
		}
	}
	{on "food_ration_anim"
		{if not dead
			{kill_delay "food_ration"}
			{kill_delay "starvation_health"}
			{tags remove "full_starvation"}
			;{ani_play "" } ;anim_food_eat
			{ani_play "life" -0.8 resume}
			{delay 50 "food_ration"
				{ani_play "life" +0.02 resume}
			}		
		}
	}
	{on animation_event "start_starvation"	
		{if tagged "starvation_cap"				
			{tags remove "starvation_cap"}
			{ani_play "life" +0.02 resume}
		}
	}
	{on animation_event "med_starvation"	
		; {if not dead
			; {if not tagged "check_move"
				; {if not tagged "fire_hold"
					; {if not able "burning"
						; {if rand 0.7
							; {call "food_ration"}
							; {call "stop_idle_s"}
							; {call "check_anim_food"}
						; }
					; }
				; }
			; }
		; }
	}
	{on animation_event "starvation_cap"	
		{if not dead
			{tags add "starvation_cap"} ; через скрипт миссии урезать стамину
			;{if tagged "idle"
				; {if not tagged "check_move"
					; {if not tagged "fire_hold"
						; {if not able "burning"
							; {if rand 0.4
								; {call "food_ration"}
								; {call "stop_idle_s"}
								; {call "check_anim_food"}
							; }
						; }
					; }
				; }
			;}
			{if tagged "full_starvation"
				{tags remove "full_starvation"}
			}
		}
	}
	{on animation_event "full_starvation"	
		{tags add "full_starvation"}
		{if user_control	
			{call "starvation_health"}
		}
	}
	{on animation_event "drink_canteen"	
		{call "food_ration"}
		{play_sound "drink_canteen"}
	}
	{on "starvation_health" ; добавить если в  бою пробежать по проверкам если есть передых и быстро поесть для АИ
		{if not dead
			{if tagged "full_starvation"
				; {if not tagged "check_move"
					; {if not tagged "fire_hold"
						; {if not able "burning"
							; {if rand 0.1
								; {call "stop_idle_s"}
								; {call "food_ration"}
								; {call "check_anim_food"}
							; }
						; }
					; }
				; }
				{health_damage_count 1
					{effects "" "hit" "hit" "die" "die"}
				}
				{delay_effect 0.5 "starvation_health"}
			else
				{kill_delay "starvation_health"}
			}
		}
	}
	{on animation_event "start_idle"	
		{tags add "idle"}
	}
	{on animation_event "end_idle"	
		{tags remove "idle"}
	}
	{on "check_anim_food"
		{if tagged "stand"
			{ani_play "stand_look_around_gun" 1.4}		
			{delay 3
				{ani_stop "stand_look_around_gun" }				
			}
		else tagged "squat"
			{delay 0.5
				{ani_play "squat_from_stand_empty" -0.7}		
				{delay 1
					{ani_play "stand_look_around_gun" 1.5 }				
					{delay 9
						{ani_stop "stand_look_around_gun" }				
						{delay 0.5
							{ani_play "squat_from_stand_empty" 0.8}		
						}
					}
				}
			}
		}
	}
	{on "stop_idle_s"
		{ani_stop "stand_idle_1hand" }
		{ani_stop "stand_idle_empty_1" }
		{ani_stop "stand_idle_empty_2" }
		{ani_stop "stand_idle_empty_3" }
		{ani_stop "stand_idle_empty_4" }
		{ani_stop "stand_idle_strap_1" }
		{ani_stop "stand_idle_strap_2" }
		{ani_stop "stand_idle_strap_3" }
		{ani_stop "stand_look_around_gun_1" }
		{ani_stop "stand_look_around_gun_2" }
		{ani_stop "stand_look_around_gun_3" }
		{ani_stop "stand_smoke_1" }
		{ani_stop "stand_smoke_2" }
		{ani_stop "stand_smoke_3" }
	}
	{on animation_event "check_die" ;engine_error
		{if "die_sound"
			{if not tagged "fixed"
				{tags add "fixed"}
				{ani_play "crawl_gun" }		
				{ani_play "crawl" }	
			}
		else not tagged "lying"
			{ani_stop "crawl_gun" }		
			{ani_stop "crawl" }	
		}
	}
	(define "play_leg_sound"
		{if "fast_move_mode"
			("play_move_sound" args fast %0)
		else lying
			("play_move_sound" args lying %0)
		else
			("play_move_sound" args normal %0)
		}
	)
	{on animation_event "leg_left"
		{call "move_signal"}
		{if tagged "deploy"
			{spawn "run_quiet" "footstep_l" }
		}
		{if tagged "fast"
			{ani_play "move_human_left_fast"  resume  }
		else
			{ani_play "move_human_left_slow"  resume  }
		}			
		{call "check_bleeding_legs"}
		("play_leg_sound" args left)	
		{if tagged "blood_step"
			{spawn "human_steps_blood" "footstep_l"}
		else
			{if not tagged "lying"
				{spawn "footstep" "footstep_l" x terrain_texmod}
			}
		}
		{if tagged "sand" 
			{spawn "human_steps_dust_sand" "footstep_l"}
		}
		{if rand 0.05
			{spawn "human_steps_dust" "footstep_l"}
		}
	}
	{on animation_event "leg_right"
		{call "move_signal"}
		{if tagged "deploy"
			{spawn "run_quiet" "footstep_r"}
		}
		{if tagged "fast"
			{ani_play "move_human_right_fast"  resume  }
		else
			{ani_play "move_human_right_slow" resume  }
		}			
		{call "check_bleeding_legs"}
		("play_leg_sound" args right)
		{if tagged "blood_step"
			{spawn "human_steps_blood" "footstep_r"}
		else
			{if not tagged "lying"
				{spawn "footstep" "footstep_r" x terrain_texmod}
			}
		}
		{if rand 0.05
			{spawn "human_steps_dust" "footstep_r"}
		}
	}
	{on animation_event "shovel"			;// event created by animation
		{if terrain_fx "snow"
			{play_sound "shovel_snow"}
		else terrain_fx "sand"
			{play_sound "shovel_snow"}
		else
			{play_sound "shovel_ground"}
		}
	}
	{on animation_event "pickaxe"			;// event created by animation
		{play_sound "pickaxe_ground"}
	}
	{on animation_event "construct_mine"			;// event created by animation
		{play_sound "construct_mine"}
	}
	{on animation_event "construct_sandbag"			;// event created by animation
		{play_sound "construct_sandbag"}
	}
	{on "bodyfalls"
		(define "bodyfalls"
			{if tagged %0 
				{if rand 0.5
					{burn volume "body" fx "dust_bodyfals" time 4 fake even_law}
					;{burn volume fx "dust_bodyfals" time 3 fake even_law}
				}
				{start_sound "bodyfalls/%1/"}	
			}					
		)
		("bodyfalls" args "shoot_emit_ext_sand" sand				)
		("bodyfalls" args "shoot_emit_int_wood"	wood_solid		 	)
		("bodyfalls" args "shoot_emit_ext" 		concrete_gritty		)
		("bodyfalls" args "shoot_emit_int"		wood_solid		 	)
		("bodyfalls" args "shoot_emit_mtl"		metal_thick		 	)
		("bodyfalls" args "shoot_emit_mtl_int"	metal_thick		 	)
		("bodyfalls" args "floor" 				concrete_gritty		)
		("bodyfalls" args "volume"				concrete_gritty		)
		("bodyfalls" args "snow"				mud		 			)
		("bodyfalls" args "land"				concrete_gritty		)
		("bodyfalls" args "metal"				metal_thick		 	)
		("bodyfalls" args "ground"				dirt		 		)
		("bodyfalls" args "bridge"				concrete_dry		)
		("bodyfalls" args "bridge_wood"			carpet_wood		 	)
		("bodyfalls" args "road"				concrete_dry		)
		("bodyfalls" args "country_road"		concrete_dry		)
		("bodyfalls" args "rock"				concrete_dry		)
		("bodyfalls" args "sand"    	 		sand			 	)
		("bodyfalls" args "grass"	 			dirt				)
	}
	
	
	{on animation_event "body_contact"	
		{if tagged "link_weapon"
			{delay 0.2
				{if not user_control
					{if rand 0.1
						{if not tagged "non_lethal" 
							{if not prop "civilian"
								{spawn "grenade_m67_drop" "IK_LeftRight"}
							}
						}
					}
				}
				(define "terrain_fx"
					{if tagged %0 
						{start_sound "hit/small/weapon/ar/%1/"}	
					}
				)
				("terrain_fx" args "ground" 		ground 			 	)
				("terrain_fx" args "grass" 			grass 		 	)
				("terrain_fx" args "road" 			concrete 	 	)
				("terrain_fx" args "country_road" 	mud 		 	)
				("terrain_fx" args "sand" 			sand 		 	)
				("terrain_fx" args "snow"  			mud 		 	)
				("terrain_fx" args "water" 			water 		 	)
				("terrain_fx" args "bridge" 		wood 		   )
				("terrain_fx" args "bridge_wood" 	wood_hollow	   )
				("terrain_fx" args "floor" 			carpet 		   )
				("terrain_fx" args "rock" 			ground 		   )
				("terrain_fx" args "metal" 			metal 		   )
				("terrain_fx" args "shoot_emit_mtl" 				metal 		 )
				("terrain_fx" args "shoot_emit_mtl_int" 			metal 		 )
				("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
				("terrain_fx" args "shoot_emit_ext" 				grass 		 )
				("terrain_fx" args "shoot_emit_int" 				carpet 		 )	
			}
		}
		{call "bodyfalls"}
	}
	
	{on animation_event "body_shuffle"			
		(define "terrain_fx"
			{if tagged %0 
				{start_sound "body_slide/%1/"}	
			}
		)
		("terrain_fx" args "ground" 		dirt 			 	)
		("terrain_fx" args "grass" 			dirt 		 	)
		("terrain_fx" args "road" 			concrete 	 	)
		("terrain_fx" args "country_road" 	concrete 		 	)
		("terrain_fx" args "sand" 			sand 		 	)
		("terrain_fx" args "snow"  			mud 		 	)
		("terrain_fx" args "water" 			water 		 	)
		("terrain_fx" args "bridge" 		wood 		   )
		("terrain_fx" args "bridge_wood" 	wood	   )
		("terrain_fx" args "floor" 			carpet 		   )
		("terrain_fx" args "rock" 			gravel 		   )
		("terrain_fx" args "metal" 			metal_thin 		   )
		("terrain_fx" args "shoot_emit_mtl" 				metal_thick 		 )
		("terrain_fx" args "shoot_emit_mtl_int" 			metal_thick 		 )
		("terrain_fx" args "shoot_emit_ext_sand" 			sand 		 )
		("terrain_fx" args "shoot_emit_ext" 				grass 		 )
		("terrain_fx" args "shoot_emit_int" 				dirt 		 )	
	}
	{on animation_event "blood_death"			
		{add_view 	"blood_s_hit" "blood" "j_visor_inner"}
		{view start	"blood"}
		{delay 7
			{view pause	"blood"}
		}
	}
	{on animation_event "axe_wood"			
		;{start_sound "hit/small/axe/wood/"}	
		{spawn "axe_wood_hit" "right_hand_link"}
	}
	{on animation_event "death_breathe"			
		{talk "death_breathe"}
		;{play_sound "death_breathe"}
	}
	{on animation_event "death_choke"			
		{talk "death_choke"}
		;{play_sound "death_choke"}
	}
	{on animation_event "screw_twist"
		{if not tagged "healing"
			{play_sound "screw_twist"}
		}	
	}	
	{on animation_event "wrench_turn"			
		{if not tagged "healing"
			{play_sound "wrench_turn"}
		}	
	}	
	{on animation_event "toolbox_open"			
		{if not tagged "healing"
			{play_sound "toolbox_open"}
		}	
	}	
	{on animation_event "toolbox_close"			
		{view hide "wrench2"}
		{view hide "wrench1"}
		{if not tagged "healing"
			{play_sound "toolbox_close"}
			{if rand 0.6
				{spawn "wrenchgarage01" "repair_bone2" 
					{impulse dir 0.1 rnd_dir 2}
				}
			else rand 0.4
				{spawn "wrenchgarage03" "repair_bone" 
					{impulse dir 0.1 rnd_dir 2}
				}
			else rand 0.2
				{spawn "wrenchgarage02" "repair_bone2" 
					{impulse dir 0.1 rnd_dir 2}
				}
			else rand 0.1
				{spawn "hammergarage01" "repair_bone" 
					{impulse dir 0.1 rnd_dir 2}
				}
			else rand 0.1
				{spawn "screwdrivergarage01" "repair_bone2" 
					{impulse dir 0.1 rnd_dir 2}
				}
			}
		}
	}
	{on animation_event "tool_equip"			
		{if not tagged "healing"
			{add_view "wrenchgarage02" "wrench2" 		"right_hand_link"}
			{view show "wrench2"}
			{play_sound "tool_equip"}
		}
	}
	{on animation_event "pick_up_small"			
		{play_sound "pick_up_small"}
	}
	{on animation_event "crouch"			
		{play_sound "crouch"}
	}
	{on animation_event "squat_out"	
		{tags remove "squat"}
	}
	{on animation_event "squat_in"			
		{tags add "squat"}
	}
	{on animation_event "talk_water"	
		{talk "talk_water"}
	}
	
	{on animation_event "drink_view"
		{start_sound "weapon/move"}		
		{add_view "canteen" "canteen" 		"left_hand"}
		{view show "canteen"}
		{delay 3
			{start_sound "weapon/move"}		
			{view hide "canteen"}
		}
	}
	{on animation_event "prone_to_stand"			
		{play_sound "prone_to_stand"}
	}
	{on animation_event "stand_to_prone"			
		{play_sound "stand_to_prone"}
	}
	{on animation_event "rest_gun"			
		{play_sound "rest_gun"}
	}
	{on animation_event "stand_at_attention"			
		{play_sound "stand_at_attention"}
	}
	{on animation_event "blocked_anim"			
		{set "blocked" 1}
	}
	{on animation_event "move_wp"			
		{if tagged "link_weapon"
			{start_sound "weapon/move/"}	
		}
	}
	{on animation_event "weapmvmt"			
		(define "weapmvmt"
			{if tagged "%tag"
				{start_sound "human/weapmvmt/%sound/"}	
			}
		)

		("weapmvmt" tag(shortsmg)			sound(medium))
		("weapmvmt" tag(assaultrifle)		sound(medium))
		("weapmvmt" tag(mgun)				sound(large))
		("weapmvmt" tag(pistol)				sound(small))
		("weapmvmt" tag(smg)				sound(medium))
		("weapmvmt" tag(rocketlauncher)		sound(launcher))
		("weapmvmt" tag(shotgun)			sound(medium))
		("weapmvmt" tag(sniper)				sound(large))
	}
	
}
