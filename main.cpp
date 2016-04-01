//¬рем€ передачи данных в сет€х с коммутацией каналов складываетс€ из задержки распространени€ сигнала и задержки передачи сообщени€.
//«адержка распространени€ равна отношению дистанции к скорости передачи электромагнитных волн в определЄнной среде передачи, котора€ равна 0,6-0,9 скорость света.
//«адержка передачи собственно сообщени€ равна отношению размера сообщени€ к пропускной способности канала.

#include <iostream>

int main() {
	int Distance, Capacity;
	float SCR, PropagationDelay, MessageTransferTime, MessageSize, DataTransmissionTime;
	const int SpeedOfLight = 299792458;
	std::cout << "Message size (Mb): ";
	std::cin >> MessageSize;
	std::cout << "Distance (m): ";
	std::cin >> Distance;
	std::cout << "Capacity (Mbit/s): ";
	std::cin >> Capacity;
	std::cout << "Speed change ratio (0.6-0.9): ";
	std::cin >> SCR;
	PropagationDelay = Distance / (SpeedOfLight*SCR);
	MessageTransferTime = (MessageSize * 8) / Capacity;
	DataTransmissionTime = PropagationDelay + MessageTransferTime;
	std::cout << "Result: " << DataTransmissionTime << " sec";
}
