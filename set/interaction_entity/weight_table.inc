{"weight_6500"
	{on animation_event "update_mass"
		{call "mass_update"}	
		{if tagged "move"
			{if tagged "max_overload"
				(define "blast"
					{if rand 0.01
						{if not tagged %1
							{spawn "ex_wheel" %0}
							{impulse up 0.1 }
							{spawn "metal_crush" }
							{components %0 destroy}
							{tear "piece_medium_steel" bone %0
								{spawn "spheredust_small"}
								{burn volume %0 fx "dust_small" time 1 fake even_law}
								{impulse up 0.2 }
							}	
							{start_sound "vehicle/suspension_brake/"}
							{components %0 break}
							{ani_play "wheell_blast"}
							{tags add %1}
						}
					}
				)
				("blast" args "wheelleft2" "wheell2_b"  )
				("blast" args "wheelright2" "wheelr2_b"  )
			else tagged "overload"
				(define "blast"
					{if work %0
						{if rand 0.03
							{if not tagged %1
								{spawn "ex_wheel" %0}
								{impulse up 0.1 }
								{burn volume %0 fx "dust_small" time 1 fake even_law}
								{start_sound "vehicle/suspension_brake/"}
								{damage_report "body" "component/disk"}
								{components %0 break}
								{ani_play "wheell_blast"}
								{ani_play %1 1}
								{tags add %1}
							}
						}
					}
				)
				("blast" args "wheelleft2" "wheell2_b"  )
				("blast" args "wheelright2" "wheelr2_b"  )
			}
		}
	}
	(define "weight"
		{on animation_event "%event"
			{if tagged "%tagged_weight"	
				{ani_stop "weight_full" }
			}
		}
	)
	;                      
	("weight" event(w_1) tagged_weight(0_mass) )
	("weight" event(w_50) tagged_weight(50_mass) )
	("weight" event(w_100) tagged_weight(100_mass) )
	("weight" event(w_200) tagged_weight(200_mass) )
	("weight" event(w_300) tagged_weight(300_mass) )
	("weight" event(w_400) tagged_weight(400_mass) )
	("weight" event(w_500) tagged_weight(500_mass) )
	("weight" event(w_600) tagged_weight(600_mass) )
	("weight" event(w_700) tagged_weight(700_mass) )
	("weight" event(w_800) tagged_weight(800_mass) )
	("weight" event(w_900) tagged_weight(900_mass) )
	("weight" event(w_1000) tagged_weight(1000_mass) )
	("weight" event(w_1100) tagged_weight(1100_mass) )
	("weight" event(w_1200) tagged_weight(1200_mass) )
	("weight" event(w_1300) tagged_weight(1300_mass) )
	("weight" event(w_1400) tagged_weight(1400_mass) )
	("weight" event(w_1500) tagged_weight(1500_mass) )
	("weight" event(w_1600) tagged_weight(1600_mass) )
	("weight" event(w_1700) tagged_weight(1700_mass) )
	("weight" event(w_1800) tagged_weight(1800_mass) )
	("weight" event(w_1900) tagged_weight(1900_mass) )
	("weight" event(w_2000) tagged_weight(2000_mass) )
	{on "mass_update"
		{if min_mass 13000
			{if not tagged "max_overload"
				(define "weight"
					{if tagged %0
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	+1  +1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "max_overload"}
				{tags add "2500_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 11800
			{if not tagged "2000_mass"
				{movement_limit slow}
				{tags add "overload"}
				{tags add "2000_mass"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				("weight" args "1900_mass" 	+1  -1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 11200
			{if not tagged "1900_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1900_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 11000
			{if not tagged "1800_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1800_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 10800
			{if not tagged "1700_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1700_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 10400
			{if not tagged "1600_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1600_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 10200
			{if not tagged "1500_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	-1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1500_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 9800
			{if not tagged "1400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	-1  -1 	)
				("weight" args "1500_mass" 	-1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1400_mass"}
			}
		else min_mass 9400
			{if not tagged "1300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1300_mass"}
			}
		else min_mass 8800
			{if not tagged "1200_mass"
				{call "check_work_mover"}
				{start_sound "amb_emitters/car_blasted/"}				
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1200_mass"}
			}
		else min_mass 8400
			{if not tagged "1100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1100_mass"}
			}
		else min_mass 8000
			{if not tagged "1000_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1000_mass"}
			}
		else min_mass 7600
			{if not tagged "900_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "900_mass"}
			}
		else min_mass 7400
			{if not tagged "800_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "800_mass"}
			}
		else min_mass 7200
			{if not tagged "700_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "700_mass"}
			}
		else min_mass 7100
			{if not tagged "600_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "600_mass"}
			}
		else min_mass 7000
			{if not tagged "500_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "500_mass"}
			}
		else min_mass 6900
			{if not tagged "400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "400_mass"}
			}
		else min_mass 6800
			{if not tagged "300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "300_mass"}
			}
		else min_mass 6700
			{if not tagged "200_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "200_mass"}
			}
		else min_mass 6600
			{if not tagged "100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "100_mass"}
			}
		else min_mass 6550
			{if not tagged "50_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "100_mass" 	-1  +1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "50_mass"}
			}
		else min_mass 6450
			{if not tagged "0_mass"
				{call "check_work_mover"}
				{tags add "0_mass"}
				{tags remove "overload"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-3  +1 	)
				("weight" args "1900_mass" 	-3  +1 	)
				("weight" args "1800_mass" 	-3  +1 	)
				("weight" args "1700_mass" 	-3  +1 	)
				("weight" args "1600_mass" 	-3  +1 	)
				("weight" args "1500_mass" 	-3  +1 	)
				("weight" args "1400_mass" 	-3  +1 	)
				("weight" args "1300_mass" 	-3  +1 	)
				("weight" args "1200_mass" 	-3  +1 	)
				("weight" args "1100_mass" 	-3  +1 	)
				("weight" args "1000_mass" 	-3  +1 	)
				("weight" args "900_mass" 	-3  +1 	)
				("weight" args "800_mass" 	-3  +1 	)
				("weight" args "700_mass" 	-3  +1 	)
				("weight" args "600_mass" 	-3  +1 	)
				("weight" args "500_mass" 	-3  +1 	)
				("weight" args "400_mass" 	-3  +1 	)
				("weight" args "300_mass" 	-3  +1 	)
				("weight" args "200_mass" 	-3  +1 	)
				("weight" args "100_mass" 	-3  +1 	)
				("weight" args "50_mass" 	-1  +1 	)
			}
		}
	}
	{on "clear_weight"
		{tags remove "1600_mass"}
		{tags remove "1200_mass"}
		{tags remove "800_mass"}
		{tags remove "400_mass"}
		{tags remove "200_mass"}
	}
}
{"weight_3500"
	{on animation_event "update_mass"
		{call "mass_update"}	
		{if tagged "move"
			{if tagged "max_overload"
				(define "blast"
					{if rand 0.01
						{if not tagged %1
							{spawn "ex_wheel" %0}
							{impulse up 0.1 }
							{spawn "metal_crush" }
							{components %0 destroy}
							{tear "piece_medium_steel" bone %0
								{spawn "spheredust_small"}
								{burn volume %0 fx "dust_small" time 1 fake even_law}
								{impulse up 0.2 }
							}	
							{start_sound "vehicle/suspension_brake/"}
							{components %0 break}
							{ani_play "wheell_blast"}
							{tags add %1}
						}
					}
				)
				("blast" args "wheelleft2" "wheell2_b"  )
				("blast" args "wheelright2" "wheelr2_b"  )
			else tagged "overload"
				(define "blast"
					{if work %0
						{if rand 0.03
							{if not tagged %1
								{spawn "ex_wheel" %0}
								{impulse up 0.1 }
								{burn volume %0 fx "dust_small" time 1 fake even_law}
								{start_sound "vehicle/suspension_brake/"}
								{damage_report "body" "component/disk"}
								{components %0 break}
								{ani_play "wheell_blast"}
								{ani_play %1 1}
								{tags add %1}
							}
						}
					}
				)
				("blast" args "wheelleft2" "wheell2_b"  )
				("blast" args "wheelright2" "wheelr2_b"  )
			}
		}
	}
	; {events 
		; {0   "w_1"}
		; {15  "w_50"}
		; {25  "w_100"}
		; {35  "w_200"}
		; {70  "w_300"}
		; {120 "w_400"}
		; {150 "w_500"}
		; {180 "w_600"}
		; {210 "w_700"}
		; {240 "w_800"}
		; {270 "w_900"}
		; {300 "w_1000"}
		; {330 "w_1100"}
		; {350 "w_1200"}
		; {380 "w_1300"}
		; {390 "w_1400"}
		; {410 "w_1500"}
		; {425 "w_1600"}
		; {440 "w_1700"}
		; {460 "w_1800"}
		; {480 "w_1900"}
		; {500 "w_2000"}
	; }
	(define "weight"
		{on animation_event "%event"
			{if tagged "%tagged_weight"	
				{ani_stop "weight_full" }
			}
		}
	)
	;                      
	("weight" event(w_1) tagged_weight(0_mass) )
	("weight" event(w_50) tagged_weight(50_mass) )
	("weight" event(w_100) tagged_weight(100_mass) )
	("weight" event(w_200) tagged_weight(200_mass) )
	("weight" event(w_300) tagged_weight(300_mass) )
	("weight" event(w_400) tagged_weight(400_mass) )
	("weight" event(w_500) tagged_weight(500_mass) )
	("weight" event(w_600) tagged_weight(600_mass) )
	("weight" event(w_700) tagged_weight(700_mass) )
	("weight" event(w_800) tagged_weight(800_mass) )
	("weight" event(w_900) tagged_weight(900_mass) )
	("weight" event(w_1000) tagged_weight(1000_mass) )
	("weight" event(w_1100) tagged_weight(1100_mass) )
	("weight" event(w_1200) tagged_weight(1200_mass) )
	("weight" event(w_1300) tagged_weight(1300_mass) )
	("weight" event(w_1400) tagged_weight(1400_mass) )
	("weight" event(w_1500) tagged_weight(1500_mass) )
	("weight" event(w_1600) tagged_weight(1600_mass) )
	("weight" event(w_1700) tagged_weight(1700_mass) )
	("weight" event(w_1800) tagged_weight(1800_mass) )
	("weight" event(w_1900) tagged_weight(1900_mass) )
	("weight" event(w_2000) tagged_weight(2000_mass) )
	{on "mass_update"
		{if min_mass 10000
			{if not tagged "max_overload"
				(define "weight"
					{if tagged %0
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	+1  -1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "max_overload"}
				{tags add "2500"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 8800
			{if not tagged "2000_mass"
				{movement_limit slow}
				{tags add "overload"}
				{tags add "2000_mass"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				("weight" args "1900_mass" 	+1  -1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 8200
			{if not tagged "1900_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1900_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 8000
			{if not tagged "1800_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1800_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 7800
			{if not tagged "1700_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1700_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 7400
			{if not tagged "1600_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1600_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 7200
			{if not tagged "1500_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1500_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 6800
			{if not tagged "1400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{tags add "1400_mass"}
			}
		else min_mass 6400
			{if not tagged "1300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1300_mass"}
			}
		else min_mass 5800
			{if not tagged "1200_mass"
				{call "check_work_mover"}
				{start_sound "amb_emitters/car_blasted/"}				
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1200_mass"}
			}
		else min_mass 5400
			{if not tagged "1100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1100_mass"}
			}
		else min_mass 5000
			{if not tagged "1000_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1000_mass"}
			}
		else min_mass 4600
			{if not tagged "900_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "900_mass"}
			}
		else min_mass 4400
			{if not tagged "800_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "800_mass"}
			}
		else min_mass 4200
			{if not tagged "700_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "700_mass"}
			}
		else min_mass 4100
			{if not tagged "600_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "600_mass"}
			}
		else min_mass 4000
			{if not tagged "500_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "500_mass"}
			}
		else min_mass 3900
			{if not tagged "400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "400_mass"}
			}
		else min_mass 3800
			{if not tagged "300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "300_mass"}
			}
		else min_mass 3700
			{if not tagged "200_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "200_mass"}
			}
		else min_mass 3600
			{if not tagged "100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "100_mass"}
			}
		else min_mass 3550
			{if not tagged "50_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "100_mass" 	-1  +1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "50_mass"}
			}
		else min_mass 3450
			{if not tagged "0_mass"
				{call "check_work_mover"}
				{tags add "0_mass"}
				{tags remove "overload"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-3  +1 	)
				("weight" args "1900_mass" 	-3  +1 	)
				("weight" args "1800_mass" 	-3  +1 	)
				("weight" args "1700_mass" 	-3  +1 	)
				("weight" args "1600_mass" 	-3  +1 	)
				("weight" args "1500_mass" 	-3  +1 	)
				("weight" args "1400_mass" 	-3  +1 	)
				("weight" args "1300_mass" 	-3  +1 	)
				("weight" args "1200_mass" 	-3  +1 	)
				("weight" args "1100_mass" 	-3  +1 	)
				("weight" args "1000_mass" 	-3  +1 	)
				("weight" args "900_mass" 	-3  +1 	)
				("weight" args "800_mass" 	-3  +1 	)
				("weight" args "700_mass" 	-3  +1 	)
				("weight" args "600_mass" 	-3  +1 	)
				("weight" args "500_mass" 	-3  +1 	)
				("weight" args "400_mass" 	-3  +1 	)
				("weight" args "300_mass" 	-3  +1 	)
				("weight" args "200_mass" 	-3  +1 	)
				("weight" args "100_mass" 	-3  +1 	)
				("weight" args "50_mass" 	-1  +1 	)
			}
		}
	}
	{on "clear_weight"
		{tags remove "1600_mass"}
		{tags remove "1200_mass"}
		{tags remove "800_mass"}
		{tags remove "400_mass"}
		{tags remove "200_mass"}
	}
}
{"weight_2300"
	{on animation_event "update_mass"
		{call "mass_update"}	
		{if tagged "overload"
			{if tagged "move"
				(define "blast"
					{if work %0
						{if rand 0.03
							{if not tagged %1
								{spawn "ex_wheel" %0}
								{impulse up 0.1 }
								{burn volume %0 fx "dust_small" time 1 fake even_law}
								{start_sound "vehicle/suspension_brake/"}
								{damage_report "body" "component/disk"}
								{components %0 break}
								{ani_play "wheell_blast"}
								{ani_play %1 1}
								{tags add %1}
							}
						}
					}
				)
				("blast" args "wheelleft2" "wheell2_b"  )
				("blast" args "wheelright2" "wheelr2_b"  )
			}
		}
	}
	; {events 
		; {0   "w_1"}
		; {15  "w_50"}
		; {25  "w_100"}
		; {35  "w_200"}
		; {70  "w_300"}
		; {120 "w_400"}
		; {150 "w_500"}
		; {180 "w_600"}
		; {210 "w_700"}
		; {240 "w_800"}
		; {270 "w_900"}
		; {300 "w_1000"}
		; {330 "w_1100"}
		; {350 "w_1200"}
		; {380 "w_1300"}
		; {390 "w_1400"}
		; {410 "w_1500"}
		; {425 "w_1600"}
		; {440 "w_1700"}
		; {460 "w_1800"}
		; {480 "w_1900"}
		; {500 "w_2000"}
	; }
	(define "weight"
		{on animation_event "%event"
			{if tagged "%tagged_weight"	
				{ani_stop "weight_full" }
			}
		}
	)
	;                      
	("weight" event(w_1) tagged_weight(0_mass) )
	("weight" event(w_50) tagged_weight(50_mass) )
	("weight" event(w_100) tagged_weight(100_mass) )
	("weight" event(w_200) tagged_weight(200_mass) )
	("weight" event(w_300) tagged_weight(300_mass) )
	("weight" event(w_400) tagged_weight(400_mass) )
	("weight" event(w_500) tagged_weight(500_mass) )
	("weight" event(w_600) tagged_weight(600_mass) )
	("weight" event(w_700) tagged_weight(700_mass) )
	("weight" event(w_800) tagged_weight(800_mass) )
	("weight" event(w_900) tagged_weight(900_mass) )
	("weight" event(w_1000) tagged_weight(1000_mass) )
	("weight" event(w_1100) tagged_weight(1100_mass) )
	("weight" event(w_1200) tagged_weight(1200_mass) )
	("weight" event(w_1300) tagged_weight(1300_mass) )
	("weight" event(w_1400) tagged_weight(1400_mass) )
	("weight" event(w_1500) tagged_weight(1500_mass) )
	("weight" event(w_1600) tagged_weight(1600_mass) )
	("weight" event(w_1700) tagged_weight(1700_mass) )
	("weight" event(w_1800) tagged_weight(1800_mass) )
	("weight" event(w_1900) tagged_weight(1900_mass) )
	("weight" event(w_2000) tagged_weight(2000_mass) )
	{on "mass_update"
		{if min_mass 7200
			{if not tagged "2000_mass"
				{movement_limit slow}
				{tags add "overload"}
				{tags add "2000_mass"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				("weight" args "1900_mass" 	+1  -1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 7000
			{if not tagged "1900_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	+1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{movement_limit slow}
				{tags add "1900_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 6800
			{if not tagged "1800_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	+1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1800_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 6600
			{if not tagged "1700_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1700_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 6400
			{if not tagged "1600_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1600_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 6200
			{if not tagged "1500_mass"
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	-1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{movement_limit slow}
				{tags add "1500_mass"}
				{start_sound "amb_emitters/car_blasted/"}				
			}
		else min_mass 5800
			{if not tagged "1400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  -1 	)
				("weight" args "1800_mass" 	-1  -1 	)
				("weight" args "1700_mass" 	-1  -1 	)
				("weight" args "1600_mass" 	-1  -1 	)
				("weight" args "1500_mass" 	-1  -1 	)
				("weight" args "1300_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1400_mass"}
			}
		else min_mass 5400
			{if not tagged "1300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	+1  -1 	)
				("weight" args "1500_mass" 	+1  -1 	)
				("weight" args "1400_mass" 	+1  -1 	)
				("weight" args "1200_mass" 	+1  -1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1300_mass"}
			}
		else min_mass 4800
			{if not tagged "1200_mass"
				{call "check_work_mover"}
				{start_sound "amb_emitters/car_blasted/"}				
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	+1  -1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1200_mass"}
			}
		else min_mass 4400
			{if not tagged "1100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	+1  -1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1100_mass"}
			}
		else min_mass 4000
			{if not tagged "1000_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "900_mass" 	+1  -1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "1000_mass"}
			}
		else min_mass 3600
			{if not tagged "900_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "800_mass" 	+1  -1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "900_mass"}
			}
		else min_mass 3200
			{if not tagged "800_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "700_mass" 	+1  -1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "800_mass"}
			}
		else min_mass 3100
			{if not tagged "700_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "600_mass" 	+1  -1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "700_mass"}
			}
		else min_mass 3000
			{if not tagged "600_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "500_mass" 	+1  -1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "600_mass"}
			}
		else min_mass 2900
			{if not tagged "500_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "400_mass" 	+1  -1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "500_mass"}
			}
		else min_mass 2800
			{if not tagged "400_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "300_mass" 	+1  -1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "400_mass"}
			}
		else min_mass 2700
			{if not tagged "300_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "200_mass" 	+1  -1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "300_mass"}
			}
		else min_mass 2600
			{if not tagged "200_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "100_mass" 	+1  -1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "200_mass"}
			}
		else min_mass 2500
			{if not tagged "100_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "50_mass" 	+1  -1 	)
				("weight" args "0_mass" 		+1  -1 	)
				{tags add "100_mass"}
			}
		else min_mass 2400
			{if not tagged "50_mass"
				{call "check_work_mover"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-1  +1 	)
				("weight" args "1900_mass" 	-1  +1 	)
				("weight" args "1800_mass" 	-1  +1 	)
				("weight" args "1700_mass" 	-1  +1 	)
				("weight" args "1600_mass" 	-1  +1 	)
				("weight" args "1500_mass" 	-1  +1 	)
				("weight" args "1400_mass" 	-1  +1 	)
				("weight" args "1300_mass" 	-1  +1 	)
				("weight" args "1200_mass" 	-1  +1 	)
				("weight" args "1100_mass" 	-1  +1 	)
				("weight" args "1000_mass" 	-1  +1 	)
				("weight" args "900_mass" 	-1  +1 	)
				("weight" args "800_mass" 	-1  +1 	)
				("weight" args "700_mass" 	-1  +1 	)
				("weight" args "600_mass" 	-1  +1 	)
				("weight" args "500_mass" 	-1  +1 	)
				("weight" args "400_mass" 	-1  +1 	)
				("weight" args "300_mass" 	-1  +1 	)
				("weight" args "200_mass" 	-1  +1 	)
				("weight" args "100_mass" 	-1  +1 	)
				("weight" args "0_mass" 	+1  -1 	)
				{tags add "50_mass"}
			}
		else min_mass 2200
			{if not tagged "0_mass"
				{call "check_work_mover"}
				{tags add "0_mass"}
				{tags remove "overload"}
				(define "weight"
					{if tagged %0
						{ani_play "weight_full" %1 resume}
						{tags remove %0}
					}
				)
				;						in out
				("weight" args "2000_mass" 	-3  +1 	)
				("weight" args "1900_mass" 	-3  +1 	)
				("weight" args "1800_mass" 	-3  +1 	)
				("weight" args "1700_mass" 	-3  +1 	)
				("weight" args "1600_mass" 	-3  +1 	)
				("weight" args "1500_mass" 	-3  +1 	)
				("weight" args "1400_mass" 	-3  +1 	)
				("weight" args "1300_mass" 	-3  +1 	)
				("weight" args "1200_mass" 	-3  +1 	)
				("weight" args "1100_mass" 	-3  +1 	)
				("weight" args "1000_mass" 	-3  +1 	)
				("weight" args "900_mass" 	-3  +1 	)
				("weight" args "800_mass" 	-3  +1 	)
				("weight" args "700_mass" 	-3  +1 	)
				("weight" args "600_mass" 	-3  +1 	)
				("weight" args "500_mass" 	-3  +1 	)
				("weight" args "400_mass" 	-3  +1 	)
				("weight" args "300_mass" 	-3  +1 	)
				("weight" args "200_mass" 	-3  +1 	)
				("weight" args "100_mass" 	-3  +1 	)
				("weight" args "50_mass" 	-1  +1 	)
			}
		}
	}
	{on "clear_weight"
		{tags remove "1600_mass"}
		{tags remove "1200_mass"}
		{tags remove "800_mass"}
		{tags remove "400_mass"}
		{tags remove "200_mass"}
	}
}
