; {"crush_event_pickup_skoda"
	; {on animation_event "crash_parts_doorr_med"
		; {tear "piece_delete" bone "glass_front_right"
			; {spawn "glass_hit_car" "glass_front_right"}
		; }
	; }
	; {on animation_event "crash_parts_doorl_med"
		; {tear "piece_delete" bone "glass_front_left"
			; {spawn "glass_hit_car" "glass_front_left"}
		; }
	; }
	; {on animation_event "crash_parts_doorr1_med"
		; {tear "piece_delete" bone "glass_back_right"
			; {spawn "glass_hit_car" "glass_back_right"}
		; }
	; }
	; {on animation_event "crash_parts_doorl1_med"
		; {tear "piece_delete" bone "glass_back_left"
			; {spawn "glass_hit_car" "glass_back_left"}
		; }
	; }
; }



{"crush_event_pickup_grad"
	{on animation_event "crash_parts_doorl_small"
		{if rand 0.1
			;{call "break_l1"}
		}
		(define "crush"
			{if rand 0.3
				{tear "piece_small_steel" bone %0
					(define "disable_contact_0")
					{spawn "spheredust_small_short2"}
					{impulse forward 0.4 cx 0.4 cy 0.4}
				}
			}				
		)
		("crush" args "doorhandle_l" )
		("crush" args "trim_door_l" )
		("crush" args "windowhandle_l" )
	}
	{on animation_event "crash_parts_doorl_med"
		{if rand 0.5
			;{call "break_l1"}
		}
		{if rand 0.8
			(define "crush"
				{tear "piece_small_steel" bone %0
					(define "disable_contact_0")
					{spawn "spheredust_small_short2"}
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "doorhandle_L" )
			("crush" args "trim_door_L" )
			("crush" args "windowhandle_L" )
			("crush" args "mirror_L" )
		}
	}
	{on animation_event "crash_parts_doorl_full"
		;{call "break_l1"}
		(define "crush"
			{tear "piece_small_steel" bone %0
				{spawn "spheredust_small_short2"}
				(define "disable_contact_0")
				{impulse forward 2 1 cx 2 1 cy 2 1}
			}	
		)
		("crush" args "doorhandle_L" )
		("crush" args "trim_door_L" )
		("crush" args "windowhandle_L" )
		("crush" args "mirror_L" )
	}
	{on animation_event "crash_parts_doorr_small"
		{if rand 0.1
			;{call "break_r1"}
		}
		(define "crush"
			{if rand 0.3
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 0.4 cx 0.4 cy 0.4}
				}
			}				
		)
		("crush" args "doorhandle_r" )
		("crush" args "trim_door_r" )
		("crush" args "windowhandle_r" )
	}
	{on animation_event "crash_parts_doorr_med"
		{if rand 0.5
			;{call "break_r1"}
		}
		{if rand 0.8
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "doorhandle_r" )
			("crush" args "trim_door_r" )
			("crush" args "windowhandle_r" )
			("crush" args "mirror_r" )
		}
	}
	{on animation_event "crash_parts_doorr_full"
		;{call "break_r1"}
		(define "crush"
			{tear "piece_small_steel" bone %0
				{spawn "spheredust_small_short2"}
				(define "disable_contact_0")
				{impulse dir 2 1 cx 2 1 cy 2 1}
			}	
		)
		("crush" args "doorhandle_r" )
		("crush" args "trim_door_r" )
		("crush" args "windowhandle_r" )
		("crush" args "mirror_r" )
	}
	{on animation_event "crash_parts_back_bumper_med"
		{if rand 0.8
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "trim_bumper_r" )
			("crush" args "trim_bumper_l" )
		}
	}
	{on animation_event "crash_parts_front_bumper_full"
		(define "crush"
			{tear "piece_small_steel" bone %0
				{spawn "spheredust_small_short2"}
				(define "disable_contact_0")
				{impulse dir 2 1 cx 2 1 cy 2 1}
			}	
		)
		("crush" args "front_bumper_alt" )
	}	
	{on animation_event "crash_parts_fender_r_med"
		{if rand 0.5
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "trim_fender_r" )
			("crush" args "fenderflare_fr" )
		}
	}
	{on animation_event "crash_parts_fender_l_med"
		{if rand 0.5
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "trim_fender_l" )
			("crush" args "fenderflare_fl" )
		}
	}
	{on animation_event "crash_parts_hood_small"
		{if rand 0.3
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "bugshield" )
		}
	}
	{on animation_event "crash_parts_hood_med"
		{if rand 0.7
			(define "crush"
				{tear "piece_small_steel" bone %0
					{spawn "spheredust_small_short2"}
					(define "disable_contact_0")
					{impulse forward 2 1 cx 1 cy 1}
				}	
			)
			("crush" args "bugshield" )
		}
	}	
}



