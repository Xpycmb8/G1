(define "distance_1" 
	{spreading 
		{radiusTable {10 0.01} {50 %r1} {80 %r2} {120 %r3} {150 %r4} {500 (* 5.00 %r4)}}
	}		
)

(define "distance_2" 
	{spreading 
		{radiusTable {10 0.01} {25 %r1} {50 %r2} {120 %r3} {160 %r4} {800 (* 2.50 %r4)}}
	}		
)
(define "distance_3" 
	{spreading 
		{radiusTable {10 0.01} {25 %r1} {50 %r2} {120 %r3} {160 %r4} {800 (* 2.25 %r4)}}
	}		
)
(define "distance_4" 
	{spreading 
		{radiusTable {10 0.01} {25 %r1} {50 %r2} {120 %r3} {160 %r4} {800 (* 2.00 %r4)}}
	}		
)
(define "distance_5" 
	{spreading 
		{radiusTable {10 0.01} {100 %r1} {250 %r2} {450 %r3} {700 %r4} {900 (* 2.50 %r4)}}
	}		
)

;----------------------------pistol
(define "distance_pistol" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 1 	%r1)}
			{75		(* 2	%r1)}
			{100	(* 3 	%r1)}
			{125	(* 3.5  %r1)}
			{150	(* 5 	%r1)}
			{200	(* 6	%r1)}
			{350	(* 8 	%r1)}
		}
	}		
)
(define "distance_pistol_heavy" 
	{spreading 
		{radiusTable {10 0.01} {50 %r1} {90 %r2} {120 %r3} {160 %r4} {200 %r5}}
	}		
)
(define "accuracy_pistol_short_sp_9x19"
	("distance_pistol" r1(2.5))
)

(define "accuracy_pistol_short_ap_9x19"
	("distance_pistol" r1(2))
)
(define "accuracy_pistol_med_sp_9x19"
	("distance_pistol" r1(2))
)

(define "accuracy_pistol_med_ap_9x19"
	("distance_pistol" r1(1.5))
)
(define "accuracy_pistol_long_sp_9x19"
	("distance_pistol" r1(1))
)

(define "accuracy_pistol_long_ap_9x19"
	("distance_pistol" r1(0.5))
)

(define "accuracy_pistol_med_sp_127x33"
	("distance_pistol" r1(2))
)

(define "accuracy_pistol_med_ap_127x33"
	("distance_pistol" r1(1.5))
)

(define "accuracy_pistol_long_sp_127x33"
	("distance_pistol" r1(1.75))
)

(define "accuracy_pistol_long_ap_127x33"
	("distance_pistol" r1(1.2))
)

(define "accuracy_pistol_short_sp_11x23"
	("distance_pistol" r1(1.25))
)

(define "accuracy_pistol_short_ap_11x23"
	("distance_pistol" r1(1))
)

(define "accuracy_pistol_med_sp_11x23"
	("distance_pistol" r1(1))
)

(define "accuracy_pistol_med_ap_11x23"
	("distance_pistol" r1(0.75))
)

(define "accuracy_pistol_long_sp_11x23"
	("distance_pistol" r1(0.5))
)

(define "accuracy_pistol_long_ap_11x23"
	("distance_pistol" r1(0.35))
)




;------------MGUN
(define "distance_short_barrel_mg" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 1 	%r1)}
			{75		(* 2	%r1)}
			{100	(* 3 	%r1)}
			{150	(* 3.5  %r1)}
			{200	(* 5 	%r1)}
			{350	(* 6	%r1)}
			{500	(* 8 	%r1)}
		}
	}		
)
(define "distance_med_barrel_mg" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.55 %r1)}
			{75		(* 0.9	%r1)}
			{100	(* 1.5 %r1)}
			{150	(* 2.5  %r1)}
			{200	(* 3.5 	%r1)}
			{350	(* 4	%r1)}
			{500	(* 7 	%r1)}
			{700	(* 9 	%r1)}
			{1000	(* 15 	%r1)}
		}
	}		
)
(define "distance_long_barrel_mg" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.45 %r1)}
			{75		(* 0.75	%r1)}
			{100	(* 1.25 %r1)}
			{150	(* 2.5  %r1)}
			{200	(* 3 	%r1)}
			{350	(* 4.5	%r1)}
			{500	(* 5.5 	%r1)}
			{700	(* 7 	%r1)}
			{1000	(* 9 	%r1)}
		}
	}		
)
;---
;------short_barrel
(define "accuracy_mg_short_sp_556"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(2))
)
(define "accuracy_mg_short_ap_556"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.5))
)

