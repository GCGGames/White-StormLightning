singleton:AddSprite( 1, false )
position:SetX( 200 )
position:SetY( 300 )
position:SetZ( 1 )
stack:SetInt( "ufoNum", stack:GetInt( "ufoNum" ):Get() + 1 )
stack:AddInt( "dir" , 0, false )
stack:AddInt( "count", 0, true )
sprite:SetRenderLayer( "levelRenderLayer0" )
stack:SetInt( "add", object:GetID() )
print( "UFO!" )