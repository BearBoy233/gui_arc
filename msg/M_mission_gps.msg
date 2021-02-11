# M_mission_gps.msg
# ID 191 Mission_gps

# --- Common --- 
# 发送端 编号 
uint8 Send_ID		
# 接收端 编号
uint8 Receive_ID	 

# --- M_mission_loc ---
# state uint8
uint8 state

# x float
float64 longtitude	
	
# y float
float64 latitude

# z float
float32 altitude