(define "accuracy_mg_short_sp_545"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.75))
)
(define "accuracy_mg_short_ap_545"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.5))
)


(define "accuracy_mg_short_sp_762"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.5))
)
(define "accuracy_mg_short_ap_762"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.25))
)
(define "accuracy_mg_short_fg_762"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.25))
)

(define "accuracy_mg_short_sp_127"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(2))
)
(define "accuracy_mg_short_ap_127"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_mg" r1(1.5))
)

;------med_barrel
(define "accuracy_mg_med_sp_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_mg" r1(1.2))
)
(define "accuracy_mg_med_ap_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_mg" r1(1))
)
(define "accuracy_mg_med_fg_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_mg" r1(1.75))
)

(define "accuracy_mg_med_sp_545"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.35) r2(1.2) r3(2.3) r4(4.8) 		r5(6) 	r6(8))
	("distance_med_barrel_mg" r1(1.4))
)
(define "accuracy_mg_med_ap_545"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.25) r2(0.8) r3(1.9) r4(3) 		r5(5) 	r6(7))
	("distance_med_barrel_mg" r1(1.2))
)
(define "accuracy_mg_med_fg_545"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.60) r2(1.70) r3(3.2) r4(6) 		r5(8) 	r6(12))
	("distance_med_barrel_mg" r1(1.75))
)

(define "accuracy_mg_med_sp_762"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) 		r5(6) r6(7.3))
	("distance_med_barrel_mg" r1(1))
)
(define "accuracy_mg_med_fg_762"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" 	r1(0.75) r2(2) 	  r3(3.5) 	r4(7) 		r5(8.5) r6(12))
	("distance_med_barrel_mg" r1(1.35))
)
(define "accuracy_mg_med_ap_762"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) 		r5(5.75) r6(6.3))
	("distance_med_barrel_mg" r1(0.8))
)
(define "accuracy_mg_med_sp_127"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(3.25) 		r5(4.5) r6(6))
	("distance_med_barrel_mg" r1(2))
)
(define "accuracy_mg_med_ap_127"
	;							50	     75       100 		150			200		350
	;("distance_med_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(3.25) 		r5(4) r6(5.5))
	("distance_med_barrel_mg" r1(1.6))
)

;--------------------------------------------
;------long_barrel
(define "accuracy_mg_long_sp_556"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(6) 	r6(8))
	("distance_long_barrel_mg" r1(0.8))
)
(define "accuracy_mg_long_ap_556"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.25) r2(1.40) r3(2.75) r4(5.25) 		r5(6.5) r6(8))
	("distance_long_barrel_mg" r1(0.6))
)
(define "accuracy_mg_long_fg_556"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.4) r2(1.70) r3(2.75) r4(5.25) 		r5(6.5) r6(8))
	("distance_long_barrel_mg" r1(1.2))
)
(define "accuracy_mg_long_sp_762"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(0.6))
)
(define "accuracy_mg_long_ap_762"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(0.45))
)
(define "accuracy_mg_long_sp_792"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.25) r2(1.10) r3(2.1) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(0.55))
)
(define "accuracy_mg_long_ap_792"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(0.4))
)
(define "accuracy_mg_long_sp_127"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(1))
)
(define "accuracy_mg_long_ap_127"
	;							50	     75       100 		150			200		350
	;("distance_long_barrel_mg" r1(0.40) r2(1.40) r3(2.75) r4(5.25) r5(5.25) 	r6(5.25))
	("distance_long_barrel_mg" r1(0.6))
)





