TEMPLATE = app

QT += core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TARGET = Demo

DEFINES += QT_DEPRECATED_WARNINGS QT_ASCII_CAST_WARNINGS

include(../de_skycoder42_qconsole.pri)

SOURCES += main.cpp
