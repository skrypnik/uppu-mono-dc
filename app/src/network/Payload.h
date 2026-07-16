#pragma once

#include <memory>

#include <QByteArray>

namespace Enercom::Network
{
    class Payload
    {
        /**
        * Construction is deprecated
        */
        Payload() = default;

    public:
        /**
        * Request type
        */
        enum class Request : uint8_t
        {
            SetMetersInfo          = 0x80,
            GetMetersInfo          = 0x81,
            SetGivenMeter          = 0x82,
            GetGivenMeter          = 0x83,
            AllowVoltageFlow       = 0x84,
            GetDeviceInfo          = 0x00,
            GetMeterReadings       = 0x90,
            GetCalibratorReadings  = 0x91,
            SetCalibratorInfo      = 0xA0,
            GetCalibratorInfo      = 0x91,
            SetHiVoltageInfo       = 0xA4,
            GetHiVoltageInfo       = 0xA5,
            SetLoVoltageInfo       = 0xA6,
            GetLoVoltageInfo       = 0xA7,
            GetStatusInfo          = 0xA8,
            AllowVoltageGeneration = 0xA9,
            SetNetworkInfo         = 0xB0
        };

    public:
        /**
         * Decomposed payload data
         */
        class Fields
        {
            /**
             * For easy usage in Packet class
             */
            friend class Payload;

        public:
            /**
             * Alias for shared_ptr
             */
            using Ptr = std::shared_ptr<Fields>;

        public:
            /**
             * Default constructor
             */
            Fields() = default;

            /**
             * Payload type according to Payload::Request enum getter
             */
            [[nodiscard]] uint8_t type() const;

            /**
             * Payload data (Fields::data_) size getter
             */
            [[nodiscard]] uint8_t size() const;

            /**
             * Payload data getter
             */
            [[nodiscard]] const QByteArray& data() const;

            /**
             * Payload raw data getter
             */
            [[nodiscard]] const QByteArray& bytes() const;

        private:
            /**
             * Payload type according to Payload::Request enum
             */
            uint8_t type_ {};

            /**
             * Payload data (Fields::data_) size
             */
            uint8_t size_ {}; /// \todo

            /**
             * Payload data
             */
            QByteArray data_;

            /**
             * Payload raw data
             */
            QByteArray bytes_;
        };

    public:
        /**
         * Decompose packet raw data
         * @param data packet raw data
         * @return pointer to decomposed data
         */
        static Fields::Ptr fromRawData(const QByteArray& data);

    public:
        /**
         * Generates TLV formated byte sequence for device info request
         * @return TLV formated request
         */
        static QByteArray deviceInfoRequest(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for set meters info request
         * @param count meters count
         * @param speed baud rate
         * @param type input type
         * @param voltage input voltage
         * @return TLV formated request
         */
        static QByteArray setMetersInfoRequest(uint8_t count, uint32_t speed, uint8_t type, float voltage);

        /**
         * Generates TLV formated byte sequence for get meters info request
         * @return TLV formated request
         */
        static QByteArray getMetersInfoRequest();

        /**
         * Generates TLV formated byte sequence for set meter params request
         * @param index meter index
         * @param address meter MODBUS address
         * @param current meter current
         * @param voltage meter voltage
         * @param constant meter constant coefficient
         * @param factor meter impulse factor
         * @return TLV formated request
         */
        static QByteArray setGivenMeterRequest(uint8_t index, uint8_t address, float current, float voltage, uint32_t constant, uint8_t factor);

        /**
         * Generates TLV formated byte sequence for get meter params request
         * @param index meter index
         * @return TLV formated request
         */
        static QByteArray getGivenMeterRequest(uint8_t index);

        /**
         * Generates TLV formated byte sequence for allow meter voltage to flow request
         * @param allow allow flag (0 - off, 1 -on)
         * @return TLV formated request
         */
        static QByteArray allowVoltageFlow(uint8_t allow);

        /**
         * Generates TLV formated byte sequence for get meter readings request
         * @param index meter index
         * @return TLV formated request
         */
        static QByteArray getMeterReadingsRequest(uint8_t index);

        /**
         * Generates TLV formated byte sequence for get calibrator readings request
         * @param reserved reserved param
         * @return TLV formated request
         */
        static QByteArray getCalibratorReadingsRequest(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for set calibrator info request
         * @param type meter type
         * @param constant meter constant coefficient
         * @param current meter current
         * @param voltage meter voltage
         * @return TLV formated request
         */
        static QByteArray setCalibratorInfoRequest(uint8_t type, uint32_t constant, float current, float voltage);

        /**
         * Generates TLV formated byte sequence for get calibrator info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        static QByteArray getCalibratorInfoRequest(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for set high voltage info request
         * @param mode operating mode
         * @param volREG regulator voltage
         * @param volDAC DAC voltage
         * @return TLV formated request
         */
        static QByteArray setHiVoltageInfoRequest(uint8_t mode, float volREG, float volDAC);

        /**
         * Generates TLV formated byte sequence for get high voltage info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        static QByteArray getHiVoltageInfoRequest(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for set low voltage info request
         * @param mode operating mode
         * @param volREG regulator voltage
         * @param volDAC DAC voltage
         * @return TLV formated request
         */
        static QByteArray setLoVoltageInfoRequest(uint8_t mode, float volREG, float volDAC);

        /**
         * Generates TLV formated byte sequence for get low voltage info request
         * @param reserved reserved param
         * @return TLV formated request
         */
        static QByteArray getLoVoltageInfoRequest(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for get status request
         * @param reserved reserved param
         * @return TLV formated request
         */
        static QByteArray getStatus(uint8_t reserved = 0x00);

        /**
         * Generates TLV formated byte sequence for allow voltage generation request
         * @param hiVoltage hi voltage
         * @param loVoltage lo voltage
         * @return TLV formated request
         */
        static QByteArray allowVoltageGenerationRequest(uint8_t hiVoltage, uint8_t loVoltage);

        /**
         * Generates TLV formated byte sequence for set network info request
         * @param host network address
         * @param port network port
         * @param mask network mask
         * @return
         */
        static QByteArray setNetworkInfoRequest(uint32_t host, uint16_t port, uint32_t mask);

    public:
        /**
        * Generates TLV for given tag and value
        * @param type type
        * @param value value
        * @return TLV formated byte array for given tag and value
        */
        static QByteArray pack(uint8_t type, const QByteArray& value);

    public:
        /**
        * Construction is deprecated
        */
        Payload(const Payload&) = delete;
        Payload(Payload&&) = delete;
        Payload& operator=(const Payload&) = delete;
        Payload& operator=(Payload&&) = delete;
    };

}