;--------------------------------
;------------AR
(define "distance_short_barrel_ar" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 1 	%r1)}
			{75		(* 2	%r1)}
			{100	(* 3 	%r1)}
			{150	(* 3.5  %r1)}
			{200	(* 6 	%r1)}
			{350	(* 7	%r1)}
			{450	(* 9 	%r1)}
		}
	}		
)
(define "distance_med_barrel_ar" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.75 %r1)}
			{75		(* 1.25	%r1)}
			{100	(* 2.25 %r1)}
			{150	(* 3.5  %r1)}
			{200	(* 4 	%r1)}
			{350	(* 6	%r1)}
			{450	(* 8 	%r1)}
			{600	(* 12 	%r1)}
			{800	(* 18 	%r1)}
		}
	}		
)
(define "distance_long_barrel_ar" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.75 %r1)}
			{75		(* 1.25	%r1)}
			{100	(* 2.25 %r1)}
			{150	(* 3.5  %r1)}
			{200	(* 4 	%r1)}
			{350	(* 5.5	%r1)}
			{600	(* 7 	%r1)}
			{800	(* 9.5 	%r1)}
			{900	(* 11 	%r1)}
		}
	}		
)
;---
;------short_barrel
(define "accuracy_ar_short_sp_556"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(1.8))
)
(define "accuracy_ar_short_ap_556"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(1.5))
)
(define "accuracy_ar_short_fg_556"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(1.1))
)
;------short_barrel_9,19
(define "accuracy_ar_short_sp_919"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(2))
)
(define "accuracy_ar_short_ap_919"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(1.7))
)
(define "accuracy_ar_short_fg_919"
	;							50	     75       100 		150			200		350
	("distance_short_barrel_ar" r1(1.5))
)
;------med_barrel
(define "accuracy_ar_med_sp_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_ar" r1(1.2))
)
(define "accuracy_ar_med_ap_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_ar" r1(1))
)
(define "accuracy_ar_med_fg_556"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_ar" r1(1.75))
)
;------long_barrel
(define "accuracy_ar_long_sp_556"
	;							50	     75       100 		150			200		350
	("distance_long_barrel_ar" r1(1.1))
)
(define "accuracy_ar_long_ap_556"
	;							50	     75       100 		150			200		350
	("distance_long_barrel_ar" r1(0.9))
)
(define "accuracy_ar_long_fg_556"
	;							50	     75       100 		150			200		350
	("distance_long_barrel_ar" r1(1.5))
)




;--------------------------------
;------------Rifle
(define "distance_short_barrel_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.75 %r1)}
			{75		(* 1.5	%r1)}
			{100	(* 2 	%r1)}
			{150	(* 2.5  %r1)}
			{200	(* 3 	%r1)}
			{350	(* 5.5	%r1)}
			{450	(* 7 	%r1)}
		}
	}		
)
(define "distance_med_barrel_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.5  %r1)}
			{75		(* 1.25	%r1)}
			{100	(* 1.75 %r1)}
			{150	(* 2    %r1)}
			{200	(* 2.5 	%r1)}
			{350	(* 4	%r1)}
			{450	(* 6 	%r1)}
			{600	(* 9 	%r1)}
			{800	(* 14 	%r1)}
		}
	}		
)
(define "distance_long_barrel_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.35 %r1)}
			{75		(* 0.75	%r1)}
			{100	(* 1 	%r1)}
			{150	(* 1.25 %r1)}
			{200	(* 2 	%r1)}
			{350	(* 3	%r1)}
			{600	(* 5 	%r1)}
			{800	(* 7 	%r1)}
			{900 	(* 8 	%r1)}
		}
	}		
)
;---
;------med_barrel
(define "accuracy_rifle_med_sp_762"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_rifle" r1(1.2))
)
(define "accuracy_rifle_med_ap_762"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_rifle" r1(1))
)
(define "accuracy_rifle_med_fg_762"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_rifle" r1(1.75))
)




;------------Rifle
(define "distance_short_barrel_sn_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.75 %r1)}
			{75		(* 1.5	%r1)}
			{100	(* 2 	%r1)}
			{150	(* 2.5  %r1)}
			{200	(* 3 	%r1)}
			{350	(* 5.5	%r1)}
			{450	(* 7 	%r1)}
		}
	}		
)
(define "distance_med_barrel_sn_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.5  %r1)}
			{75		(* 1.25	%r1)}
			{100	(* 1.75 %r1)}
			{150	(* 2    %r1)}
			{200	(* 2.5 	%r1)}
			{350	(* 4	%r1)}
			{450	(* 6 	%r1)}
			{600	(* 9 	%r1)}
			{800	(* 14 	%r1)}
		}
	}		
)
(define "distance_long_barrel_sn_rifle" 
	{spreading 
		{radiusTable 
			{10 			0.01} 
			{25 			%r1} 
			{50 	(* 0.35 %r1)}
			{75		(* 0.75	%r1)}
			{100	(* 1 	%r1)}
			{150	(* 1.25 %r1)}
			{200	(* 2 	%r1)}
			{350	(* 3	%r1)}
			{600	(* 5 	%r1)}
			{800	(* 7 	%r1)}
			{900 	(* 8 	%r1)}
		}
	}		
)
;---



