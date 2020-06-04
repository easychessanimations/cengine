(module
	(import "js" "mem" (memory 1))
	(func $toCase (param $offset i32) (param $rangeLow i32) (param $rangeHigh i32) (param $shift i32) (local $ptr i32)
		get_local $offset
		set_local $ptr ;; set pointer to offset
		block $B1
			loop $L1
				get_local $ptr
				i32.load ;; load char at ptr
				i32.const 0
				i32.eq ;; compare the char at ptr to 0
				br_if $B1 ;; break if character is 0				
				block $B2
					get_local $ptr
					i32.load ;; get char at ptr
					get_local $rangeLow
					i32.lt_u ;; compare it to rangeLow
					br_if $B2 ;; break if below range
					get_local $ptr
					i32.load ;; get char at ptr
					get_local $rangeHigh
					i32.gt_u ;; compare it to rangeHigh
					br_if $B2 ;; break if above range
					get_local $ptr ;; get ptr		
					get_local $ptr		
					i32.load ;; get char at ptr
					get_local $shift
					i32.add ;; add shift
					i32.store ;; store at ptr
				end				
				get_local $ptr
				i32.const 4
				i32.add ;; add size of i32 to ptr
				set_local $ptr ;; store increased ptr				
				br $L1 ;; loop				
			end		
		end
	)
	(func (export "toUpper") (param $offset i32) (local i32)
		get_local $offset
		i32.const 4
		i32.mul ;; multiply offset by size of i32
		i32.const 97
		i32.const 122
		i32.const -32
		call $toCase
	)
	(func (export "toLower") (param $offset i32) (local i32)
		get_local $offset
		i32.const 4
		i32.mul ;; multiply offset by size of i32
		i32.const 65
		i32.const 90
		i32.const 32
		call $toCase
	)
)
