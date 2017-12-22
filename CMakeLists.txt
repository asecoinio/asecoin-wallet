cmake_minimum_required(VERSION 3.0.2)
include(CryptoNoteWallet.cmake)

project(${CN_PROJECT_NAME})

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(CRYPTONOTE_LIB bytecoin)

find_package(Qt5 COMPONENTS Core Gui Widgets Network DBus REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
  set(Boost_USE_STATIC_RUNTIME OFF)
else()
  set(Boost_USE_STATIC_RUNTIME ON)
endif(WIN32)

find_package(Boost 1.58 REQUIRED COMPONENTS date_time filesystem program_options regex serialization system thread chrono)
if ((${Boost_MAJOR_VERSION} EQUAL 1) AND (${Boost_MINOR_VERSION} EQUAL 54))
  message(SEND_ERROR "Boost version <= 1.54 unsupported, more details are available here http://goo.gl/RrCFmA")
endif ()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

configure_file("${CRYPTONOTE_LIB}/src/version.h.in" "${PROJECT_BINARY_DIR}/version.h")
configure_file("${PROJECT_SOURCE_DIR}/src/CryptoNoteWalletConfig.h.in" "${PROJECT_BINARY_DIR}/CryptoNoteWalletConfig.h")

add_definitions(-DGIT_REVISION="${GIT_REVISION}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(bytecoin)

set(SOURCES
    src/Application/AddressBookManager.cpp
    src/Application/BlogReader.cpp
    src/Application/CommandLineParser.cpp
    src/Application/LogFileWatcher.cpp
    src/Application/MiningManager.cpp
    src/Application/OptimizationManager.cpp
    src/Application/SignalHandler.cpp
    src/Application/WalletApplication.cpp
    src/Application/WalletSplashScreen.cpp
    src/CryptoNoteWrapper/BlockChainExplorerAdapter.cpp
    src/CryptoNoteWrapper/BlockChainExplorerWorker.cpp
    src/CryptoNoteWrapper/CommonNodeAdapter.cpp
    src/CryptoNoteWrapper/CryptoNoteAdapter.cpp
    src/CryptoNoteWrapper/GuardExecutor.cpp
    src/CryptoNoteWrapper/InProcessNodeAdapter.cpp
    src/CryptoNoteWrapper/InProcessNodeWorker.cpp
    src/CryptoNoteWrapper/ProxyRpcNodeAdapter.cpp
    src/CryptoNoteWrapper/ProxyRpcNodeWorker.cpp
    src/CryptoNoteWrapper/SemaphoreUtils.cpp
    src/CryptoNoteWrapper/WalletGreenAdapter.cpp
    src/CryptoNoteWrapper/WalletGreenWorker.cpp
    src/Gui/AddressBook/AddressBookDelegate.cpp
    src/Gui/AddressBook/AddressBookFrame.cpp
    src/Gui/AddressBook/DonationColumnDelegate.cpp
    src/Gui/AddressBook/NewAddressDialog.cpp
    src/Gui/BlockchainExplorer/BlockDetailsDialog.cpp
    src/Gui/BlockchainExplorer/BlockExplorerFrame.cpp
    src/Gui/BlockchainExplorer/FilteredBlockModel.cpp
    src/Gui/BlockchainExplorer/TransactionsBlockModel.cpp
    src/Gui/BlockchainExplorer/WindowedBlockModel.cpp
    src/Gui/Common/AboutDialog.cpp
    src/Gui/Common/AddressBookDialog.cpp
    src/Gui/Common/BlockchainInstaller.cpp
    src/Gui/Common/ChangePasswordDialog.cpp
    src/Gui/Common/ClearableLineEdit.cpp
    src/Gui/Common/CopyColumnDelegate.cpp
    src/Gui/Common/CopyMagicLabel.cpp
    src/Gui/Common/ExitWidget.cpp
    src/Gui/Common/GlassFrame.cpp
    src/Gui/Common/KeyDialog.cpp
    src/Gui/Common/LinkLikeColumnDelegate.cpp
    src/Gui/Common/MagicLabel.cpp
    src/Gui/Common/NewPasswordDialog.cpp
    src/Gui/Common/NewsFrame.cpp
    src/Gui/Common/NewTransactionDelegate.cpp
    src/Gui/Common/P2pBindPortErrorDialog.cpp
    src/Gui/Common/PoolTransactionDetailsDialog.cpp
    src/Gui/Common/QuestionDialog.cpp
    src/Gui/Common/ResizableScrollArea.cpp
    src/Gui/Common/RightAlignmentColumnDelegate.cpp
    src/Gui/Common/TransactionDetailsDialog.cpp
    src/Gui/Common/TransactionsAmountDelegate.cpp
    src/Gui/Common/TransactionsHeaderView.cpp
    src/Gui/Common/TransactionsTimeDelegate.cpp
    src/Gui/Common/TransfersHeaderView.cpp
    src/Gui/Common/WalletBlueButton.cpp
    src/Gui/Common/WalletCancelButton.cpp
    src/Gui/Common/WalletDescriptionLabel.cpp
    src/Gui/Common/WalletGrayCheckBox.cpp
    src/Gui/Common/WalletLinkLikeButton.cpp
    src/Gui/Common/WalletNavigationButton.cpp
    src/Gui/Common/WalletOkButton.cpp
    src/Gui/Common/WalletTableView.cpp
    src/Gui/Common/WalletTextLabel.cpp
    src/Gui/Common/WalletTreeView.cpp
    src/Gui/Common/WalletWindowedItemModel.cpp
    src/Gui/MainWindow/MainWindow.cpp
    src/Gui/MainWindow/WalletStatusBar.cpp
    src/Gui/Mining/MinerDelegate.cpp
    src/Gui/Mining/MiningFrame.cpp
    src/Gui/Mining/PoolHeaderView.cpp
    src/Gui/Mining/PoolTreeView.cpp
    src/Gui/NoWallet/NoWalletFrame.cpp
    src/Gui/Options/ConnectionOptionsFrame.cpp
    src/Gui/Options/DonationAddressesModel.cpp
    src/Gui/Options/DonationOptionsFrame.cpp
    src/Gui/Options/OptimizationOptionsFrame.cpp
    src/Gui/Options/OptionsDialog.cpp
    src/Gui/Options/PrivacyFrame.cpp
    src/Gui/Overview/OverviewFrame.cpp
    src/Gui/Overview/OverviewHeaderFrame.cpp
    src/Gui/Overview/OverviewHeaderGlassFrame.cpp
    src/Gui/Overview/OverviewTransactionPoolModel.cpp
    src/Gui/Overview/OverviewTransactionPoolTreeView.cpp
    src/Gui/Overview/RecentTransactionsModel.cpp
    src/Gui/Send/SendFrame.cpp
    src/Gui/Send/SendGlassFrame.cpp
    src/Gui/Send/TransferFrame.cpp
    src/Gui/Transactions/DrawableTransfersModel.cpp
    src/Gui/Transactions/FilteredByAddressTransactionsModel.cpp
    src/Gui/Transactions/FilteredByAgeTransactionsModel.cpp
    src/Gui/Transactions/FilteredByHashTransactionsModel.cpp
    src/Gui/Transactions/FilteredByPeriodTransactionsModel.cpp
    src/Gui/Transactions/FilteredTransactionsModel.cpp
    src/Gui/Transactions/TransactionsDelegate.cpp
    src/Gui/Transactions/TransactionsFrame.cpp
    src/Gui/Transactions/TransactionTransfersRenderer.cpp
    src/main.cpp
    src/Miner/Miner.cpp
    src/Miner/StratumClient.cpp
    src/Miner/Worker.cpp
    src/Models/AddressBookModel.cpp
    src/Models/BlockchainModel.cpp
    src/Models/FusionTransactionsFilterModel.cpp
    src/Models/MinerModel.cpp
    src/Models/NodeStateModel.cpp
    src/Models/SortedAddressBookModel.cpp
    src/Models/SortedTransactionsModel.cpp
    src/Models/TransactionPoolModel.cpp
    src/Models/TransactionsModel.cpp
    src/Models/TransfersModel.cpp
    src/Models/WalletStateModel.cpp
    src/QJsonRpc/JsonRpcNotification.cpp
    src/QJsonRpc/JsonRpcObject.cpp
    src/QJsonRpc/JsonRpcObjectFactory.cpp
    src/QJsonRpc/JsonRpcRequest.cpp
    src/QJsonRpc/JsonRpcResponse.cpp
    src/QJsonRpc/JsonRpcServer.cpp
    src/Settings/Settings.cpp
    src/Style/DarkStyle.cpp
    src/Style/LightStyle.cpp
    src/Style/Style.cpp
    src/WalletLogger/WalletLogger.cpp
    )
if(MSVC)
  include_directories(platform/Windows)
  set(SOURCES ${SOURCES} src/platform/Windows/ApplicationEventHandler.cpp)
elseif(APPLE)
  include_directories(platform/OSX)
  set(SOURCES ${SOURCES} src/platform/OSX/*)
else()
  include_directories(platform/Linux)
  set(SOURCES ${SOURCES} src/platform/Linux/ApplicationEventHandler.cpp)
endif()

if (WIN32)
  if (NOT MSVC)
    message(FATAL_ERROR "Only MSVC is supported on this platform")
  endif ()

  set(STATIC OFF CACHE BOOL "Link libraries statically" FORCE)

  add_definitions(/D_CRT_SECURE_NO_WARNINGS /D_WIN32_WINNT=0x0600)
  include_directories(${CRYPTONOTE_LIB}/src/Platform/msc)

  set(PLATFORM_DIR Windows)
  set(BUILD_PLATFORM WIN32)
  set(BUILD_RESOURCES src/bytecoinwallet.rc)
  set(QTMAIN Qt5::WinMain)

elseif (UNIX)

  add_custom_target(
     rocksdb
     COMMAND make static_lib -Wno-undef -Wno-unused-result -Wno-unused-value
     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/cryptonote/external/rocksdb
  )
  add_library(rocksdblib STATIC IMPORTED GLOBAL)
  set_target_properties(rocksdblib PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/cryptonote/external/rocksdb/librocksdb.a)
  add_dependencies(rocksdblib rocksdb)

  set(CRYPTONOTE_SOURCES ${CRYPTONOTE_SOURCES} cryptonote/external/miniupnpc/minissdpc.c)

  if (APPLE)
    enable_language(ASM)
    file(GLOB_RECURSE OBJC_SOURCES src/*.mm)
    set(SOURCES ${SOURCES} ${OBJC_SOURCES})
    set(PLATFORM_DIR OSX)
    set(MACOSX_BUNDLE_INFO_STRING "Cryptonote GUI wallet")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_NAME CryptonoteWallet)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "$${VERSION_VERSION}.${VERSION_MINOR}.${VERSION_PATCH}")

    find_package(Qt5PrintSupport REQUIRED)

    include_directories(/usr/include/malloc)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11 -stdlib=libc++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -maes -D_DARWIN_C_SOURCE")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework CoreFoundation -framework Carbon -framework IOKit -L/usr/lib")

    set(MACOSX_BUNDLE_ICON_FILE cryptonote.icns)
    set(APPLICATION_ICON src/images/cryptonote.icns)
    set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

    set(BUILD_PLATFORM MACOSX_BUNDLE)
    set(BUILD_RESOURCES ${APPLICATION_ICON})

    GET_TARGET_PROPERTY(QT_LIB_DIR "${Qt5Widgets_LIBRARIES}" LOCATION)
    GET_FILENAME_COMPONENT(QT_LIB_DIR "${QT_LIB_DIR}" PATH)

  else(APPLE)

    set(PLATFORM_DIR Linux)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -std=c11")
  endif (APPLE)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/${CRYPTONOTE_LIB}/external/rocksdb/include)
add_executable(${PROJECT_NAME} ${BUILD_PLATFORM} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS _GNU_SOURCE )
target_include_directories(${PROJECT_NAME} PUBLIC
    include
    src
    ${CRYPTONOTE_LIB}/external/rocksdb/include/rocksdb
    ${CRYPTONOTE_LIB}/external
    ${CRYPTONOTE_LIB}/include
    ${CRYPTONOTE_LIB}/src/Platform/${PLATFORM_DIR}
    ${CRYPTONOTE_LIB}/src
    )
target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${QTMAIN}
    ${Qt5DBus_LIBRARIES}
    BlockchainExplorer
    Common
    Crypto
    CryptoNoteCore
    Http
    InProcessNode
    Logging
    NodeRpcProxy
    P2p
    Rpc
    Serialization
    System
    Transfers
    Wallet
    rocksdblib
    Qt5::Widgets
    Qt5::Gui
    Qt5::Network)

if (APPLE)
  target_link_libraries(${PROJECT_NAME} PrintSupport)
elseif (UNIX)
  target_link_libraries(${PROJECT_NAME} -lpthread)
elseif (WIN32)
  target_link_libraries(${PROJECT_NAME} Imm32 Iphlpapi Rpcrt4 Winmm Wtsapi32)
  target_include_directories(${PROJECT_NAME} PUBLIC src/Platform/${PLATFORM_DIR})
endif (APPLE)
