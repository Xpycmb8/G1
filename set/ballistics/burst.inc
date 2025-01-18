(define "burst_assault"
	{burst
		;{min 1}			; min burst shots in automatic mode
		;{noaiming}			; no aiming during burst
		{short 1 0}			; short burst shots on long distance, rand (+-)shots
		{long 5 2}			; long burst shots on short distance, rand (+-)shots
		{rangeKoef 0.3}		; rangeKoef * aimRange = max long burst distance
	}
)

(define "burst_assault_short"
	{burst
		{short 1 0}
		{long 3 0}
		{rangeKoef 0.3}
	}
)

(define "burst_assault_x2"
	{burst
		{min 2}
		{short 2 0}
		{long 2 0}
		{rangeKoef 0.3}
	}
)

(define "burst_assault_x3"
	{burst
		{min 3}
		{short 3 0}
		{long 3 0}
		{rangeKoef 0.3}
	}
)

(define "burst_rifle"
	{burst
		{short 1 0}
		{long 1 0}
		{rangeKoef 0.3}
	}
)

(define "burst_pistol"
	{burst
		{short 1 0}
		{long 3 1}
		{rangeKoef 0.3}
	}
)

(define "burst_smg"
	{burst
		{short 5 1}
		{long 8 3}
		{rangeKoef 0.3}
	}
)

(define "burst_grenade"
	{burst
		{short 3 0}
		{long 5 1}
		{rangeKoef 0.20}
	}
)

(define "burst_mg"
	{burst
		{short 5 1}
		{long 12 3}
		{rangeKoef 0.25}
	}
	{FiringTimeout 0.8 0.2}	
)

(define "burst_x1"
	{burst
		{short 1 0}
		{long 1 0}
		{rangeKoef 0.3}
	}
)

(define "burst_x3"
	{burst
		{short 3 0}
		{long 3 0}
		{rangeKoef 0.3}
	}
)

(define "burst_x6"
	{burst
		{short 6 9}
		{long 6 9}
		{rangeKoef 0.6}
	}
)

(define "burst_short"
	{burst
		{short 3 1}
		{long 12 2}
		{rangeKoef 0.4}
	}
)

(define "burst_long"
	{burst
		{short 5 1}
		{long 15 2}
		{rangeKoef 0.4}
	}
)
