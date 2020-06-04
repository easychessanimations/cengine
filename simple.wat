(module
	(import "js" "mem" (memory 1))
	(func (export "toUpper") (param i32) (local i32)
		i32.const 0
		set_local 0				
		block $B1
			loop $L1
				get_local 0		
				i32.load
				i32.const 0
				i32.eq
				br_if $B1 ;; break if character is 0				
				block $B2
					get_local 0		
					i32.load
					i32.const 97
					i32.lt_u
					br_if $B2
					get_local 0		
					i32.load
					i32.const 122
					i32.gt_u
					br_if $B2
					get_local 0		
					get_local 0		
					i32.load
					i32.const 32
					i32.sub		
					i32.store
				end				
				get_local 0
				i32.const 4
				i32.add
				set_local 0				
				br $L1				
			end		
		end
	)
	(func (export "toLower") (param i32) (local i32)
		i32.const 0
		set_local 0				
		block $B1
			loop $L1
				get_local 0		
				i32.load
				i32.const 0
				i32.eq
				br_if $B1 ;; break if character is 0				
				block $B2
					get_local 0		
					i32.load
					i32.const 65
					i32.lt_u
					br_if $B2
					get_local 0		
					i32.load
					i32.const 90
					i32.gt_u
					br_if $B2
					get_local 0		
					get_local 0		
					i32.load
					i32.const 32
					i32.add	
					i32.store
				end				
				get_local 0
				i32.const 4
				i32.add
				set_local 0				
				br $L1				
			end		
		end
	)
)
