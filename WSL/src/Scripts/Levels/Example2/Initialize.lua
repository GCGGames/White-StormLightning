function MakeUFO( num )
	singleton:Instantiate( "bin/Info/Objects/UFO/Object.txt" )
	level:AddObject( num, 0 )
end

level:SetActive( true )
level.active = true
level.refresh = true
defaultRenderLayer:SetActive( true )
stack:AddInt( "ufoNum", 1, true )
MakeUFO( 0 )
MakeUFO( 1 )
MakeUFO( 2 )
MakeUFO( 3 )

stack:AddInt( "add", 0, true )
print( "Level Up!" )

