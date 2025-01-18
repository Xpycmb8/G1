;spreading
(define "spreading_low"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 99.0 95.0 90.0 85.0 80.0 75.0 70.0}
	}
)
(define "spreading_low_boost"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.25}
		{BurstAccuracy 100 99.0 95.0 90.0 85.0 80.0}
	}
)
(define "spreading_low_boost_ap"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.15}
		{BurstAccuracy 100 99.0 97.0 94.0 88.0 86.0}
	}
)
(define "spreading_medium"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 95.0 90.0 85.0 80.0 75.0 70.0 65.0}
	}
)
(define "spreading_medium_boost"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.25}
		{BurstAccuracy 100 95.0 90.0 85.0 80.0 75.0}
	}
)
(define "spreading_high"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 90.0 85.0 80.0 75.0 70.0 65.0 60.0}
	}
)
(define "spreading_high_boost"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.25}
		{BurstAccuracy 100 90.0 85.0 80.0 75.0 70.0}
	}
)
(define "spreading_medium_mgun"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 90.0 85.0 80.0 75.0 70.0 65.0 60.0 55.0 50.0}
	}
)
(define "spreading_high_mgun"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.5}
		{BurstAccuracy 100 85.0 80.0 75.0 70.0 65.0 60.0 55.0 50.0 45.0}
	}
)
(define "spreading_short_barrel"
	{spreading 1
		{SpreadPower	1}
		{BurstRecoveryTime 0.7}
		{BurstAccuracy 100 85.0 80.0 75.0 70.0 65.0 60.0 55.0 50.0 45.0}
	}
)

(define "spreading_mounted"
	{spreading
		{BurstAccuracy 100 95 90 85 80 75 70 65 60}
	}
)
