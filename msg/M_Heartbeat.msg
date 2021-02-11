# M_Heartbeat.msg
# ID 180

# --- Common --- 
# 发送端 编号 
uint8 Send_ID		
# 接收端 编号
uint8 Receive_ID	 

# --- Heartbeat ---
# 飞机状态 offboard... [0-255]
uint8 mav_mode		
# 任务状态 
uint8 task_status

# 电池 电压 (V-6)/0.1 -> [0-255]
uint8 battery_voltage
# 电池 剩余电量 %
uint8 battery_remaining

# To be completed !
# Communication status
# mavlink_seq %
uint8 commun_seq
# Rn %
uint8 commun_Rn

