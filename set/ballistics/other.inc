;new_recoil_angle


(define "recoil_verylow"
	{recoil
		{shoot {0.45 0.37} {0 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 7 7}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_short_boost"
	{recoil
		{shoot {0.47 0.41} {0 0.6}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 7.5 7.5}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_low"
	{recoil
		{shoot {0.55 0.40} {0 0.9}}			; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 9 9}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_low_boost"
	{recoil
		{shoot {0.5 0.35} {0 0.6}}			; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8.5 8.5}					; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_medium"
	{recoil
		{shoot {0.7 0.45} {0 0.15}}
		{maxAngle 10 10}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)
(define "recoil_medium_boost"
	{recoil
		{shoot {0.6 0.3} {0 0.1}}
		{maxAngle 9.5 9.5}					; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)

(define "recoil_high"
	{recoil
		{shoot {1 0.5} {0 0.4}}
		{maxAngle 12 12}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)
(define "recoil_high_boost"
	{recoil
		{shoot {0.85 0.35} {0 0.2}}
		{maxAngle 1 1}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)
(define "recoil_ash_short"
	{recoil
		{shoot {0.7 0.4} {0 0.8}}
		{maxAngle 10 10}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)

(define "recoil_ash_long"
	{recoil
		{shoot {0.9 0.5} {0 0.6}}
		{maxAngle 9 9}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)


(define "recoil_high_d" ;de_2v
	{recoil
		{shoot {3 2.25} {1 3}}				; качка / +- Рандом и отклонение / +- Рандом, За выстрел, В градусах
		{maxAngle 20 25 }					; Макс угол выстрела (качка/yaw), В градусах
		{restoreTime 0.25 0.005}			; Время востеновления, Первый -> Мин время, Второй -> Добавление за выстрел
		{restoreDelay 999}					; Время востановления в секундах
	}
)


(define "recoil_long_at_rifle"
	{recoil
		{shoot {1.2 0.35} {0 0.9}}
		{maxAngle 8 8}
		{restoreTime 0.25 0.012}
		{restoreDelay 9999}
	}
)

(define "recoil_long_at_rifle_sup"
	{recoil
		{shoot {0.9 0.27} {0 0.6}}
		{maxAngle 8 8}
		{restoreTime 0.25 0.012}
		{restoreDelay 9999}
	}
)

(define "recoil_medium_mgun"
	{recoil
		{shoot {0.6 0.3} {0 0.1}}
		{maxAngle 9.5 9.5}					; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)


(define "recoil_long_rifle"
	{recoil
		{shoot {0.7 0.32} {0 0.65}}
		{maxAngle 8 8}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)

(define "recoil_short_pistol"
	{recoil
		{shoot {0.3 0.15} {0 0.5}}			; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 7 7}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_short_pistol_nt"
	{recoil
		{shoot {0.15 0.05} {0 0.25}}			; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 3.5 3.5}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_short_auto_pistol"
	{recoil
		{shoot {0.25 0.12} {0 0.3}}			; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 4 4}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 9999}					; delay before restore, sec
	}
)

(define "recoil_long_pistol"
	{recoil
		{shoot {0.475 0.25} {0 0.535}}
		{maxAngle 8 8}
		{restoreTime 0.25 0.005}
		{restoreDelay 9999}
	}
)
(define "recoil_shotgun"
	{recoil
		{shoot {2.50 0.75} {1 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_rifle_at"
	{recoil
		{shoot {2.50 0.75} {1 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 1.10 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_pistol"
	{recoil
		{shoot {0.40 0.15} {0 0.45}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_stg"
	{recoil
		{shoot {0.45 0.20} {0 0.50}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_fg42"
	{recoil
		{shoot {0.55 0.20} {0.10 0.50}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_rifle_semi"
	{recoil
		{shoot {0.75 0.25} {0 0.60}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_rifle_bolt"
	{recoil
		{shoot {0.90 0.25} {0 0.60}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.5 0.025}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_sniper_semi"
	{recoil
		{shoot {1.20 0.25} {0 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_sniper_bolt"
	{recoil
		{shoot {1.50 0.25} {0 0.75}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 1.00 0.025}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_smg_low"
	{recoil
		{shoot {0.325 0.10} {0 0.2}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_smg_medium"
	{recoil
		{shoot {0.325 0.15} {0 0.25}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.15 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_mg_medium"
	{recoil
		{shoot {0.45 0.25} {0 0.515}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005}				; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

(define "recoil_hmg_medium"
	{recoil
		{shoot {0.50 0.25} {0 0.55}}		; pitch / +- random and yaw / +- random, per shot, degree
		{maxAngle 8 8}						; max recoil angle (pitch/yaw), degree
		{restoreTime 0.25 0.005	}			; recoil restore time, first -> minimum time, second -> additional time per shot, sec
		{restoreDelay 999}					; delay before restore, sec
	}
)

;------------------------
(define "minimumDamageModifier"
	{minimumDamageModifier (* 1.0 %m)}
	(mod "hardcore"
		{minimumDamageModifier (* 2.0 %m)}
	)
)
(define "accuracy_boost"
	{ZeroingAccuracy 0.75 0.5}
)
(define "speed"   
	{speed (* 1.0 %s)}  
)
(define "speed2"
	{speed (* 0.5 %s)}
	(mod "hardcore"
		{speed (* 0.5 %s)}
	)
)
(define "recoveryTime"   
	{recoveryTime (/ 60 %r)}
)
(define "speed_fg"   
	{speed (* 1.0 %s)}  
)
(define "damage_inc"
	{projectileDamageTable {10 %a} {50 %b} {70 %c} {90 %d} {120 %e} {400 0}}
)

(define "clickSound_ar"
	{clickSound "ar_dryfire"}
)

(define "clickSound_rifle"
	{clickSound "rifle_dryfire"}
)

(define "clickSound_smg"
	{clickSound "smg_dryfire"}
)

(define "clickSound_shotgun"
	{clickSound "shotgun_dryfire"}
)
(define "clickSound_revolver"
	{clickSound "revolver_dryfire"}
)

(define "clickSound_pistol"
	{clickSound "pistol_dryfire"}
)

(define "clickSound_pistol_02"
	{clickSound "pistol_dryfire_02"}
)

(define "armor health"
	{minimumDamageModifier (* 1.0 %damage)}
)
(define "penetration"			;// penetration table. penetration reduced after intended fire range to prevent explotation of Direct control
	{projectileDamageTable {75 %0} {80 0}}
)
(define "velocity"				;// muzzle velocity in meters per second
	{speed (* 0.70 %mps)}
)
(define "fire rate"				;// rate of fire in rounds per minute 
	{recoveryTime (/ 60 (* %rpm 1.083))}
)
(define "reload time"			;// reload time for magazine or shell
	{rechargeTime %seconds}
)
(define "human health"
	{healthDamage (* 1.0 %damage)}
)


;/*====================Slope Multiplier==================*/


(define "ap_slope_multiplier"	;use for AP and for any other Projectiles not specifically defined below
	{overmatchCalibre
		{0		0.96		0.0637	}
		{5		0.96297		0.0637	}
		{10		0.98297		0.0637	}
		{15		1.00066		0.0969	}
		{20		1.0361		0.13561	}
		{25		1.1116		0.16164	}
		{30		1.2195		0.19702	}
		{35		1.3771		0.22546	}
		{40		1.6263		0.26313	}
		{45		2.0033		0.34717	}
		{50		2.6447		0.57353	}
		{55		3.231		0.69075	}
		{60		4.0708		0.81826	}
		{65		6.2655		0.9192	}
		{70		8.6492		1.00539	}
		{75		13.7512		1.074	}
		{80		21.8713		1.17973	}
		{85		34.4862		1.28631	}
		{90		99.0000		0.00000	}
	}
)
(define "ap_7_62_slope_multiplier"	;	7.62mm - 8mm bullets, MG, rifles
	{overmatchCalibre
		{0		1			0.00	}
		{10		1.037		0.01	}
		{20		1.10		0.02	}
		{30		1.435		0.15	}
		{40		2.19		0.10	}
		{45		2.79		0.12	}
		{50		3.86		0.12	}
		{60		6.23		0.15	}
		{65		7.70		0.15	}
		{70		9.93		0.15	}
		{75		14.3		0.17	}
		{80		22.9		0.17	}
		{85		62.7		0.242	}
		{90		99.0000		0.00000	}
	}
)
(define "ap_12_slope_multiplier"	;	12.7mm bullets, HMG
	{overmatchCalibre
		{0		1			0.00	}
		{20		1.24		-0.015	}
		{30		1.59		0.015	}
		{40		1.885		0.11	}
		{45		2.395		0.15	}
		{50		3.32		0.14	}
		{60		5.43		0.185	}
		{65		6.78		0.192	}
		{70		8.85		0.193	}
		{75		12.75		0.21	}
		{80		22.17		0.245	}
		{85		69.6		0.36	}
		{90		99.0000		0.00000	}
	}
)

(define "at_rifle_slope_multiplier"	;use for AP and for any other Projectiles not specifically defined below
	{overmatchCalibre
		{0		0.1			0.0637	}
		{10		1.00066		0.0969	}
		{15		1.0361		0.13561	}
		{20		1.1116		0.16164	}
		{25		1.2195		0.19702	}
		{30		1.3771		0.22546	}
		{40		1.6263		0.26313	}
		{65		2.0033		0.34717	}
		{70		2.6447		0.57353	}
		{80		8.6492		1.00539	}
		{85		21.8713		1.17973	}
		{90		99.0000		0.00000	}
	}
)

(define "apcr_slope_multiplier"	;use for APCR & HVAP Projectiles 76mm Caliber or below
	{overmatchFixed
		{0  1.00	}
		{10	1.01	}
		{10	1.03	}
		{15	1.07	}
		{20	1.13	}
		{25	1.23	}
		{30	1.36	}
		{35	1.59	}
		{40	1.90	}
		{45	2.28	}
		{50	2.78	}
		{55	3.41	}
		{60	4.23	}
		{65	5.29	}
		{70	6.69	}
		{75	8.52	}
		{80	10.93	}
		{85	14.15	}
		{90 99		}
	}
)
