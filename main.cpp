//Калькулятор для определения времени передачиданных с заданным объёмом

#include <iostream>

//Время передачи определяется путём отношения объёма передаваемого блока к пропускной способности
long double TransferTime(float Size, unsigned short Capacity){
return (Size * 8 / Capacity);
}

int main() {
	unsigned int Distance, DataTransmissionTimeSec, DataTransmissionTimeMsec;
	unsigned short Capacity;
	float SpeedChangeRatio, MessageSize;
	long double PropagationDelay, DataTransmissionTime, MessageTransferTime;
	char mode;
	const unsigned int SpeedOfLight = 299792458;

	std::cout << "Choose mode ((C)hanel Switching or (P)acket Swithing): ";
	std::cin >> mode;
	std::cout << "Message size (Mb): ";
	std::cin >> MessageSize;
	std::cout << "Distance (m): ";
	std::cin >> Distance;
	std::cout << "Capacity (Mbit/s): ";
	std::cin >> Capacity;
	std::cout << "Speed change ratio (0.6-0.9): ";
	std::cin >> SpeedChangeRatio;

	//Время задержки распростраения сигнала представляет собой отношение расстояния к скорости распространения сигнала в определённой среде.
	//Скорость указывается в виде доли от скорости света. 
	PropagationDelay = Distance / (SpeedOfLight*SpeedChangeRatio);

	MessageTransferTime = TransferTime(MessageSize, Capacity);

	switch (tolower(mode)){
		//Расчёт времени передачи при коммутации каналов.
		case 'c':
			//Время передачи данных равно сумме времени задержки распространения сигнала и времени передачи собственно сообщения
			DataTransmissionTime = PropagationDelay + MessageTransferTime;
			break;

		//Расчёт времени передачи при коммутации пакетов.
		case 'p':
			int NumberOfSwitches, PacketSize, NumberOfPackets, SendingDelayOnSwitch;
			long double HeaderSize, HeaderTransferTime, SwitchingDelayOnSwitch, BuferisationDelayOnSwitch;

			std::cout << "Number of swithes: ";
			std::cin >> NumberOfSwitches;
			std::cout << "Packet size (kb): ";
			std::cin >> PacketSize;
			std::cout << "Header size (kb): ";
			std::cin >> HeaderSize;
			std::cout << "Sending Delay on Switch (ms): ";
			std::cin >> SendingDelayOnSwitch;
			std::cout << "Switching Delay on Switch (ms): ";
			std::cin >> SwitchingDelayOnSwitch;
			std::cout << "Buferisation Delay on Switch (ms): ";
			std::cin >> BuferisationDelayOnSwitch;

			//Определение количества пакетов необходимых для передачи данных.
			NumberOfPackets = MessageSize * 1024 / PacketSize;
			if (MessageSize * 1024 - NumberOfPackets * PacketSize)
				NumberOfPackets++;

			HeaderTransferTime = TransferTime(HeaderSize / 1024, Capacity);

			//Определение времени передачи данных по сетям с коммутацией пакетов аналогично сетям с коммутацией каналов, но дополнительно учитывается время передачи заголовков пакетов и задержки перед отправкой каждого пакета, а также задержка коммутации и буферизации на каждом свитче.
			DataTransmissionTime = PropagationDelay + MessageTransferTime + (HeaderTransferTime + SendingDelayOnSwitch / 1000) * NumberOfPackets + ((SwitchingDelayOnSwitch + BuferisationDelayOnSwitch) / 1000) * NumberOfSwitches;
			break;

		default:
			std::cout << "Only C or P" << std::endl;
	}
	
	DataTransmissionTimeSec = DataTransmissionTime;
	DataTransmissionTimeMsec = (DataTransmissionTime - DataTransmissionTimeSec) * 1000;
	
	if ((DataTransmissionTimeSec > 0) && (DataTransmissionTimeMsec))
		std::cout << "Result: " << DataTransmissionTimeSec << " sec " << DataTransmissionTimeMsec << " ms"<< std::endl;
	else if ((DataTransmissionTimeSec > 0) && (DataTransmissionTimeMsec == 0))
		std::cout << "Result: " << DataTransmissionTimeSec << " sec" << std::endl;
	else if ((DataTransmissionTimeSec == 0) && (DataTransmissionTimeMsec))
		std::cout << "Result: " << DataTransmissionTimeMsec << " ms"<< std::endl;
		
	system("pause");
}
