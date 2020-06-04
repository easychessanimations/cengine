(module
	(import "js" "mem" (memory 1))
	(func (export "addTwo") (param i32 i32) (result i32)						
		i32.const 0
		i32.const 65
		i32.store
		i32.const 4
		i32.const 66
		i32.store
		i32.const 8
		i32.const 0
		i32.store
		get_local 0
		i32.const 4
		i32.mul
		i32.load
		get_local 1
		i32.add
	)
)
