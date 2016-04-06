//¬рем€ передачи данных в сет€х с коммутацией каналов складываетс€ из задержки распространени€ сигнала и задержки передачи сообщени€.
//«адержка распространени€ равна отношению дистанции к скорости передачи электромагнитных волн в определЄнной среде передачи, котора€ равна 0,6-0,9 скорость света.
//«адержка передачи собственно сообщени€ равна отношению размера сообщени€ к пропускной способности канала.

#include <iostream>

long double TransferTime(float Size, unsigned short Capacity){
return (Size * 8 / Capacity);
}

int main() {
	unsigned int Distance;
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
	PropagationDelay = Distance / (SpeedOfLight*SpeedChangeRatio);
	MessageTransferTime = TransferTime(MessageSize, Capacity);
	switch (mode){
		case 'C':
			DataTransmissionTime = PropagationDelay + MessageTransferTime;
			break;
		case 'P':
			int NumberOfSwitches, PacketSize, NumberOfPackets, HeaderSize, SendingDelayOnSwitch, SwitchingDelayOnSwitch, BuferisationDelayOnSwitch;
			long double HeaderTransferTime;
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
			NumberOfPackets = MessageSize * 1024 / PacketSize;
			if (MessageSize * 1024 - NumberOfPackets * PacketSize)
				NumberOfPackets++;
			HeaderTransferTime = TransferTime(HeaderSize, Capacity);
			DataTransmissionTime = (PropagationDelay + HeaderTransferTime + SendingDelayOnSwitch * 1000) * NumberOfPackets + (SwitchingDelayOnSwitch + BuferisationDelayOnSwitch) * 1000 * NumberOfSwitches + MessageTransferTime;
			break;
		default:
			std::cout << "Only C or P" << std::endl;
	}
	std::cout << "Result: " << DataTransmissionTime << " sec" << std::endl;
	system("pause");
}