{"deform_event_small"
	{on animation_event "hit_parts_bm_armor"
		{tags add "full_damage_armor"}
		{tags add "hit_parts_bm_armor"}
	}
	{on animation_event "hit_parts_bs_armor"
		{tags add "hit_parts_bs_armor"}
	}
	{on animation_event "hit_parts_b_armor"
		{tags add "hit_parts_b_armor"}
	}
	{on animation_event "hit_parts_m_armor"
		{tags add "hit_parts_m_armor"}
	}
	{on animation_event "hit_parts_s_armor"
		{tags add "hit_parts_s_armor"}
	}
	{on animation_event "hit_parts_bm_armor2"
		{tags add "full_damage_armor2"}
		{tags add "hit_parts_bm_armor2"}
	}
	{on animation_event "hit_parts_bs_armor2"
		{tags add "hit_parts_bs_armor2"}
	}
	{on animation_event "hit_parts_b_armor2"
		{tags add "hit_parts_b_armor2"}
	}
	{on animation_event "hit_parts_m_armor2"
		{tags add "hit_parts_m_armor2"}
	}
	{on animation_event "hit_parts_s_armor2"
		{tags add "hit_parts_s_armor2"}
	}
	{on contact
		{if not effector "obstacle"		
			(define "detail_contact"
				{if volume "%detail_contact"
					{if min_speed 40
						{if rand 0.9
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					else min_speed 15
						{if rand 0.5
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					else min_speed 5
						{if rand 0.3
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					}
				}
			)
			("detail_contact" detail_contact(armor))
			("detail_contact" detail_contact(armor2))
		}
	}
	{on pierce
		(define "detail_pierce"
			(define "pierce_system_health"
				{if volume "%detail_pierce"
					{if stuff %0
						{if rand %1
							{if tagged "hit_parts_bm_%detail_pierce"
								{tear "piece_medium_steel" bone from_volume
									{impulse up 0.1 forward 3 1 cx 2 1}
								}						
							}
						}
					}
				}
			)	
			("pierce_system_health" args "bullet stackable small"  		0.1  		 )
			("pierce_system_health" args "bullet big ap"  	  		 	0.7  		 )
			("pierce_system_health" args "bullet big sp"  	  			0.6  		 )
			("pierce_system_health" args "zenite fg"  	  			 	0.9  		 )
			("pierce_system_health" args "zenite ap"  	  			 	0.9  		 )
			("pierce_system_health" args "zenite"  	  					 0.7  		 )
			("pierce_system_health" args "shell"  	  				 	1  			 )
			(define "pierce_system"
				{if volume "%detail_pierce"
					{if stuff %0
						{if rand %1
							{if not tagged "hit_parts_s_%detail_pierce"
								{ani_play "hit_parts_s_%detail_pierce" resume}
							}
							{if not tagged "hit_parts_m_%detail_pierce"
								{if tagged "hit_parts_s_%detail_pierce"
									{ani_play "hit_parts_m_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_pierce"
								{if tagged "hit_parts_m_%detail_pierce"
									{ani_play "hit_parts_b_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_pierce"
								{if tagged "hit_parts_b_%detail_pierce"
									{ani_play "hit_parts_bs_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_pierce"
								{if tagged "hit_parts_bs_%detail_pierce"
									{ani_play "hit_parts_bm_%detail_pierce" resume}
								}
							}
						}
					}
				}
			)	
			("pierce_system" args "bullet stackable small"  	0.1  		 )
			("pierce_system" args "bullet big ap"  	  		 	0.7  		 )
			("pierce_system" args "bullet big sp"  	  			0.6  		 )
			("pierce_system" args "zenite fg"  	  			 	0.9  		 )
			("pierce_system" args "zenite ap"  	  			 	0.9  		 )
			("pierce_system" args "zenite"  	  				 0.7  		 )
			("pierce_system" args "shell"  	  				 	1  			 )
		)
		("detail_pierce" detail_pierce(armor))
		("detail_pierce" detail_pierce(armor2))
	}
	{on blast sync
		(define "detail_blast"
			{if min_energy 10
				{if volume "%detail_blast"
					{if rand 0.5
						{tear "piece_medium_steel" bone from_volume
							{impulse up 0.3 dir 6 2 cx 2 1}
						}						
					}
					{if rand 0.5
						{if tagged "hit_parts_bm_%detail_pierce"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 0.1 forward 3 1 cx 2 1}
							}						
						}
					}
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
								{if not tagged "hit_parts_s_%detail_blast" 
								{ani_play "hit_parts_s_%detail_blast" 1 resume}
							}
							{if rand 0.8
								{if tagged "hit_parts_s_%detail_blast" 
									{delay 0
										{ani_play "hit_parts_m_%detail_blast" 1 resume}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if not tagged "hit_parts_b_%detail_blast" 
							{delay 0
								{ani_play "hit_parts_b_%detail_blast" 1 resume}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.9
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.9
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			else min_energy 5
				{if volume "%detail_blast"
					{if rand 0.4
						{if tagged "hit_parts_bm_%detail_pierce"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 0.1 forward 2 1 cx 2 1}
							}						
						}
					}
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
							{if rand 0.95
								{if not tagged "hit_parts_s_%detail_blast" 
									{ani_play "hit_parts_s_%detail_blast" 1 resume}
								}
								{if rand 0.9
									{if tagged "hit_parts_s_%detail_blast" 
										{delay 0
											{ani_play "hit_parts_m_%detail_blast" 1 resume}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_b_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_b_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			else min_energy 1
				{if volume "%detail_blast"
					{if rand 0.2
						{if tagged "hit_parts_bm_%detail_pierce"
							{tear "piece_medium_steel" bone from_volume
								{impulse up 0.1 forward 0.2 cx 0.2}
							}						
						}
					}
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
							{if rand 0.8
								{if not tagged "hit_parts_s_%detail_blast" 
									{ani_play "hit_parts_s_%detail_blast" 1 resume}
								}
								{if rand 0.5
									{if tagged "hit_parts_s_%detail_blast" 
										{delay 0
											{ani_play "hit_parts_m_%detail_blast" 1 resume}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if rand 0.4
							{if not tagged "hit_parts_b_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_b_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.4
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.3
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			}
		)
		("detail_blast" detail_blast(armor))
		("detail_blast" detail_blast(armor2))
	}
}



{"deform_event"
	{on animation_event "hit_parts_bm_body_back"
		{tags add "full_damage_body_back"}
		{tags add "hit_parts_bm_body_back"}
	}
	{on animation_event "hit_parts_bs_body_back"
		{tags add "hit_parts_bs_body_back"}
	}
	{on animation_event "hit_parts_b_body_back"
		{tags add "hit_parts_b_body_back"}
	}
	{on animation_event "hit_parts_m_body_back"
		{tags add "hit_parts_m_body_back"}
	}
	{on animation_event "hit_parts_s_body_back"
		{tags add "hit_parts_s_body_back"}
	}

	{on animation_event "hit_parts_bm_fender_l"
		{tags add "full_damage_fender_l"}
		{tags add "hit_parts_bm_fender_l"}
	}
	{on animation_event "hit_parts_bs_fender_l"
		{tags add "hit_parts_bs_fender_l"}
	}
	{on animation_event "hit_parts_b_fender_l"
		{tags add "hit_parts_b_fender_l"}
	}
	{on animation_event "hit_parts_m_fender_l"
		{tags add "hit_parts_m_fender_l"}
	}
	{on animation_event "hit_parts_s_fender_l"
		{tags add "hit_parts_s_fender_l"}
	}
	{on animation_event "hit_parts_bm_fender_r"
		{tags add "full_damage_fender_r"}
		{tags add "hit_parts_bm_fender_r"}
	}
	{on animation_event "hit_parts_bs_fender_r"
		{tags add "hit_parts_bs_fender_r"}
	}
	{on animation_event "hit_parts_b_fender_r"
		{tags add "hit_parts_b_fender_r"}
	}
	{on animation_event "hit_parts_m_fender_r"
		{tags add "hit_parts_m_fender_r"}
	}
	{on animation_event "hit_parts_s_fender_r"
		{tags add "hit_parts_s_fender_r"}
	}
	{on animation_event "hit_parts_bm_doorl"
		{tags add "full_damage_doorl"}
		{tags add "hit_parts_bm_doorl"}
	}
	{on animation_event "hit_parts_bs_doorl"
		{tags add "hit_parts_bs_doorl"}
	}
	{on animation_event "hit_parts_b_doorl"
		{tags add "hit_parts_b_doorl"}
	}
	{on animation_event "hit_parts_m_doorl"
		{tags add "hit_parts_m_doorl"}
	}
	{on animation_event "hit_parts_s_doorl"
		{tags add "hit_parts_s_doorl"}
	}
	{on animation_event "hit_parts_bm_doorr"
		{tags add "full_damage_doorr"}
		{tags add "hit_parts_bm_doorr"}
	}
	{on animation_event "hit_parts_bs_doorr"
		{tags add "hit_parts_bs_doorr"}
	}
	{on animation_event "hit_parts_b_doorr"
		{tags add "hit_parts_b_doorr"}
	}
	{on animation_event "hit_parts_m_doorr"
		{tags add "hit_parts_m_doorr"}
	}
	{on animation_event "hit_parts_s_doorr"
		{tags add "hit_parts_s_doorr"}
	}
	{on animation_event "hit_parts_bm_doorr1"
		{tags add "full_damage_doorr1"}
		{tags add "hit_parts_bm_doorr1"}
	}
	{on animation_event "hit_parts_bs_doorr1"
		{tags add "hit_parts_bs_doorr1"}
	}
	{on animation_event "hit_parts_b_doorr1"
		{tags add "hit_parts_b_doorr1"}
	}
	{on animation_event "hit_parts_m_doorr1"
		{tags add "hit_parts_m_doorr1"}
	}
	{on animation_event "hit_parts_s_doorr1"
		{tags add "hit_parts_s_doorr1"}
	}
	{on animation_event "hit_parts_bm_doorl1"
		{tags add "full_damage_doorl1"}
		{tags add "hit_parts_bm_doorl1"}
	}
	{on animation_event "hit_parts_bs_doorl1"
		{tags add "hit_parts_bs_doorl1"}
	}
	{on animation_event "hit_parts_b_doorl1"
		{tags add "hit_parts_b_doorl1"}
	}
	{on animation_event "hit_parts_m_doorl1"
		{tags add "hit_parts_m_doorl1"}
	}
	{on animation_event "hit_parts_s_doorl1"
		{tags add "hit_parts_s_doorl1"}
	}
	{on animation_event "hit_parts_bm_cabin"
		{tags add "full_damage_cabin"}
		{tags add "hit_parts_bm_cabin"}
	}
	{on animation_event "hit_parts_bs_cabin"
		{tags add "hit_parts_bs_cabin"}
	}
	{on animation_event "hit_parts_b_cabin"
		{tags add "hit_parts_b_cabin"}
	}
	{on animation_event "hit_parts_m_cabin"
		{tags add "hit_parts_m_cabin"}
	}
	{on animation_event "hit_parts_s_cabin"
		{tags add "hit_parts_s_cabin"}
	}
	{on animation_event "hit_parts_bm_front_bumper"
		{tags add "full_damage_front_bumper"}
		{tags add "hit_parts_bm_front_bumper"}
	}
	{on animation_event "hit_parts_bs_front_bumper"
		{tags add "hit_parts_bs_front_bumper"}
	}
	{on animation_event "hit_parts_b_front_bumper"
		{tags add "hit_parts_b_front_bumper"}
	}
	{on animation_event "hit_parts_m_front_bumper"
		{tags add "hit_parts_m_front_bumper"}
	}
	{on animation_event "hit_parts_s_front_bumper"
		{tags add "hit_parts_s_front_bumper"}
	}
	{on animation_event "hit_parts_bm_back_bumper"
		{tags add "full_damage_back_bumper"}
		{tags add "hit_parts_bm_back_bumper"}
	}
	{on animation_event "hit_parts_bs_back_bumper"
		{tags add "hit_parts_bs_back_bumper"}
	}
	{on animation_event "hit_parts_b_back_bumper"
		{tags add "hit_parts_b_back_bumper"}
	}
	{on animation_event "hit_parts_m_back_bumper"
		{tags add "hit_parts_m_back_bumper"}
	}
	{on animation_event "hit_parts_s_back_bumper"
		{tags add "hit_parts_s_back_bumper"}
	}
	{on animation_event "hit_parts_bm_hood"
		{tags add "full_damage_hood"}
		{tags add "hit_parts_bm_hood"}
	}
	{on animation_event "hit_parts_bs_hood"
		{tags add "hit_parts_bs_hood"}
	}
	{on animation_event "hit_parts_b_hood"
		{tags add "hit_parts_b_hood"}
	}
	{on animation_event "hit_parts_m_hood"
		{tags add "hit_parts_m_hood"}
	}
	{on animation_event "hit_parts_s_hood"
		{tags add "hit_parts_s_hood"}
	}
	{on animation_event "hit_parts_bs_hook"
		{tags add "hit_parts_bs_hook"}
	}
	{on animation_event "hit_parts_b_hook"
		{tags add "hit_parts_b_hook"}
	}
	{on animation_event "hit_parts_m_hook"
		{tags add "hit_parts_m_hook"}
	}
	{on animation_event "hit_parts_s_hook"
		{tags add "hit_parts_s_hook"}
	}
	{on animation_event "hit_parts_bm_hook"
		{tags add "full_damage_hook"}
		{tags add "hit_parts_bm_hook"}
	}
	{on ground_hit
		(define "detail_hit"
			{if volume "%detail_hit"
				{if min_speed 15
					{if not tagged "hit_parts_s_%detail_hit"
						{ani_play "hit_parts_s_%detail_hit" resume}
					}
					{if not tagged "hit_parts_m_%detail_hit"
						{if tagged "hit_parts_s_%detail_hit"
							{ani_play "hit_parts_m_%detail_hit" resume}
						}
					}
					{if not tagged "hit_parts_b_%detail_hit"
						{if tagged "hit_parts_m_%detail_hit"
							{ani_play "hit_parts_b_%detail_hit" resume}
						}
					}
					{if not tagged "hit_parts_bs_%detail_hit"
						{if tagged "hit_parts_b_%detail_hit"
							{ani_play "hit_parts_bs_%detail_hit" resume}
						}
					}
					{if not tagged "hit_parts_bm_%detail_hit"
						{if tagged "hit_parts_bs_%detail_hit"
							{ani_play "hit_parts_bm_%detail_hit" resume}
						}
					}
				}
			}
		)
		("detail_hit" detail_hit(fender_r))
		("detail_hit" detail_hit(fender_l))
		("detail_hit" detail_hit(front_bumper))
		("detail_hit" detail_hit(back_bumper))
		("detail_hit" detail_hit(hook))
		("detail_hit" detail_hit(hood))
		("detail_hit" detail_hit(doorb))
		("detail_hit" detail_hit(front_light_left_m))
		("detail_hit" detail_hit(front_light_left_l))
		("detail_hit" detail_hit(front_light_right_m))
		("detail_hit" detail_hit(front_light_right_l))
		("detail_hit" detail_hit(back_light_right_m))
		("detail_hit" detail_hit(back_light_left_m))
		("detail_hit" detail_hit(doorl))
		("detail_hit" detail_hit(doorl1))
		("detail_hit" detail_hit(doorr))
		("detail_hit" detail_hit(doorr1))
		("detail_hit" detail_hit(mirrorl))
		("detail_hit" detail_hit(mirrorr))
		("detail_hit" detail_hit(roof))
		("detail_hit" detail_hit(cabin))
		("detail_hit" detail_hit(body_back))
	}
	{on contact
		{if not effector "obstacle"		
			(define "detail_contact"
				{if volume "%detail_contact"
					{if min_speed 40
						{if rand 0.9
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					else min_speed 15
						{if rand 0.5
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					else min_speed 5
						{if rand 0.3
							{if not tagged "hit_parts_s_%detail_contact"
								{ani_play "hit_parts_s_%detail_contact" resume}
							}
							{if not tagged "hit_parts_m_%detail_contact"
								{if tagged "hit_parts_s_%detail_contact"
									{ani_play "hit_parts_m_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_contact"
								{if tagged "hit_parts_m_%detail_contact"
									{ani_play "hit_parts_b_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_contact"
								{if tagged "hit_parts_b_%detail_contact"
									{ani_play "hit_parts_bs_%detail_contact" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_contact"
								{if tagged "hit_parts_bs_%detail_contact"
									{ani_play "hit_parts_bm_%detail_contact" resume}
								}
							}
						}
					}
				}
			)
			("detail_contact" detail_contact(fender_r))
			("detail_contact" detail_contact(fender_l))
			("detail_contact" detail_contact(front_bumper))
			("detail_contact" detail_contact(back_bumper))
			("detail_contact" detail_contact(hook))
			("detail_contact" detail_contact(hood))
			("detail_contact" detail_contact(doorb))
			("detail_contact" detail_contact(doorl))
			("detail_contact" detail_contact(doorl1))
			("detail_contact" detail_contact(doorr))
			("detail_contact" detail_contact(doorr1))
			("detail_contact" detail_contact(mirrorl))
			("detail_contact" detail_contact(mirrorr))
			("detail_contact" detail_contact(roof))
			("detail_contact" detail_contact(cabin))
			("detail_contact" detail_contact(body_back))
		}
	}
	{on pierce
		(define "detail_pierce"
			(define "pierce_system"
				{if volume "%detail_pierce"
					{if stuff %0
						{if rand %1
							{if not tagged "hit_parts_s_%detail_pierce"
								{ani_play "hit_parts_s_%detail_pierce" resume}
							}
							{if not tagged "hit_parts_m_%detail_pierce"
								{if tagged "hit_parts_s_%detail_pierce"
									{ani_play "hit_parts_m_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_b_%detail_pierce"
								{if tagged "hit_parts_m_%detail_pierce"
									{ani_play "hit_parts_b_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_bs_%detail_pierce"
								{if tagged "hit_parts_b_%detail_pierce"
									{ani_play "hit_parts_bs_%detail_pierce" resume}
								}
							}
							{if not tagged "hit_parts_bm_%detail_pierce"
								{if tagged "hit_parts_bs_%detail_pierce"
									{ani_play "hit_parts_bm_%detail_pierce" resume}
								}
							}
						}
					}
				}
			)	
			("pierce_system" args "bullet stackable small"  		0.1  		 )
			("pierce_system" args "bullet big ap"  	  		 	0.7  		 )
			("pierce_system" args "bullet big sp"  	  			0.6  		 )
			("pierce_system" args "zenite fg"  	  			 	0.9  		 )
			("pierce_system" args "zenite ap"  	  			 	0.9  		 )
			("pierce_system" args "zenite"  	  				 	0.7  		 )
			("pierce_system" args "shell"  	  				 	1  			 )
		)
		("detail_pierce" detail_pierce(fender_r))
		("detail_pierce" detail_pierce(fender_l))
		("detail_pierce" detail_pierce(front_bumper))
		("detail_pierce" detail_pierce(back_bumper))
		("detail_pierce" detail_pierce(hook))
		("detail_pierce" detail_pierce(hood))
		("detail_pierce" detail_pierce(doorb))
		("detail_pierce" detail_pierce(front_light_left_m))
		("detail_pierce" detail_pierce(front_light_left_l))
		("detail_pierce" detail_pierce(front_light_right_m))
		("detail_pierce" detail_pierce(front_light_right_l))
		("detail_pierce" detail_pierce(back_light_right_m))
		("detail_pierce" detail_pierce(back_light_left_m))
		("detail_pierce" detail_pierce(doorl))
		("detail_pierce" detail_pierce(doorl1))
		("detail_pierce" detail_pierce(doorr))
		("detail_pierce" detail_pierce(doorr1))
		("detail_pierce" detail_pierce(mirrorl))
		("detail_pierce" detail_pierce(mirrorr))
		("detail_pierce" detail_pierce(roof))
		("detail_pierce" detail_pierce(cabin))
		("detail_pierce" detail_pierce(body_back))
	}
	{on blast sync
		(define "detail_blast"
			{if min_energy 10
				{if volume "%detail_blast"
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
								{if not tagged "hit_parts_s_%detail_blast" 
								{ani_play "hit_parts_s_%detail_blast" 1 resume}
							}
							{if rand 0.8
								{if tagged "hit_parts_s_%detail_blast" 
									{delay 0
										{ani_play "hit_parts_m_%detail_blast" 1 resume}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if not tagged "hit_parts_b_%detail_blast" 
							{delay 0
								{ani_play "hit_parts_b_%detail_blast" 1 resume}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.9
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.9
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			else min_energy 8
				{if volume "%detail_blast"
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
							{if rand 0.95
								{if not tagged "hit_parts_s_%detail_blast" 
									{ani_play "hit_parts_s_%detail_blast" 1 resume}
								}
								{if rand 0.9
									{if tagged "hit_parts_s_%detail_blast" 
										{delay 0
											{ani_play "hit_parts_m_%detail_blast" 1 resume}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_b_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_b_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.8
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			else min_energy 1
				{if volume "%detail_blast"
					{if not tagged "hit_parts_b_%detail_blast"
						{if not tagged "hit_parts_m_%detail_blast"
							{if rand 0.8
								{if not tagged "hit_parts_s_%detail_blast" 
									{ani_play "hit_parts_s_%detail_blast" 1 resume}
								}
								{if rand 0.5
									{if tagged "hit_parts_s_%detail_blast" 
										{delay 0
											{ani_play "hit_parts_m_%detail_blast" 1 resume}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%detail_blast" 
						{if rand 0.4
							{if not tagged "hit_parts_b_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_b_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%detail_blast" 
						{if rand 0.4
							{if not tagged "hit_parts_bs_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bs_%detail_blast" 1 resume}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%detail_blast" 
						{if rand 0.3
							{if not tagged "hit_parts_bm_%detail_blast" 
								{delay 0
									{ani_play "hit_parts_bm_%detail_blast" 1 resume}
								}
							}
						}
					}
				}
			}
		)
		("detail_blast" detail_blast(body_back))
		("detail_blast" detail_blast(fender_r))
		("detail_blast" detail_blast(fender_l))
		("detail_blast" detail_blast(front_bumper))
		("detail_blast" detail_blast(back_bumper))
		("detail_blast" detail(hood))
		; ("detail" detail(doorb))
		; ("detail" detail(front_light_left_m))
		; ("detail" detail(front_light_left_l))
		; ("detail" detail(front_light_right_m))
		; ("detail" detail(front_light_right_l))
		; ("detail" detail(back_light_right_m))
		; ("detail" detail(back_light_left_m))
		("detail_blast" detail_blast(doorl))
		("detail_blast" detail_blast(doorl1))
		("detail_blast" detail_blast(doorr))
		("detail_blast" detail_blast(doorr1))
		; ("detail" detail(mirrorl))
		; ("detail" detail(mirrorr))
		("detail_blast" detail_blast(roof))
		("detail_blast" detail_blast(cabin))
	}
}
{"deform_l5a1"
	{on spawn
		{call "reset"}
	}
	{on "reset"
		(define "reset"
			{if tagged "hit_detail_bm_%0"
				{ani_play "hit_detail_bm_%0" 1}
			}
			{if tagged "hit_detail_bs_%0" 
				{ani_play "hit_detail_bs_%0" 1}
			}
			{if tagged "hit_detail_b_%0"
				{ani_play "hit_detail_s_%0" 1}
			}
			{if tagged "hit_detail_m_%0" 
				{ani_play "hit_detail_b_%0" 1}
			}
			{if tagged "hit_detail_s_%0" 
				{ani_play "hit_detail_s_%0" 1}
			else
				{ani_play "hit_detail_s_%0" -2}				
			}
		)	
		("reset" args ex_armor_turret_l01)
		("reset" args ex_armor_turret_l02)
		("reset" args ex_armor_turret_l03)
		("reset" args ex_armor_turret_r01)
		("reset" args ex_armor_turret_r02)
		("reset" args ex_armor_turret_r03)
		("reset" args ex_decor_01)
		("reset" args ex_decor_02)
	}
	{on pierce
		{if stuff "shell"
			(define "deform_armor"
				{if volume "%vol"
					{if not tagged "hit_detail_b_%anim_tags"
						{if not tagged "hit_detail_m_%anim_tags"
							{if rand %f_hit
								{if not tagged "hit_detail_s_%anim_tags" 
									{ani_play "hit_detail_s_%anim_tags" 1}
								}
								{delay 0.1
									{tags add "hit_detail_s_%anim_tags"}
								}
								{if rand %s_hit
									{if tagged "hit_detail_s_%anim_tags" 
										{tags add "hit_detail_m_%anim_tags"}
										{delay 0.01
											{ani_play "hit_detail_m_%anim_tags" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_detail_m_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_b_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_b_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_b_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_b_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bs_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bs_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bs_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_bs_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bm_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bm_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bm_%anim_tags"}
							}
						}
					}
				}
				{if rand %rand_tear
					{if volume "%vol"
						{tear "piece_big_steel" bone "%bone"
							{spawn "metal_crush" "%bone"}
							{burn volume fx "smoke_hits" time 4 fake even_law}
							{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
						}
					}
				}
			)	
			;                %Bone                     %Vol                     %rand_tear    	   %Anim_tags  					%First_hit   %Second
			("deform_armor" bone(ex_armor_turret_l01) vol(ex_armor_turret_l01) rand_tear(0.35) anim_tags(ex_armor_turret_l01) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l02) vol(ex_armor_turret_l02) rand_tear(0.35) anim_tags(ex_armor_turret_l02) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l03) vol(ex_armor_turret_l03) rand_tear(0.35) anim_tags(ex_armor_turret_l03) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r01) vol(ex_armor_turret_r01) rand_tear(0.35) anim_tags(ex_armor_turret_r01) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r02) vol(ex_armor_turret_r02) rand_tear(0.35) anim_tags(ex_armor_turret_r02) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r03) vol(ex_armor_turret_r03) rand_tear(0.35) anim_tags(ex_armor_turret_r03) f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_decor_01) 		  vol(ex_decor_01) 		   rand_tear(0.3) anim_tags(ex_decor_01) 		 f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_decor_02) 		  vol(ex_decor_02) 		   rand_tear(0.3) anim_tags(ex_decor_02) 		 f_hit(0.8) s_hit(0.8) )
		else stuff "shell_minimum"
			(define "deform_armor"
				{if volume "%vol"
					{if not tagged "hit_detail_b_%anim_tags"
						{if not tagged "hit_detail_m_%anim_tags"
							{if rand %f_hit
								{if not tagged "hit_detail_s_%anim_tags" 
									{ani_play "hit_detail_s_%anim_tags" 1}
								}
								{delay 0.1
									{tags add "hit_detail_s_%anim_tags"}
								}
								{if rand %s_hit
									{if tagged "hit_detail_s_%anim_tags" 
										{tags add "hit_detail_m_%anim_tags"}
										{delay 0.01
											{ani_play "hit_detail_m_%anim_tags" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_detail_m_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_b_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_b_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_b_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_b_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bs_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bs_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bs_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_bs_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bm_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bm_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bm_%anim_tags"}
							}
						}
					}
				}
				{if rand %rand_tear
					{if volume "%vol"
						{tear "piece_big_steel" bone "%bone"
							{spawn "metal_crush" "%bone"}
							{burn volume fx "smoke_hits" time 4 fake even_law}
							{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
						}
					}
				}
			)	
			;                %Bone                     %Vol                     %rand_tear    	   %Anim_tags  					%First_hit   %Second
			("deform_armor" bone(ex_armor_turret_l01) vol(ex_armor_turret_l01) rand_tear(0.05) anim_tags(ex_armor_turret_l01) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l02) vol(ex_armor_turret_l02) rand_tear(0.05) anim_tags(ex_armor_turret_l02) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l03) vol(ex_armor_turret_l03) rand_tear(0.05) anim_tags(ex_armor_turret_l03) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r01) vol(ex_armor_turret_r01) rand_tear(0.05) anim_tags(ex_armor_turret_r01) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r02) vol(ex_armor_turret_r02) rand_tear(0.05) anim_tags(ex_armor_turret_r02) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r03) vol(ex_armor_turret_r03) rand_tear(0.05) anim_tags(ex_armor_turret_r03) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_decor_01) 		  vol(ex_decor_01) 		   rand_tear(0.05) anim_tags(ex_decor_01) 		  f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_decor_02) 		  vol(ex_decor_02) 		   rand_tear(0.05) anim_tags(ex_decor_02) 		  f_hit(0.5) s_hit(0.8) )
		else stuff "zenite ap"
			(define "deform_armor"
				{if volume "%vol"
					{if not tagged "hit_detail_b_%anim_tags"
						{if not tagged "hit_detail_m_%anim_tags"
							{if rand %f_hit
								{if not tagged "hit_detail_s_%anim_tags" 
									{ani_play "hit_detail_s_%anim_tags" 1}
								}
								{delay 0.1
									{tags add "hit_detail_s_%anim_tags"}
								}
								{if rand %s_hit
									{if tagged "hit_detail_s_%anim_tags" 
										{tags add "hit_detail_m_%anim_tags"}
										{delay 0.01
											{ani_play "hit_detail_m_%anim_tags" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_detail_m_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_b_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_b_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_b_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_b_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bs_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bs_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bs_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_bs_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bm_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bm_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bm_%anim_tags"}
							}
						}
					}
				}
				{if rand %rand_tear
					{if volume "%vol"
						{tear "piece_big_steel" bone "%bone"
							{spawn "metal_crush" "%bone"}
							{burn volume fx "smoke_hits" time 4 fake even_law}
							{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
						}
					}
				}
			)	
			;                %Bone                     %Vol                     %rand_tear    	   %Anim_tags  					%First_hit   %Second
			("deform_armor" bone(ex_armor_turret_l01) vol(ex_armor_turret_l01) rand_tear(0.05) anim_tags(ex_armor_turret_l01) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l02) vol(ex_armor_turret_l02) rand_tear(0.05) anim_tags(ex_armor_turret_l02) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l03) vol(ex_armor_turret_l03) rand_tear(0.05) anim_tags(ex_armor_turret_l03) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r01) vol(ex_armor_turret_r01) rand_tear(0.05) anim_tags(ex_armor_turret_r01) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r02) vol(ex_armor_turret_r02) rand_tear(0.05) anim_tags(ex_armor_turret_r02) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r03) vol(ex_armor_turret_r03) rand_tear(0.05) anim_tags(ex_armor_turret_r03) f_hit(0.3) s_hit(0.8) )
			("deform_armor" bone(ex_decor_01) 		  vol(ex_decor_01) 		   rand_tear(0.05) anim_tags(ex_decor_01) 		  f_hit(0.5) s_hit(0.8) )
			("deform_armor" bone(ex_decor_02) 		  vol(ex_decor_02) 		   rand_tear(0.05) anim_tags(ex_decor_02) 		  f_hit(0.5) s_hit(0.8) )
		}
	}
	{on blast sync
		{if min_energy 15
			(define "deform_armor"
				{if volume "%vol"
					{if not tagged "hit_detail_b_%anim_tags"
						{if not tagged "hit_detail_m_%anim_tags"
							{if rand %f_hit
								{if not tagged "hit_detail_s_%anim_tags" 
									{ani_play "hit_detail_s_%anim_tags" 1}
								}
								{delay 0.1
									{tags add "hit_detail_s_%anim_tags"}
								}
								{if rand %s_hit
									{if tagged "hit_detail_s_%anim_tags" 
										{tags add "hit_detail_m_%anim_tags"}
										{delay 0.01
											{ani_play "hit_detail_m_%anim_tags" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_detail_m_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_b_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_b_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_b_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_b_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bs_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bs_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bs_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_bs_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bm_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bm_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bm_%anim_tags"}
							}
						}
					}
				}
				{if rand %rand_tear
					{if volume "%vol"
						{tear "piece_big_steel" bone "%bone"
							{spawn "metal_crush" "%bone"}
							{burn volume fx "smoke_hits" time 4 fake even_law}
							{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
						}
					}
				}
			)	
			;                %Bone                     %Vol                      %rand_tear    	   %Anim_tags  					%First_hit   %Second
			("deform_armor" bone(ex_armor_turret_l01) vol(ex_armor_turret_l01) rand_tear(0.3) anim_tags(ex_armor_turret_l01) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l02) vol(ex_armor_turret_l02) rand_tear(0.3) anim_tags(ex_armor_turret_l02) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l03) vol(ex_armor_turret_l03) rand_tear(0.3) anim_tags(ex_armor_turret_l03) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r01) vol(ex_armor_turret_r01) rand_tear(0.3) anim_tags(ex_armor_turret_r01) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r02) vol(ex_armor_turret_r02) rand_tear(0.3) anim_tags(ex_armor_turret_r02) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r03) vol(ex_armor_turret_r03) rand_tear(0.3) anim_tags(ex_armor_turret_r03) f_hit(0.8) s_hit(0.8) )
			("deform_armor" bone(ex_decor_01) 		  vol(ex_decor_01) 		   rand_tear(0.3) anim_tags(ex_decor_01) 		 f_hit(1) 	s_hit(0.8) )
			("deform_armor" bone(ex_decor_02) 		  vol(ex_decor_02) 		   rand_tear(0.3) anim_tags(ex_decor_02) 		 f_hit(1) 	s_hit(0.8) )
		else min_energy 5
			(define "deform_armor"
				{if volume "%vol"
					{if not tagged "hit_detail_b_%anim_tags"
						{if not tagged "hit_detail_m_%anim_tags"
							{if rand %f_hit
								{if not tagged "hit_detail_s_%anim_tags" 
									{ani_play "hit_detail_s_%anim_tags" 1}
								}
								{delay 0.1
									{tags add "hit_detail_s_%anim_tags"}
								}
								{if rand %s_hit
									{if tagged "hit_detail_s_%anim_tags" 
										{tags add "hit_detail_m_%anim_tags"}
										{delay 0.01
											{ani_play "hit_detail_m_%anim_tags" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_detail_m_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_b_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_b_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_b_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_b_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bs_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bs_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bs_%anim_tags"}
							}
						}
					}
					{if tagged "hit_detail_bs_%anim_tags" 
						{if rand %s_hit
							{if not tagged "hit_detail_bm_%anim_tags" 
								{delay 0.01
									{ani_play "hit_detail_bm_%anim_tags" 1}
								}
							}
							{delay 0.01
								{tags add "hit_detail_bm_%anim_tags"}
							}
						}
					}
				}
				{if rand %rand_tear
					{if volume "%vol"
						{tear "piece_big_steel" bone "%bone"
							{spawn "metal_crush" "%bone"}
							{burn volume fx "smoke_hits" time 4 fake even_law}
							{impulse up 0 dir 0.4 forward 5 2 com  fx 0}		
						}
					}
				}
			)	
			;                %Bone                     %Vol                      %rand_tear    	   %Anim_tags  					%First_hit   %Second
			("deform_armor" bone(ex_armor_turret_l01) vol(ex_armor_turret_l01) rand_tear(0.1) anim_tags(ex_armor_turret_l01) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l02) vol(ex_armor_turret_l02) rand_tear(0.1) anim_tags(ex_armor_turret_l02) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_l03) vol(ex_armor_turret_l03) rand_tear(0.1) anim_tags(ex_armor_turret_l03) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r01) vol(ex_armor_turret_r01) rand_tear(0.1) anim_tags(ex_armor_turret_r01) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r02) vol(ex_armor_turret_r02) rand_tear(0.1) anim_tags(ex_armor_turret_r02) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_armor_turret_r03) vol(ex_armor_turret_r03) rand_tear(0.1) anim_tags(ex_armor_turret_r03) f_hit(0.4) s_hit(0.8) )
			("deform_armor" bone(ex_decor_01) 		  vol(ex_decor_01) 		   rand_tear(0.1) anim_tags(ex_decor_01) 		 f_hit(0.6) s_hit(0.8) )
			("deform_armor" bone(ex_decor_02) 		  vol(ex_decor_02) 		   rand_tear(0.1) anim_tags(ex_decor_02) 		 f_hit(0.6) s_hit(0.8) )
		}
	}
}
{"deform_engine_small"
	{on blast_hit  
		{if volume "part"
			{if stuff "zenite fg"
				{tear "piece_medium_steel" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			}
		}
	}	
	{on pierce sync
		{if volume "part"
			{if stuff "zenite ap"
				{tear "piece_medium_steel" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			else stuff "heavy_zenite"
				{tear "piece_medium_steel" bone from_volume
					{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
				}	
			else stuff "shell fg"
				{tear "piece_medium_steel" bone from_volume
					{spawn "metal_crush" }
					{impulse up 8 2 dir 5 2 cx 5 2 cy 5 2 rnd_dir 4 no_position}
				}	
			else stuff "bullet ap"
				{if volume "part"
					{if rand 0.5		
						{tear "piece_small_steel" bone from_volume
							{impulse up 2 1 dir 3 1 cx 4 2 cy 4 2 rnd_dir 2 no_position}
						}
					}	
				}	
			else stuff "bullet hmgun"
				{if volume "part"
					{if rand 0.7		
						{tear "piece_small_steel" bone from_volume
							{impulse up 3 1 dir 3 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
						}
					}	
				}	
			}			
		}
		{if stuff "rocketlauncher"
			(define "cut_part_shell"
				{if rand %2
					{if not "fire"
						{spawn "ex_lamps" }
					}
					{delay 0.03
						{set "fire" 1}
						{tear "piece_medium_steel" bone %0
							{impulse up 3 1 dir 2 1 cx 5 2 cy 5 2 rnd_dir 2 no_position}
							{spawn "metal_crush" %0}
						}
					}
				}
			)	
			("cut_part_shell" args "wheel01"		"wheel01"			0.8		wheel01)
			("cut_part_shell" args "wheel02"		"wheel02"			0.8		wheel02)
			("cut_part_shell" args "wheel03"		"wheel03"			0.8		wheel03)
			("cut_part_shell" args "wheel04"		"wheel04"			0.8		wheel04)
			("cut_part_shell" args "front_grate"	"front_grate"		0.8		front_grate)
			("cut_part_shell" args "back_grate"		"back_grate"		0.8		back_grate)
			("cut_part_shell" args "part1"			"part1"				0.8		part1	)
			("cut_part_shell" args "part2"			"part2"				0.8		part2)
			("cut_part_shell" args "part3"			"part3"				0.8		part3)
			("cut_part_shell" args "part4"			"part4"				0.8		part4)
		else stuff "fx_40"
			{bullet_detonate}
			(define "cut_part_fx_40"
				{if rand %2
					{if volume %1
						{spawn "metal_crush" %0}
						{delay 0.1
							{tear "piece_medium_steel" bone %0
								{impulse up 3 0.5 dir 1 0.5}
							}
						}
					}
				}
			)	
			("cut_part_shell" args "wheel01"		"wheel01"		0.5)
			("cut_part_shell" args "wheel02"		"wheel02"		0.5)
			("cut_part_shell" args "wheel03"		"wheel03"		0.5)
			("cut_part_shell" args "wheel04"		"wheel04"		0.5)
			("cut_part_shell" args "front_grate"	"front_grate"	0.5)
			("cut_part_shell" args "back_grate"		"back_grate"	0.5)
			("cut_part_shell" args "part1"			"part1"			0.5)
			("cut_part_shell" args "part2"			"part2"			0.5)
			("cut_part_shell" args "part3"			"part3"			0.5)
			("cut_part_shell" args "part4"			"part4"			0.5)
		else stuff "bullet"
			{if volume "part"
				{if rand 0.4		
					{tear "piece_small_steel" bone from_volume
						{impulse up 2 1 dir 3 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}
					}
				}	
			}	
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if volume %1
					{if rand %2
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "wheel01"		"wheel01"			0.3 	wheel01  0.5  0.8 )
			("cut_part_anim" args "wheel02"		"wheel02"			0.3 	wheel02  0.5  0.8 )
			("cut_part_anim" args "wheel03"		"wheel03"			0.3 	wheel03  0.5  0.8 )
			("cut_part_anim" args "wheel04"		"wheel04"			0.3 	wheel04  0.5  0.8 )
			("cut_part_anim" args "body"		"body"				0		body  	0.5  0.8 )
			("cut_part_anim" args "part1"		"part1"				0.2		part1  0.5  0.8 )
			("cut_part_anim" args "part2"		"part2"				0.2		part2  0.5  0.8 )
			("cut_part_anim" args "part3"		"part3"				0.2		part3  0.5  0.8 )
			("cut_part_anim" args "part4"		"part4"				0.2		part4  0.5  0.8 )
			("cut_part_anim" args "floor_fan"	"floor_fan"			0		floor_fan  0.5  0.8 )
			("cut_part_anim" args "front_grate"	"front_grate"		0.2		front_grate  0.5  0.8 )
			("cut_part_anim" args "back_grate"	"back_grate"		0.2		back_grate  0.5  0.8 )
		}
	}
	{on contact 
		{if effector "fraction" 
			{if volume "part"
				{if rand 0.6		
					{tear "piece_medium_steel" bone from_volume
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
			else effector "small_vehicle" 
				{if volume "part"
					{if rand 0.3		
						{tear "piece_medium_steel" bone from_volume
							{impulse up 0.5 dir 0.6 0.1}
						}
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
			else effector "small_vehicle" 
				{if volume "part"
					{if rand 0.2		
						{tear "piece_medium_steel" bone from_volume
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
			}
		}
	}
	{on blast
		{if min_energy 12
			(define "cut_min_energy_12"
				{if volume %1
					{tear "piece_medium_steel" bone %0
						{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
					{delay 1
						{tags remove "hit_parts_s_%2"}
						{tags remove "hit_parts_m_%2"}
						{tags remove "hit_parts_b_%2"}
						{tags remove "hit_parts_bs_%2"}
						{tags remove "hit_parts_bm_%2"}
					}
				}
			)
			("cut_min_energy_12" args "wheel01"		"wheel01" 	wheel01 )
			("cut_min_energy_12" args "wheel02"		"wheel02" 	wheel02 )
			("cut_min_energy_12" args "wheel03"		"wheel03" 	wheel03 )
			("cut_min_energy_12" args "wheel04"		"wheel04" 	wheel04 )
			("cut_min_energy_12" args "part1"		"part1" 	part1 )
			("cut_min_energy_12" args "part2"		"part2" 	part2 )
			("cut_min_energy_12" args "part3"		"part3" 	part3 )
			("cut_min_energy_12" args "part4"		"part4" 	part4 )
			("cut_min_energy_12" args "front_grate"	"front_grate" 	front_grate )
			("cut_min_energy_12" args "back_grate"	"back_grate" 	back_grate )
		else min_energy 4
			(define "cut_min_energy_4"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if tagged "hit_parts_m_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					}
				}
			)	
			("cut_min_energy_4" args "wheel01"			"wheel01"			0.01		wheel01  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wheel02"			"wheel02"			0.01		wheel02  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wheel03"			"wheel03"			0.01		wheel03  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wheel04"			"wheel04"			0.01		wheel04  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "part1"			"part1"				0.01		part1  		0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "part2"			"part2"				0.01		part2  		0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "part3"			"part3"				0.01		part3 	    0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "part4"			"part4"				0.01		part4 	    0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "front_grate"		"front_grate"		0.01		front_grate  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "back_grate"		"back_grate"		0.01		back_grate   0.8  0.98  0.5  0.2)
		else min_energy 1.0
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if tagged "hit_parts_bm_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					}
				}
				{if rand 0.1
					{if volume %1
						{delay 0.01
							{spawn "metal_crush" %0}
							{tear "piece_medium_steel" bone %0
								{impulse up 1 0.5 dir 1 0.5}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"			"body"				0.001		body  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "floor_fan"		"floor_fan"			0.001		floor_fan  	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "part1"			"part1"				0.01		part1  		 0.8  0.95  0.5  0.2)
			("deform_anim" args "part2"			"part2"				0.01		part2  		 0.8  0.95  0.5  0.2)
			("deform_anim" args "part3"			"part3"				0.01		part3  		 0.8  0.95  0.5  0.2)
			("deform_anim" args "part4"			"part4"				0.01		part4  		 0.8  0.95  0.5  0.2)
			("deform_anim" args "front_grate"	"front_grate"		0.01		front_grate  0.8  0.95  0.5  0.2)
			("deform_anim" args "back_grate"	"back_grate"		0.01		back_grate   0.8  0.95  0.5  0.2)
		}
	}
}


{"deform_engine_not_tear"
	{on pierce sync
		{if stuff "shell fg"
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.9 0.5  0.2 )
		else stuff "rocketlauncher"
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.9 0.5  0.2 )
		else stuff "fx_40"
			{bullet_detonate}
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.9 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.9 0.5  0.2 )
		else stuff "bullet ap"
			{if volume "simple"
				{if rand 0.8		
					{tear "piece_small_steel" bone from_volume
						{impulse up 2 1 dir 3 1 cx 4 2 cy 4 2 rnd_dir 2 no_position}
					}
				}	
			}	
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.4 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.4 0.5  0.2 )
		else stuff "bullet hmgun"
			{if volume "simple"
				{if rand 0.9		
					{tear "piece_small_steel" bone from_volume
						{impulse up 3 1 dir 3 1 cx 9 2 cy 9 2 rnd_dir 4 no_position}
					}
				}	
			}	
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
		else stuff "bullet"
			{if volume "simple"
				{if rand 0.4		
					{tear "piece_small_steel" bone from_volume
						{impulse up 2 1 dir 3 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}
					}
				}	
			}	
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.3 0.5  0.2 )
		}
	}
	{on contact sync
		{if effector "fraction" 
			{if contact_velocity 1
				(define "deform_anim"
					{if volume %0
						{if not tagged "hit_parts_bm_%3" ;small
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3"
										{if not tagged "hit_parts_s_%3" 
											{tags add "hit_parts_s_%3"}
											{if rand %5
												{delay 0.1
													{ani_play "hit_parts_s_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_s_%3"  ;meds
							{if not tagged "hit_parts_bs_%3"  ;meds
								{if not tagged "hit_parts_bm_%3"
									{if not tagged "hit_parts_b_%3"
										{if not tagged "hit_parts_m_%3" 
											{if rand %4
												{tags add "hit_parts_m_%3"}
												{delay 0.01
													{ani_play "hit_parts_m_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_m_%3"
							{if not tagged "hit_parts_bm_%3" ;big
								{if not tagged "hit_parts_bs_%3"
									{if not tagged "hit_parts_b_%3" 
										{if rand %4
											{tags add "hit_parts_b_%3"}
											{delay 0.01
												{ani_play "hit_parts_b_%3" 1}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_b_%3"
							{if not tagged "hit_parts_bm_%3" ;big small
								{if not tagged "hit_parts_bs_%3"
									{if rand %6
										{tags add "hit_parts_bs_%3"}
										{delay 0.02
											{ani_play "hit_parts_bs_%3" 1}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_bm_%3" ;big meds
								{if rand %7
									{tags add "hit_parts_bm_%3"}
									{delay 0.03
										{ani_play "hit_parts_bm_%3" 1}
									}
								}
							}
						}
					}
				)	
				("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
				("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
			}	
		else effector "tank" 
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
		else effector "helicopter" 
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
		else effector "vehicle" 
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
		}
	}
	{on blast
		{if min_energy 12
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.8 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.8 0.5  0.2 )
		else min_energy 4
			(define "cut_min_energy_4"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.5 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.5 0.5  0.2 )
		else min_energy 1.0
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"				"body"					0		body  	 		 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_00"			"sheet_00"				0		sheet_00  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_01"			"sheet_01"				0		sheet_01  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_02"			"sheet_02"				0		sheet_02  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_03"			"sheet_03"				0		sheet_03  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_04"			"sheet_04"				0		sheet_04  	 	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "sheet_05"			"sheet_05"				0		sheet_05  	 	 0.1  0.3 0.5  0.2 )
		}
	}
}


{"deform_engine_single"
	{on pierce sync
		{if stuff "shell"
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "body"		"body"			0.3 	body  0.5  0.8 )
		else stuff "fx_40"
			{bullet_detonate}
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "body"		"body"			0.3 	body  0.5  0.8 )
		else stuff "zenite"
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "body"		"body"			0.4 	body  0.8  1 )
		else stuff "bullet"
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "body"		"body"			0.3 	body  0.5  0.8 )
		}
	}
	{on blast
		{if min_energy 4
			(define "cut_min_energy_4"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("cut_min_energy_4" args "body"			"body"			0.01		body  	0.8  1  0.7  0.5)
		else min_energy 1.0
			(define "deform_anim"
				{if volume %0
					{if not tagged "hit_parts_bm_%3" ;small
						{if not tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_b_%3"
								{if not tagged "hit_parts_m_%3"
									{if not tagged "hit_parts_s_%3" 
										{tags add "hit_parts_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_parts_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%3"  ;meds
						{if not tagged "hit_parts_bs_%3"  ;meds
							{if not tagged "hit_parts_bm_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3" 
										{if rand %4
											{tags add "hit_parts_m_%3"}
											{delay 0.01
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3"
						{if not tagged "hit_parts_bm_%3" ;big
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3" 
									{if rand %4
										{tags add "hit_parts_b_%3"}
										{delay 0.01
											{ani_play "hit_parts_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_bm_%3" ;big small
							{if not tagged "hit_parts_bs_%3"
								{if rand %6
									{tags add "hit_parts_bs_%3"}
									{delay 0.02
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3"
						{if not tagged "hit_parts_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_parts_bm_%3"}
								{delay 0.03
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "body"			"body"				0.001		body  	 	 0.8  0.5 0.9  0.5 )
		}
	}
	{on bullet_hit
		{if stuff "fx_40"
			{bullet_detonate}
		}
	}
}




{"deform_engine_armor"
	{on contact sync
		(define "deform_armor_contact"
			{if contact_velocity 10
				{if volume "%props"
					{if not tagged "hit_parts_s_%props" 
						{if rand %first_rand
							{ani_play "hit_parts_s_%props" +5.0 resume }
							{tags add "hit_parts_s_%props"}
						}	
					else tagged "hit_parts_s_%props" 
						{if rand %second_rand
							{ani_play "hit_parts_m_%props" +5.0 resume }
							{tags add "hit_parts_m_%props"}
						}
					else not tagged "hit_parts_b_%props" 
						{if tagged "hit_parts_m_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_b_%props" +5.0 resume }
								{tags add "hit_parts_b_%props"}
							}	
						}	
					else not tagged "hit_parts_bs_%props" 
						{if tagged "hit_parts_b_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_bs_%props" +5.0 resume }
								{tags add "hit_parts_bs_%props"}
							}	
						}	
					else not tagged "hit_parts_bm_%props" 
						{if tagged "hit_parts_bs_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_bm_%props" +5.0 resume }
								{tags add "hit_parts_bm_%props"}
							}	
						}	
					}	
				}
			}
		)	
		("deform_armor_contact" 	props(cabin)					first_rand(0.01) second_rand(0.1)	 )
		("deform_armor_contact" 	props(body_back)				first_rand(0.01) second_rand(0.1)	 )
		("deform_armor_contact" 	props(front_bumper)				first_rand(0.8)	second_rand(0.4)	 )
		("deform_armor_contact" 	props(back_bumper)				first_rand(0.8)	second_rand(0.4)	 )
		("deform_armor_contact" 	props(hook)						first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(doorb)					first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(doorr)					first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(doorl)					first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(doorr1)					first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(doorl1)					first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_part1)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_part3)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_engine_cover)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_hood_armor)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_front_part4)		first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_front_part3)		first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_front_part1)		first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_back_part2)		first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_b_part1)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_r_b_part6)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_r_b_part7)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_r_b_part3)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_r_b_part2)			first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part8)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part7)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part6)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part3)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part4)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part9)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl1_part2)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl_part5)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl_part3)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorl_part4)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part8)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part7)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part6)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part5)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part3)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part9)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr_part2)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr_part5)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr_part4)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr1_part4)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_doorr_part3)			first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_l_b_part2)			first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_l_b_part3)			first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_l_b_part6)			first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_part2)			first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(arm_body_front_part6)		first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_contact" 	props(radiator)					first_rand(0.7)	second_rand(0.4)	 )
	}
	{on ground_hit
		(define "deform_armor_hit"
			{if contact_velocity 15
				{if volume "%props"
					{if not tagged "hit_parts_s_%props" 
						{if rand %first_rand_fast
							{ani_play "hit_parts_s_%props" +5.0 resume }
							{tags add "hit_parts_s_%props"}
						}	
					else tagged "hit_parts_s_%props" 
						{if rand %second_rand_fast
							{ani_play "hit_parts_m_%props" +5.0 resume }
							{tags add "hit_parts_m_%props"}
						}
					else not tagged "hit_parts_b_%props" 
						{if tagged "hit_parts_m_%props" 
							{if rand %second_rand_fast
								{ani_play "hit_parts_b_%props" +5.0 resume }
								{tags add "hit_parts_b_%props"}
							}	
						}	
					else not tagged "hit_parts_bs_%props" 
						{if tagged "hit_parts_b_%props" 
							{if rand %second_rand_fast
								{ani_play "hit_parts_bs_%props" +5.0 resume }
								{tags add "hit_parts_bs_%props"}
							}	
						}	
					else not tagged "hit_parts_bm_%props" 
						{if tagged "hit_parts_bs_%props" 
							{if rand %second_rand_fast
								{ani_play "hit_parts_bm_%props" +5.0 resume }
								{tags add "hit_parts_bm_%props"}
							}	
						}	
					}	
				}	
			else contact_velocity 3
				{if volume "%props"
					{if not tagged "hit_parts_s_%props" 
						{if rand %first_rand
							{ani_play "hit_parts_s_%props" +5.0 resume }
							{tags add "hit_parts_s_%props"}
						}	
					else tagged "hit_parts_s_%props" 
						{if rand %second_rand
							{ani_play "hit_parts_m_%props" +5.0 resume }
							{tags add "hit_parts_m_%props"}
						}
					else not tagged "hit_parts_b_%props" 
						{if tagged "hit_parts_m_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_b_%props" +5.0 resume }
								{tags add "hit_parts_b_%props"}
							}	
						}	
					else not tagged "hit_parts_bs_%props" 
						{if tagged "hit_parts_b_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_bs_%props" +5.0 resume }
								{tags add "hit_parts_bs_%props"}
							}	
						}	
					else not tagged "hit_parts_bm_%props" 
						{if tagged "hit_parts_bs_%props" 
							{if rand %second_rand
								{ani_play "hit_parts_bm_%props" +5.0 resume }
								{tags add "hit_parts_bm_%props"}
							}	
						}	
					}	
				}
			}
		)	
		("deform_armor_hit" 	props(cabin)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.1) second_rand(0.1)	 )
		("deform_armor_hit" 	props(body_back)				first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.1) second_rand(0.1)	 )
		("deform_armor_hit" 	props(front_bumper)				first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(back_bumper)				first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(hook)						first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(doorb)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(doorr)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(doorl)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(doorr1)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(doorl1)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.8)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_part1)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_engine_cover)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_hood_armor)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_front_part4)		first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_front_part3)		first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_front_part1)		first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_back_part2)		first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_b_part1)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_r_b_part6)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_r_b_part7)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_r_b_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_r_b_part2)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part8)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part7)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part6)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part4)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part9)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl1_part2)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl_part5)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorl_part4)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part8)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part7)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part6)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part5)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part9)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr_part2)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr_part5)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr_part4)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr1_part4)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_doorr_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.4)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_l_b_part2)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_l_b_part3)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_l_b_part6)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_part2)			first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(arm_body_front_part6)		first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.3)	second_rand(0.3)	 )
		("deform_armor_hit" 	props(radiator)					first_rand_fast(0.6) second_rand_fast(0.6)  first_rand(0.7)	second_rand(0.4)	 )
	}
	{on pierce 
		(define "deform_armor_pierce"
			{if volume "%props"
				{if not tagged "hit_parts_s_%props" 
					{if rand %first_rand
						{ani_play "hit_parts_s_%props" +5.0 resume }
						{tags add "hit_parts_s_%props"}
					}	
				else tagged "hit_parts_s_%props" 
					{if rand %second_rand
						{ani_play "hit_parts_m_%props" +5.0 resume }
						{tags add "hit_parts_m_%props"}
					}
				else not tagged "hit_parts_b_%props" 
					{if tagged "hit_parts_m_%props" 
						{if rand %second_rand
							{ani_play "hit_parts_b_%props" +5.0 resume }
							{tags add "hit_parts_b_%props"}
						}	
					}	
				else not tagged "hit_parts_bs_%props" 
					{if tagged "hit_parts_b_%props" 
						{if rand %second_rand
							{ani_play "hit_parts_bs_%props" +5.0 resume }
							{tags add "hit_parts_bs_%props"}
						}	
					}	
				else not tagged "hit_parts_bm_%props" 
					{if tagged "hit_parts_bs_%props" 
						{if rand %second_rand
							{ani_play "hit_parts_bm_%props" +5.0 resume }
							{tags add "hit_parts_bm_%props"}
						}	
					}	
				}	
				{if tagged "hit_parts_bm_%props" 
					{if rand %full_tear
						{tear "piece_small_steel" bone from_volume
							{impulse up 2 0.5 dir 3 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}
						}	
					}	
				}	
			}
		)	
		("deform_armor_pierce" 	props(cabin)					first_rand(0.01) second_rand(0.1) full_tear(0) 		 )
		("deform_armor_pierce" 	props(body_back)				first_rand(0.01) second_rand(0.1) full_tear(0)   	 )
		("deform_armor_pierce" 	props(front_bumper)				first_rand(0.3)	second_rand(0.1) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(back_bumper)				first_rand(0.3)	second_rand(0.1) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(hook)						first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(doorb)					first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(doorr)					first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(doorl)					first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(doorr1)					first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(doorl1)					first_rand(0.8)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_part1)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_part3)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_engine_cover)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_hood_armor)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_front_part4)		first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_front_part3)		first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_front_part1)		first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_back_part2)		first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_b_part1)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_r_b_part6)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_r_b_part7)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_r_b_part3)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_r_b_part2)			first_rand(0.7)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part8)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part7)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part6)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part3)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part4)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part9)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl1_part2)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl_part5)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl_part3)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorl_part4)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part8)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part7)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part6)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part5)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part3)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part9)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr_part2)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr_part5)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr_part4)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr1_part4)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_doorr_part3)			first_rand(0.4)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_l_b_part2)			first_rand(0.3)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_l_b_part3)			first_rand(0.3)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_l_b_part6)			first_rand(0.3)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_part2)			first_rand(0.3)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(arm_body_front_part6)		first_rand(0.3)	second_rand(0.3) full_tear(0.1) 	 )
		("deform_armor_pierce" 	props(radiator)					first_rand(0.7)	second_rand(0.4)  full_tear(0) 	 	 )
		(define "pierce_tear"
			{if stuff "%stuff"
				{if not volume "not_tear" 
					{if volume "parts"
						{if rand %parts
							{tear "piece_small_steel" bone from_volume
								%impact	
							}	
						}	
					}	
					{if volume "armor_tear_heavy"
						{if rand %armor_tear_heavy
							{tear "piece_medium_steel" bone from_volume
								%impact	
							}	
						}	
					}	
					{if volume "armor_tear"
						{if rand %armor_tear
							{tear "piece_medium_steel" bone from_volume
								%impact	
							}	
						}	
					}	
					{if volume "light_part"
						{if rand %light_part
							{tear "piece_small_misc" bone from_volume
								%impact	
							}	
						}	
					}	
					{if volume "doors"
						{if rand %doors
							{tear "piece_medium_steel_crushed" bone from_volume
								%impact
							}	
						}	
					}	
				}	
			}	
		)
		;               ;stuff%0             	;%rand_tear_parts	  	;%rand_tear_armor_tear_heavy    %rand_tear_armor_tear  	%rand_tear_light_part 	%rand_tear_doors
		("pierce_tear" 	stuff(shell_big)  				parts(1) 			armor_tear_heavy(1)				armor_tear(1)		light_part(1)				doors(0.4) 			impact({impulse up 4 2 dir 5 2 cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("pierce_tear" 	stuff(atgm_launcher)  			parts(1) 			armor_tear_heavy(1)				armor_tear(1)		light_part(1)				doors(0.4) 			impact({impulse up 4 2 dir 5 2 cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("pierce_tear" 	stuff(shell_minimum)  			parts(1) 			armor_tear_heavy(0.3)			armor_tear(1)		light_part(1)				doors(0.2) 			impact({impulse up 3 2 dir 5 2 cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("pierce_tear" 	stuff(rocketlauncher shell)  	parts(1) 			armor_tear_heavy(0.7)			armor_tear(1)		light_part(1)				doors(0.4) 			impact({impulse up 4 2 dir 5 2 cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("pierce_tear" 	stuff(bullet grenade fg)  		parts(1) 			armor_tear_heavy(0.5)			armor_tear(0.6)		light_part(1)				doors(0.1) 			impact({impulse up 3 2 dir 5 2 cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("pierce_tear" 	stuff(bullet zenite th)  		parts(0.8) 			armor_tear_heavy(0.2)			armor_tear(0.2)		light_part(1)				doors(0.05) 		impact({impulse up 1 0.5 dir 2 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("pierce_tear" 	stuff(bullet zenite fg)  		parts(0.5) 			armor_tear_heavy(0.2)			armor_tear(0.2)		light_part(1)				doors(0.2) 			impact({impulse up 2 1 dir 4 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("pierce_tear" 	stuff(bullet zenite ap)  		parts(1) 			armor_tear_heavy(0.1)			armor_tear(0.4)		light_part(1)				doors(0.1) 			impact({impulse up 1 0.5 dir 2 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("pierce_tear" 	stuff(bullet heavy_zenite)  	parts(1) 			armor_tear_heavy(0.2)			armor_tear(0.8)		light_part(1)				doors(0.4) 			impact({impulse up 3 0.5 dir 6 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("pierce_tear" 	stuff(bullet sp big)  			parts(0.2) 			armor_tear_heavy(0.07)			armor_tear(0.1)		light_part(0.4)				doors(0.05) 		impact({impulse up 1 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position})) ;   bullet sp big     
		("pierce_tear" 	stuff(bullet ap big)  			parts(0.3) 			armor_tear_heavy(0.1)			armor_tear(0.3)		light_part(0.9)				doors(0.05) 		impact({impulse up 2 0.5 dir 3 2 cx 4 2 cy 4 2 rnd_dir 4 no_position}))  ;       bullet ap big
		("pierce_tear" 	stuff(bullet fg big)  			parts(0.3) 			armor_tear_heavy(0.1)			armor_tear(0.2)		light_part(1)				doors(0.05) 		impact({impulse up 3 2 dir 3 2 cx 4 2 cy 4 2 rnd_dir 4 no_position}))   ;      bullet fg big
		("pierce_tear" 	stuff(bullet sp small)  		parts(0.01) 		armor_tear_heavy(0.02)			armor_tear(0.05)	light_part(0.04)			doors(0) 			impact({impulse up 2 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}))    ;    bullet sp small 
		("pierce_tear" 	stuff(bullet ap small)  		parts(0.1) 			armor_tear_heavy(0.1)			armor_tear(0.2)		light_part(0.2)				doors(0.02) 		impact({impulse up 1 0.5 dir 2 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))     ;    bullet ap small
		("pierce_tear" 	stuff(bullet sp normal)  		parts(0.1) 			armor_tear_heavy(0.05)			armor_tear(0.05)	light_part(0.07)			doors(0) 			impact({impulse up 1 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}))      ;   bullet sp normal
		("pierce_tear" 	stuff(bullet ap normal)  		parts(0.3) 			armor_tear_heavy(0.1)			armor_tear(0.2)		light_part(0.2)				doors(0.02) 		impact({impulse up 2 0.5 dir 3 1 cx 3 1 cy 3 1 rnd_dir 2 no_position}))       ;  bullet ap normal
	}		
	{on blast_hit
		{if min_energy 4
			{if rand 0.5
				{if volume "parts"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				else volume "armor_tear"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				else volume "light_part"
					{tear "piece_small_steel" bone from_volume
						{impulse up 12 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				else volume "doors"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 4 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				}	
			}	
		}
	}
}





{"deform_engine_parts"
	{on pierce
		{if stuff "bullet big"
			{if not volume "not_tear" 
				{if volume "arm_body"
					{if rand 0.01
						{tear "piece_medium_steel" bone from_volume
							{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 1 no_position}
						}	
					}	
				}	
			}
			(define "cut_part_anim"
				{if volume %0
					{if rand %4
						{if not tagged "hit_parts_b_%3" 
							{delay 0.01
								{ani_play "hit_parts_b_%3" 1}
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
									{tags add "hit_parts_bs_%3"}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
									{tags add "hit_parts_bm_%3"}
								}
							}
						}
					}
				}
			)
			;bullet def---------------------volume----------------------------------------rand_tear---tagged---------------rand_deform_f---------------------           
			("cut_part_anim" args "arm_body_part1"			"arm_body_part1"			0.1		arm_body_part1 			0.5  0.8 )
			("cut_part_anim" args "arm_body_part2"			"arm_body_part2"			0.1		arm_body_part2			0.5  0.8 )
			("cut_part_anim" args "arm_body_part3"			"arm_body_part3"			0.1		arm_body_part3			0.5  0.8 )
			("cut_part_anim" args "arm_body_part4"			"arm_body_part4"			0.1		arm_body_part4 			0.5  0.8 )
			("cut_part_anim" args "arm_body_part5"			"arm_body_part5"			0.1		arm_body_part5 			0.5  0.8 )
			("cut_part_anim" args "arm_body_part6"			"arm_body_part6"			0.1		arm_body_part6 			0.5  0.8 )
			("cut_part_anim" args "arm_body_part7"			"arm_body_part7"			0.1		arm_body_part7 			0.5  0.8 )
			("cut_part_anim" args "arm_body_part8"			"arm_body_part8"			0.1		arm_body_part8 			0.5  0.8 )
		}
		{if stuff "shell"
			{if rand 0.8
				{if volume "arm_body"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				else volume "nodef"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				}	
			}	
		else stuff "fx_40"
			{bullet_detonate}
			(define "cut_part_anim_fg"
				{if volume %0
					{if not tagged "hit_parts_b_%3"
						{if not tagged "hit_parts_m_%3"
							{if rand %5
								{if not tagged "hit_parts_s_%3" 
									{ani_play "hit_parts_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_parts_s_%3"}
								}
								{if rand %4
									{if tagged "hit_parts_s_%3" 
										{tags add "hit_parts_m_%3"}
										{delay 0.01
											{ani_play "hit_parts_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%3" 
						{if rand %4
							{if not tagged "hit_parts_b_%3" 
								{delay 0.01
									{ani_play "hit_parts_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_b_%3"}
							}
						}
					}
					{if tagged "hit_parts_b_%3" 
						{if rand %4
							{if not tagged "hit_parts_bs_%3" 
								{delay 0.01
									{ani_play "hit_parts_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bs_%3"}
							}
						}
					}
					{if tagged "hit_parts_bs_%3" 
						{if rand %4
							{if not tagged "hit_parts_bm_%3" 
								{delay 0.01
									{ani_play "hit_parts_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_parts_bm_%3"}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if not volume "not_tear" 
							{if tagged "hit_parts_bm_%3" 
								{impulse up 0.1}
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			;fg def---------------------volume----------------------------------------rand_tear---tagged-----------------second----first_deform_f-------------           
			("cut_part_anim_fg" args "arm_body_part1"			"arm_body_part1"			0.3 	arm_body_part1 			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part2"			"arm_body_part2"			0.3		arm_body_part2			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part3"			"arm_body_part3"			0.3		arm_body_part3			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part4"			"arm_body_part4"			0.3		arm_body_part4 			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part5"			"arm_body_part5"			0.3		arm_body_part5 			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part6"			"arm_body_part6"			0.3		arm_body_part6 			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part7"			"arm_body_part7"			0.3		arm_body_part7 			0.5  	1 )
			("cut_part_anim_fg" args "arm_body_part8"			"arm_body_part8"			0.3		arm_body_part8 			0.5  	1 )
		else stuff "bullet"
			(define "cut_part_anim_bullet"
				{if volume %0
					{if rand %4
						{if not tagged "hit_parts_s_%2" ;first hit
							{ani_play "hit_parts_s_%2" 3}
							{tags add "hit_parts_s_%2"}
						}
						{if not tagged "hit_parts_m_%2" 
							{if rand %3
								{tags add "hit_parts_m_%2"}
								{delay 0.01
									{ani_play "hit_parts_m_%2" 3}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%2" 
						{if rand %3
							{if not tagged "hit_parts_b_%2" 
								{tags add "hit_parts_b_%2"}
								{delay 0.01
									{ani_play "hit_parts_b_%2" 3}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%2" 
						{if rand %3
							{if not tagged "hit_parts_bs_%2" 
								{tags add "hit_parts_bs_%2"}
								{delay 0.01
									{ani_play "hit_parts_bs_%2" 3}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%2" 
						{if rand %3
							{if not tagged "hit_parts_bm_%2" 
								{tags add "hit_parts_bm_%2"}
								{delay 0.01
									{ani_play "hit_parts_bm_%2" 3}
								}
							}
						}
					}
				}
			)	
			;bullet def---------------------volume(0)------rand_tear(1)-----tagged(2)--------second(3)----first_deform_f(4)-------------           
			("cut_part_anim_bullet" args "arm_body_part1"   0.1 			arm_body_part1   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part2"   0.1 			arm_body_part2   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part3"   0.1 			arm_body_part3   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part4"   0.1 			arm_body_part4   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part5"   0.1 			arm_body_part5   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part6"   0.1 			arm_body_part6   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part7"   0.1 			arm_body_part7   0.4  	      0.7 )
			("cut_part_anim_bullet" args "arm_body_part8"   0.1 			arm_body_part8   0.4  	      0.7 )
		}
	}
	{on blast
		{if min_energy 8
			{if rand 0.6
				{if volume "arm_body"
					{tear "piece_medium_steel" bone from_volume
						{impulse up 8 2 dir 12 2 cx 8 2 cy 8 2 rnd_dir 8 no_position}
					}	
				}	
				(define "blast_energy_4"
					{if volume %0
						{if rand 0.5
							{tags add "hit_parts_bm_%2"}
							{delay 0.01
								{ani_play "hit_parts_bm_%2" 1}
							}
						}
					}
				)
			}	
		else min_energy 4
			(define "blast_energy_4"
				{if rand 0.5
					{if volume %0
						{tags add "hit_parts_bm_%2"}
						{delay 0.01
							{ani_play "hit_parts_bm_%2" 1}
						}
					}					
					{if not tagged "hit_parts_bm_%2" ;small
						{if not tagged "hit_parts_bs_%2"
							{if not tagged "hit_parts_b_%2"
								{if not tagged "hit_parts_m_%2"
									{if not tagged "hit_parts_s_%2" 
										{tags add "hit_parts_s_%2"}
										{if rand %4
											{delay 0.1
												{ani_play "hit_parts_s_%2" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_parts_s_%2"  ;meds
						{if not tagged "hit_parts_m_%2" 
							{if rand %3
								{tags add "hit_parts_m_%2"}
								{delay 0.01
									{ani_play "hit_parts_m_%2" 1}
								}
							}
						}
					}
					{if tagged "hit_parts_m_%2"
						{if not tagged "hit_parts_b_%2" 
							{if rand %3
								{tags add "hit_parts_b_%2"}
								{delay 0.01
									{ani_play "hit_parts_b_%2" 1}
								}
							}
						}
					}
					{if tagged "hit_parts_b_%2"
						{if not tagged "hit_parts_bs_%2"
							{if rand %3
								{tags add "hit_parts_bs_%2"}
								{delay 0.01
									{ani_play "hit_parts_bs_%2" 1}
								}
							}
						}
					}
					{if tagged "hit_parts_bs_%2"
						{if not tagged "hit_parts_bm_%2" ;big meds
							{if rand %3
								{tags add "hit_parts_bm_%2"}
								{delay 0.03
									{ani_play "hit_parts_bm_%2" 1}
								}
							}
						}
					}
				}
			)	

			;blast def---------------------volume(0)------rand_tear(1)-----tagged(2)--------second(3)----first_deform_f(4)-------------           
			("blast_energy_4" args 			"arm_body_part1"   0.1 			arm_body_part1   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part2"   0.1 			arm_body_part2   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part3"   0.1 			arm_body_part3   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part4"   0.1 			arm_body_part4   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part5"   0.1 			arm_body_part5   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part6"   0.1 			arm_body_part6   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part7"   0.1 			arm_body_part7   0.4  	      0.7 )
			("blast_energy_4" args 			"arm_body_part8"   0.1 			arm_body_part8   0.4  	      0.7 )
		}
	}
}














{"deform_engine"
	{on ground_hit
		(define "deform_engine"
			{if volume "%detail"
				{if min_speed %max_spd
					{if rand 0.8
						{if not tagged "hit_parts_b_%detail"
							{ani_play "hit_parts_b_%detail" resume}
						else tagged "hit_parts_b_%detail"
							{ani_play "hit_parts_bs_%detail" resume}
						else tagged "hit_parts_bs_%detail"
							{ani_play "hit_parts_bm_%detail" resume}
						}							
					}
				else min_speed %min_spd
					{if rand 0.5
						{if not tagged "hit_parts_s_%detail"
							{ani_play "hit_parts_s_%detail" resume}
						else tagged "hit_parts_s_%detail"
							{ani_play "hit_parts_m_%detail" resume}
						else tagged "hit_parts_m_%detail"
							{ani_play "hit_parts_b_%detail" resume}
						else tagged "hit_parts_b_%detail"
							{ani_play "hit_parts_bs_%detail" resume}
						else tagged "hit_parts_bs_%detail"
							{ani_play "hit_parts_bm_%detail" resume}
						}
					}
				}
			}
		)	
		("deform_engine" detail(front_bumper) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(rear_bumper) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(hook) 				max_spd(25) min_spd(5)  )
		("deform_engine" detail(doorb) 				max_spd(25) min_spd(5)  )
		("deform_engine" detail(front_light_left_m) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(front_light_left_l) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(front_light_right_m) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(front_light_right_l) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(back_light_right_m) 		max_spd(25) min_spd(5)  )
		("deform_engine" detail(back_light_left_m) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(doorl) 						max_spd(25) min_spd(5)  )
		("deform_engine" detail(doorl1) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(doorr) 				max_spd(25) min_spd(5)  )
		("deform_engine" detail(doorr1) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(mirrorl) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(mirrorr) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(roof) 				max_spd(25) min_spd(5)  )
		("deform_engine" detail(ballon) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(loader) 			max_spd(25) min_spd(5)  )
		("deform_engine" detail(part2) 				max_spd(25) min_spd(5)  )
	}
	{on pierce sync
		{if stuff "hmgun"
			{if volume "hold_tear"
				{if rand 0.3
					{tear "piece_medium_steel" bone from_volume
						{spawn "ex_w_small" }
						{impulse up 1 0.5 dir 1 0.5}
					}
				}
			}
			(define "cut_part_anim"
				{if not "exploded"
					{if volume %0
						{if not tagged "hit_parts_b_%3"
							{if not tagged "hit_parts_m_%3"
								{if rand %5
									{if not tagged "hit_parts_s_%3" 
										{ani_play "hit_parts_s_%3" 1}
									}
									{delay 0.1
										{tags add "hit_parts_s_%3"}
									}
									{if rand %4
										{if tagged "hit_parts_s_%3" 
											{delay 0.1
												{tags add "hit_parts_m_%3"}
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_m_%3" 
							{if rand %4
								{if not tagged "hit_parts_b_%3" 
									{delay 0.01
										{ani_play "hit_parts_b_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_b_%3"}
								}
							}
						}
						{if tagged "hit_parts_b_%3" 
							{if rand %4
								{if not tagged "hit_parts_bs_%3" 
									{delay 0.01
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_bs_%3"}
								}
							}
						}
						{if tagged "hit_parts_bs_%3" 
							{if rand %4
								{if not tagged "hit_parts_bm_%3" 
									{delay 0.01
										{ani_play "hit_parts_bm_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_bm_%3"}
								}
							}
						}
					}
					{if volume "hook"
						{if tagged "hit_parts_bm_hook" 
							{if rand 0.7
								{spawn "spheredust_small_short2" "hook_lock"}
								{delay 1
									{ani_play "hook_crash" 1}
								}
							}
						}
					}
				}
				{if volume %1
					{if not volume "not_tear" 
						{if tagged "hit_parts_bm_%3" 
							{if rand %4
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
;-----------------------------------0---------------------------1------------------------------2------3-------------------------4-----5-6
			("cut_part_anim" args "front_bumper"			"front_bumper"					0.2		front_bumper 				0.7  1  0)
			("cut_part_anim" args "rear_bumper"				"rear_bumper"					0.2		rear_bumper 				0.7  1  0)
			("cut_part_anim" args "hook"					"hook"							0.2		hook  						0.7  1  0)
			("cut_part_anim" args "doorb"					"doorb"							0.2		doorb						0.7  1  0)
			("cut_part_anim" args "front_light_left_m"		"front_light_left_m"			0.2		front_light_left_m  		0.7  1  0.1)
			("cut_part_anim" args "front_light_left_l"		"front_light_left_l"			0.2		front_light_left_l  		0.7  1  0.1)
			("cut_part_anim" args "front_light_right_m"		"front_light_right_m"			0.2		front_light_right_m  		0.7  1  0.1)
			("cut_part_anim" args "front_light_right_l"		"front_light_right_l"			0.2		front_light_right_l  		0.7  1  0.1)
			("cut_part_anim" args "back_light_right_m"		"back_light_right_m"			0.2		back_light_right_m  		0.7  1  0.1)
			("cut_part_anim" args "back_light_left_m"		"back_light_left_m"				0.2		back_light_left_m  			0.7  1  0.1)
			("cut_part_anim" args "doorl"					"doorl"							0.2		doorl  						0.7  1  0.02)
			("cut_part_anim" args "doorl1"					"doorl1"						0.2		doorl1 						0.7  1  0.02)
			("cut_part_anim" args "doorr"					"doorr"							0.2		doorr  						0.7  1  0.02)
			("cut_part_anim" args "doorr1"					"doorr1"						0.2		doorr1  					0.7  1  0.02)
			("cut_part_anim" args "mirrorl"					"mirrorl"						0.2		mirrorl  					0.7  1  0.05)
			("cut_part_anim" args "mirrorr"					"mirrorr"						0.2		mirrorr  					0.7  1  0.05)
			("cut_part_anim" args "roof"					"roof"							0.2		roof  						0.7  1  0.05)
			("cut_part_anim" args "ballon"					"ballon"						0.2		ballon  					0.7  1  0.05)
			("cut_part_anim" args "loader"					"loader"						0.2		loader  					0.7  1  0.05)
			("cut_part_anim" args "part2"					"part2"							0.2		part2  						0.7  1  0.05)
		else stuff "bullet"
			{if volume "hold_tear"
				{if rand 0.3
					{tear "piece_medium_steel" bone from_volume
						{spawn "ex_w_small" }
						{impulse up 1 0.5 dir 1 0.5}
					}
				}
			}
			(define "cut_part_anim"
				{if not "exploded"
					{if volume %0
						{if not tagged "hit_parts_b_%3"
							{if not tagged "hit_parts_m_%3"
								{if rand %5
									{if not tagged "hit_parts_s_%3" 
										{ani_play "hit_parts_s_%3" 1}
									}
									{delay 0.1
										{tags add "hit_parts_s_%3"}
									}
									{if rand %4
										{if tagged "hit_parts_s_%3" 
											{delay 0.1
												{tags add "hit_parts_m_%3"}
												{ani_play "hit_parts_m_%3" 1}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_m_%3" 
							{if rand %4
								{if not tagged "hit_parts_b_%3" 
									{delay 0.01
										{ani_play "hit_parts_b_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_b_%3"}
								}
							}
						}
						{if tagged "hit_parts_b_%3" 
							{if rand %4
								{if not tagged "hit_parts_bs_%3" 
									{delay 0.01
										{ani_play "hit_parts_bs_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_bs_%3"}
								}
							}
						}
						{if tagged "hit_parts_bs_%3" 
							{if rand %4
								{if not tagged "hit_parts_bm_%3" 
									{delay 0.01
										{ani_play "hit_parts_bm_%3" 1}
									}
								}
								{delay 0.01
									{tags add "hit_parts_bm_%3"}
								}
							}
						}
					}
				}
				{if volume %1
					{if not volume "not_tear" 
						{if tagged "hit_parts_bm_%3" 
							{if rand %6
								{delay 0
									{tear "piece_medium_steel" bone %0
										{spawn "metal_crush" %0}
										{impulse up 1 0.5 dir 1 0.5}
									}
								}
							}
						}
					}
				}
			)	
			("cut_part_anim" args "front_bumper"			"front_bumper"					0.2		front_bumper 				0.5  0.8  0)
			("cut_part_anim" args "rear_bumper"				"rear_bumper"					0.2		rear_bumper 				0.5  0.8  0)
			("cut_part_anim" args "hook"					"hook"							0.2		hook  						0.5  0.8  0.1)
			("cut_part_anim" args "doorb"				"doorb"							0.2		doorb						0.5  0.8  0)
			("cut_part_anim" args "front_light_left_m"		"front_light_left_m"			0.2		front_light_left_m  		0.5  0.8  0.1)
			("cut_part_anim" args "front_light_left_l"		"front_light_left_l"			0.2		front_light_left_l  		0.5  0.8  0.1)
			("cut_part_anim" args "front_light_right_m"		"front_light_right_m"			0.2		front_light_right_m  		0.5  0.8  0.1)
			("cut_part_anim" args "front_light_right_l"		"front_light_right_l"			0.2		front_light_right_l  		0.5  0.8  0.1)
			("cut_part_anim" args "back_light_right_m"		"back_light_right_m"			0.2		back_light_right_m  		0.5  0.8  0.1)
			("cut_part_anim" args "back_light_left_m"		"back_light_left_m"				0.2		back_light_left_m  			0.5  0.8  0.1)
			("cut_part_anim" args "doorl"					"doorl"							0.2		doorl  						0.5  0.8  0.1)
			("cut_part_anim" args "doorl1"					"doorl1"						0.2		doorl1 						0.5  0.8  0.1)
			("cut_part_anim" args "doorr"					"doorr"							0.2		doorr  						0.5  0.8  0.1)
			("cut_part_anim" args "doorr1"					"doorr1"						0.2		doorr1  					0.5  0.8  0.1)
			("cut_part_anim" args "mirrorl"					"mirrorl"						0.2		mirrorl  					0.5  0.8  0.1)
			("cut_part_anim" args "mirrorr"					"mirrorr"						0.2		mirrorr  					0.5  0.8  0.1)
			("cut_part_anim" args "roof"					"roof"							0.2		roof  						0.5  0.8  0.1)
			("cut_part_anim" args "ballon"					"ballon"						0.2		ballon  					0.5  0.8  0.1)
			("cut_part_anim" args "loader"					"loader"						0.2		loader  					0.5  0.8  0.1)
			("cut_part_anim" args "part2"					"part2"							0.2		part2  						0.5  0.8  0.1)
		}
	}
	{on contact
		{if contact_velocity 15
			{if volume "mirror" 
				{tear "piece_medium_steel" bone from_volume
					{impulse up 2 1 dir 2 1}
				}	
			}	
			{if volume "part" 
				{tear "piece_medium_steel" bone from_volume
					{impulse up 2 1 dir 2 1}
				}	
			}
			{if volume "hook"
				{if tagged "hit_parts_bm_hook" 
					{if rand 0.4
						{spawn "spheredust_small_short2" "hook_lock"}
						{delay 1
							{ani_play "hook_crash" 1}
						}
					}
				}
			}
		}
		{if effector "fraction" 
			{if contact_velocity 5
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "doorr"		"doorr"				0.07)
				("cut_part" args "doorr1"		"doorr1"			0.07)
				("cut_part" args "doorl"		"doorl"				0.07)
				("cut_part" args "doorl1"		"doorl1"			0.07)
				("cut_part" args "mirrorl"		"mirrorl"			0.07)
				("cut_part" args "mirrorr"		"mirrorr"			0.07)
			}	
		}	
		(define "deform_engine"
			{if volume "%detail"
				{with_effector
					{if min_mass %mass_max
						{with_effector
							{if min_speed %max_spd
								{if rand 0.8
									{if not tagged "hit_parts_b_%detail"
										{ani_play "hit_parts_b_%detail" resume}
									else tagged "hit_parts_b_%detail"
										{ani_play "hit_parts_bs_%detail" resume}
									else tagged "hit_parts_bs_%detail"
										{ani_play "hit_parts_bm_%detail" resume}
									}							
								}
							else min_speed %min_spd
								{if rand 0.5
									{if not tagged "hit_parts_s_%detail"
										{ani_play "hit_parts_s_%detail" resume}
									else tagged "hit_parts_s_%detail"
										{ani_play "hit_parts_m_%detail" resume}
									else tagged "hit_parts_m_%detail"
										{ani_play "hit_parts_b_%detail" resume}
									else tagged "hit_parts_b_%detail"
										{ani_play "hit_parts_bs_%detail" resume}
									else tagged "hit_parts_bs_%detail"
										{ani_play "hit_parts_bm_%detail" resume}
									}
								}
							}
						}
					else min_mass %mass_min
						;{tags add "%mass_min"} ; for test
						{with_effector
							{if min_speed %max_spd
								{if rand 0.5
									{if not tagged "hit_parts_b_%detail"
										{ani_play "hit_parts_b_%detail" resume}
									else tagged "hit_parts_bs_%detail"
										{ani_play "hit_parts_bs_%detail" resume}
									else tagged "hit_parts_bm_%detail"
										{ani_play "hit_parts_bm_%detail" resume}
									}							
								}
							else min_speed %min_spd
								{if rand 0.2
									{if not tagged "hit_parts_s_%detail"
										{ani_play "hit_parts_s_%detail" resume}
									else tagged "hit_parts_s_%detail"
										{ani_play "hit_parts_m_%detail" resume}
									else tagged "hit_parts_m_%detail"
										{ani_play "hit_parts_b_%detail" resume}
									else tagged "hit_parts_b_%detail"
										{ani_play "hit_parts_bs_%detail" resume}
									else tagged "hit_parts_bs_%detail"
										{ani_play "hit_parts_bm_%detail" resume}
									}
								}
							}
						}
					}
				}
			}
		)	
		("deform_engine" detail(front_bumper) 					max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(rear_bumper) 					max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(hook) 							max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(doorb) 							max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(front_light_left_m) 			max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(front_light_left_l) 			max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(front_light_right_m) 			max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(front_light_right_l) 			max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(back_light_right_m) 			max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(back_light_left_m) 				max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(doorl) 							max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(doorl1) 						max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(doorr) 							max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(doorr1) 						max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(mirrorl) 						max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(mirrorr) 						max_spd(20) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(roof) 							max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(ballon) 						max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(loader) 						max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
		("deform_engine" detail(part2) 							max_spd(25) min_spd(10) mass_max(900) mass_min(250) )
	}
	{on blast
		{if min_energy 12
			(define "cut_min_energy_12"
				{if volume %1
					{tear "piece_medium_steel" bone %0
						{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
					{delay 1
						{tags remove "hit_parts_s_%2"}
						{tags remove "hit_parts_m_%2"}
						{tags remove "hit_parts_b_%2"}
						{tags remove "hit_parts_bs_%2"}
						{tags remove "hit_parts_bm_%2"}
					}
				}
			)
			("cut_min_energy_12" args "front_light_right_m"		"front_light_right_m" 	front_light_right_m )
			("cut_min_energy_12" args "front_light_right_l"		"front_light_right_l" 	front_light_right_l )
			("cut_min_energy_12" args "front_light_left_l"		"front_light_left_l" 	front_light_left_l )
			("cut_min_energy_12" args "front_light_left_m"		"front_light_left_m" 	front_light_left_m )
			("cut_min_energy_12" args "mirrorl"		"mirrorl" 	mirrorl )
			("cut_min_energy_12" args "mirrorr"		"mirrorr" 	mirrorr )
			("cut_min_energy_12" args "hook"		"hook" 	hook )
		else min_energy 4
			(define "cut_min_energy_4"
				{if not "exploded"
					{if volume %0
						{if not tagged "hit_parts_bm_%3" ;small
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3"
										{if not tagged "hit_parts_s_%3" 
											{tags add "hit_parts_s_%3"}
											{if rand %5
												{delay 0.1
													{ani_play "hit_parts_s_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_s_%3"  ;meds
							{if not tagged "hit_parts_bs_%3"  ;meds
								{if not tagged "hit_parts_bm_%3"
									{if not tagged "hit_parts_b_%3"
										{if not tagged "hit_parts_m_%3" 
											{if rand %4
												{tags add "hit_parts_m_%3"}
												{delay 0.01
													{ani_play "hit_parts_m_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_m_%3"
							{if not tagged "hit_parts_bm_%3" ;big
								{if not tagged "hit_parts_bs_%3"
									{if not tagged "hit_parts_b_%3" 
										{if rand %4
											{tags add "hit_parts_b_%3"}
											{delay 0.01
												{ani_play "hit_parts_b_%3" 1}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_b_%3"
							{if not tagged "hit_parts_bm_%3" ;big small
								{if not tagged "hit_parts_bs_%3"
									{if rand %6
										{tags add "hit_parts_bs_%3"}
										{delay 0.02
											{ani_play "hit_parts_bs_%3" 1}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_bm_%3" ;big meds
								{if rand %7
									{tags add "hit_parts_bm_%3"}
									{delay 0.03
										{ani_play "hit_parts_bm_%3" 1}
									}
								}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if tagged "hit_parts_m_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					}
				}
			)	
			("cut_min_energy_4" args "front_bumper"				"front_bumper"				0			front_bumper  			0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "rear_bumper"				"rear_bumper"				0			rear_bumper  			0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "hook"						"hook"						0			hook  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "doorb"					"doorb"						0			doorb  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "front_light_left_m"		"front_light_left_m"		0.01		front_light_left_m  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "front_light_left_l"		"front_light_left_l"		0.01		front_light_left_l  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "front_light_right_m"		"front_light_right_m"		0.01		front_light_right_m 	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "front_light_right_l"		"front_light_right_l"		0.01		front_light_right_l  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "back_light_right_m"		"back_light_right_m"		0.01		back_light_right_m  	0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "back_light_left_m"		"back_light_left_m"			0.01		back_light_left_m  		0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "doorr"					"doorr"						0.01		doorr  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "doorr1"					"doorr1"					0.01		doorr  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "doorl"					"doorl"						0.01		doorr  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "doorl1"					"doorl1"					0.01		doorr  					0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "mirrorl"					"mirrorl"					0.01		mirrorl  				0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "mirrorr"					"mirrorr"					0.01		mirrorr  				0.8  0.98  0.5  0.2)
		else min_energy 1.0
			(define "deform_anim"
				{if not "exploded"
					{if volume %0
						{if not tagged "hit_parts_bm_%3" ;small
							{if not tagged "hit_parts_bs_%3"
								{if not tagged "hit_parts_b_%3"
									{if not tagged "hit_parts_m_%3"
										{if not tagged "hit_parts_s_%3" 
											{tags add "hit_parts_s_%3"}
											{if rand %5
												{delay 0.1
													{ani_play "hit_parts_s_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_s_%3"  ;meds
							{if not tagged "hit_parts_bs_%3"  ;meds
								{if not tagged "hit_parts_bm_%3"
									{if not tagged "hit_parts_b_%3"
										{if not tagged "hit_parts_m_%3" 
											{if rand %4
												{tags add "hit_parts_m_%3"}
												{delay 0.01
													{ani_play "hit_parts_m_%3" 1}
												}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_m_%3"
							{if not tagged "hit_parts_bm_%3" ;big
								{if not tagged "hit_parts_bs_%3"
									{if not tagged "hit_parts_b_%3" 
										{if rand %4
											{tags add "hit_parts_b_%3"}
											{delay 0.01
												{ani_play "hit_parts_b_%3" 1}
											}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_b_%3"
							{if not tagged "hit_parts_bm_%3" ;big small
								{if not tagged "hit_parts_bs_%3"
									{if rand %6
										{tags add "hit_parts_bs_%3"}
										{delay 0.02
											{ani_play "hit_parts_bs_%3" 1}
										}
									}
								}
							}
						}
						{if tagged "hit_parts_bs_%3"
							{if not tagged "hit_parts_bm_%3" ;big meds
								{if rand %7
									{tags add "hit_parts_bm_%3"}
									{delay 0.03
										{ani_play "hit_parts_bm_%3" 1}
									}
								}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if tagged "hit_parts_m_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					}
				}
			)	
			("deform_anim" args "front_bumper"				"front_bumper"				0		front_bumper  			0.8  0.98  0.5  0.2)
			("deform_anim" args "rear_bumper"				"rear_bumper"				0		rear_bumper  			0.8  0.98  0.5  0.2)
			("deform_anim" args "hook"						"hook"						0		hook  					0.8  0.98  0.5  0.2)
			("deform_anim" args "doorb"						"doorb"						0		doorb  					0.8  0.98  0.5  0.2)
			("deform_anim" args "front_light_left_m"		"front_light_left_m"		0		front_light_left_m  	0.8  0.98  0.5  0.2)
			("deform_anim" args "front_light_left_l"		"front_light_left_l"		0		front_light_left_l  	0.8  0.98  0.5  0.2)
			("deform_anim" args "front_light_right_m"		"front_light_right_m"		0		front_light_right_m 	0.8  0.98  0.5  0.2)
			("deform_anim" args "front_light_right_l"		"front_light_right_l"		0		front_light_right_l  	0.8  0.98  0.5  0.2)
			("deform_anim" args "back_light_right_m"		"back_light_right_m"		0		back_light_right_m  	0.8  0.98  0.5  0.2)
			("deform_anim" args "back_light_left_m"			"back_light_left_m"			0		back_light_left_m  		0.8  0.98  0.5  0.2)
			("deform_anim" args "doorl"						"doorl"						0.01	doorr  					0.8  0.98  0.5  0.2)
			("deform_anim" args "doorl1"					"doorl1"					0.01	doorr1  				0.8  0.98  0.5  0.2)
			("deform_anim" args "doorr"						"doorr"						0.01	doorr  					0.8  0.98  0.5  0.2)
			("deform_anim" args "doorr1"					"doorr1"					0.01	doorr1  				0.8  0.98  0.5  0.2)
			("deform_anim" args "mirrorr"					"mirrorr"					0.01	mirrorr  				0.8  0.98  0.5  0.2)
			("deform_anim" args "mirrorl"					"mirrorl"					0.01	mirrorl  				0.8  0.98  0.5  0.2)
		}
	}
}