(define "accuracy_sn_rifle_med_sp_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(1.2))
)
(define "accuracy_sn_rifle_med_ap_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(1))
)
(define "accuracy_sn_rifle_med_fg_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(1.75))
)

(define "accuracy_sn_rifle_long_sp_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(1))
)
(define "accuracy_sn_rifle_long_ap_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(0.75))
)
(define "accuracy_sn_rifle_long_fg_127"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(1.5))
)


(define "accuracy_sn_rifle_med_sp_762"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(0.7))
)
(define "accuracy_sn_rifle_med_ap_762"
	;							50	     75       100 		150			200		350
	("distance_med_barrel_sn_rifle" r1(0.45))
)


(define "accuracy_assault"
	("distance_2" r1(0.70) r2(1.90) r3(3.25) r4(4.25))
)

(define "accuracy_assault_boost"
	("distance_2" r1(0.55) r2(1.80) r3(3.00) r4(3.50))
)

(define "accuracy_assault_boost2"
	("distance_2" r1(0.425) r2(1.55) r3(2.725) r4(3.95))
)



(define "accuracy_smg"
	("distance_1" r1(0.85) r2(1.95) r3(2.10) r4(3.90))
)
(define "accuracy_smg_short"
	("distance_1" r1(1.25) r2(2.35) r3(2.70) r4(5.90))
)

(define "accuracy_smg_short_muzzle"
	("distance_1" r1(1.25) r2(2.1) r3(2.2) r4(5.2))
)

(define "accuracy_smg_boost"
	("distance_1" r1(0.70) r2(1.75) r3(2.95) r4(3.60))
)
(define "accuracy_smg_boost_short"
	("distance_1" r1(1.20) r2(2.5) r3(3.2) r4(5))
)

(define "accuracy_smg_boost_sd"
	("distance_1" r1(0.70) r2(1.6) r3(2.5) r4(3.20))
)
(define "accuracy_smg_lower"
	("distance_1" r1(0.95) r2(2.25) r3(3.95) r4(4.60))
)

(define "accuracy_smg_boost_long_barrel"
	("distance_1" r1(0.45) r2(1.25) r3(2.25) r4(3))
)

(define "accuracy_smg_boost_ap"
	("distance_1" r1(0.52) r2(1.50) r3(2.25) r4(2.70))
)

(define "accuracy_smg_boost2"
	("distance_1" r1(0.575) r2(1.50) r3(2.675) r4(3.10))
)

(define "accuracy_smg_boost3"
	("distance_1" r1(0.475) r2(1.20) r3(2.1) r4(2.70))
)

(define "accuracy_grenade_launcher"
	("distance_3" r1(0.90) r2(1.90) r3(3.15) r4(7.50))
)

(define "accuracy_grenade_launcher_boost"
	("distance_3" r1(0.85) r2(1.80) r3(3.00) r4(7.30))
)


(define "accuracy_sniper_rifle"
	("distance_5" r1(4) r2(6) r3(9) r4(15))
)
(define "accuracy_sniper_rifle_long"
	("distance_5" r1(2) r2(4) r3(6) r4(10))
)
(define "accuracy_sniper_rifle_long_skir"
	("distance_5" r1(0.4) r2(1.5) r3(3) r4(7))
)
(define "accuracy_shotgun_long_skir"
	("distance_1" r1(0.4) r2(2) r3(3) r4(8))
)
(define "accuracy_mg_long"
	("distance_4" r1(0.75) r2(1.70) r3(2.90) r4(3.35))
)

(define "accuracy_shotgun_lb"
	("distance_1" r1(0.25) r2(0.75) r3(1.75) r4(2.2))
)

(define "accuracy_shotgun_mb"
	("distance_1" r1(0.45) r2(1.25) r3(2.25) r4(3))
)



(define "distance_flaer"
	{spreading
		{radiusTable {0 0} {20 %r1} {40 %r2} {80 %r3} {120 %r4}}
	}
)
(define "distance_bonic_callin"
	{spreading
		{radiusTable {0 0} {1000 0}}
	}
)
(define "distance_rifle"
	{spreading
		{radiusTable {0 0} {15 %r1} {35 %r2} {70 %r3} {100 %r4}}
	}
)
(define "distance_rifle_scope"
	{spreading
		{radiusTable {0 0} {15 %r1} {35 %r2} {70 %r3} {100 %r4} {140 %r5}}
	}
)
(define "distance_at"
	{spreading
		{radiusTable {0 0} {20 %r1} {40 %r2} {80 %r3} {120 %r4}}
	}
)

