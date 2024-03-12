/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <string>

template <typename T>
class DLLoader {
    public:
        /**
         * @brief Construct a new DLLoader object
         *
         */
        DLLoader() = default;

        /**
         * @brief Destroy the DLLoader object
         *
         */
        ~DLLoader();


        /**
         * @brief Get the Instance object
         *
         * Use this function to get an instance of the class
         * Throw a runtime_error if the library cannot be opened or if the symbol cannot be loaded
         *
         * @param path path to the library
         * @param entryPoint name of the function to load
         * @return T*
         */
        T *getInstance(const std::string &path, const std::string &entryPoint = "entryPoint");

        /**
         * @brief Destroy the Instance object
         *
         * @param instance
         */
        void destroyInstance(T *instance);

    private:
        void *handle = nullptr;
};

#endif /* !DLLOADER_HPP_ */
