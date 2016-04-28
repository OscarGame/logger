///
/// \brief �������ķ�װ
///
#ifndef MUTEX
#define MUTEX

#include <stdint.h> 
#include <pthread.h>
#include <errno.h>
#include <stdexcept>
#include <string.h>
using namespace std;

class Mutex {
public:
    explicit Mutex(){
	init();
	}
	
    ~Mutex() {
        pthread_mutex_destroy(&m_Mutex);
    }
    
    void init() {
        int32_t error_t;
        error_t = pthread_mutex_init(&m_Mutex, NULL);
        checkError("Mutex::Mutex", error_t);
    }
    
    ///
    /// \brief ֱ�Ӽ���
    ///
    void Lock() {
        checkError("Mutex::Lock", pthread_mutex_lock(&m_Mutex));
    }
    
    ///
    /// \brief ���Լ���
    ///
    bool TryLock() {
        int32_t error_t =pthread_mutex_trylock(&m_Mutex);
        if (error_t == EBUSY) {
            return false;
        }else{
            checkError("Mutex::trylock", error_t);
            return true;
        }
    }
    
    ///
    /// \brief ����
    ///
    void unLock() {
        checkError("Mutex::Unlock", pthread_mutex_unlock(&m_Mutex));
    }
    
private:
    ///
    /// \brief �����������
    ///
    static void checkError(const char *error_msg, int error) {
        if (error != 0) {
            string msg = error_msg;
            msg += " error: ";
            msg += strerror(error);
            throw runtime_error(msg);
        }
    }
    
    pthread_mutex_t m_Mutex;
    
    friend class ConditionVariable;
    
private:
    ///
    /// \brief ��ֹ��������
    ///
    Mutex(const Mutex& right);
    
    ///
    /// \brief ��ֹ��ֵ
    ///
    Mutex& operator = (const Mutex& right);   
};
#endif