(define "accuracy_smg_low"
	("distance_1" r1(0.385) r2(1.925) r3(4.40)) 		;old r1(0.35) r2(1.75) r3(4.00)
)
(define "accuracy_smg_high"
	("distance_1" r1(0.275) r2(1.375) r3(3.575)) 		;old r1(0.25) r2(1.25) r3(3.25)
)

(define "accuracy_scoped"
	("distance_rifle_scope" r1(0.45) r2(0.65) r3(1.30) r4(1.70) r5(2.00))
)

(define "accuracy_rifle"
	("distance_rifle" r1(0.385) r2(0.66) r3(1.43) r4(1.98))		;old r1(0.35) r2(0.60) r3(1.30) r4(1.80)
)

(define "accuracy_automatic_rifle"
	("distance_rifle" r1(0.40) r2(0.70) r3(1.50) r4(2.05))		;old r1(0.40) r2(0.65) r3(1.40) r4(2.00)
)

(define "accuracy_carabine"
	("distance_rifle" r1(0.45) r2(1.00) r3(1.50) r4(2.50))	;old r1(0.45) r2(0.95) r3(1.80) r4(2.75)
)

(define "accuracy_assault_rifle"
	("distance_rifle" r1(0.6) r2(0.8) r3(0.89) r4(1.02))		;old r1(0.75) r2(1.00) r3(2.10) r4(3.50)
)

(define "accuracy_assault_rifle_scoped"
	("distance_rifle" r1(0.43) r2(0.55) r3(0.61) r4(0.81))		;old r1(0.70) r2(0.95) r3(1.80) r4(2.90)
)


(define "accuracy_mgun_r"
	("distance_mg" r1(0.60) r2(0.96) r3(1.80) r4(2.88) r5(3.5))	;old r1(0.50) r2(0.80) r3(1.50) r4(2.40) r5(2.75)
)

(define "accuracy_ptr"
	("distance_at" r1(0.50) r2(1.00) r3(1.70) r4(2.50))
)
(define "accuracy_ptr_bolt"
	("distance_at" r1(0.25) r2(0.75) r3(1.25) r4(2.00))
)

(define "accuracy_dshk"
	("distance_mg" r1(0.60) r2(0.90) r3(1.74) r4(2.76) r5(3.12))	;old r1(0.50) r2(0.75) r3(1.45) r4(2.30) r5(2.60)
)
;=================
(define "accuracy_detect"
	("distance_4" r1(25) r2(32) r3(40) r4(55))
)

(define "accuracy_mg"
	("distance_long_barrel_mg" r1(1.2))
)
(define "accuracy_hmg"
	("distance_mg" r1(0.60) r2(0.90) r3(1.74) r4(2.76) r5(3.12))	;old r1(0.50) r2(0.75) r3(1.45) r4(2.30) r5(2.60)
)
(define "accuracy_hmg_tank"
	("distance_mg" r1(0.60) r2(0.90) r3(1.74) r4(2.76) r5(3.12))	;old r1(0.50) r2(0.75) r3(1.45) r4(2.30) r5(2.60)
)

(define "accuracy_mg_plane"
	("distance_long_barrel_mg" r1(1.1))
)

(define "accuracy_pistol"
	("distance_1" r1(0.85) r2(1.95) r3(2.10) r4(3.90))
)

(define "accuracy_smg"
	("distance_1" r1(0.85) r2(1.95) r3(2.10) r4(3.90))
)

;/*----------------------*/

(define "accuracy_rifle_sniper"
	("distance_rifle" r0(0.2) r1(0.4) r2(0.8) r3(1.00) )
)
(define "accuracy_rifle_auto"
	("distance_rifle"	r0(0.2) r1(0.5) r2(1.0) r3(1.50) )
)
(define "accuracy_rifle_auto_sniper"
	("distance_rifle" r0(0.4) r1(0.5) r2(1.0) r3(1.50) )
)
(define "accuracy_shotgun"
	("distance_rifle"	r0(0.2) r1(1.4) r2(0.9) r3(1.25) )
)
(define "accuracy_rifle_at"
	("distance_rifle"	r0(0.4) r1(0.8) r2(1.2) r3(1.50) )
)

;/*----------------------*/

