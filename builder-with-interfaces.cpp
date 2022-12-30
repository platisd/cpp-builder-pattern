#include <memory>
#include <string>
#include <vector>

namespace
{
class Menu
{
public:
    virtual ~Menu()                      = default;
    virtual void show() const            = 0;
    virtual void select(int index) const = 0;
};

class Builder
{
public:
    virtual ~Builder()                             = default;
    virtual Builder& withTitle(std::string title)  = 0;
    virtual Builder& withBorder(int pixels)        = 0;
    virtual Builder& addOption(std::string option) = 0;
    virtual Builder& horizontal()                  = 0;
    virtual Builder& vertical()                    = 0;
    virtual std::unique_ptr<Menu> build()          = 0;
};

class MenuBuilder : public Builder
{
public:
    class DefaultMenu : public Menu
    {
    public:
        void show() const override {}
        void select(int /* index */) const override {}

    private:
        friend class MenuBuilder;

        std::string mId{};
        std::string mTitle{};
        std::vector<std::string> mOptions{};
        bool mHorizontal{false};
        int mBorder{0};

        DefaultMenu(std::string id)
            : mId{id}
        {
        }
    };

    MenuBuilder(std::string id)
        : mMenu{new DefaultMenu{id}}
    {
    }

    std::unique_ptr<Menu> build() override
    {
        return std::move(mMenu);
    }

    MenuBuilder& withTitle(std::string title) override
    {
        mMenu->mTitle = title;
        return *this;
    }

    MenuBuilder& withBorder(int pixels) override
    {
        mMenu->mBorder = pixels;
        return *this;
    }

    MenuBuilder& addOption(std::string option) override
    {
        mMenu->mOptions.emplace_back(option);
        return *this;
    }

    MenuBuilder& horizontal() override
    {
        mMenu->mHorizontal = true;
        return *this;
    }

    MenuBuilder& vertical() override
    {
        mMenu->mHorizontal = false;
        return *this;
    }

private:
    std::unique_ptr<DefaultMenu> mMenu{};
};
} // namespace

int main()
{
    const auto menu = MenuBuilder{"main"}
                          .withTitle("Main Menu")
                          .withBorder(1)
                          .addOption("Option 1")
                          .addOption("Option 2")
                          .horizontal()
                          .build();
    menu->show();
    menu->select(1);

    return 0;
}
