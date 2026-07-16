#include "Payload.h"

#include "Packet.h"

#include <QDebug>

namespace Enercom::Network
{
    uint8_t Payload::Fields::type() const
    {
        return type_;
    }

    uint8_t Payload::Fields::size() const
    {
        return size_;
    }

    const QByteArray& Payload::Fields::data() const
    {
        return data_;
    }

    const QByteArray& Payload::Fields::bytes() const
    {
        return bytes_;
    }

    Payload::Fields::Ptr Payload::fromRawData(const QByteArray& data)
    {
        auto ptr = std::make_shared<Fields>();

        ptr->type_ = data[0];
        ptr->size_ = data[1]; /// \todo
        ptr->data_ = data.mid(0x02, static_cast<int>(ptr->size_));
        ptr->bytes_ = data;

        return ptr;
    }

    /*static*/ QByteArray Payload::deviceInfoRequest(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetDeviceInfo), value);
    }

    QByteArray Payload::setMetersInfoRequest(uint8_t count, uint32_t speed, uint8_t type, float voltage)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&count), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&speed), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&type), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&voltage), sizeof(float)));

        return pack(static_cast<uint8_t>(Request::SetMetersInfo), value);
    }

    QByteArray Payload::getMetersInfoRequest()
    {
        return pack(static_cast<uint8_t>(Request::GetMetersInfo), {});
    }

    QByteArray Payload::setGivenMeterRequest(uint8_t index, uint8_t address, float current, float voltage, uint32_t constant, uint8_t factor)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&index), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&address), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&current), sizeof(float)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&voltage), sizeof(float)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&constant), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&factor), sizeof(int8_t)));

        return pack(static_cast<uint8_t>(Request::SetGivenMeter), value);
    }

    QByteArray Payload::getGivenMeterRequest(uint8_t index)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&index), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetGivenMeter), value);
    }

    QByteArray Payload::allowVoltageFlow(uint8_t allow)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&allow), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::AllowVoltageFlow), value);
    }

    QByteArray Payload::getMeterReadingsRequest(uint8_t index)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&index), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetMeterReadings), value);
    }

    QByteArray Payload::getCalibratorReadingsRequest(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetCalibratorReadings), value);
    }

    QByteArray Payload::setCalibratorInfoRequest(uint8_t type, uint32_t constant, float current, float voltage)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&type), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&constant), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&current), sizeof(float)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&voltage), sizeof(float)));

        return pack(static_cast<uint8_t>(Request::SetCalibratorInfo), value);
    }

    QByteArray Payload::getCalibratorInfoRequest(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetCalibratorInfo), value);
    }

    QByteArray Payload::setHiVoltageInfoRequest(uint8_t mode, float volREG, float volDAC)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&mode), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&volREG), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&volDAC), sizeof(uint32_t)));

        return pack(static_cast<uint8_t>(Request::SetHiVoltageInfo), value);
    }

    QByteArray Payload::getHiVoltageInfoRequest(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetHiVoltageInfo), value);
    }

    QByteArray Payload::setLoVoltageInfoRequest(uint8_t mode, float volREG, float volDAC)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&mode), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&volREG), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&volDAC), sizeof(uint32_t)));

        return pack(static_cast<uint8_t>(Request::SetLoVoltageInfo), value);
    }

    QByteArray Payload::getLoVoltageInfoRequest(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetLoVoltageInfo), value);
    }

    QByteArray Payload::getStatus(uint8_t reserved)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&reserved), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::GetStatusInfo), value);
    }

    QByteArray Payload::allowVoltageGenerationRequest(uint8_t hiVoltage, uint8_t loVoltage)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&hiVoltage), sizeof(uint8_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&loVoltage), sizeof(uint8_t)));

        return pack(static_cast<uint8_t>(Request::AllowVoltageGeneration), value);
    }

    QByteArray Payload::setNetworkInfoRequest(uint32_t host, uint16_t port, uint32_t mask)
    {
        QByteArray value;
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&host), sizeof(uint32_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&port), sizeof(uint16_t)));
        value.append(QByteArray::fromRawData(reinterpret_cast<char*>(&mask), sizeof(uint32_t)));

        return pack(static_cast<uint8_t>(Request::SetNetworkInfo), value);
    }

    /*static*/ QByteArray Payload::pack(const uint8_t type, const QByteArray& value)
    {
        const auto len = static_cast<uint8_t>(value.length());

        auto tlv = QByteArray();

        tlv.append(static_cast<char>(type));

        if (len < 0x7F)
        {
            tlv.append(static_cast<char>(len));
        }
        else
        {
            /// \todo
        }

        tlv.append(value);

        return tlv;
    }

}