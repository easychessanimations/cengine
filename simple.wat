(module
	(import "js" "mem" (memory 1))
	(func (export "addTwo") (param i32 i32) (result i32)						
		get_local 0
		i32.load
		get_local 1
		i32.add
	)
)
